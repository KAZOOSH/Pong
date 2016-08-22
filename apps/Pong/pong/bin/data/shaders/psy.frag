#version 150

// this is how we receive the texture
uniform vec2 dimensions;
uniform float iGlobalTime;
uniform int nBalls;
uniform vec2 b1_pos,b2_pos,b3_pos,b4_pos,b5_pos;
uniform float radius;
//uniform sampler2DRect tex0;

in vec2 texCoordVarying;

out vec4 outputColor;

vec3 backgroundColor = vec3(0.0, 0.0, 0.0);
float speed = 8.0;


void main()
{

    float smallRadius = radius*0.7;

	vec2 uv = gl_FragCoord.xy;// / dimensions;

    vec2 screenCenter = (b1_pos.xy);
    vec2 circleCenter = screenCenter + vec2(sin(iGlobalTime * speed) * radius, cos(iGlobalTime * speed) * radius);
    vec3 result = backgroundColor;
   	
    vec2 dir = uv - circleCenter;
    float len = length(dir);
    if(len < smallRadius){
        result = vec3(sin(len*0.5));
    }
    else if(length(uv - screenCenter) < (smallRadius + radius)){
       	result = vec3(sin(uv.y*0.5 + iGlobalTime * -40.0));
    }
    else {
        result += vec3(sin(uv.x / 3.0 + iGlobalTime * - 20.0) + sin(uv.y / 3.0));
    }
    


	outputColor = vec4(result,1.0);

}

