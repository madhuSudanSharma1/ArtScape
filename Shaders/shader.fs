#version 460 core
out vec4 FragColor;

in vec2 textCordinate;
uniform sampler2D texture;
uniform int checkTex;


void main()
{
	if(checkTex==0)
		FragColor = texture(texture, textCordinate);
	else
		FragColor = vec4(0.753f, 0.753f, 0.753f,1.0f);

}