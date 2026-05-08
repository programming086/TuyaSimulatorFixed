//
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartMiniAppBizBundle : NSObject



/// 通过miniProgramId打开小程序
/// @param miniProgramId 小程序id
/// @param extraParams 额外参数
+ (void)openMiniProgramWithId:(nonnull NSString *)miniProgramId
                  extraParams:(nullable NSDictionary *)extraParams;


/// 通过路由打开小程序
/// @param miniProgramRoute 小程序路由
/// @param extraParams 额外参数
+ (void)openMiniProgramWithRoute:(nonnull NSString *)miniProgramRoute
                     extraParams:(nullable NSDictionary *)extraParams;



// 打开扫码控制器
+ (void)openScan;


//清理缓存
+ (void)cleanMiniProgramsCache;

@end

NS_ASSUME_NONNULL_END
