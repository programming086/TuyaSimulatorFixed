//
//  ThingCLAreaDeviceListProtocol.h
//  ThingLampModuleServices
//
//  Created by 飞熊 on 2022/9/1.
//

#import <Foundation/Foundation.h>

@class ThingLightingAreaModel;

NS_ASSUME_NONNULL_BEGIN

@protocol ThingCLAreaDeviceListProtocol <NSObject>

@required

- (void)openAreaDeviceListVCWithTitle:(NSString *)title
                            areaModel:(ThingLightingAreaModel *)areaModel
                       filterByMeshId:(BOOL)filterByMeshId;

@end

NS_ASSUME_NONNULL_END
