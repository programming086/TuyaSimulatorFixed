//
//  ThingMallInfo.h
//  ThingModuleServices
//
//  Created by TuyaInc on 2023/6/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingMallInfo : NSObject

+ (ThingMallInfo *)errorRequestMallInfo;

// Mall order page can use
- (BOOL)enableOrder;

// Order page
- (NSString *_Nullable)orderURL;



// Mall main page can use
- (BOOL)enableMall;

// Mall main page
- (NSString *_Nullable)mallURL;

@end

NS_ASSUME_NONNULL_END
