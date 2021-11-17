//this is a 3D car game made from scratch

#include <cstdlib>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <time.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string>
#define SEC_PER_FRAME 10
#define PI 3.14159265
using namespace std;
GLvoid* font_style = GLUT_BITMAP_TIMES_ROMAN_24;
int unit = 2;
int rot = 0;
bool pauseMotion = false;
int switchView = 0;
int x, y, z;
bool aceler = true;
int ac = 0;
bool rightarrow = false;
int score = 0;
int r1, r2, r;
bool randomgenerator = false;


void textScore(void* font, const char* string) {
    glColor3f(0, 0, 0);
    glRasterPos2f(-30, 121);
    for (const char* c = string; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
    
}

//text is staying behind in the motion, move it as well?
void text2(void* font, const char* string) {
    glColor3f(0, 0, 0);
    glRasterPos2f(45, 30);
    for (const char* c = string; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
    
}

void drawCar() {
    //the first 2 squares are too large
    
    glBegin(GL_LINE_STRIP); //front part square (on left lane)
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(40.0 + (unit * 2) + 1, (unit + 1) + 9 -2 - 4 -1, 0.0); //1
    glVertex3f(40.0 + (unit * 2) + 1, (unit + 1) + 9 - 2 + 1 -4 - 1, 0.0); //2
    glVertex3f(40.0 + (unit * 2) + 1, (unit + 1) + 9 - 2 + 1 -4 - 1, (unit + 1)); //3
    glVertex3f(40.0 + (unit * 2) + 1, (unit + 1) + 9 - 2 - 4 - 1, (unit + 1)); //4
    glVertex3f(40.0 + (unit * 2) + 1, (unit + 1) + 9 - 2 - 4 - 1, 0.0); //5
    
    glVertex3f(40.0 + (unit * 2) + (unit + 1) + 1, (unit + 1) + 9 - 2 - 4 - 1, 0.0); //6
    glVertex3f(40.0 + (unit * 2) + (unit + 1) + 1, (unit + 1) + 9 - 2 + 1 - 4 - 1, 0.0); //7
    glVertex3f(40.0 + (unit * 2) + (unit + 1) + 1, (unit + 1) + 9 - 2 + 1 - 4 - 1, (unit + 1)); //8
    glVertex3f(40.0 + (unit * 2) + (unit + 1) + 1, (unit + 1) + 9 - 2 - 4 - 1, (unit + 1));//9
    glVertex3f(40.0 + (unit * 2) + (unit + 1) + 1, (unit + 1) + 9 - 2 - 4 - 1, 0.0);//10
    
    glVertex3f(40.0 + (unit * 2) + (unit + 1) + 1, (unit + 1) + 9 - 2 +1 - 4 - 1, 0.0);//11
    glVertex3f(40.0 + (unit * 2) + 1, (unit + 1) + 9 - 2 + 1 - 4 - 1, 0.0); //12
    glVertex3f(40.0 + (unit * 2) + 1, (unit + 1) + 9 - 2 +1 - 4 - 1, (unit + 1));//13
    glVertex3f(40.0 + (unit * 2) + (unit + 1) + 1, (unit + 1) + 9 - 2 + 1 - 4 - 1, (unit + 1));//14
    glVertex3f(40.0 + (unit * 2) + (unit + 1) + 1, (unit + 1) + 9 - 2 - 4 - 1, (unit + 1)); //15
    glVertex3f(40.0 + (unit * 2) + 1, (unit + 1) + 9 - 2 - 4 - 1, (unit + 1));//16
    glEnd();
    
    glBegin(GL_LINE_STRIP); //middle part square (on left lane)
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(40.0 + (unit * 2) + 0.5, (unit + 1.5)  , 0.0); //1
    glVertex3f(40.0 + (unit * 2) + 0.5, (unit + 1.5) + (unit + 1.5) - 2, 0.0);//2
    glVertex3f(40.0 + (unit * 2) + 0.5, (unit + 1.5) + (unit + 1.5) - 2, (unit + 1.5));//3
    glVertex3f(40.0 + (unit * 2) + 0.5, (unit + 1.5) , (unit + 1.5));//4
    glVertex3f(40.0 + (unit * 2) + 0.5, (unit + 1.5) , 0.0);//5
    
    glVertex3f(40.0 + (unit * 2) + (unit + 1.5) + 0.5 + 0.5, (unit + 1.5) , 0.0);//6
    glVertex3f(40.0 + (unit * 2) + (unit + 1.5) + 0.5 + 0.5, (unit + 1.5) + (unit + 1.5) - 2, 0.0);//7
    glVertex3f(40.0 + (unit * 2) + (unit + 1.5) + 0.5 + 0.5, (unit + 1.5) + (unit + 1.5) - 2, (unit + 1.5));//8
    glVertex3f(40.0 + (unit * 2) + (unit + 1.5) + 0.5 + 0.5, (unit + 1.5) , (unit + 1.5));//9
    glVertex3f(40.0 + (unit * 2) + (unit + 1.5) + 0.5 + 0.5, (unit + 1.5) , 0.0);//10
    
    glVertex3f(40.0 + (unit * 2) + (unit + 1.5) + 0.5 + 0.5, (unit + 1.5) + (unit + 1.5) - 2, 0.0);//11
    glVertex3f(40.0 + (unit * 2) + 0.5, (unit + 1.5) + (unit + 1.5) - 2, 0.0);//12
    glVertex3f(40.0 + (unit * 2) + 0.5, (unit + 1.5) + (unit + 1.5) - 2, (unit + 1.5));//13
    glVertex3f(40.0 + (unit * 2) + (unit + 1.5) + 0.5 + 0.5, (unit + 1.5) + (unit + 1.5) - 2, (unit + 1.5));//14
    glVertex3f(40.0 + (unit * 2) + (unit + 1.5) + 0.5 + 0.5, (unit + 1.5) , (unit + 1.5));//15
    glVertex3f(40.0 + (unit * 2) + 0.5, (unit + 1.5), (unit + 1.5));//16
    glEnd();
    
    //big back part (rectangle) on left lane
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(40.0 + (unit * 2), (unit + 2) + 1.5 - 7, 0.0); ///1
    glVertex3f(40.0 + (unit * 2), (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, 0.0); ///2
    glVertex3f(40.0 + (unit * 2), (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, (unit + 2));///3
    glVertex3f(40.0 + (unit * 2), (unit + 2) + 1.5 - 7, (unit + 2));///4
    glVertex3f(40.0 + (unit * 2), (unit + 2) + 1.5 - 7, 0.0);///5
    
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + 1.5 - 7, 0.0);///6
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, 0.0);///7
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, (unit + 2));///8
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + 1.5 - 7, (unit + 2));///9
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + 1.5 - 7, 0.0);///10
    
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, 0.0);///11
    glVertex3f(40.0 + (unit * 2), (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, 0.0);///12
    glVertex3f(40.0 + (unit * 2), (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, (unit + 2));///13
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, (unit + 2));///14
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + 1.5 - 7, (unit + 2));///15
    glVertex3f(40.0 + (unit * 2), (unit + 2) + 1.5 - 7, (unit + 2));///16
    glEnd();
    
    glBegin(GL_TRIANGLE_STRIP); //coloring the front part of truck
    glColor3f(1, 0, 0);
    glVertex3f(40.0 + (unit * 2) + 1, (unit + 1) + 9 - 2 - 4 - 1, 0.0); //1
    glVertex3f(40.0 + (unit * 2) + 1, (unit + 1) + 9 - 2 - 4 - 1 +1, 0.0); //2
    glVertex3f(40.0 + (unit * 2) + (unit + 1) + 1, (unit + 1) + 9 - 2 - 4 - 1, 0.0); //6
    glVertex3f(40.0 + (unit * 2) + (unit + 1) + 1, (unit + 1) + 9 - 2 - 4 - 1 +1, 0.0); //7
    glVertex3f(40.0 + (unit * 2) + (unit + 1) + 1, (unit + 1) + 9 - 2 - 4 - 1, (unit + 1));//9
    glVertex3f(40.0 + (unit * 2) + (unit + 1) + 1, (unit + 1) + 9 - 2 - 4 - 1 +1, (unit + 1)); //8
    glVertex3f(40.0 + (unit * 2) + 1, (unit + 1) + 9 - 2 - 4 - 1, (unit + 1)); //4
    glVertex3f(40.0 + (unit * 2) + 1, (unit + 1) + 9 - 2 - 4 - 1 +1 , (unit + 1)); //3
    glVertex3f(40.0 + (unit * 2) + 1, (unit + 1) + 9 - 2 - 4 - 1, 0.0); //1
    glVertex3f(40.0 + (unit * 2) + 1, (unit + 1) + 9 - 2 - 4 - 1 +1, 0.0); //2
    glVertex3f(40.0 + (unit * 2) + (unit + 1) + 1, (unit + 1) + 9 - 2 - 4 - 1 +1, 0.0); //7
    glVertex3f(40.0 + (unit * 2) + 1, (unit + 1) + 9 - 2 - 4 - 1 +1, (unit + 1)); //3
    glVertex3f(40.0 + (unit * 2) + (unit + 1) + 1, (unit + 1) + 9 - 2 - 4 - 1+1, (unit + 1)); //8
    glEnd();
    
    glBegin(GL_TRIANGLE_STRIP); //coloring middle part of truck
    glColor3f(1, 0, 0);
    glVertex3f(40.0 + (unit * 2) + 0.5, (unit + 1.5) , 0.0); //1
    glVertex3f(40.0 + (unit * 2) + 0.5, (unit + 1.5) + (unit + 1.5) - 2, 0.0);//2
    glVertex3f(40.0 + (unit * 2) + (unit + 1.5) + 0.5 + 0.5, (unit + 1.5) , 0.0);//6
    glVertex3f(40.0 + (unit * 2) + (unit + 1.5) + 0.5 + 0.5, (unit + 1.5) + (unit + 1.5) - 2, 0.0);//7
    glVertex3f(40.0 + (unit * 2) + (unit + 1.5) + 0.5 + 0.5, (unit + 1.5) , (unit + 1.5));//9
    glVertex3f(40.0 + (unit * 2) + (unit + 1.5) + 0.5 + 0.5, (unit + 1.5) + (unit + 1.5) - 2, (unit + 1.5));//8
    glVertex3f(40.0 + (unit * 2) + 0.5, (unit + 1.5), (unit + 1.5));//4
    glVertex3f(40.0 + (unit * 2) + 0.5, (unit + 1.5) + (unit + 1.5) - 2, (unit + 1.5));//3
    glVertex3f(40.0 + (unit * 2) + 0.5, (unit + 1.5) +(unit + 1.5) - 2, 0.0);//2
    glVertex3f(40.0 + (unit * 2) + (unit + 1.5) + 0.5 + 0.5, (unit + 1.5) + (unit + 1.5) - 2, 0.0);//7
    glVertex3f(40.0 + (unit * 2) + 0.5, (unit + 1.5) + (unit + 1.5) - 2, (unit + 1.5));//3
    glVertex3f(40.0 + (unit * 2) + (unit + 1.5) + 0.5 + 0.5, (unit + 1.5) + (unit + 1.5) - 2, (unit + 1.5));//8
    glEnd();
    
    
    glBegin(GL_TRIANGLE_STRIP); //coloring back part of truck
    glColor3f(0.545, 0.000, 0.000); //dark red
    glVertex3f(40.0 + (unit * 2), (unit + 2) + 1.5 - 7, 0.0); ///1
    glVertex3f(40.0 + (unit * 2), (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, 0.0); ///2
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + 1.5 - 7, 0.0);///6
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, 0.0);///7
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + 1.5 - 7, (unit + 2));///9
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, (unit + 2));///8
    glVertex3f(40.0 + (unit * 2), (unit + 2) + 1.5 - 7, (unit + 2));///4
    glVertex3f(40.0 + (unit * 2), (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, (unit + 2));///3
    glVertex3f(40.0 + (unit * 2), (unit + 2) + 1.5 - 7, 0.0); ///1
    glVertex3f(40.0 + (unit * 2), (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, 0.0); ///2
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, 0.0);///7
    glVertex3f(40.0 + (unit * 2), (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, (unit + 2));///3
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + (unit + 2) + (unit + 2) + 1.5 - 7 - 3, (unit + 2));///8
    glVertex3f(40.0 + (unit * 2), (unit + 2) + 1.5 - 7, (unit + 2));///4
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + 1.5 - 7, (unit + 2));///9
    glVertex3f(40.0 + (unit * 2), (unit + 2) + 1.5 - 7, 0.0); ///1
    glVertex3f(40.0 + (unit * 2) + (unit + 2) + 1, (unit + 2) + 1.5 - 7, 0.0);///6
    glEnd();
}


void drawLanscape() {
    
    
    //green left
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-500.0, 0.0, 0.0);
    glVertex3f(-500.0, unit * 1000, 0.0);
    glVertex3f(40.0, 0.0, 0.0);
    glVertex3f(40.0, unit * 1000, 0.0);
    glEnd();
    
    
    //green right
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(40.0 + (unit * 16), 0.0, 0.0);
    glVertex3f(40 + (unit * 16), unit * 1000, 0.0);
    glVertex3f(500.0, 0.0, 0.0);
    glVertex3f(500.0, unit * 1000, 0.0);
    glEnd();
    
    
    
    
}


void drawRoad() {
    
    
    //white lines in middle of road,how to make them go separate?
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < unit * 1000; i = i + 10) {
        glLineWidth(2);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(40 + (unit * 8), i, 0.0);
        glVertex3f(40 + (unit * 8), i + 5, 0.0);
        
    }
    glEnd();
    
    //left line of road
    
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < unit * 1000; i++) {
        glLineWidth(4);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(40, i, 0.0);
    }
    glEnd();
    
    
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < unit * 1000; i++) {
        glLineWidth(4);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(40.0 + (unit * 16), i, 0.0);
    }
    glEnd();
    
    
    
    //glBegin() 2 big triangles colored in gray with triangle stip
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(40.0, 0.0, 0.0);
    glVertex3f(40.0, unit * 1000, 0.0);
    glVertex3f(40.0 + (unit * 16), 0.0, 0.0);
    glVertex3f(40.0 + (unit * 16), unit * 1000, 0.0);
    glEnd();
    
}

void draw3dsquare1() {
    
    glBegin(GL_LINE_STRIP); //square for first lane
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(40.0 + (unit * 3), unit + 15, 0.0); //1    //first square on y=17
    glVertex3f(40.0 + (unit * 3), unit + unit + 15, 0.0); //2
    glVertex3f(40.0 + (unit * 3), unit + unit + 15, unit); //3
    glVertex3f(40.0 + (unit * 3), unit + 15, unit); //4
    glVertex3f(40.0 + (unit * 3), unit + 15, 0.0); //5
    
    glVertex3f(40.0 + (unit * 3) + unit, unit + 15, 0.0); //6
    glVertex3f(40.0 + (unit * 3) + unit, unit + unit + 15, 0.0); //7
    glVertex3f(40.0 + (unit * 3) + unit, unit + unit + 15, unit); //8
    glVertex3f(40.0 + (unit * 3) + unit, unit + 15, unit); //9
    glVertex3f(40.0 + (unit * 3) + unit, unit + 15, 0.0); //10
    
    glVertex3f(40.0 + (unit * 3) + unit, unit + unit + 15, 0.0); //11
    glVertex3f(40.0 + (unit * 3), unit + unit + 15, 0.0); //12
    glVertex3f(40.0 + (unit * 3), unit + unit + 15, unit); //13
    glVertex3f(40.0 + (unit * 3) + unit, unit + unit + 15, unit); //14
    glVertex3f(40.0 + (unit * 3) + unit, unit + 15, unit); //15
    glVertex3f(40.0 + (unit * 3), unit + 15, unit); //16
    glEnd();
    
    glBegin(GL_TRIANGLE_STRIP); //coloring the square with yellow
    glColor3f(1.0, 1.0, 0);
    glVertex3f(40.0 + (unit * 3), unit + 15, 0.0);//1
    glVertex3f(40.0 + (unit * 3), unit + unit + 15, 0.0); //2
    glVertex3f(40.0 + (unit * 3) + unit, unit + 15, 0.0); //6
    glVertex3f(40.0 + (unit * 3) + unit, unit + unit + 15, 0.0); //7
    glVertex3f(40.0 + (unit * 3) + unit, unit + 15, unit); //9
    glVertex3f(40.0 + (unit * 3) + unit, unit + unit + 15, unit); //8
    glVertex3f(40.0 + (unit * 3), unit + 15, unit); //4
    glVertex3f(40.0 + (unit * 3), unit + unit + 15, unit); //3
    glVertex3f(40.0 + (unit * 3), unit + 15, 0.0);//1
    glVertex3f(40.0 + (unit * 3), unit + unit + 15, 0.0); //2
    glVertex3f(40.0 + (unit * 3) + unit, unit + unit + 15, 0.0); //7
    glVertex3f(40.0 + (unit * 3), unit + unit + 15, unit); //3
    glVertex3f(40.0 + (unit * 3) + unit, unit + unit + 15, unit); //8
    glVertex3f(40.0 + (unit * 3), unit + 15, unit); //4
    glVertex3f(40.0 + (unit * 3), unit + 15, 0.0);//1
    glVertex3f(40.0 + (unit * 3) + unit, unit + 15, unit); //9
    glVertex3f(40.0 + (unit * 3) + unit, unit + 15, 0.0); //6
    glEnd();
    
    
    
    
}

void draw3dsquare2() {
    
    glBegin(GL_LINE_STRIP); //square for second lane
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(40 + (unit * 8) + (unit * 3), unit, 0.0); //1
    glVertex3f(40 + (unit * 8) + (unit * 3), unit + unit, 0.0); //2
    glVertex3f(40 + (unit * 8) + (unit * 3), unit + unit, unit); //3
    glVertex3f(40 + (unit * 8) + (unit * 3), unit, unit); //4
    glVertex3f(40 + (unit * 8) + (unit * 3), unit, 0.0); //5
    
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit, 0.0); //6
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit + unit, 0.0); //7
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit + unit, unit); //8
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit, unit); //9
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit, 0.0); //10
    
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit + unit, 0.0); //11
    glVertex3f(40 + (unit * 8) + (unit * 3), unit + unit, 0.0); //12
    glVertex3f(40 + (unit * 8) + (unit * 3), unit + unit, unit);//13
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit + unit, unit);//14
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit, unit);//15
    glVertex3f(40 + (unit * 8) + (unit * 3), unit, unit);//16
    glEnd();
    
    glBegin(GL_TRIANGLE_STRIP); //coloring the square with yellow
    glColor3f(1.0, 1.0, 0);
    glVertex3f(40 + (unit * 8) + (unit * 3), unit, 0.0); //1
    glVertex3f(40 + (unit * 8) + (unit * 3), unit + unit, 0.0); //2
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit, 0.0); //6
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit + unit, 0.0); //7
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit, unit); //9
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit + unit, unit); //8
    glVertex3f(40 + (unit * 8) + (unit * 3), unit, unit); //4
    glVertex3f(40 + (unit * 8) + (unit * 3), unit + unit, unit); //3
    glVertex3f(40 + (unit * 8) + (unit * 3), unit, 0.0); //1
    glVertex3f(40 + (unit * 8) + (unit * 3), unit + unit, 0.0); //2
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit + unit, 0.0); //7
    glVertex3f(40 + (unit * 8) + (unit * 3), unit + unit, unit); //3
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit + unit, unit); //8
    glVertex3f(40 + (unit * 8) + (unit * 3), unit, unit); //4
    glVertex3f(40 + (unit * 8) + (unit * 3), unit, 0.0); //1
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit, unit); //9
    glVertex3f(40 + (unit * 8) + (unit * 3) + unit, unit, 0.0); //6
    glEnd();
    
}
void modifier() {
    
    if (r1 == 1698) {
        
        r1 = r1 - 198;
    }
    if (r1 == 1695) {
        
        r1 = r1 - 50;
    }
    if (r2 == 542) {
        
        r2 = r2 + 200;
    }
    if (r2 == 1480) {
        r2 = r2 + 60;
    }
    if (r2 == 1905) {
        r2 = r2 - 305;
    }
    
    if (r2 == 1305) {
        r2 = r2 + 50;
    }
    
    if (r2 == 1930) {
        r2 = r2 - 450;
    }
    if (r2 == 1924) {
        r2 = r2 + 30;
        
        if (r1 == 1727) {
            r1 = r1 + 100;
        }
        
        
    }
    if (r2 == 742) {
        r2 = r2 + 50;
    }
}
void drawRandomObjects() {
    //translate the squares across the road seemingly random , do it 20 times
    
    srand(10);
    
    for (int i = 0; i < 10; i++) {
        
        r1 = (rand() % 2000) + 1;
        modifier();
        cout << r1 << endl;
        glLoadIdentity(); //1
        glTranslatef(0, r1, 0);
        draw3dsquare1();
        glLoadIdentity();
    }
    
    for (int i = 0; i < 10; i++) {
        
        r2 = (rand() % 2000) + 1;
        modifier();
        cout << r2 << endl;
        glLoadIdentity(); //1
        glTranslatef(0, r2, 0);
        draw3dsquare2();
        glLoadIdentity();
        
    }
    
    
    
    
}

void scoreNumber(int a) {
    
    int p, k;
    
    
    p = a;
    k = 0;
    
    glColor3f(0, 0, 0);
    if (p > 999) {
        k = p % 10;
        glRasterPos2f(18, 121);
        glutBitmapCharacter(font_style, 48 + k);
        p /= 10;
        
    }
    if (p > 99) {
        k = p % 10;
        glRasterPos2f(14, 121);
        glutBitmapCharacter(font_style, 48 + k);
        p /= 10;
    }
    if (p > 9) {
        k = p % 10;
        glRasterPos2f(10, 121);
        glutBitmapCharacter(font_style, 48 + k);
        p /= 10;
        
    }
    if (p < 10) {
        glColor3f(0, 0, 0);
        glRasterPos2f(6, 121);
        glutBitmapCharacter(font_style, 48 + p);
    }
    //figure out for when the score gets to 1000 (an extra integer)
}

//complete the conditions' info for collisions
void collisionchecker() {
    
    if ((ac == (72 + 2) || ac == (72 + 3) || ac == (72 + 4) || ac == (72 + 5) || ac == (72 + 6) || ac == (72 + 7) ||
         ac == (72 + 8) || ac == (72 + 9) || ac == (72 + 10) || ac == (72 + 11) || ac == (72 + 12)
         || ac == (72 + 13) || ac == (72 + 14) || ac == (72 + 15) || ac == (72 + 16) || ac == (72 + 17)) && rightarrow == false) {
        
        pauseMotion = true;
        text2(GLUT_BITMAP_TIMES_ROMAN_24, "YOU LOSE!");
    }
    if ((ac == (297 + 2) || ac == (72 + 3) || ac == (72 + 4) || ac == (72 + 5) || ac == (72 + 6) || ac == (72 + 7) ||
         ac == (72 + 8) || ac == (72 + 9) || ac == (72 + 10) || ac == (72 + 11) || ac == (72 + 12)
         || ac == (72 + 13) || ac == (72 + 14) || ac == (72 + 15) || ac == (72 + 16) || ac == (72 + 17)) && rightarrow == false) {
        
        pauseMotion = true;
        text2(GLUT_BITMAP_TIMES_ROMAN_24, "YOU LOSE!");
    }
    if ((ac == (723 + 2) || ac == (72 + 3) || ac == (72 + 4) || ac == (72 + 5) || ac == (72 + 6) || ac == (72 + 7) ||
         ac == (72 + 8) || ac == (72 + 9) || ac == (72 + 10) || ac == (72 + 11) || ac == (72 + 12)
         || ac == (72 + 13) || ac == (72 + 14) || ac == (72 + 15) || ac == (72 + 16) || ac == (72 + 17)) && rightarrow == false) {
        
        pauseMotion = true;
        text2(GLUT_BITMAP_TIMES_ROMAN_24, "YOU LOSE!");
    }
    if ((ac == (900 + 2) || ac == (72 + 3) || ac == (72 + 4) || ac == (72 + 5) || ac == (72 + 6) || ac == (72 + 7) ||
         ac == (72 + 8) || ac == (72 + 9) || ac == (72 + 10) || ac == (72 + 11) || ac == (72 + 12)
         || ac == (72 + 13) || ac == (72 + 14) || ac == (72 + 15) || ac == (72 + 16) || ac == (72 + 17)) && rightarrow == false) {
        
        pauseMotion = true;
        text2(GLUT_BITMAP_TIMES_ROMAN_24, "YOU LOSE!");
    }
    if ((ac == (1013 + 2) || ac == (72 + 3) || ac == (72 + 4) || ac == (72 + 5) || ac == (72 + 6) || ac == (72 + 7) ||
         ac == (72 + 8) || ac == (72 + 9) || ac == (72 + 10) || ac == (72 + 11) || ac == (72 + 12)
         || ac == (72 + 13) || ac == (72 + 14) || ac == (72 + 15) || ac == (72 + 16) || ac == (72 + 17)) && rightarrow == false) {
        
        pauseMotion = true;
        text2(GLUT_BITMAP_TIMES_ROMAN_24, "YOU LOSE!");
    }
    if ((ac == (1273 + 2) || ac == (72 + 3) || ac == (72 + 4) || ac == (72 + 5) || ac == (72 + 6) || ac == (72 + 7) ||
         ac == (72 + 8) || ac == (72 + 9) || ac == (72 + 10) || ac == (72 + 11) || ac == (72 + 12)
         || ac == (72 + 13) || ac == (72 + 14) || ac == (72 + 15) || ac == (72 + 16) || ac == (72 + 17)) && rightarrow == false) {
        
        pauseMotion = true;
        text2(GLUT_BITMAP_TIMES_ROMAN_24, "YOU LOSE!");
    }
    if ((ac == (1698 + 2) || ac == (72 + 3) || ac == (72 + 4) || ac == (72 + 5) || ac == (72 + 6) || ac == (72 + 7) ||
         ac == (72 + 8) || ac == (72 + 9) || ac == (72 + 10) || ac == (72 + 11) || ac == (72 + 12)
         || ac == (72 + 13) || ac == (72 + 14) || ac == (72 + 15) || ac == (72 + 16) || ac == (72 + 17)) && rightarrow == false) {
        
        pauseMotion = true;
        text2(GLUT_BITMAP_TIMES_ROMAN_24, "YOU LOSE!");
    }
    if ((ac == (1727 + 2) || ac == (72 + 3) || ac == (72 + 4) || ac == (72 + 5) || ac == (72 + 6) || ac == (72 + 7) ||
         ac == (72 + 8) || ac == (72 + 9) || ac == (72 + 10) || ac == (72 + 11) || ac == (72 + 12)
         || ac == (72 + 13) || ac == (72 + 14) || ac == (72 + 15) || ac == (72 + 16) || ac == (72 + 17)) && rightarrow == false) {
        
        pauseMotion = true;
        text2(GLUT_BITMAP_TIMES_ROMAN_24, "YOU LOSE!");
    }
    if ((ac == (1795 + 2) || ac == (72 + 3) || ac == (72 + 4) || ac == (72 + 5) || ac == (72 + 6) || ac == (72 + 7) ||
         ac == (72 + 8) || ac == (72 + 9) || ac == (72 + 10) || ac == (72 + 11) || ac == (72 + 12)
         || ac == (72 + 13) || ac == (72 + 14) || ac == (72 + 15) || ac == (72 + 16) || ac == (72 + 17)) && rightarrow == false) {
        
        pauseMotion = true;
        text2(GLUT_BITMAP_TIMES_ROMAN_24, "YOU LOSE!");
    }
    if ((ac == (1900 + 2) || ac == (72 + 3) || ac == (72 + 4) || ac == (72 + 5) || ac == (72 + 6) || ac == (72 + 7) ||
         ac == (72 + 8) || ac == (72 + 9) || ac == (72 + 10) || ac == (72 + 11) || ac == (72 + 12)
         || ac == (72 + 13) || ac == (72 + 14) || ac == (72 + 15) || ac == (72 + 16) || ac == (72 + 17)) && rightarrow == false) {
        
        pauseMotion = true;
        text2(GLUT_BITMAP_TIMES_ROMAN_24, "YOU LOSE!");
    }
    
    if ((ac == (375 + 2) || ac == (375 + 3) || ac == (375 + 4) || ac == (375 + 5) || ac == (375 + 6) || ac == (375 + 7) ||
         ac == (375 + 8) || ac == (375 + 9) || ac == (375 + 10) || ac == (375 + 11) || ac == (375 + 12)
         || ac == (375 + 13) || ac == (375 + 14) || ac == (375 + 15) || ac == (375 + 16) || ac == (375 + 17)) && rightarrow == true) {
        
        pauseMotion = true;
        text2(GLUT_BITMAP_TIMES_ROMAN_24, "YOU LOSE!");
    }
   
}

// Drawing routine.
void drawScene(void) {
    glClearColor(0, 0.9, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    //------------------------------------------------
    
    gluLookAt(40 + (unit * 8), ac, 20, 40 + (unit * 8), 10 + ac, 10, 0, 0, 1); //get it a little farther back from the car
    scoreNumber(score);
    textScore(GLUT_BITMAP_TIMES_ROMAN_24, "SCORE:");
    
    glPushMatrix();
    
    srand(10);
    for (int i = 0; i < 10; i++) {
        glPushMatrix();
        r1 = (rand() % 2000) + 1;
        modifier();
        cout << "r1:" << r1 << endl;
        glTranslatef(0, r1, 0);
        draw3dsquare1();
        glPopMatrix();
    }
    
    for (int i = 0; i < 10; i++) {
        glPushMatrix();
        r2 = (rand() % 2000) + 1;
        modifier();
        cout << "r2:" << r2 << endl;
        glTranslatef(0, r2, 0);
        draw3dsquare2();
        glPopMatrix();
    }
    
    glPushMatrix();
    
    
    drawRoad();
    
    drawLanscape();
    
    if (rightarrow == true) {
        glLoadIdentity;
        glTranslatef((unit * 8), 0, 0);
        glLoadIdentity;
        
    }
    collisionchecker();
    
    if (aceler == true) {
        
        //increase score everytime u pass through an object's X coordinate
        if (ac == (72 + 17) || ac == (297 + 17) || ac == (375 + 17) || ac == (551 + 17) || ac == (642 + 17) || (ac == 723 + 17) || ac == (900 + 17) ||
            ac == (982 + 17) || ac == (1013 + 17) || ac == (1084 + 17) || ac == (1273 + 17) || ac == (1305 + 17) || ac == (1483 + 17) || ac == (1698 + 17)
            || ac == (1727 + 17) || ac == (1760 + 17) || ac == (1795 + 17) || ac == (1900 + 17) || ac == (1924 + 17)
            || ac == (1960 + 17)) { //put the rest Xs of random objects
            score = score + 100;
            cout << score;
            
        }
        if (ac == unit * 1000 - 1) {
            
            pauseMotion = true;
            text2(GLUT_BITMAP_TIMES_ROMAN_24, "YOU WIN!");
            
        }
        
        glPushMatrix();
        glTranslatef(0, ac, 0);
        drawCar();
        glPopMatrix();
        
        
    }
    
    drawRandomObjects();
    
    //------------------------------------------
    glDisable(GL_DEPTH_TEST);
    glFlush();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y) { //change a , d to -> , <-
    switch (key)
    {
        case 27:
            exit(0);
            break;
        case ' ':
            if (pauseMotion) pauseMotion = false;
            else pauseMotion = true;
            break;
        case 'd':
            rightarrow = true;
            break;
        case 'a':
            rightarrow = false;
            break;
        default:
            break;
    }
}

void mouseControl(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int click_x = x;
        int click_y = y;
        cout << click_x << "  " << click_y << endl;
        
    }
}
//Timer function is called in every MSEC_PER_FRAME milliseconds
void timerFunc(int value) {
    
    if (!pauseMotion)
        
        if (aceler)
            ac += 1;
    
    glutPostRedisplay();
    glutTimerFunc(SEC_PER_FRAME, timerFunc, value);
}

// Initialization routine.
void setup(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h) {
    glViewport(0, 0, w, h);
    
    glMatrixMode(GL_PROJECTION);
   
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

// Main routine.
int main(int argc, char** argv) {
    //srand(time(NULL));
    
    glutInit(&argc, argv);
    
    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("HW2.cpp");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    glutMouseFunc(mouseControl);
    
    glutTimerFunc(SEC_PER_FRAME, timerFunc, 1);
    
    glewExperimental = GL_TRUE;
    glewInit();
    
    setup();
    
    glutMainLoop();
}












