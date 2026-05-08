
#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/// alarm action
@interface ThingSecurityAlarmOperationModel : NSObject

/// Action description
@property (nonatomic, copy) NSString *operationDescription;

/// Action type
@property (nonatomic, assign) NSInteger type;


@end

NS_ASSUME_NONNULL_END

