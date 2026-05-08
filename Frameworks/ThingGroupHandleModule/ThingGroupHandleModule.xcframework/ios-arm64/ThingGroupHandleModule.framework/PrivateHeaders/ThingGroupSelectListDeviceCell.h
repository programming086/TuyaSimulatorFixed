//
//  ThingBleMeshAddGroupDeviceCell.h
//  ThingSmartKitExample
//
//  Created by XuChengcheng on 2017/8/18.
//  Copyright © 2017年 thing. All rights reserved.
//

#import <ThingSmartBusinessLibrary/TPBaseTableViewCell.h>

@interface ThingGroupSelectListDeviceCellModel : NSObject

/// The device ID.
@property(nonatomic,strong) NSString    *devId;

/// The URL of the device icon.
@property(nonatomic,strong) NSString    *iconUrl;

/// The product ID.
@property(nonatomic,strong) NSString    *productId;

/// Indicates whether the device is selected.
@property(nonatomic,assign) BOOL        checked;

/// The device name.
@property(nonatomic,strong) NSString    *name;

@property (nonatomic, assign) BOOL isAlwaysSelectable;
@property (nonatomic, assign) BOOL isLowPowerDevice;

@end

@interface ThingGroupSelectListDeviceCell : ThingTableViewCell

@property (nonatomic, strong, readonly) ThingGroupSelectListDeviceCellModel *cellModel;

- (void)setItem:(ThingGroupSelectListDeviceCellModel *)item;

@end
