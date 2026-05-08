//
//  LimitedCVPixelBufferPool.h
//  ThingCameraSDK
//
//  Created by pipu on 2023/3/3.
//

#ifndef LimitedCVPixelBufferPool_hpp
#define LimitedCVPixelBufferPool_hpp

#include <CoreFoundation/CoreFoundation.h>
#include <CoreVideo/CoreVideo.h>
#include <queue>
#include <stdio.h>
#include <mutex>

class LimitedCVPixelBufferPool {
public:
    LimitedCVPixelBufferPool(int width, int height, int pixelfmt);

    ~LimitedCVPixelBufferPool();

    CVPixelBufferRef GetPixelBuffer();

    void ReleasePixelBuffer(CVPixelBufferRef pixelBuffer);
    
    int width() {
        return width_;
    };
    int height() {
        return height_;
    }
    
 private :
    CFMutableDictionaryRef gen_pixelbuffer_attributes();
    CFDictionaryRef gen_pixelbuffer_pool_attributes();
    //static void bufferReleased(void *releaseRefCon, void *baseAddress);
    int width_;
    int height_;
    int pixelfmt_;
    int min_buffer_count_;
    int max_buffer_count_;
    CVPixelBufferPoolRef pixelbuffer_pool_; 
    std::queue<CVPixelBufferRef> bufferQueue_;
    std::mutex mutex_;
};




#endif /* LimitedCVPixelBufferPool_h */
