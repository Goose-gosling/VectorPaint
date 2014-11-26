#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct{

    GLdouble x;
    GLdouble y;

}Vector2;

typedef struct {

    GLfloat x;
    GLfloat y;
    GLfloat z;

}Vector3;

    Vector2 pos[1024][1024];
    int i[1024];
    int count = 0;
    GLenum _polygon[1024];
    Vector3 color[1024];
    bool colortri = false;
    bool pencil = false;

    GLdouble x,y;
    GLdouble gl_x, gl_y;
    int width, height;


namespace gui {

    static bool checkForGUI() {

        if (gl_x <= 40.f && gl_x >= 10.f && gl_y <= 40.f && gl_y >= 10.f) {   // color-modifier
            return true;
        }
        if (gl_x <= width-170.f && gl_x >= width-200.f && gl_y <= 40.f && gl_y >= 10.f) {   // pencil button
            return true;
        }
        if (gl_x <= 220 && gl_x >= 60 && gl_y <= 50 && gl_y >= 20) {  // grey--coloring
            return true;
        }
        if (gl_y <= 230 &&
            gl_y - 56.794924 >= (( gl_x - 130 ) * ( 173.2050808/100)) &&
            gl_y - 56.794924 >= (( gl_x - 130 ) * ( -173.2050808/100)) ) {
            return true;
        }
        if (gl_x <= width-10.f && gl_x >= width-40.f && gl_y <= 40.f && gl_y >= 10.f) {   // power-off button
            return true;
        }
        if (gl_x <= width-50.f && gl_x >= width-80.f && gl_y <= 40.f && gl_y >= 10.f) {
            return true;
        }
        if (gl_x <= width-90.f && gl_x >= width-120.f && gl_y <= 40.f && gl_y >= 10.f) {
            return true;
        }
        if (gl_x <= width-130.f && gl_x >= width-160.f && gl_y <= 40.f && gl_y >= 10.f) {
            return true;
        }
        if (gl_x <= width-210.f && gl_x >= width-240.f && gl_y <= 40.f && gl_y >= 10.f) {   // pencil button
            return true;
        }
        if (gl_x <= 47 && gl_x >= 10 && gl_y <= 250 && gl_y >= 47) {
            return true;
        }
        if (gl_x <= 250 && gl_x >= 47 && gl_y <= 250 && gl_y >= 10) {
            return true;
        }

        return false;
    }

    static void power_button() {

        glBegin(GL_POLYGON);

            glColor3f(0.7f, 0.f, 0.f);
            glVertex2f(width-10.f, 10.f);
            glVertex2f(width-10.f, 40.f);
            glVertex2f(width-40.f, 40.f);
            glVertex2f(width-40.f, 10.f);

        glEnd();

        glBegin(GL_LINE_STRIP);

            glColor3f(1.f, 1.f, 1.f);
            glVertex2f(width-22.f, 17.f);
            glVertex2f(width-15.f, 17.f);
            glVertex2f(width-15.f, 35.f);
            glVertex2f(width-35.f, 35.f);
            glVertex2f(width-35.f, 17.f);
            glVertex2f(width-29.f, 17.f);

        glEnd();

        glBegin(GL_LINE_STRIP);

            glVertex2f(width-25.f, 20.f);
            glVertex2f(width-25.f, 14.f);

        glEnd();

    }

    static void color_triangle() {

        if (colortri) {

            glColor3f(1.f, 0.7f, 0.f);

            glBegin(GL_POLYGON);

                glVertex2f(10.f, 47.f);
                glVertex2f(10.f, 250.f);
                glVertex2f(47.f, 250.f);
                glVertex2f(47.f, 47.f);

            glEnd();

            glBegin(GL_POLYGON);

                glVertex2f(47.f,10.f);
                glVertex2f(47.f,250.f);
                glVertex2f(250.f,250.f);
                glVertex2f(250.f,10.f);

            glEnd();

            glBegin(GL_POLYGON);

                glColor3f(1.f, 0.f, 0.f);
                glVertex2f(30.f, 230.f);
                glColor3f(0.f, 1.f, 0.f);
                glVertex2f(130.f, 56.794919f);
                glColor3f(0.f, 0.f, 1.f);
                glVertex2f(230.f, 230.f);

            glEnd();


            glColor3f(0.f, 0.f, 0.f);

            glBegin(GL_POLYGON); // green

                glVertex2f(60.f, 20.f);
                glVertex2f(60.f, 50.f);

                glColor3f(1.f, 1.f, 1.f);

                glVertex2f(220.f, 50.f);
                glVertex2f(220.f, 20.f);

            glEnd();


            glBegin(GL_LINE_STRIP); // green

                glColor3f(1.f, 1.f, 1.f);
                glVertex2f(-0.852f, 0.951f);
                glVertex2f(-0.852f, 0.849f);

                glColor3f(0.f, 0.f, 0.f);
                glVertex2f(-0.599f, 0.849f);
                glVertex2f(-0.599f, 0.951f);

                glColor3f(1.f, 1.f, 1.f);
                glVertex2f(-0.852f, 0.951f);
                glVertex2f(-0.852f, 0.849f);

            glEnd();
        }

    }

    static void colortri_button() {

        glBegin(GL_POLYGON); // red

            glColor3f(1.f, 0.f, 0.f);
            glVertex2f(10.f, 10.f);
            glColor3f(0.f, 1.f, 0.f);
            glVertex2f(10.f , 40.f);
            glColor3f(0.f, 0.f, 1.f);
            glVertex2f(40.f , 40.f);
            glColor3f(1.f, 1.f, 0.f);
            glVertex2f(40.f, 10.f);

        glEnd();

    }

    static void polygon_mode_button() {

        glBegin(GL_POLYGON);

            glColor3f(1.f, 0.7f, 0.f);
            glVertex2f(width-50.f, 10.f);
            glVertex2f(width-50.f, 40.f);
            glVertex2f(width-80.f, 40.f);
            glVertex2f(width-80.f, 10.f);

        glEnd();

        glBegin(GL_LINE_STRIP);

            glColor3f(1.f, 1.f, 1.f);
            glVertex2f(width-52.f, 12.f);
            glVertex2f(width-78.f, 38.f);

        glEnd();

        if (_polygon[count] == GL_POLYGON)
            glColor3f(1.f, 0.f, 0.f);

        glBegin(GL_QUADS);

            glVertex2f(width-76.f, 13.f);
            glVertex2f(width-76.f, 22.f);
            glVertex2f(width-67.f, 22.f);
            glVertex2f(width-67.f, 13.f);

        glEnd();

        glColor3f(1.f, 1.f, 1.f);
        if (_polygon[count] != GL_POLYGON)
            glColor3f(1.f, 0.f, 0.f);

        glBegin(GL_LINE_STRIP);

            glVertex2f(width-54.f, 37.f);
            glVertex2f(width-54.f, 28.f);
            glVertex2f(width-63.f, 28.f);
            glVertex2f(width-63.f, 37.f);
            glVertex2f(width-54.f, 37.f);

        glEnd();

    }

    static void new_array_button() {

        glColor3f(0.f, 1.f, 0.4f);

        glBegin(GL_POLYGON);

            glVertex2f(width-90.f, 10.f);
            glVertex2f(width-90.f, 40.f);
            glVertex2f(width-120.f, 40.f);
            glVertex2f(width-120.f, 10.f);

        glEnd();

        glColor3f(1.f, 1.f, 1.f);

        glBegin(GL_QUADS);

            glVertex2f(width-97.f, 24.f);
            glVertex2f(width-113.f, 24.f);
            glVertex2f(width-113.f, 26.f);
            glVertex2f(width-97.f, 26.f);

        glEnd();

        glColor3f(1.f, 1.f, 1.f);

        glBegin(GL_QUADS);

            glVertex2f(width-104.f, 17.f);
            glVertex2f(width-104.f, 33.f);
            glVertex2f(width-106.f, 33.f);
            glVertex2f(width-106.f, 17.f);

        glEnd();

    }

    static void reset_array_button() {

        glBegin(GL_POLYGON);

            glColor3f(1.f, 0.5f, 0.f);
            glVertex2f(width-130.f, 10.f);
            glVertex2f(width-130.f, 40.f);
            glVertex2f(width-160.f, 40.f);
            glVertex2f(width-160.f, 10.f);

        glEnd();

        glBegin(GL_LINE_STRIP);

            glColor3f(0.f, 0.f, 0.f);
            glVertex2f(width-135.f, 15.f);
            glVertex2f(width-135.f, 35.f);
            glVertex2f(width-155.f, 35.f);
            glVertex2f(width-155.f, 15.f);
            glVertex2f(width-135.f, 15.f);

        glEnd();



    }

    static void reset_all_button() {

        glBegin(GL_POLYGON);

            glColor3f(1.f, 0.5f, 0.f);
            glVertex2f(width-210.f, 10.f);
            glVertex2f(width-210.f, 40.f);
            glVertex2f(width-240.f, 40.f);
            glVertex2f(width-240.f, 10.f);

        glEnd();

        glBegin(GL_LINE_STRIP);

            glColor3f(0.f, 0.f, 0.f);
            glVertex2f(width-215.f, 15.f);
            glVertex2f(width-215.f, 35.f);
            glVertex2f(width-235.f, 35.f);
            glVertex2f(width-235.f, 15.f);
            glVertex2f(width-215.f, 15.f);

        glEnd();

        glBegin(GL_LINE_STRIP);

            glVertex2f(width-218, 32);
            glVertex2f(width-225, 18);
            glVertex2f(width-232, 32);

        glEnd();

    }

    static void pencil_mode_button() {

        glBegin(GL_POLYGON);

            glColor3f(0.f, 0.5f, 1.f);
            glVertex2f(width-170.f, 10.f);
            glVertex2f(width-170.f, 40.f);
            glVertex2f(width-200.f, 40.f);
            glVertex2f(width-200.f, 10.f);

        glEnd();

        if (pencil) {
            glBegin(GL_POLYGON);
        }else {
            glBegin(GL_LINE_STRIP);
        }

            glColor3f(1.f, 1.f, 1.f);
            glVertex2f(width-198, 18);
            glVertex2f(width-192, 12);
            glVertex2f(width-176, 28);
            glVertex2f(width-176, 34);
            glVertex2f(width-182, 34);
            glVertex2f(width-198, 18);


        glEnd();

    }

}


namespace gl {


    void initWindowHints() {

    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glfwWindowHint(GLFW_RED_BITS, 8);
    glfwWindowHint(GLFW_GREEN_BITS, 8);
    glfwWindowHint(GLFW_BLUE_BITS, 8);
    glfwWindowHint(GLFW_ALPHA_BITS, 8);
    glfwWindowHint(GLFW_SAMPLES, 16);
    //glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    }

    GLFWwindow *createWindow(GLint width, GLint heigt, const char* name) {

        GLFWwindow *window = glfwCreateWindow(width, heigt, name, NULL, NULL);
        glfwMakeContextCurrent(window);

        if (!window) {

            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        return window;
    }

    static void error_callback(int error, const char* description) {

        fputs(description, stderr);

    }

    static void mouse_callback(GLFWwindow *window) {

        if (pencil && !gui::checkForGUI()) {
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS) {

                    if (i[count] >= 1024)
                        i[count] = 0;

                    pos[count][i[count]].x = gl_x;
                    pos[count][i[count]].y = gl_y;
                    i[count]++;
                    std::cout << "[INFORMATION] New Coordinate: " << gl_x << " , " << gl_y << std::endl;
            }
        }

    }

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {

            glfwTerminate();
            std::cout << "[INFORMATION] Quitting ..." << std::endl;
            exit(EXIT_SUCCESS);

        }

        if (key == GLFW_KEY_P && action == GLFW_PRESS) {

            if (pencil) {
                pencil = false;
                std::cout << "[INFORMATION] Disabled pencil-mode." << std::endl;
            } else {
                pencil = true;
                std::cout << "[INFORMATION] Enabled pencil-mode." << std::endl;
            }

        }

        if (key == GLFW_KEY_LEFT_SHIFT && action == GLFW_RELEASE) {
            if (_polygon[count] == GL_POLYGON) {
                _polygon[count] = GL_LINE_STRIP;
                std::cout << "[INFORMATION] Disabled polygon-mode." << std::endl;
            } else {
                _polygon[count] = GL_POLYGON;
                std::cout << "[INFORMATION] Enabled polygon-mode." << std::endl;
            }
        }

        if (mods == GLFW_MOD_CONTROL && key == GLFW_KEY_Q && action == GLFW_RELEASE) {
            glfwTerminate();

            std::cout << "[INFORMATION] Quitting ..." << std::endl;

            exit(EXIT_SUCCESS);
        }

        if (mods == GLFW_MOD_CONTROL && key == GLFW_KEY_R && action == GLFW_RELEASE) {
            i[count] = 0;
            _polygon[count] = GL_LINE_STRIP;

            std::cout << "[INFORMATION] Reseted Vector Array." << std::endl;
        }

        if (mods == GLFW_MOD_CONTROL && key == GLFW_KEY_A && action == GLFW_RELEASE) {

            i[count] = 0;

            for (int h = 0;h <= count; h++) {
                i[h] = 0;
                color[h].x = color[h].y = color[h].z = 0.f;
                _polygon[h] = GL_LINE_STRIP;
            }

            count = 0;

            std::cout << "[INFORMATION] Reseted Sence." << std::endl;

        }

        if (key == GLFW_KEY_N && action == GLFW_RELEASE) {
            count++;
            std::cout << "[INFORMATION] New Vector Array: " << count << std::endl;

            if (count >= 1024)
                count = 0;

            i[count] = 0;
            _polygon[count] = GL_LINE_STRIP;
        }

    }

    static void mousebutton_callback(GLFWwindow *window, int button, int action, int mods) {

        if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS) {

            if (gl_x >= 10.f && gl_x <= 40.f &&            // color-modifier
                gl_y >= 10.f && gl_y <= 40.f) {
                if (colortri) {
                    colortri = false;
                    std::cout << "[INFORMATION] Disabled color triangle." << std::endl;
                } else {
                    colortri = true;
                    std::cout << "[INFORMATION] Enabled color triangle." << std::endl;
                }
            }
            if (colortri) {

                    if (gl_y >= 20 && gl_y <= 50 && gl_x >= 60 && gl_x <= 220) {

                        double grey = (gl_x - 60)/160;

                        color[count].x = grey;
                        color[count].y = grey;
                        color[count].z = grey;

                    }

                    if (gl_y <= 230 &&
                        gl_y - 56.794924 >= (( gl_x - 130 ) * ( 173.2050808/100)) &&
                        gl_y - 56.794924 >= (( gl_x - 130 ) * ( -173.2050808/100)) ){

                        double x1   = (gl_y - 230)*(gl_y - 230)  +  (gl_x - 30)*(gl_x - 30);
                        double y1   = (gl_y - 56.794919f)*(gl_y - 56.794919f)  +  (gl_x - 130)*(gl_x - 130);
                        double z1   = (gl_y - 230)*(gl_y - 230)  + (gl_x - 230)*(gl_x - 230);

                        x1 = sqrt(x1);
                        y1 = sqrt(y1);
                        z1 = sqrt(z1);

                        color[count].x = 1.75-x1/100;
                        color[count].y = 1.75-y1/100;
                        color[count].z = 1.75-z1/100;
                    }

                }
                if (gl_x <= width-10.f && gl_x >= width-40.f && gl_y <= 40.f && gl_y >= 10.f) {

                    glfwTerminate();

                    std::cout << "[INFORMATION] Quitting ..." << std::endl;

                    exit(EXIT_SUCCESS);

                }
                if (gl_x <= width-50.f && gl_x >= width-80.f && gl_y <= 40.f && gl_y >= 10.f) {

                    if (_polygon[count] == GL_POLYGON) {
                        _polygon[count] = GL_LINE_STRIP;
                        std::cout << "[INFORMATION] Disabled polygon-mode." << std::endl;
                    } else {
                        _polygon[count] = GL_POLYGON;
                        std::cout << "[INFORMATION] Enabled polygon-mode." << std::endl;
                    }


                }
                if (gl_x <= width-90.f && gl_x >= width-120.f && gl_y <= 40.f && gl_y >= 10.f) {

                    count++;
                    std::cout << "[INFORMATION] New Vector Array: " << count << std::endl;

                    if (count >= 1024)
                        count = 0;

                    i[count] = 0;
                    _polygon[count] = GL_LINE_STRIP;

                }else if (gl_x <= width-130.f && gl_x >= width-160.f && gl_y <= 40.f && gl_y >= 10.f) {

                    i[count] = 0;
                    _polygon[count] = GL_LINE_STRIP;

            std::cout << "[INFORMATION] Reseted Vector Array." << std::endl;

                }
                if (!pencil && !gui::checkForGUI()) {


                    if (i[count] >= 1024)
                        i[count] = 0;

                    pos[count][i[count]].x = gl_x;
                    pos[count][i[count]].y = gl_y;

                    i[count]++;

                    std::cout << "[INFORMATION] New Coordinate: " << gl_x << " , " << gl_y << std::endl;

                }
                if (gl_x <= width-170.f && gl_x >= width-200.f && gl_y <= 40.f && gl_y >= 10.f) {
                    if (pencil) {
                        pencil = false;
                        std::cout << "[INFORMATION] Disabled pencil-mode." << std::endl;
                    } else {
                        pencil = true;
                        std::cout << "[INFORMATION] Enabled pencil-mode." << std::endl;
                    }
                }
                if (gl_x <= width-210.f && gl_x >= width-240.f && gl_y <= 40.f && gl_y >= 10.f) {
                    i[count] = 0;
                    for (int h = 0;h <= count; h++) {
                        i[h] = 0;
                        color[h].x = color[h].y = color[h].z = 0.f;
                        _polygon[h] = GL_LINE_STRIP;
                    }
                    count = 0;
                    std::cout << "[INFORMATION] Reseted Sence." << std::endl;
                }


            }
    }

    void initGLFW() {

        glfwSetErrorCallback(gl::error_callback);

        if (!glfwInit())
        {
            exit(EXIT_FAILURE);
        }
    }

}


namespace miscellaneous {

    static void calculate_positions() {

        glfwGetWindowSize(glfwGetCurrentContext(), &width, &height);
        glfwGetCursorPos(glfwGetCurrentContext(), &x, &y);

        gl_x = x;
        gl_y = y;

    }

}

#endif // MAIN_H_INCLUDED
