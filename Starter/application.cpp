#include "application.h"

ImGuiIO* io = nullptr;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (!(*io).WantCaptureKeyboard)
    {
        switch (key)
        {
        case GLFW_KEY_SPACE:
        {
            if (action == GLFW_PRESS) Application::cameraMovement.rotating = !Application::cameraMovement.rotating;
            break;
        }
        case GLFW_KEY_UP:
        {
            if (action == GLFW_PRESS) Application::cameraMovement.goingUp = true;
            else if (action == GLFW_RELEASE) Application::cameraMovement.goingUp = false;
            break;
        }
        case GLFW_KEY_DOWN:
        {
            if (action == GLFW_PRESS) Application::cameraMovement.goingDown = true;
            else if (action == GLFW_RELEASE) Application::cameraMovement.goingDown = false;
            break;
        }
        case GLFW_KEY_RIGHT:
        {
            if (action == GLFW_PRESS) Application::cameraMovement.goingRight = true;
            else if (action == GLFW_RELEASE) Application::cameraMovement.goingRight = false;
            break;
        }
        case GLFW_KEY_LEFT:
        {
            if (action == GLFW_PRESS) Application::cameraMovement.goingLeft = true;
            else if (action == GLFW_RELEASE) Application::cameraMovement.goingLeft = false;
            break;
        }
        case GLFW_KEY_KP_SUBTRACT:
        {
            if (action == GLFW_PRESS) Application::cameraMovement.goingBackward = true;
            else if (action == GLFW_RELEASE) Application::cameraMovement.goingBackward = false;
            break;
        }
        case GLFW_KEY_KP_ADD:
        {
            if (action == GLFW_PRESS) Application::cameraMovement.goingForward = true;
            else if (action == GLFW_RELEASE) Application::cameraMovement.goingForward = false;
            break;
        }
        }
    }
}

bool Application::init()
{
    // intialize GLWF window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Name", NULL, NULL); // TODO: adjust the name
    if (window == NULL)
    {
        std::cout << "Cannot create window." << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);

    // register GLWF function callback
    glfwSetKeyCallback(window, keyCallback);

    // verify GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Cannot initialize GLAD." << std::endl;
        return false;
    }

    // initialize viewport
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // initialize imgui
    IMGUI_CHECKVERSION();
    ImGui::SetCurrentContext(ImGui::CreateContext());
    io = &ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    // create shader program
    shaderProgram = Shader().createShaderProgram("VS.glsl", "FS.glsl");
    glUseProgram(shaderProgram);

    // initialize uniforms
    setViewMatrix(camera.getViewMatrix());
    setProjectionMatrix(ProjectionMatrix(1, WINDOW_WIDTH / WINDOW_HEIGHT, 0.1f, 1000.0f));

    // TODO: create cube and bind all needed arrays - remove or adjust accordingly
    float verts[] = {
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f
    };
    unsigned int idx[] = {
        0,1, 1,2, 2,3, 3,0,
        4,5, 5,6, 6,7, 7,4,
        0,4, 1,5, 2,6, 3,7
    };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(idx), idx, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

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

    // TODO: GUI drawing code

    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Application::render()
{
    // adjust view matrix if the camera has moved
    if (cameraMovement.goingBackward || cameraMovement.goingDown || cameraMovement.goingLeft || cameraMovement.goingRight || cameraMovement.goingForward || cameraMovement.goingUp)
    {
        camera.move(cameraMovement);
        setViewMatrix(camera.getViewMatrix());
    }

    glClear(GL_COLOR_BUFFER_BIT);

    // TODO: OpenGL rendering code goes here
    // for now rendering a cube
    glDrawElements(GL_LINES, 24, GL_UNSIGNED_INT, 0);

    renderGUI();
    glfwSwapBuffers(window);
    glfwPollEvents();
}


void Application::setViewMatrix(Matrix4x4 matrix)
{
    view = matrix;
    view.toArray(viewMatrix);
    viewO = glGetUniformLocation(shaderProgram, "view");
    glUniformMatrix4fv(viewO, 1, GL_TRUE, viewMatrix);
}

void Application::setProjectionMatrix(Matrix4x4 matrix)
{
    projection = matrix;
    projection.toArray(projectionMatrix);
    projectionO = glGetUniformLocation(shaderProgram, "projection");
    glUniformMatrix4fv(projectionO, 1, GL_TRUE, projectionMatrix);
}
