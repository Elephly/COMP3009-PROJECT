#version 430

uniform vec4 lightColor;
uniform vec4 ambient;
uniform vec4 diffuse;
uniform vec4 specular;
uniform float shine;

varying vec3 vPosition;
varying vec3 vNormal;
varying vec4 vColor;
varying vec3 light;

vec4 threeTermReflectionLighting(vec3 normal, vec3 position, vec3 lightPos, float shininess,
	vec4 ambientFraction, vec4 diffuseFraction, vec4 specularFraction, vec4 objectColor, vec4 lightCol)
{
	vec3 N = normalize(normal);
	vec3 V = normalize(-position);
	vec3 L = normalize(lightPos - position);
	vec3 R = normalize(-L + 2 * (dot(L, N)) * N);

	float diffuseIntensity = max(dot(N, L), 0.0);

    float specularAngleCosine = max(dot(V, R), 0.0);
	float specularIntensity = pow(specularAngleCosine, shininess);

	vec4 ambi = ambientFraction * lightCol;
	vec4 diff = diffuseIntensity * diffuseFraction * lightCol;
	vec4 spec = specularIntensity * specularFraction * lightCol;
	
	return (objectColor * (ambi + diff)) + spec;
}

vec4 threeTermHalfwayLighting(vec3 normal, vec3 position, vec3 lightPos, float shininess,
	vec4 ambientFraction, vec4 diffuseFraction, vec4 specularFraction, vec4 objectColor, vec4 lightCol)
{
	vec3 N = normalize(normal);
	vec3 V = normalize(-position);
	vec3 L = normalize(lightPos - position);
	vec3 H = normalize(V + L);

	float diffuseIntensity = max(dot(N, L), 0.0);

    float specularAngleCosine = max(dot(N, H), 0.0);
	float specularIntensity = pow(specularAngleCosine, shininess);

	vec4 ambi = ambientFraction * lightCol;
	vec4 diff = diffuseIntensity * diffuseFraction * lightCol;
	vec4 spec = specularIntensity * specularFraction * lightCol;
	
	return (objectColor * (ambi + diff)) + spec;
}

void main(void)
{
	vec4 fragColor;
	
	fragColor = threeTermHalfwayLighting(vNormal, vPosition, light, shine, ambient, diffuse, specular, vColor, lightColor);

    gl_FragColor = fragColor;
}
