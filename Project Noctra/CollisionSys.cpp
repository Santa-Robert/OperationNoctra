#include <stdio.h>
#include <iostream>
#include "tenuki.h"

using namespace std;

void collision(const float COLLISION_THICKNESS, bool& rightSurfaceCollision, bool& bottomSurfaceCollision, bool& topSurfaceCollision, bool& leftSurfaceCollision, float& XMovement,
float& YMovement, bool showHitBox, Texture& texture,
GLuint uniformModel, int scaleX, int scaleY, int offsetX, int offsetY,
int right, int left, int top, int bottom) {

    if (showHitBox == true) {
        spawnObj(0, XMovement + offsetX, YMovement + offsetY, 0.6f, 5.0f * scaleX, 5.0f * scaleY, 1.0f, texture, uniformModel);
    }

   
        if (XMovement >= right - COLLISION_THICKNESS && XMovement <= right + COLLISION_THICKNESS && YMovement >= top && YMovement <= bottom) { rightSurfaceCollision = true;  }
        else { rightSurfaceCollision = false; }

        if (YMovement >= top - COLLISION_THICKNESS && YMovement <= top + COLLISION_THICKNESS && XMovement >= left && XMovement <= right) {
            bottomSurfaceCollision = true; 
        }
        else { bottomSurfaceCollision = false; }

        if (YMovement >= bottom - COLLISION_THICKNESS && YMovement <= bottom + COLLISION_THICKNESS && XMovement >= left - 1 && XMovement <= right) {
            topSurfaceCollision = true; 
        }
        else { topSurfaceCollision = false; }

        if (XMovement >= left - COLLISION_THICKNESS && XMovement <= left + COLLISION_THICKNESS && YMovement >= top && YMovement <= bottom) { leftSurfaceCollision = true; }
        else { leftSurfaceCollision = false; }
   
   

    

}