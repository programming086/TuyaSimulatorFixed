

#ifndef ThingPixelBufferQueue_h
#define ThingPixelBufferQueue_h

#include <stdio.h>

typedef struct ThingFeatureRect {
    float x;
    float y;
    float width;
    float height;
} ThingFeatureRect;

ThingFeatureRect ThingFeatureRectMake(float x, float y, float width, float height);

typedef struct ThingPixelBufferItem {
    ThingFeatureRect rect;
    void *data;
} ThingPixelBufferItem;

typedef ThingPixelBufferItem * ThingPixelBufferItemRef;

typedef struct ThingPixelBufferQueue {
    int maxSize;
    int size;
    int front;
    int rear;
    void * datas[];
} ThingPixelBufferQueue;

typedef ThingPixelBufferQueue * ThingPixelBufferQueueRef;

void ThingPixelBufferItemCreate(ThingPixelBufferItemRef *pixelBufferItem, ThingFeatureRect rect, void *data);

void ThingPixelBufferItemRelease(ThingPixelBufferItemRef pixelBufferItem);

void ThingPixelBufferQueueCreate(ThingPixelBufferQueueRef *pixelBufferQueue, int maxSize);

void ThingPixelBufferQueueEnqueueOut(ThingPixelBufferQueueRef pixelBufferQueue, void *enBuffer, void **deBuffer);

int ThingPixelBufferQueueEnQueue(ThingPixelBufferQueueRef pixelBufferQueue, void *pixelBuffer);

int ThingPixelBufferQueueDeQueue(ThingPixelBufferQueueRef pixelBufferQueue, void **pixelBuffer);

int ThingPixelBufferQueueGetFront(ThingPixelBufferQueueRef pixelBufferQueue, void **pixelBuffer);

void ThingPixelBufferQueueClear(ThingPixelBufferQueueRef pixelBufferQueue);

void ThingPixelBufferQueueRelease(ThingPixelBufferQueueRef pixelBufferQueue);

#endif /* ThingPixelBufferQueue_h */
