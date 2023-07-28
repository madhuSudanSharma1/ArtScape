#version 460 core
out vec4 FragColor;

in vec2 textCordinate;
uniform sampler2D texture;
uniform int checkTex;


void main()
{
	if(checkTex==1)
		FragColor = texture(texture, textCordinate);
	else
		FragColor = vec4(0.722f, 0.871f, 0.686f,1.0f);

}