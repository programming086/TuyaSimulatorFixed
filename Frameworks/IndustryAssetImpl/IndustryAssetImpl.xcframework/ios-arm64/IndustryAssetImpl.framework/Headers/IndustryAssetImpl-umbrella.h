#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "IndustryAsset.h"
#import "IndustryAssetAssociatedModel.h"
#import "IndustryAssetDevice.h"
#import "IndustryAssetDeviceListResult.h"
#import "IndustryAssetManager.h"
#import "IndustryAssetMessageServiceHandler.h"

FOUNDATION_EXPORT double IndustryAssetImplVersionNumber;
FOUNDATION_EXPORT const unsigned char IndustryAssetImplVersionString[];

