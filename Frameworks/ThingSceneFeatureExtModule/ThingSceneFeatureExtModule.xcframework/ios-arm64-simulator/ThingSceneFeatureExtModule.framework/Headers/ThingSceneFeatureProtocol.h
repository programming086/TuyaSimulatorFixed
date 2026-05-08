
#import <Foundation/Foundation.h>
#import "TSceneFeatureResultModel.h"

@class ThingSmartSceneModel;
@class ThingSmartSceneActionModel;

NS_ASSUME_NONNULL_BEGIN

typedef void(^TSceneFeatureCompletion)(TSceneFeatureResultModel *_Nullable result, NSError *_Nullable error);

@protocol ThingSceneFeatureProtocol <NSObject>

/// Create Scene
/// - Parameters:
///   - sceneModel: Scene model to be created
///   - completion: Callback after creation is complete, including validation of the resulting model and error messages
- (void)createSceneWithModel:(ThingSmartSceneModel *)sceneModel
                  completion:(TSceneFeatureCompletion)completion;

/// Edit Scene
/// - Parameters:
///   - sceneModel: Scene model to be edited
///   - oldActions: List of actions in the scene before editing
///   - completion: Callback after editing is complete, including validation of the resulting model and error messages
- (void)editSceneWithModel:(ThingSmartSceneModel *)sceneModel
                oldActions:(NSArray<ThingSmartSceneActionModel *> *)oldActions
                completion:(TSceneFeatureCompletion)completion;

/// Delete Scene
/// - Parameters:
///   - sceneModel: Scenes to be deleted
///   - completion: Callback after deletion is complete, including validation of the resulting model and error messages
- (void)deleteSceneWithModel:(ThingSmartSceneModel *)sceneModel
                  completion:(TSceneFeatureCompletion)completion;

@end

NS_ASSUME_NONNULL_END
