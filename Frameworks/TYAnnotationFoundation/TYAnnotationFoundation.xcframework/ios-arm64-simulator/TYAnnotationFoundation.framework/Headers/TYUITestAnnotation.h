//
//  TYUITestAnnotation.h
//  TYAnnotationFoundation
//
//  Created by Storm on 2021/11/29.
//
#import "TYUITestContext.h"
#pragma mark TYAnnotation
#define TYUITestAnnotation(title,startBlock,testBlock) __TYUITestAnnotation(UITest,title,startBlock,testBlock)
#define TYUITestIDAnnotation(id,title,startBlock,testBlock) __TYUITestAnnotation(id,title,startBlock,testBlock)


#pragma mark TYAnnotationIMPL

typedef void(^TYAnnotationUITestLaunchTaskBlock)(TYUITestContext *);
typedef BOOL(^TYAnnotationUITestBlock)(NSInteger, TYUITestContext *);
typedef void(^TYAnnotationRegisterUITestBlock)(NSString *title, TYAnnotationUITestLaunchTaskBlock startBlock, TYAnnotationUITestBlock testBlock);

extern void setRegisterUITestBlock(TYAnnotationRegisterUITestBlock block);
extern NSArray *getUITestSectionData(void);

typedef struct __attribute__((packed)) {
    const char * title;
    TYAnnotationUITestLaunchTaskBlock startBlock;
    TYAnnotationUITestBlock testBlock;
} _TuyaMachRegisterUITestStruct;



#define __TYUITestAnnotation(id,title,startBlock,testBlock) \
static _TuyaMachRegisterUITestStruct  __##id __attribute__((used, section("__RouterSection, UITest"))) = {\
title,\
startBlock,\
testBlock\
};

@interface TYUITestAnnotationObject : NSObject
@property (strong)  NSString *title;
@property (copy)  TYAnnotationUITestLaunchTaskBlock startBlock;
@property (copy)  TYAnnotationUITestBlock testBlock;
@end


