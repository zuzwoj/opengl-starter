#include "application.h"

bool leftMouseDown = false, rightMouseDown = false, zaxis = false, GUIactive = true;
double xPos = 0.0f, yPos = 0.0f;
double rotationX = 0.0f, rotationY = 0.0f, rotationZ = 0.0f;
double translationX = 0.0f, translationY = 0.0f, translationZ = 0.0f;
int maxR = 0, minR = 0, maxPixelSize = 3;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) GUIactive = !GUIactive;
    else if (key == GLFW_KEY_LEFT_SHIFT && action == GLFW_PRESS) zaxis = !zaxis;
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) 
{
    if (button == GLFW_MOUSE_BUTTON_LEFT) 
    {
        if (action == GLFW_PRESS)
        {
            maxR = maxPixelSize;
            minR = maxPixelSize;
            leftMouseDown = true;
        }
        else if (action == GLFW_RELEASE)
        {
            maxR = 0;
            leftMouseDown = false;
        }
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if (action == GLFW_PRESS)
        {
            maxR = maxPixelSize;
            minR = maxPixelSize;
            rightMouseDown = true;
        }
        else if (action == GLFW_RELEASE)
        {
            maxR = 0;
            rightMouseDown = false;
        }
    }
}

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) 
{
    if (!GUIactive)
    {
        if (leftMouseDown) // rotation
        {
            if (zaxis)
            {
                rotationZ += (ypos - yPos) / 100.0f;
            }
            else
            {
                rotationX += (xpos - xPos) / 100.0f;
                rotationY += (ypos - yPos) / 100.0f;
            }
        }
        else if (rightMouseDown) // translation
        {
            if (zaxis)
            {
                translationZ += (ypos - yPos);
            }
            else
            {
                translationY += (xpos - xPos);
                translationX -= (ypos - yPos);
            }
        }
    }
    xPos = xpos;
    yPos = ypos;
}

bool Application::init()
{
    // intialize GLWF window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Name", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Tworzenie okna nie powiodlo sie." << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);

    // register GLWF function callbacks
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);
    glfwSetKeyCallback(window, keyCallback);

    // verify GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Inicjlizacja GLAD nie powiodla sie." << std::endl;
        return false;
    }

    // initialize viewport
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // initialize imgui
    IMGUI_CHECKVERSION();
    ImGui::SetCurrentContext(ImGui::CreateContext());
    ImGuiIO& io = ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    // create shader program
    shaderProgram = Shader().createShaderProgram("VS.glsl", "FS.glsl");
    return true;
}

void Application::mainLoop()
{
    while (!glfwWindowShouldClose(window)) render();
}

void Application::cleanup()
{
    // terminate imgui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // terminate glwf
    glfwTerminate();
}

void Application::renderGUI()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("GUI");
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Application::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    renderGUI();
    glfwSwapBuffers(window);
    glfwPollEvents();
}
