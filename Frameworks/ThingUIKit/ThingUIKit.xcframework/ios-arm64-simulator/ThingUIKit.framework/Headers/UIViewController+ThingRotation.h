//
//  UIViewController+ThingRotation.h
//  ThingUIKit
//
//  Created by ThingInc on 2019/12/12.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (ThingRotation)

/**
 [^en]
 rotate window when window orientation is not supported and -shouldAutorotate return YES
 [$en]
 */
- (void)thing_rotateWindowIfNeed;


/**
 [^en]
 callback when window rotates because the view controller does not support it's orientation
 automatically matches -supportedInterfaceOrientations by default
 [$en]
 
 @return [^en]the orientation you want[$en]
 */
- (UIInterfaceOrientation)thing_preferredOrientationForWindowRotation;

/**
 Rotate to the specified direction
*/
- (BOOL)thing_rotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;

@end

NS_ASSUME_NONNULL_END
