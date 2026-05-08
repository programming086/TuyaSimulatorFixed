//
//  TYProtocolAnnotation.h
//  TYAnnotationFoundation
//
//  Created by Storm on 2021/11/29.
//

#import "TYRegisterAPIProtocol.h"
#pragma mark TYAnnotation
//实现协议，即提供协议
//举例：TYRegisterApiAnnotation(TYLoginProtocol, TYLoginProtocolImpl)
//TYLoginProtocol是登录协议 TYLoginProtocolImpl是登录实现
#define TYRegisterAPIAnnotation(Protocol, IMPL) __TYInterfaceAnnotation(Protocol,IMPL)

//需要，可选协议。目前看可以只是用做脚本扫描，不需要记录数据到macho里面
//举例：TYRequireAPIAnnotation(TYLoginProtocol)
#define TYRequireAPIAnnotation(Protocol)
#define TYOptionalAPIAnnotation(Protocol)



#pragma mark TYAnnotationIMPL

extern NSMutableArray *getProtocolSectionData(void);

typedef struct __attribute__((packed)) {
    const char * protocol;
    const char * impl;
} _TuyaMachRegisterProtocolStruct;


#define __TYInterfaceAnnotation(Protocol,IMPL) \
static _TuyaMachRegisterProtocolStruct  __##Protocol __attribute__((used, section("__RouterSection, Protocol"))) = {\
#Protocol,\
#IMPL,\
};




