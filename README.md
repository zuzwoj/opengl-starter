# opengl-starter

Starter for applications drawing 3D shapes with OpenGL. 
- displays a window with empty imgui GUI
- renders a simple cubes
- compiles sample vertex and fragment shaders - VS.glsl and FS.glsl
- allows for camera movement and rotation via right, left, up, down, + (forward), - (backward) keys; press space to choose between movement and rotation; rotation only along X and Y axes, meaning only pitch and yaw, no roll 

## Dependencies
- OpenGL with GLFW, installation of which is extensively described in https://learnopengl.com/Getting-started/OpenGL and https://learnopengl.com/Getting-started/Creating-a-window
- imgui https://github.com/ocornut/imgui
- mathematical structures https://github.com/zuzwoj/maths

## Build
*Currently a workaround*

Possible to build in Visual Studio with some manual adjustments in .vcproj (paths to dependencies)
