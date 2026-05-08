//
//  ThingGroupHandleModuleConstants.h
//  ThingGroupHandleModule
//
//  Created by 后主 on 2023/11/15.
//

#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingGroupDeviceFilter <NSObject>

- (BOOL)filter:(ThingSmartDeviceModel *)device;

@end


@interface ThingGroupRoomFilter : NSObject <ThingGroupDeviceFilter>

@property (nonatomic, copy) NSString *roomId;

- (instancetype)initWithRoomId:(NSString *)roomId;

@end



@interface ThingGroupHandleModuleRoom : NSObject
@property (nonatomic, copy) NSString *roomName;
@property (nonatomic, copy) NSString *roomId;
@end

@interface ThingGroupHandleModuleRoomGroup : NSObject
@property (nonatomic, copy) NSString *roomGroupName;
@property (nonatomic, copy) NSString *roomGroupId;
@property (nonatomic, strong) NSArray<ThingGroupHandleModuleRoom *> *rooms;
@end



@interface ThingGroupHandleModuleRoomRelation : NSObject
@property (nonatomic, strong) NSArray<ThingGroupHandleModuleRoomGroup *> *roomGroups;
@property (nonatomic, strong) NSArray<ThingGroupHandleModuleRoom *> *rooms;
@end


NS_ASSUME_NONNULL_END
