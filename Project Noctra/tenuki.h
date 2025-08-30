#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include <stdio.h>
#include <iostream>

#include "Texture.h"

extern Texture a, b, c, d, e, f, g, h, iL, j, k, l, m;
extern Texture n, o, p, q, r, s, t, u, v, w, x, y, z;
extern Texture singleQuote, comma;

void spawnObj(int meshNum,
    int transX, float transY, float transZ,
    float scaleX, float scaleY, float scaleZ,
    Texture& texture,
    GLuint uniformModel);

void readString(const std::string& str, GLint uniformModel);

void initTextures();

void collision(
    const float COLLISION_THICKNESS,
    bool& rightSurfaceCollision,
    bool& bottomSurfaceCollision,
    bool& topSurfaceCollision,
    bool& leftSurfaceCollision,
    float& XMovement,
    float& YMovement,
    bool showHitBox,
    Texture& texture,
    GLuint uniformModel,
    int scaleX,
	int scaleY,
	int offsetX,
	int offsetY,
    int right, int left, int top, int bottom
);

void battleHitBox(bool& canHit, Texture& texture, float& XMovement,
    float& YMovement, GLuint uniformModel, int scaleX, int scaleY, int offsetX, int offsetY,
    int right, int left, int top, int bottom, bool showHitBox);

