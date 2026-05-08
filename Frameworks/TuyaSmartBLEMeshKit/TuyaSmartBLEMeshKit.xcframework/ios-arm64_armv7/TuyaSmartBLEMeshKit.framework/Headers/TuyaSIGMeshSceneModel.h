//
//  TuyaSIGMeshSceneModel.h
//  TuyaSmartBLEMeshKit
//
//  Created by liuguang on 2021/11/29.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, TuyaSIGMeshSceneHandleType){
    TuyaSIGMeshSceneHandleTypeAdd,
    TuyaSIGMeshSceneHandleTypeDelete,
    TuyaSIGMeshSceneHandleTypeExe
};

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSIGMeshSceneModel : NSObject

/// Operation type
@property (nonatomic, assign) TuyaSIGMeshSceneHandleType type;

/// SceneId
@property (nonatomic, assign)  unsigned int sceneId;

///  The local short address(Hexadecimal string) of groups.
@property (nonatomic, strong) NSString *localId;

/// Node ID of the scenario to be distributed
@property (nonatomic, strong) NSString *nodeId;

/// A collection of node ID that you want to delete and execute scenarios
@property (nonatomic, strong) NSArray *sceneNodeIds;

/// Dp set to be distributed to the device
@property (nonatomic, strong) NSDictionary *dps;

@end

NS_ASSUME_NONNULL_END
