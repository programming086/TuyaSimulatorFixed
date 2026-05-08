//
//  ThingGroupBeaconService+GroupHandle.h
//  ThingGroupHandleModule
//
//  Created by 后主 on 2023/9/19.
//

#import <ThingGroupManagerKit/ThingGroupBeaconService.h>
#import <ThingBluetoothInterface/ThingBluetoothInterface.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingGroupBeaconService (GroupHandle)

@property (nonatomic, strong, readonly) ThingBluetoothBleMeshGroup *meshGroup;

@end

NS_ASSUME_NONNULL_END
