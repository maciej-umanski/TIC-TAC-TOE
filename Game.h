//
// Created by Maciej on 03.05.2020.
//

#ifndef BOXES_GAME_H
#define BOXES_GAME_H

#include <GL/gl.h>

void drawGrid();
void drawSquare(GLenum mode, int x, int y, float r, float g, float b, float lineWidth, float alpha);
void trackCursor(int x, int y);
void refreshGameTable();
void drawX(int x, int y, float r, float g, float b, float lineWidth);
void drawO(int x, int y, float r, float g, float b, float lineWidth);
void placeSign(int sign, int WindowWidth, int WindowHeight);
bool checkifwin();
bool checkDraw();


#endif //BOXES_GAME_H
