//
//  ThingSettingsProtocol.h
//  ThingModuleServices
//
//  Created by 吴戈 on 2019/1/9.
//

#import <Foundation/Foundation.h>

@protocol ThingSettingsProtocol <NSObject>

@optional

/**
 * 检查是否用户是否开启声音
 */
- (BOOL)soundEnabled;

@end

