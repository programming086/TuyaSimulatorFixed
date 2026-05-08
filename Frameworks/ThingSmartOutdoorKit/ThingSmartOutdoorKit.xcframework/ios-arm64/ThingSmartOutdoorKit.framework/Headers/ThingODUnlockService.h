
#import <ThingSmartNetworkKit/ThingSmartNetworkKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ThingODAliasInfoType) {
    ThingODAliasInfoType_Card = 1 << 0, //
    ThingODAliasInfoType_Password = 1 << 1,
} NS_SWIFT_NAME(AliasInfoType);

NS_SWIFT_NAME(UnlockAliasModel)
@interface ThingODUnlockAliasModel : NSObject

@property (nonatomic, copy) NSDictionary<NSString *, NSString *> *cardAliasInfo; /// key:serial  value:alias
@property (nonatomic, copy) NSDictionary<NSString *, NSString *> *passwordAliasInfo; /// key:serial  value:alias

@end

NS_SWIFT_NAME(UnlockService)
@interface ThingODUnlockService : ThingSmartRequest

- (void)updateAliasInfo:(NSDictionary<NSString *, NSString *> *)aliasInfo deviceID:(NSString *)deviceID aliasType:(ThingODAliasInfoType)aliasType
             completion:(void (^)(BOOL result, NSError *error))completion;


- (void)fetchAliasInfoWithAliasType:(ThingODAliasInfoType)aliasType deviceID:(NSString *)deviceID
                         completion:(void (^)(ThingODUnlockAliasModel *aliasModel, NSError *error))completion;


@end

NS_ASSUME_NONNULL_END
