//
//  Header.h
//  Pods
//
//  Created by Goko on 2018/7/6.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void(^DoneActionBlock)(NSString *changedName);

/// Family Management Service
@protocol ThingFamilyProtocol <NSObject>

@optional

/// jump to Family Management ViewController
- (void)gotoFamilyManagement;

/// update current family id , make sure call this method whenever you change the current family id
- (void)updateCurrentFamilyId:(long long)familyId;

/// get current family id , you can create a `ThingSmartHome` instance by calling the class method `[ThingSmartHome homeWithHomeId:currentFamilyId]`.
- (long long)currentFamilyId;

/// clear current family id cache
- (void)clearCurrentFamily;

/// Whether to restrict administrator rights
- (BOOL)checkAdminAndRightLimit:(BOOL)alert;
- (BOOL)checkAdminAndRightLimit:(BOOL)alert withHomeId:(long long)homeId;

@end
