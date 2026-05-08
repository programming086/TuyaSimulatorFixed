//
//  IotContainer.h
//  IotContainer
//
//  Created by 后主 on 2022/5/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define ContainerRegister(prot) \
+ (void)load {\
    [IotContainer.shareInstance registerCls:self forProtocol:@protocol(prot)];\
}

@protocol IotContainerInitialize <NSObject>
+ (instancetype)shareInstance;
@end


@interface IotContainer : NSObject

+ (instancetype)shareInstance;

- (void)registerCls:(nullable Class)cls forProtocol:(nonnull Protocol *)protocol;

- (void)deRegisterProtocol:(nonnull Protocol *)protocol;

- (nullable Class)clsForProtocol:(nonnull Protocol *)protocol;

- (id)instanceForProtocol:(nonnull Protocol *)protocol;

@end

NS_ASSUME_NONNULL_END
