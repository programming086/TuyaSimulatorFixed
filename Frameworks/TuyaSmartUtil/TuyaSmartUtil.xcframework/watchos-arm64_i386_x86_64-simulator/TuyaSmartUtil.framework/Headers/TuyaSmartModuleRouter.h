//
//  TuyaSmartModuleRouter.h
//  TuyaSmartBaseKit
//
//  Created by 余豪 on 2021/12/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartModuleRouter : NSObject

+ (instancetype)router;

- (id)entryForProtocol:(Protocol *)protocol;

@end

NS_ASSUME_NONNULL_END
