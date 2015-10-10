#version 150 

uniform int useColourAtt;

varying vec4 vColor; // the vertex colour

void main(void)
{
    if (useColourAtt == 0) {
        gl_FragColor = vec4(1.0,0.0,0.0,1.0);
    } else {
        gl_FragColor = vColor;
    }
}
