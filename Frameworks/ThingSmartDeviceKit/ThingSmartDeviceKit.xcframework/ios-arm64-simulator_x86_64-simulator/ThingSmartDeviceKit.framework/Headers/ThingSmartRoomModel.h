//
//  ThingSmartRoomModel.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>

@interface ThingSmartRoomModel : NSObject

// The room ID.
@property (nonatomic, assign) long long roomId;

// The room icon.
@property (nonatomic, strong) NSString *iconUrl;

// The room name.
@property (nonatomic, strong) NSString *name;

// The order.
@property (nonatomic, assign) NSInteger displayOrder;


@end
