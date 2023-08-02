#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <shader.h>
#include <iostream>
#include <camera.h>


void createTexture(const char* path, unsigned int* tex);
void VAOVBO(unsigned int VAO[], unsigned int VBO[], int id, float data[], int dataSize, bool hasTexture = false);
