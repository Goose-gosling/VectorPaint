#include <GL/glew.h>
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "main.h"



int main(int argc, char **argv)
{

    gl::initGLFW(); // glfwinit();
    std::cout << "[INFORMATION] Initialized GLFW." << std::endl;

    gl::initWindowHints(); // analasing, colors

    GLFWwindow *_window = gl::createWindow(624, 624, "OpenGL-Vectorpaint"); // fenster
    std::cout << "[INFORMATION] Created Window." << std::endl;

    glfwSetKeyCallback(_window, gl::key_callback);
    glfwSetMouseButtonCallback(_window, gl::mousebutton_callback);

    glClearColor(1.f, 1.f,1.f, 1.f);



    for (int i = 0; i <= 1024;i++) {
        _polygon[i] = GL_LINE_STRIP;
    }

    //glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    while(!glfwWindowShouldClose(_window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        miscellaneous::calculate_positions();

        glViewport(0.f, 0.f, width, height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, width, height, 0);
        glMatrixMode(GL_MODELVIEW);
        glColor3f(0.f, 0.f, 0.f);

        gl::mouse_callback(_window);

        for (int k = 0; k <= count; k++) {
            glColor3f(color[k].x, color[k].y, color[k].z);
            glBegin(_polygon[k]);
            for (int kj = 0; kj < i[k]; kj++) {
                glVertex2f(pos[k][kj].x, pos[k][kj].y);
            }
            glEnd();
        }

        gui::color_triangle();
        gui::colortri_button();
        gui::power_button();
        gui::polygon_mode_button();
        gui::new_array_button();
        gui::reset_array_button();
        gui::pencil_mode_button();
        gui::reset_all_button();

        glfwPollEvents();
        glfwSwapBuffers(_window);
    }

    std::cout << "[INFORMATION] Quitting ..." << std::endl;

    return 0;
}
