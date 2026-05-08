//
//  thingMatrix+MediaServices.h
//  ThingSmartMediaServices
//
//  Created by Aaron on 2022/4/26.
//

#ifndef thingMatrix_h
#define thingMatrix_h

#include <stdio.h>
#include <math.h>

typedef struct thingMatrix4 {
    float m[4][4];
} thingMatrix4;

void thingMatrixLoadIdentithing(thingMatrix4 * result);

void thingMatrixScale(thingMatrix4 * result, float sx, float sy, float sz);

void thingMatrixTranslate(thingMatrix4 * result, float tx, float ty, float tz);

void thingMatrixRotate(thingMatrix4 *result, float angle, float x, float y, float z);

void thingMatrixMultiply(thingMatrix4 *result, thingMatrix4 *srcA, thingMatrix4 *srcB);

#endif /* thingMatrix_h */

