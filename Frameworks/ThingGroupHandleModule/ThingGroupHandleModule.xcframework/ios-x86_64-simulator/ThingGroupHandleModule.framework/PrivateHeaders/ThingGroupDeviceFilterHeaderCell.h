//
//  ThingGroupDeviceFilterHeaderCell.h
//  ThingGroupHandleModule
//
//  Created by 后主 on 2023/11/15.
//

#import <ThingFallLayout/ThingCollectionViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingGroupDeviceFilterHeaderCellItem : ThingCollectionReusableViewItem
@property (nonatomic, copy) NSString *title;
- (instancetype)initWithTitle:(NSString *)title;
@end

@interface ThingGroupDeviceFilterHeaderCell : ThingCollectionViewCell

@end

NS_ASSUME_NONNULL_END
