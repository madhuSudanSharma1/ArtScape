#define STB_IMAGE_IMPLEMENTATION
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <shader.h>
#include <iostream>
#include <camera.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 750;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 100.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

void createTexture(const char* path, unsigned int* tex)
{
    glGenTextures(1, tex);
    glBindTexture(GL_TEXTURE_2D, *tex);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);




    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
    if (data)
    {
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    float borderColor[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    stbi_image_free(data);
}

void VAOVBO(unsigned int VAO[], unsigned int VBO[], int id, float data[],int dataSize ,bool hasTexture = false) {
    glBindVertexArray(VAO[id]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[id]);
    glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);

    
    if(hasTexture){
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }
    else
    {
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }

}

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "ArtScape- Gallery at your Space", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSwapInterval(1);

    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
   /* float verticesSide[] = {
         -0.5f,0.5f,-0.5f,0.0f,1.0f,
        -0.5f,-0.5f,-0.5f,0.0f,0.0f,
        0.5f,-0.5f,-0.5f,1.0f,0.0f,
        -0.5f,0.5f,-0.5f,0.0f,1.0f,
        0.5f,-0.5f,-0.5f,1.0f,0.0f,
        0.5f,0.5f,-0.5f,1.0f,1.0f,

        0.5f,-0.5f,0.5f,0.0f,0.0f,
        0.5f,-0.5f,-0.5f,0.0f,1.0f,
        0.5f,0.5f,-0.5f,1.0f,1.0f,
        0.5f,-0.5f,0.5f,0.0f,0.0f,
        0.5f,0.5f,-0.5f,1.0f,1.0f,
        0.5f,0.5f,0.5f,1.0f,0.0f,

        -0.5f,-0.5f,0.5f,0.0f,0.0f,
        -0.5f,-0.5f,-0.5f,0.0f,1.0f,
        -0.5f,0.5f,-0.5f,1.0f,1.0f,
        -0.5f,-0.5f,0.5f,0.0f,0.0f,
        -0.5f,0.5f,-0.5f,1.0f,1.0f,
        -0.5f,0.5f,0.5f,1.0f,0.0f,

    };
    float verticesTopBottom[] = {

        0.5f,0.5f,-0.5f,1.0f,1.0f,
        -0.5f,0.5f,-0.5f,0.0f,1.0f,
        -0.5f,0.5f,0.5f,0.0f,0.0f,
        0.5f,0.5f,-0.5f,1.0f,1.0f,
        -0.5f,0.5f,0.5f,0.0f,0.0f,
        0.5f,0.5f,0.5f,1.0f,0.0f,

        0.5f,-0.5f,-0.5f,1.0f,1.0f,
        -0.5f,-0.5f,-0.5f,0.0f,1.0f,
        -0.5f,-0.5f,0.5f,0.0f,0.0f,
        0.5f,-0.5f,-0.5f,1.0f,1.0f,
        -0.5f,-0.5f,0.5f,0.0f,0.0f,
        0.5f,-0.5f,0.5f,1.0f,0.0f,
    };*/

    float verticesSide[] = {
        /*   -50.5f,50.5f,50.5f,0.0f,1.0f,
           -50.5f,-50.5f,50.5f,0.0f,0.0f,
           50.5f,-50.5f,50.5f,1.0f,0.0f,
           -50.5f,50.5f,50.5f,0.0f,1.0f,
           50.5f,-50.5f,50.5f,1.0f,0.0f,
           50.5f,50.5f,50.5f,1.0f,1.0f,*/

           -50.5f, 21.5f, -75.5f, 0.0f, 1.0f,
           -50.5f, -21.5f, -75.5f, 0.0f, 0.0f,
           50.5f, -21.5f, -75.5f, 1.0f, 0.0f,
           -50.5f, 21.5f, -75.5f, 0.0f, 1.0f,
           50.5f, -21.5f, -75.5f, 1.0f, 0.0f,
           50.5f, 21.5f, -75.5f, 1.0f, 1.0f,

           50.5f, -21.5f, 75.5f, 0.0f, 0.0f,
           50.5f, -21.5f, -75.5f, 0.0f, 1.0f,
           50.5f, 21.5f, -75.5f, 1.0f, 1.0f,
           50.5f, -21.5f, 75.5f, 0.0f, 0.0f,
           50.5f, 21.5f, -75.5f, 1.0f, 1.0f,
           50.5f, 21.5f, 75.5f, 1.0f, 0.0f,

           -50.5f, -21.5f, 75.5f, 0.0f, 0.0f,
           -50.5f, -21.5f, -75.5f, 0.0f, 1.0f,
           -50.5f, 21.5f, -75.5f, 1.0f, 1.0f,
           -50.5f, -21.5f, 75.5f, 0.0f, 0.0f,
           -50.5f, 21.5f, -75.5f, 1.0f, 1.0f,
           -50.5f, 21.5f, 75.5f, 1.0f, 0.0f,
    };


    float verticesTopBottom[] = {
        50.5f, 21.5f, -75.5f, 1.0f, 1.0f,
        -50.5f, 21.5f, -75.5f, 0.0f, 1.0f,
        -50.5f, 21.5f, 75.5f, 0.0f, 0.0f,
        50.5f, 21.5f, -75.5f, 1.0f, 1.0f,
        -50.5f, 21.5f, 75.5f, 0.0f, 0.0f,
        50.5f, 21.5f, 75.5f, 1.0f, 0.0f,

        50.5f, -21.5f, -75.5f, 1.0f, 1.0f,
        -50.5f, -21.5f, -75.5f, 0.0f, 1.0f,
        -50.5f, -21.5f, 75.5f, 0.0f, 0.0f,
        50.5f, -21.5f, -75.5f, 1.0f, 1.0f,
        -50.5f, -21.5f, 75.5f, 0.0f, 0.0f,
        50.5f, -21.5f, 75.5f, 1.0f, 0.0f
    };


    float verticesPillarBack[] = {
        //front
       -20.5f,21.5f,20.5f,   
       -20.5f,-21.5f,20.5f,  
       20.5f,-21.5f,20.5f,   
       -20.5f,21.5f,20.5f,   
       20.5f,-21.5f,20.5f,   
       20.5f,21.5f,20.5f,    

       -20.5f,21.5f,-20.5f,  
       -20.5f,-21.5f,-20.5f, 
       20.5f,-21.5f,-20.5f,  
       -20.5f,21.5f,-20.5f,  
       20.5f,-21.5f,-20.5f,  
       20.5f,21.5f,-20.5f,   

       20.5f,-21.5f,20.5f,   
       20.5f,-21.5f,-20.5f,  
       20.5f,21.5f,-20.5f,   
       20.5f,-21.5f,20.5f,   
       20.5f,21.5f,-20.5f,   
       20.5f,21.5f,20.5f,    

       -20.5f,-21.5f,20.5f,  
       -20.5f,-21.5f,-20.5f, 
       -20.5f,21.5f,-20.5f,  
       -20.5f,-21.5f,20.5f,  
       -20.5f,21.5f,-20.5f,  
       -20.5f,21.5f,20.5f,   

    };

    float verticesPillarImage[] = {
        //front
       -16.5f, 17.5f, 20.5f, 0.0f, 1.0f,
       -16.5f, -17.5f, 20.5f, 0.0f, 0.0f,
       16.5f, -17.5f, 20.5f, 1.0f, 0.0f,
       -16.5f, 17.5f, 20.5f, 0.0f, 1.0f,
       16.5f, -17.5f, 20.5f, 1.0f, 0.0f,
       16.5f, 17.5f, 20.5f, 1.0f, 1.0f,

       -16.5f, 17.5f, -20.5f, 0.0f, 1.0f,
       -16.5f, -17.5f, -20.5f, 0.0f, 0.0f,
       16.5f, -17.5f, -20.5f, 1.0f, 0.0f,
       -16.5f, 17.5f, -20.5f, 0.0f, 1.0f,
       16.5f, -17.5f, -20.5f, 1.0f, 0.0f,
       16.5f, 17.5f, -20.5f, 1.0f, 1.0f,

       16.5f, -17.5f, 20.5f, 0.0f, 1.0f,
       16.5f, -17.5f, -20.5f, 0.0f, 0.0f,
       16.5f, 17.5f, -20.5f, 1.0f, 0.0f,
       16.5f, -17.5f, 20.5f, 0.0f, 1.0f,
       16.5f, 17.5f, -20.5f, 1.0f, 0.0f,
       16.5f, 17.5f, 20.5f, 1.0f, 1.0f,

       -16.5f, -17.5f, 20.5f, 0.0f, 1.0f,
       -16.5f, -17.5f, -20.5f, 0.0f, 0.0f,
       -16.5f, 17.5f, -20.5f, 1.0f, 0.0f,
       -16.5f, -17.5f, 20.5f, 0.0f, 1.0f,
       -16.5f, 17.5f, -20.5f, 1.0f, 0.0f,
       -16.5f, 17.5f, 20.5f, 1.0f, 1.0f,
    };

    
    
    // build and compile our shader program
    // ------------------------------------
    Shader ourShader("./Shaders/shader.vs", "./Shaders/shader.fs");


    unsigned int VAO[4], VBO[4];
    glGenVertexArrays(4, VAO);
    glGenBuffers(4, VBO);

    VAOVBO(VAO, VBO, 0, verticesSide, sizeof(verticesSide),true);
    VAOVBO(VAO, VBO, 1, verticesTopBottom, sizeof(verticesTopBottom),true);
    VAOVBO(VAO, VBO, 2, verticesPillarImage, sizeof(verticesPillarImage),true);
    VAOVBO(VAO, VBO, 3, verticesPillarBack, sizeof(verticesPillarBack),false);

    //glBindVertexArray(VAO[0]);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(verticesSide), verticesSide, GL_STATIC_DRAW);

    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);

    //glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);


    /*glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesTopBottom), verticesTopBottom, GL_STATIC_DRAW);

    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);*/
    
    //glBindVertexArray(VAO[2]);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(verticesPillarImage), verticesPillarImage, GL_STATIC_DRAW);

    //
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);

    //glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    //glEnableVertexAttribArray(1);

   /* glBindVertexArray(VAO[3]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[3]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesPillarBack), verticesPillarBack, GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);*/


    unsigned int texture1, texture2,texture3;
    createTexture("./external/assets/wall.jpg", &texture1);
    createTexture("./external/assets/wood.png", &texture2);
    createTexture("./external/assets/arts/art1.png", &texture3);

    glEnable(GL_DEPTH_TEST);


    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);



    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {

        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        processInput(window);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        ourShader.setInt("checkTex", 0);
        
        glBindTexture(GL_TEXTURE_2D, texture3);
        glBindVertexArray(VAO[2]);
        glDrawArrays(GL_TRIANGLES,0,24);
        
        glBindTexture(GL_TEXTURE_2D, texture1);

        ourShader.use();
        glBindVertexArray(VAO[0]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        
        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 200.0f);
        ourShader.setMat4("projection", projection);

        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();
        ourShader.setMat4("view", view);

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(1.0f,0.0f,0.0f));
        ourShader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLES,0,18);
        


        glBindTexture(GL_TEXTURE_2D, texture2);


        glBindVertexArray(VAO[1]);

        glDrawArrays(GL_TRIANGLES,0,12);

        ourShader.setInt("checkTex", 1);

        glBindVertexArray(VAO[3]);
        glDrawArrays(GL_TRIANGLES, 0, 24);
            
        ourShader.setInt("checkTex", 0);

        
        

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------

        glDeleteVertexArrays(4, VAO);
        glDeleteBuffers(4, VBO);
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
    
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        camera.ProcessKeyboard(UP, deltaTime);
    
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        camera.ProcessKeyboard(DOWN, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        camera.ProcessKeyboard(ROTATE_LEFT, deltaTime);
    
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        camera.ProcessKeyboard(ROTATE_RIGHT, deltaTime);
    
    if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
        camera.ProcessKeyboard(ROTATE_UP, deltaTime);
    
    if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
        camera.ProcessKeyboard(ROTATE_DOWN, deltaTime);
    
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        camera.ProcessKeyboard(DEFAULT, deltaTime);



}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}