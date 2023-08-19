#version 460 core
out vec4 FragColor;

in vec2 textCordinate;
uniform sampler2D texture;
uniform sampler2D texture_diffuse1;

uniform int checkTex;
in vec3 surfaceNormal;
in vec3 FragPos;
uniform vec3 viewPos;
#define lightCount 5
struct Light{
	vec3 position;
	vec3 color;
} light[lightCount];
const Light light0=Light(vec3(25.25f,21.5f,37.75f),vec3(1.0f,1.0f,1.0f));
const Light light1=Light(vec3(25.25f,21.5f,-37.75f),vec3(1.0f,1.0f,1.0f));
const Light light2=Light(vec3(-25.25f,21.5f,37.75f),vec3(1.0f,1.0f,1.0f));
const Light light3=Light(vec3(-25.25f,21.5f,-37.75f),vec3(1.0f,1.0f,1.0f));
const Light light4=Light(vec3(0.0f,21.5f,0.0f),vec3(1.0f,1.0f,1.0f));

void setup()
{
	light[0]=light0;
	light[1]=light1;
	light[2]=light2;
	light[3]=light3;
	light[4]=light4;
}
struct Material{
	float ambience;
	float diffuse;
	float specular;
	float specularity;
} ;
const Material material=Material(0.11f,0.3f,0.5f,10.0f);

vec3 getLit(vec3 objColor)
{
	vec3 viewDir=normalize(viewPos-FragPos);
	//vec3 ambient=material.ambience*objColor;
	//vec3 diffuse=material.diffuse*objColor;
	//vec3 specular=material.specular*objColor;
	//float rayIntensity=(pow(0.1,2.0)/pow(length(ray),2.0))*light.intenstity;
	vec3 ambient= vec3(1.0f);
	vec3 diffuse= vec3(1.0f);
	vec3 specular=vec3(1.0f);
	for(int i=0;i<lightCount;i++)
	{
		vec3 ray=-FragPos+light[i].position;
		vec3 rayDirection=normalize(ray);
		float coeff = max(dot(rayDirection,surfaceNormal),0.0f);
		diffuse = diffuse*coeff;
		ambient=(ambient*light[i].color);
		vec3 halfDirn=reflect(-rayDirection,surfaceNormal);
		float specularity=pow(max(dot(viewDir,halfDirn),0.0f),material.specularity);
		vec3 specular=specular*(specularity*light[i].color);
	}
	ambient=ambient*material.ambience*objColor;
	diffuse=diffuse*material.diffuse*objColor;
	specular=specular*material.specular*objColor;
	return (ambient+diffuse+specular);


}

vec3 getLit(vec3 objColor)
{
	vec3 viewDir=normalize(viewPos-FragPos);
	//vec3 ambient=material.ambience*objColor;
	//vec3 diffuse=material.diffuse*objColor;
	//vec3 specular=material.specular*objColor;
	//float rayIntensity=(pow(0.1,2.0)/pow(length(ray),2.0))*light.intenstity;
	vec3 ambient= vec3(0.0f);
	vec3 diffuse= vec3(0.0f);
	vec3 specular=vec3(0.0f);
	for(int i=0;i<3;i++)
	{
		vec3 ray=-FragPos+light[i].position;
		vec3 rayDirection=normalize(ray);
		ambient=ambient+light[i].color;
		float coeff=max(dot(rayDirection,surfaceNormal),0.0f);
		diffuse=diffuse+(coeff*light[i].color);
		vec3 halfDirn=reflect(-rayDirection,surfaceNormal);
		float specularity=pow(max(dot(viewDir,halfDirn),0.0f),material.specularity);
		vec3 specular=specular+(specularity*light[i].color);
	}
	ambient=ambient*material.ambience*objColor;
	diffuse=diffuse*material.diffuse*objColor;
	specular=specular*material.specular*objColor;
	return (ambient+diffuse+specular);


}

void main()
{
	setup();
	if(checkTex==0)
		{
			vec3 color=getLit(texture(texture, textCordinate).rgb);
			FragColor =vec4(color,1.0f);
			//FragColor =vec4(getLit(vec3(1.0f,0.3f,0.7f)),1.0f);
		}
	else 
		{
			vec3 color=getLit(vec3(0.753f, 0.753f, 0.753f));
			FragColor = vec4(color,1.0f);		
		}
//	else{/			   FragColor = texture(texture_diffuse1,textCordinate);
//}
}