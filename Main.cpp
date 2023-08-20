#include "gallery.h"
#include "coordinates.h"
#define STB_IMAGE_IMPLEMENTATION
#include <model.h>



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
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "ArtScape - Gallery at your Space", NULL, NULL);
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

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
  
    //std::vector<float[]> verticessss=getCoordinate(4);
    //float* verticesImage1=verticessss[0];//.pop_back();
    //float* verticesImage2=verticessss[1];//.pop_back();
    //float* verticesImage3=verticessss[2];//.pop_back();
    //float* verticesImage4 = verticessss[3];//.pop_back();
    
    // build and compile our shader program
    // ------------------------------------
    Shader ourShader("./Shaders/shader.vs", "./Shaders/shader.fs");
 //   Model ourModel("./external/assets/bugatti/backpack.obj");


    unsigned int VAO[30], VBO[30];
    glGenVertexArrays(30, VAO);
    glGenBuffers(30, VBO);
    VAOVBO(VAO, VBO, 0, verticesSide, sizeof(verticesSide), false);
    VAOVBO(VAO, VBO, 1, verticesTop, sizeof(verticesTop), false);
    VAOVBO(VAO, VBO, 2, verticesBottom, sizeof(verticesBottom), false);
    VAOVBO(VAO, VBO, 3, verticesPillarBack, sizeof(verticesPillarBack), false);
    //Pillar Images
    VAOVBO(VAO, VBO, 4, verticesPillarImageFront, sizeof(verticesPillarImageFront), true);
    VAOVBO(VAO, VBO, 5, verticesPillarImageRight, sizeof(verticesPillarImageRight), true);
    VAOVBO(VAO, VBO, 6, verticesPillarImageLeft, sizeof(verticesPillarImageLeft), true);
    //around Image
    VAOVBO(VAO, VBO, 7, verticesImage1, sizeof(verticesImage1), true);
    VAOVBO(VAO, VBO, 8, verticesImage2, sizeof(verticesImage2), true);
    VAOVBO(VAO, VBO, 9, verticesImage3, sizeof(verticesImage3), true);
    VAOVBO(VAO, VBO, 10, verticesImage4, sizeof(verticesImage4), true);
    VAOVBO(VAO, VBO, 11, verticesImage5, sizeof(verticesImage5), true);
    VAOVBO(VAO, VBO, 12, verticesImage6, sizeof(verticesImage6), true);
    VAOVBO(VAO, VBO, 13, verticesImage7, sizeof(verticesImage7), true);
    VAOVBO(VAO, VBO, 14, verticesImage8, sizeof(verticesImage8), true);
    VAOVBO(VAO, VBO, 15, verticesImage9, sizeof(verticesImage9), true);
    VAOVBO(VAO, VBO, 16, verticesImage10, sizeof(verticesImage10), true);
    VAOVBO(VAO, VBO, 17, verticesImage11, sizeof(verticesImage11), true);
    VAOVBO(VAO, VBO, 18, verticesImage12, sizeof(verticesImage12), true);
    VAOVBO(VAO, VBO, 19, verticesImage13, sizeof(verticesImage13), true);
    //Inside Image
    VAOVBO(VAO, VBO, 20, ShivaImg, sizeof(ShivaImg), true);
    VAOVBO(VAO, VBO, 21, BuddhaImg, sizeof(BuddhaImg), true);
    VAOVBO(VAO, VBO, 22, DurgaImg, sizeof(DurgaImg), true);



    unsigned int tImageFront, tImageLeft, tImageRight, image1, image2, image3, image4, image5, image6, image7, texBuddha, image8, image9, image10, image11, image12, image13, texShivaG, texDurga;
    createTexture("./external/assets/arts/image1.jpg", &tImageFront);
    createTexture("./external/assets/arts/Sucess1.jpg", &tImageLeft);
    createTexture("./external/assets/arts/Sucess2.jpg", &tImageRight);
    createTexture("./external/assets/arts/Sucess3.jpg", &image1);
    createTexture("./external/assets/arts/Sucess4.jpg", &image2);
    createTexture("./external/assets/arts/Sucess5.jpg", &image3);
    createTexture("./external/assets/arts/Sucess6.jpg", &image4);
    createTexture("./external/assets/arts/Sucess7.jpg", &image5);
    createTexture("./external/assets/arts/Sucess8.jpg", &image6);
    createTexture("./external/assets/arts/Sucess9.jpg", &image7);
    createTexture("./external/assets/arts/Sucess10.jpg", &image8);
    createTexture("./external/assets/arts/Sucess11.jpg", &image9);
    createTexture("./external/assets/arts/Sucess12.jpg", &image10);
    createTexture("./external/assets/arts/Sucess13.jpg", &image11);
    createTexture("./external/assets/arts/Sucess14.jpg", &image12);
    createTexture("./external/assets/arts/Sucess15.jpg", &image13);
    createTexture("./external/assets/Vagawan/Buddha.jpg", &texShivaG);
    createTexture("./external/assets/Vagawan/ShivaG.jpg", &texBuddha);
    createTexture("./external/assets/Vagawan/swarswati.jpg", &texDurga);

    glEnable(GL_DEPTH_TEST);


    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);



    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        processInput(window);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 200.0f);
        ourShader.setMat4("projection", projection);

        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();
        ourShader.setMat4("view", view);

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(1.0f, 0.0f, 0.0f));
        ourShader.setMat4("model", model);

        ourShader.setVec3("viewPos", camera.Position);

        ourShader.setInt("checkTex", 1);
        //Draw 3 Sides
        glBindVertexArray(VAO[0]);
        glDrawArrays(GL_TRIANGLES, 0, 18);

        //Top
        glBindVertexArray(VAO[1]);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        //Bottom
        glBindVertexArray(VAO[2]);
        glDrawArrays(GL_TRIANGLES, 0, 6);


        ourShader.setInt("checkTex", 0);
        //PillarImage
        //Front
        glBindTexture(GL_TEXTURE_2D, tImageFront);
        glBindVertexArray(VAO[4]);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        //Right
        glBindTexture(GL_TEXTURE_2D, tImageRight);
        glBindVertexArray(VAO[5]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        //Left
        glBindTexture(GL_TEXTURE_2D, tImageLeft);
        glBindVertexArray(VAO[6]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        ////ShivaG
        glBindTexture(GL_TEXTURE_2D, texShivaG);
        glBindVertexArray(VAO[20]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glBindTexture(GL_TEXTURE_2D, texBuddha);
        glBindVertexArray(VAO[21]);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        //durga
        glBindTexture(GL_TEXTURE_2D, texDurga);
        glBindVertexArray(VAO[22]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        //Main Images
        glBindTexture(GL_TEXTURE_2D, image1);
        glBindVertexArray(VAO[7]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glBindTexture(GL_TEXTURE_2D, image2);
        glBindVertexArray(VAO[8]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glBindTexture(GL_TEXTURE_2D, image3);
        glBindVertexArray(VAO[9]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glBindTexture(GL_TEXTURE_2D, image4);
        glBindVertexArray(VAO[10]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glBindTexture(GL_TEXTURE_2D, image5);
        glBindVertexArray(VAO[11]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glBindTexture(GL_TEXTURE_2D, image6);
        glBindVertexArray(VAO[12]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glBindTexture(GL_TEXTURE_2D, image7);
        glBindVertexArray(VAO[13]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glBindTexture(GL_TEXTURE_2D, image8);
        glBindVertexArray(VAO[14]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glBindTexture(GL_TEXTURE_2D, image9);
        glBindVertexArray(VAO[15]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glBindTexture(GL_TEXTURE_2D, image10);
        glBindVertexArray(VAO[16]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glBindTexture(GL_TEXTURE_2D, image11);
        glBindVertexArray(VAO[17]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glBindTexture(GL_TEXTURE_2D, image12);
        glBindVertexArray(VAO[18]);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glBindTexture(GL_TEXTURE_2D, image13);
        glBindVertexArray(VAO[19]);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        ourShader.setInt("checkTex", 1);

        //Pillar
        ourShader.setInt("checkTex", 1);
        glBindVertexArray(VAO[3]);
        glDrawArrays(GL_TRIANGLES, 0, 42);

        ourShader.use();
        glBindVertexArray(VAO[0]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

        // pass projection matrix to shader (note that in this case it could change every frame)
        ourShader.setInt("checkTex", 2);
        // render the loaded model
        //glm::mat4 model = glm::mat4(1.0f);
       // ourModel.Draw(ourShader);


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