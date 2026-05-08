//
//  TYProtocolAnnotation.h
//  TYAnnotationFoundation
//
//  Created by Storm on 2021/11/29.
//

#pragma mark TYAnnotation

#import <UIKit/UIKit.h>
#import "TYRegisterLaunchProtocol.h"

#define TYLaunchBeforeType              "PreMain"
#define TYLaunchSyncType                "TaskSync"
#define TYLaunchSyncOtherThreadType     "TaskOther"

////+load之后，main之前
#define TYLaunchBeforeAnnotation(IMPL)  TYLaunchAnnotation(PreMain, IMPL)
////模块化启动后同步
#define TYLaunchSyncAnnotation(IMPL)  TYLaunchAnnotation(TaskSync, IMPL)
////模块化启动后非主线程同步执行
#define TYLaunchSyncOtherThreadAnnotation(IMPL)  TYLaunchAnnotation(TaskOther, IMPL)


#pragma mark TYAnnotationIMPL



typedef void(^_TYAnnotationLaunchBlock)(void);

typedef struct __attribute__((packed)) {
    const char * impl;
} _TuyaMachRegisterLaunchStruct;

#define TYLaunchAnnotation(NAME, IMPL) __TYLaunchAnnotation(NAME, IMPL)

#define __TYLaunchAnnotation(NAME, IMPL) \
static _TuyaMachRegisterLaunchStruct  __Launch__##Name __attribute__((used, section("__Launch, "#NAME))) = {\
#IMPL\
};

typedef void(^TYAnnotationRegisterLaunchBlock)(int privacy, id block);

extern NSArray *getLaunchSectionData(const char *type);


@interface TYLaunchTaskAnnotationObject:NSObject

@property (strong)  NSString *impl;

@end

