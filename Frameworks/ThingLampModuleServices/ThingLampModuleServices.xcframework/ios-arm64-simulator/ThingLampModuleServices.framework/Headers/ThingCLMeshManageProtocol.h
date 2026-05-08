//
//  ThingCLMeshManageProtocol.h
//  ThingCLMeshManageModule
//
//  Created by 凌晨 on 2022/8/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingCLMeshManageProtocol <NSObject>

- (void)gotoMeshManage;

- (void)gotoMeshConfigWithAreaId:(NSInteger)areaId;

@end

NS_ASSUME_NONNULL_END
