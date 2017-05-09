/*#version 150

// these are for the programmable pipeline system and are passed in
// by default from OpenFrameworks
uniform mat4 modelViewProjectionMatrix;

in vec4 position;
in vec2 texcoord;

// this is something we're creating for this shader
out vec2 texCoordVarying;

// this is coming from our C++ code
uniform float mouseX;

void main()
{
    // here we move the texture coordinates
    texCoordVarying = vec2(texcoord.x + mouseX, texcoord.y);

    // send the vertices to the fragment shader
	gl_Position = modelViewProjectionMatrix * position;
}
*/

#version 120

// this is coming from our C++ code
uniform float mouseX;

varying vec2 texCoordVarying;

void main()
{
    vec2 texcoord = gl_MultiTexCoord0.xy;

    // here we move the texture coordinates
    texCoordVarying = vec2(texcoord.x + mouseX, texcoord.y);

    // send the vertices to the fragment shader
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;;
}