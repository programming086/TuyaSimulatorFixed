
#import <Foundation/Foundation.h>

#define ThingNotifyName(sel) NSStringFromSelector(@selector(sel))

@protocol ThingModuleNotifyRegisterProtocol <NSObject>

@optional

/**
 * Returns the list of notification selector names that this module can respond to.
 *
 * This method should return an array of strings, where each string is a notification name or a method 
 * selector string that the module is designed to handle. The returned array allows the module to declare 
 * which notifications it is interested in or capable of processing.
 *
 * @return An array of notification names or method selector strings (e.g., @[NSStringFromSelector(@selector(xxx))] 
 *         or @[ThingNotifyName(xxx)]).
 */
- (NSArray<NSString *> *)registRespondsNotifies;

@end
