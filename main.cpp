#include <iostream>
#include <GL/glut.h>
#include "Game.h"

void windowDisplay();
void windowInit();
void windowReshape(int width, int height);
void passiveMotion(int x, int y);
void mouseFunc(int button, int state, int x, int y);
void drawString (void * font, char *s, float x, float y);

int player = 1;

int WindowWidth = 400, WindowHeight = 400;

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(WindowWidth,WindowHeight);
    glutCreateWindow("TIC-TAC-TOE");
    glutPassiveMotionFunc(passiveMotion);
    glutMouseFunc(mouseFunc);
    glutDisplayFunc(windowDisplay);
    glutReshapeFunc(windowReshape);
    windowInit();
    glutMainLoop();
    return 0;
}

void windowDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    refreshGameTable();
    if(checkifwin()){
        if(player == 2){
            char tab[15] = "Player 1 won!!";
            drawString(GLUT_BITMAP_HELVETICA_18, tab, 1.1, 1.5);
        }
        else{
            char tab[15] = "Player 2 won!!";
            drawString(GLUT_BITMAP_HELVETICA_18, tab, 1.1, 1.5);
        }
    }
    if(checkDraw()){
        char tab[15] = "Draw!!";
        drawString(GLUT_BITMAP_HELVETICA_18, tab, 1.1, 1.0);
    }
    glutSwapBuffers();
}

void windowInit(){
    glClearColor(0.0,0.0,0.0,1.0);
}

void windowReshape(int width, int height){
    glViewport(0,0,(GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,3.0,0.0,3.0,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    WindowWidth = width;
    WindowHeight = height;
}

void passiveMotion(int x, int y){
    trackCursor(x,y);
}

void mouseFunc(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && player == 1){
        placeSign(1,WindowWidth,WindowHeight);
        player = 2;
    }
    else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && player == 2){
        placeSign(2,WindowWidth,WindowHeight);
        player = 1;
    }
}

void drawString (void * font, char s[], float x, float y){
    glRasterPos2f(x, y);
    for (int i = 0; i < strlen (s); i++)
        glutBitmapCharacter (font, s[i]);
}
