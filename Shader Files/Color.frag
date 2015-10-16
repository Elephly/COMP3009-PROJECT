#version 150 

varying vec4 vColor;

float Lerp(float a, float b, float t)
{
    return ((1 - t) * a) + (t * b);
}

void main(void)
{
    gl_FragColor = vColor;
}
