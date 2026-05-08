
#import <Foundation/Foundation.h>

@class ThingCameraAIDetectEventModel;

NS_ASSUME_NONNULL_BEGIN

@interface ThingCameraAIDetectConfigModel : NSObject


@property (nonatomic, assign) BOOL isAiDevice;

@property (nonatomic, assign) BOOL supportCustomCode;

@property (nonatomic, assign) NSInteger switchState;


@property (nonatomic, strong) NSArray<ThingCameraAIDetectEventModel *> *aiItemList;

- (ThingCameraAIDetectConfigModel *)initAIDetectConfigModel:(NSDictionary *)dic;

@end


@interface ThingCameraAIDetectEventModel : NSObject

@property (nonatomic, copy) NSString *aiCode;

@property (nonatomic, copy) NSString *aiCodeIcon;

@property (nonatomic, copy) NSString *aiCodeDesc;

@property (nonatomic, assign) NSInteger configState;

@property (nonatomic, assign) NSInteger orderValue;

+ (NSArray<ThingCameraAIDetectEventModel *> *)createAIDetectConfigModel:(NSArray *)array;

@end

NS_ASSUME_NONNULL_END
