
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartBLELockRecordModel : NSObject

@property (nonatomic, strong) NSString *dpId;
@property (nonatomic, strong) NSString *userName;
@property (nonatomic, strong) NSString *avatarUrl;
@property (nonatomic, assign) NSTimeInterval time;

@end

NS_ASSUME_NONNULL_END
