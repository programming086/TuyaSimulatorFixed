
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartBeaconMeshModel : NSObject
@property (nonatomic, strong) NSString *id;
@property (nonatomic, strong) NSString *networkKey;
@property (nonatomic, strong) NSString *appKey;
@property (nonatomic, strong) NSString *meshKey;
@property (nonatomic, strong) NSString *localKey;
@property (nonatomic, assign) long long ownerId;
@property (nonatomic, strong) NSString *meshId;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *name;

@end

NS_ASSUME_NONNULL_END
