//
//  ofxGifDecoder.cpp
//  gifPhasing
//
//  Created by Jesus Gollonet on 5/14/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ofxGifDecoder.h"
//#include "FreeImage.h"
#define DWORD uint32_t

ofxGifDecoder::ofxGifDecoder(){
    globalPalette = NULL;
    globalPaletteSize = 0;
    bNeedToUpdate = false;
    ofAddListener(ofEvents().update, this, &ofxGifDecoder::update);
}

ofxGifDecoder::~ofxGifDecoder(){
    ofRemoveListener(ofEvents().update, this, &ofxGifDecoder::update);
    waitForThread();
}

// required to update textures with threaded version
void ofxGifDecoder::update( ofEventArgs & e ){
    if ( bNeedToUpdate ){
        // gif is loaded, switch all textures on
        for ( auto & frame : gifFile.getFrames() ){
            frame.setUseTexture(true);
        }
        
        bNeedToUpdate = false;
        ofNotifyEvent(onGifLoaded, gifFile, this);
    }
}

// return a bool if succesful
bool ofxGifDecoder::decode(string fileName, bool useTextures) {
    reset();
	int width, height, bpp;
	fileName                    = ofToDataPath(fileName);
	bool bDecoded               = false;
	FIMULTIBITMAP	* multiBmp  = NULL;
    
    
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	fif = FreeImage_GetFileType(fileName.c_str(), 0);
    
	if(fif != FIF_GIF) {
        ofLog(OF_LOG_WARNING, "ofxGifDecoder::decode. this is not a gif file. not processing");
        
        return bDecoded;
	}
    
    multiBmp = FreeImage_OpenMultiBitmap(fif, fileName.c_str(), false, false,true, GIF_LOAD256);
    
    if (multiBmp){

        // num frames
        int nPages = FreeImage_GetPageCount(multiBmp);
        
        // here we process the first frame
        for (int i = 0; i < nPages; i++) {
            FIBITMAP * dib = FreeImage_LockPage(multiBmp, i);            
            if(dib) {
                if (i == 0) {
                    createGifFile(dib, nPages);
                    bDecoded = true;   // we have at least 1 frame
                }
                processFrame(dib, i, useTextures);
                FreeImage_UnlockPage(multiBmp, dib, false);
            } else {
                ofLog(OF_LOG_WARNING, "ofxGifDecoder::decode. problem locking page");
                
            }
        }
        FreeImage_CloseMultiBitmap(multiBmp, 0);
    }else {
        ofLog(OF_LOG_WARNING, "ofxGifDecoder::decode. there was an error processing.");
	}    
    return bDecoded;
}

void ofxGifDecoder::decodeThreaded(string fileName) {
    // will smash if inside thread
    reset();
    
    if ( isThreadRunning() ){
        ofLogError()<<"ofxGifDecoder::Thread already running! Please wait till loaded";
        return;
    }
    currentFile = fileName;
    startThread();
}

void ofxGifDecoder::threadedFunction(){
    bool success = decode(currentFile, false);
    if ( success ){
        bNeedToUpdate = true;
    }
}

void ofxGifDecoder::createGifFile(FIBITMAP * bmp, int _nPages){

    FITAG *tag;

    int logicalWidth, logicalHeight;
    
    if( FreeImage_GetMetadata(FIMD_ANIMATION, bmp, "LogicalWidth", &tag)) {
        logicalWidth = *(unsigned short *)FreeImage_GetTagValue(tag);
    }
    
    if( FreeImage_GetMetadata(FIMD_ANIMATION, bmp, "LogicalHeight", &tag)) {
        logicalHeight = *(unsigned short *)FreeImage_GetTagValue(tag);
    }
    
    if( FreeImage_GetMetadata(FIMD_ANIMATION, bmp, "GlobalPalette", &tag) ) {
        globalPaletteSize = FreeImage_GetTagCount(tag);
        if( globalPaletteSize >= 2 ) {
            globalPalette = (RGBQUAD *)FreeImage_GetTagValue(tag);
            for (int i = 0 ; i < globalPaletteSize; i++) {
                ofColor c;
                c.set(globalPalette[i].rgbRed, globalPalette[i].rgbGreen, globalPalette[i].rgbBlue);
                palette.push_back(c);
            }
        }
    }
    
    gifFile.setup(logicalWidth, logicalHeight, palette, _nPages);    

    RGBQUAD bgColor;
    if(FreeImage_GetBackgroundColor(bmp, &bgColor)){
       gifFile.setBackgroundColor(ofColor(bgColor.rgbRed, bgColor.rgbGreen, bgColor.rgbBlue));
    }
}

void ofxGifDecoder::processFrame(FIBITMAP * bmp, int _frameNum, bool useTexture){
    FITAG *tag;
    ofPixels pix;

    unsigned int   frameLeft, frameTop;
    float frameDuration;
    GifFrameDisposal disposal_method = GIF_DISPOSAL_BACKGROUND;
    
    if( FreeImage_GetMetadata(FIMD_ANIMATION, bmp, "FrameLeft", &tag)) {
        frameLeft = *(unsigned short *)FreeImage_GetTagValue(tag);
    }
    
    if( FreeImage_GetMetadata(FIMD_ANIMATION, bmp, "FrameTop", &tag)) {
        frameTop = *(unsigned short *)FreeImage_GetTagValue(tag);
    }
    
    if( FreeImage_GetMetadata(FIMD_ANIMATION, bmp, "FrameTime", &tag)) {
        long frameTime = *(long *)FreeImage_GetTagValue(tag);// centiseconds 1/100 sec
        frameDuration =(float)frameTime/1000.f;
    }
    
    if( FreeImage_GetMetadata(FIMD_ANIMATION, bmp, "DisposalMethod", &tag)) {
        disposal_method = (GifFrameDisposal) *(unsigned char *)FreeImage_GetTagValue(tag);
    }
    
    // we do this for drawing. eventually we should be able to draw 8 bits? at least to retain the data
//    if(FreeImage_GetBPP(bmp) == 8) {
//        // maybe we should only do this when asked for rendering?
//        bmp = FreeImage_ConvertTo24Bits(bmp);
//    }
    
    FIBITMAP* bmpConverted = NULL;
	if(FreeImage_GetColorType(bmp) == FIC_PALETTE || FreeImage_GetBPP(bmp) < 8) {
		if(FreeImage_IsTransparent(bmp)) {
			bmpConverted = FreeImage_ConvertTo32Bits(bmp);
		} else {
			bmpConverted = FreeImage_ConvertTo24Bits(bmp);
		}
		bmp = bmpConverted;
	}
    
	unsigned int width      = FreeImage_GetWidth(bmp);
	unsigned int height     = FreeImage_GetHeight(bmp);
	unsigned int bpp        = FreeImage_GetBPP(bmp);
    // changed this bc we're not using PixelType template anywhere else...
	unsigned int channels   = (bpp / sizeof( unsigned char )) / 8;
	unsigned int pitch      = FreeImage_GetPitch(bmp);
    
	// ofPixels are top left, FIBITMAP is bottom left
	FreeImage_FlipVertical(bmp);

	unsigned char * bmpBits = FreeImage_GetBits(bmp);
    
	if(bmpBits != NULL) {
        
		pix.setFromAlignedPixels(bmpBits, width, height, channels, pitch);
            
        #ifdef TARGET_LITTLE_ENDIAN
            pix.swapRgb();
        #endif
        
        gifFile.addFrame(pix, frameLeft, frameTop, useTexture, disposal_method, frameDuration);
	} else {
		ofLogError() << "ofImage::putBmpIntoPixels() unable to set ofPixels from FIBITMAP";
	}
}

void ofxGifDecoder::reset(){
    gifFile.clear();
    pxs.clear();
    palette.clear();
}


// should I return a pointer of a copy?
ofxGifFile & ofxGifDecoder::getFile() {
    return gifFile;
}
