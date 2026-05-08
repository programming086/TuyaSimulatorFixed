//
//  IndustryActivatorQRCodeReportResult.h
//  IndustryActivatorImpl
//
//  Created by 后主 on 2022/8/12.
//

#import <Foundation/Foundation.h>

@import IndustryActivatorKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustryActivatorQRCodeReportActionData : NSObject

@property (nonatomic, copy) NSString *ID;

@property (nonatomic, copy) NSString *uuid;

@end



@interface IndustryActivatorQRCodeReportResult : NSObject

@property (nonatomic, copy) NSString *actionName;

@property (nonatomic, strong) IndustryActivatorQRCodeReportActionData *actionData;

@end

NS_ASSUME_NONNULL_END
