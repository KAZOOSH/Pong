precision highp float;

uniform vec2 dimensions;
uniform float iGlobalTime;
uniform int nBalls;
uniform vec2 pos;
uniform float radius;

varying vec2 texCoordVarying;

vec3 backgroundColor = vec3(0.0, 0.0, 0.0);
float speed = 8.0;

void main()
{

    float smallRadius = radius*0.7;

    vec2 uv = gl_FragCoord.xy;// / dimensions;

    vec2 screenCenter = (pos.xy);
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
    
    gl_FragColor = vec4(result,1.0);
}