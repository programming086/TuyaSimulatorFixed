
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMatterNodeModel : NSObject

@property (nonatomic, strong) NSString *devId;

@property (nonatomic, strong) NSString *fabricId;

@property (nonatomic, assign) long long nodeId;

@property (nonatomic, assign) BOOL control;

@end

NS_ASSUME_NONNULL_END
