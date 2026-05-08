//
//  ThingLightingEnergyDeviceCategoryModel.h
//  ThingLightingEnergyConsumptionKit
//
//  Created by tong san on 2021/11/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingEnergyDeviceCategoryItemModel : NSObject

@property (nonatomic, strong) NSString *category;
@property (nonatomic, strong) NSString *iconUrl;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, assign) long amount;

@end

@interface ThingLightingEnergyDeviceCategoryModel : NSObject

@property (nonatomic, strong) NSString *projectId;
@property (nonatomic, assign) long total;
@property (nonatomic, assign) long online;
@property (nonatomic, assign) long offline;
@property (nonatomic, assign) long exception;
@property (nonatomic, assign) long bluetoothOffline; 
@property (nonatomic, strong) NSArray<ThingLightingEnergyDeviceCategoryItemModel *> *categoryList;

@end

NS_ASSUME_NONNULL_END
