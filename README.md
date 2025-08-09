# opengl-starter

Starter for applications drawing 3D shapes with OpenGL. 
- displays a window with empty imgui GUI
- renders a simple cube
- compiles sample vertex and fragment shaders VS.glsl and FS.glsl
- allows for rotating the cube with the left mouse button and moving it across the space with the right mouse button in all three dimensions (press left shift for manipulation along the Z axis)
- allows for camera movement and rotation via right, left, up, down keys (press space to switch between movement and rotation, in movement mode, going forward and backward is also possible with + and - key respectively)

## Dependencies
- OpenGL with GLFW, installation of which is extensively described in https://learnopengl.com/Getting-started/OpenGL and https://learnopengl.com/Getting-started/Creating-a-window
- imgui https://github.com/ocornut/imgui
- mathematical structures https://github.com/zuzwoj/maths

## Build
*Currently a workaround*
Possible to build in Visual Studio with some manual adjustments in lines 134, 141 of .vcproj (paths to dependencies)
