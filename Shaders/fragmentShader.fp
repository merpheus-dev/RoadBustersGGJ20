#version 400 core

in vec2 pass_textureCoords;
in vec3 vertexNormal;
in vec3 lightVector;
in vec3 camVector;

out vec4 output_color;
uniform sampler2D textureSampler;

uniform vec3 LightColor;
uniform float AmbientIntensity;

uniform float MaterialShininess;
uniform vec3 ReflectionColor;

void main(void){
	vec3 normalized_lightVec = normalize(vertexNormal);
	vec3 lightDir = normalize(lightVector);
	float lambertian = max(dot(normalized_lightVec, lightDir),AmbientIntensity);
	vec3 diffuseColor = LightColor * lambertian;
	vec3 reflectDir = reflect(-lightDir,vertexNormal);
	float specularReflectionAngle = max(dot(reflectDir,camVector),0.0);
	float specular = pow(specularReflectionAngle,MaterialShininess/4.0);

	output_color = vec4(diffuseColor,1.0) * texture(textureSampler,pass_textureCoords)+vec4(ReflectionColor*specular,1.0);
}