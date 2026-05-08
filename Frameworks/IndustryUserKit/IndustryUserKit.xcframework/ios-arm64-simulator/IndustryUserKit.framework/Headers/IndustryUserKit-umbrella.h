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

#import "IUser.h"
#import "IUserService.h"
#import "UserService.h"

FOUNDATION_EXPORT double IndustryUserKitVersionNumber;
FOUNDATION_EXPORT const unsigned char IndustryUserKitVersionString[];

