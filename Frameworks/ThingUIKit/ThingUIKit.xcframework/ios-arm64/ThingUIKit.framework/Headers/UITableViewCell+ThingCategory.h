//
//  UITableViewCell+CornerRadius.h
//  AFNetworking
//
//  Created by 尼奥 on 2025/5/9.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UITableViewCell (ThingCategory)

/**
 Configures the cell's rounded corners based on its position within a table view section.
 
 @param row The current row index of the cell within its section (0-based)
 @param count The total number of rows in the section
 @param cornerRadius The radius value to apply to the corners
 
 @return The configured cell (self) to allow method chaining
 
 @discussion This method applies rounded corners to cells to create grouped appearance:
 - For a single cell in section: all corners are rounded
 - For the first cell in section: only top corners are rounded
 - For the last cell in section: only bottom corners are rounded
 - For middle cells: no corners are rounded
 
 @note Remember to set appropriate background colors for the cell and its selectedBackgroundView
 */
- (UITableViewCell *)thing_configureRoundedCornersForRow:(NSInteger)row
                                      totalRowsInSection:(NSInteger)count
                                            cornerRadius:(CGFloat)cornerRadius;

@end

NS_ASSUME_NONNULL_END
