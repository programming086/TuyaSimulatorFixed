//
//  ThingFeedBackProtocol.h
//  ThingModuleServices
//
//  Created by ThingInc on 2018/7/11.
//

#import <Foundation/Foundation.h>

@protocol ThingFeedBackProtocol <NSObject>

@optional

/**
 * Jump to Feedback Page

 *@param hdType      Type of feedback
 *@param hdId           device ID
 *@param uuid           uuid
 *@param region       Area code
 *@param need           Whether to refresh the feedback list page
 *@discussion hdType = 8 indicates an unbundled page
 **/
- (void)gotFeedBackViewControllerWithHdType:(NSInteger)hdType deviceName:(NSString *)deviceName hdId:(NSString *)hdId uuid:(NSString *)uuid region:(NSString *)region withoutRefresh:(BOOL)need;

@end
