//
// Created by Maciej on 03.05.2020.
//

#include "Game.h"
#include "GL/glut.h"

int mouseX, mouseY;

int gameTable[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
};

void drawGrid(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            drawSquare(GL_LINE_LOOP, i, j, 1.0, 1.0, 1.0, 1.0, 1);
        }
    }
}

void drawSquare(GLenum mode, int x, int y, float r, float g, float b, float lineWidth, float alpha){
    glLineWidth(lineWidth);
    glColor4f(r,g,b,alpha);
    glBegin(mode);
        glVertex2f(x,y);
        glVertex2f(x+1,y);
        glVertex2f(x+1,y+1);
        glVertex2f(x,y+1);
    glEnd();
}

void drawX(int x, int y, float r, float g, float b, float lineWidth){
    glLineWidth(lineWidth);
    glColor3f(r,g,b);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x+0.2,y+0.2);
        glVertex2f(x+0.8,y+0.8);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(x+0.2,y+0.8);
        glVertex2f(x+0.8,y+0.2);
    glEnd();
}

void drawO(int x, int y, float r, float g, float b, float lineWidth){
    glLineWidth(lineWidth);
    glColor3f(r,g,b);
    glBegin(GL_LINE_LOOP);
        glVertex2f((GLfloat)x+0.8,(GLfloat)y+0.5);
        glVertex2f((GLfloat)x+0.5,(GLfloat)y+0.8);
        glVertex2f((GLfloat)x+0.2,(GLfloat)y+0.5);
        glVertex2f((GLfloat)x+0.5,(GLfloat)y+0.2);
    glEnd();
};

void trackCursor(int x, int y){
    mouseX = x;
    mouseY = y;
}

void refreshGameTable(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(gameTable[i][j] == 1){
                drawX(i, j, 0.0, 1.0, 0.0, 3.0);
            }
            else if(gameTable[i][j] == 2){
                drawO(i,j, 0.0, 0.0, 1.0, 3.0);
            }
        }
    }
}


void placeSign(int sign, int WindowWidth, int WindowHeight){
    if(mouseX > 0 && mouseX < (WindowWidth/3) && mouseY > 0 && mouseY < (WindowHeight/3) && gameTable[0][2] == 0){
        gameTable[0][2] = sign;
    }
    else if(mouseX > 0 && mouseX < (WindowWidth/3) && mouseY > (WindowHeight/3) && mouseY < (WindowHeight*(2.0/3.0)) && gameTable[0][1] == 0) {
        gameTable[0][1] = sign;
    }
    else if(mouseX > 0 && mouseX < (WindowWidth/3) && mouseY > (WindowHeight*(2.0/3.0)) && mouseY < WindowHeight && gameTable[0][0] == 0) {
        gameTable[0][0] = sign;
    }
    else if(mouseX > (WindowWidth/3) && mouseX < (WindowWidth*(2.0/3.0)) && mouseY > 0 && mouseY < (WindowHeight/3) && gameTable[1][2] == 0){
        gameTable[1][2] = sign;
    }
    else if(mouseX > (WindowWidth/3) && mouseX < (WindowWidth*(2.0/3.0)) && mouseY > (WindowHeight/3) && mouseY < (WindowHeight*(2.0/3.0)) && gameTable[1][1] == 0) {
        gameTable[1][1] = sign;
    }
    else if(mouseX > (WindowWidth/3) && mouseX < (WindowWidth*(2.0/3.0)) && mouseY > (WindowHeight*(2.0/3.0)) && mouseY < WindowHeight && gameTable[1][0] == 0) {
        gameTable[1][0] = sign;
    }
    else if(mouseX > (WindowWidth*(2.0/3.0)) && mouseX < (WindowWidth) && mouseY > 0 && mouseY < (WindowHeight/3) && gameTable[2][2] == 0){
        gameTable[2][2] = sign;
    }
    else if(mouseX > (WindowWidth*(2.0/3.0)) && mouseX < (WindowWidth) && mouseY > (WindowHeight/3) && mouseY < (WindowHeight*(2.0/3.0)) && gameTable[2][1] == 0) {
        gameTable[2][1] = sign;
    }
    else if(mouseX > (WindowWidth*(2.0/3.0)) && mouseX < (WindowWidth) && mouseY > (WindowHeight*(2.0/3.0)) && mouseY < WindowHeight && gameTable[2][0] == 0) {
        gameTable[2][0] = sign;
    }
    glutPostRedisplay();
}

bool checkifwin(){
    for(int i = 0; i <= 2; i++){
        for(int j = 1; j <= 2; j++){
            if(gameTable[i][0] != 0 && gameTable[i][0] == gameTable[i][j]){
                if(j == 2){
                    return true;
                }
            }
            else{
                break;
            }
        }
    }
    for(int i = 0; i <= 2; i++){
        for(int j = 1; j <= 2; j++){
            if(gameTable[0][i] != 0 && gameTable[0][i] == gameTable[j][i]){
                if(j == 2){
                    return true;
                }
            }
            else{
                break;
            }
        }
    }
    for(int i = 1; i <= 2; i++){
        if(gameTable[0][0] != 0 && gameTable[0][0] == gameTable[i][i]){
            if(i == 2){
                return true;
            }
        }
        else{
            break;
        }
    }
    for(int i = 1; i <= 2; i++){
        if(gameTable[2][0] != 0 && gameTable[2][0] == gameTable[2 - i][i]){
            if(i == 2){
                return true;
            }
        }
        else{
            break;
        }
    }
    return false;
}

bool checkDraw(){
    for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            if(gameTable[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}