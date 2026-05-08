//
//  ThingSmartMultiControl.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>
#import "ThingSmartMultiControlLinkModel.h"
#import "ThingSmartMultiControlModel.h"
#import "ThingSmartMultiControlDpRelationModel.h"
#import "ThingSmartMultiControlDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMultiControl : NSObject

/// Queries the multi-control and automation functions that are associated with the specified device DP.
/// @param devId The main device ID.
/// @param dpId The DP ID.
/// @param success Called when the task is finished. ThingSmartMultiControlLinkModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)queryDeviceLinkInfoWithDevId:(NSString *)devId
                                dpId:(NSString *)dpId
                             success:(void (^)(ThingSmartMultiControlLinkModel *))success
                             failure:(ThingFailureError)failure;

/// Adds a multi-control group.
/// @param devId The main device ID.
/// @param groupName The group name.
/// @param groupDetail The multi-control group association details.
/// @param success Called when the task is finished. ThingSmartMultiControlModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)addMultiControlWithDevId:(NSString *)devId
                       groupName:(NSString *)groupName
                     groupDetail:(NSArray<ThingSmartMultiControlDetailModel *> *)groupDetail
                         success:(void (^)(ThingSmartMultiControlModel *))success
                         failure:(ThingFailureError)failure;

//// Updates the multi-control group.
/// @param devId The main device ID.
/// @param model The data model of the multi-control group.
/// @param success Called when the task is finished. ThingSmartMultiControlModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)updateMultiControlWithDevId:(NSString *)devId
                  multiControlModel:(ThingSmartMultiControlModel *)model
                            success:(void (^)(ThingSmartMultiControlModel *))success
                            failure:(ThingFailureError)failure;

/// Returns the DP information of attached devices, the associated multi-control, and the scene automation information.
/// @param devId The device ID.
/// @param success Called when the task is finished. ThingSmartMultiControlDpRelationModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)queryDeviceDpRelationWithDevId:(NSString *)devId
                               success:(void (^)(ThingSmartMultiControlDpRelationModel *))success
                               failure:(ThingFailureError)failure;


/// Enables or disables multi-control groups.
/// @param multiControlId The multi-control group ID.
/// @param enable A Boolean value that specifies whether to enable or disable the group.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)enableMultiControlWithMultiControlId:(NSString *)multiControlId
                                      enable:(BOOL)enable
                                     success:(ThingSuccessBOOL)success
                                     failure:(ThingFailureError)failure;


/// Queries a list of device IDs and device groups that support specific actions. The data is returned by home ID.
/// @param homeId The home ID.
/// @param success Called when the task is finished. A list of ThingSmartMultiControlDeviceModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getMultiControlDeviceListWithHomeId:(long long)homeId
                                    success:(void (^)(NSArray<ThingSmartMultiControlDeviceModel *> *))success
                                    failure:(ThingFailureError)failure;


/// Returns information about all DPs of the specified device.
/// @param devId The device ID.
/// @param success Called when the task is finished. A list of ThingSmartMultiControlDatapointModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getDeviceDpInfoWithDevId:(NSString *)devId
                         success:(void (^)(NSArray<ThingSmartMultiControlDatapointModel *> *))success
                         failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
