
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSecurityModeModel : NSObject

@property (nonatomic, copy) NSString *mode;
@property (nonatomic, copy) NSString *uid;
@property (nonatomic, copy) NSString *stage;//pre/switching/done
@property (nonatomic, assign) NSTimeInterval enterTime;
@property (nonatomic, strong) NSArray *states;
@property (nonatomic, copy) NSString *sid;


@end

NS_ASSUME_NONNULL_END
