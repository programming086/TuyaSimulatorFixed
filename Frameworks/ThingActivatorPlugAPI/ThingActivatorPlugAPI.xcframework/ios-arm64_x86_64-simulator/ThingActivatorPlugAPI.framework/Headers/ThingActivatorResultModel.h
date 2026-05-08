
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingActivatorResultModel : NSObject

@property (nonatomic, copy) NSString *iconUrl; ///< Device icon URL
@property (nonatomic, copy) NSString *name; ///< Device name
@property (nonatomic, strong) NSString *devId; ///< Device ID
@property (nonatomic, strong) NSString *uuid;
@property (nonatomic, strong) NSString *parentId; ///< Parent ID

@property (nonatomic, copy) NSError *error; ///< Error information
@property (nonatomic, strong) id otherParam; ///< Used to store the original device model


@end


NS_ASSUME_NONNULL_END
