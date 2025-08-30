#include <stdio.h>
#include "tenuki.h"

using namespace std;

void battleHitBox(bool& canHit, Texture& texture, float& XMovement,
	float& YMovement, GLuint uniformModel, int scaleX, int scaleY, int offsetX, int offsetY,
	int right, int left, int top, int bottom, bool showHitBox) {
	
    if (showHitBox) {
        spawnObj(0, XMovement + offsetX, YMovement + offsetY, 0.6f, 5.0f * scaleX, 5.0f * scaleY, 1.0f, texture, uniformModel);
    }

    if (XMovement <= right && XMovement >= left && YMovement >= top && YMovement <= bottom) { canHit = true; }
    else { canHit = false; }

    

}