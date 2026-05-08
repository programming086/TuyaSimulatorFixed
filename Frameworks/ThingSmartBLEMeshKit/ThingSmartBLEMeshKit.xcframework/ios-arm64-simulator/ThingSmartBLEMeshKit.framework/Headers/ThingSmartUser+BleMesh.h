
#import <ThingSmartBaseKit/ThingSmartUser.h>
#import "ThingSmartBleMesh.h"

NS_ASSUME_NONNULL_BEGIN

/// @brief The mesh information category for a user.
@interface ThingSmartUser (BleMesh)

@property (nonatomic, strong) ThingSmartBleMeshModel *meshModel;

@property (nonatomic, strong, nullable) ThingSmartBleMesh *mesh;

@end

NS_ASSUME_NONNULL_END
