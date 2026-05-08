//
//  ThingGroupDeviceFilterCell.h
//  ThingGroupHandleModule
//
//  Created by 后主 on 2023/11/15.
//

#import <ThingFallLayout/ThingCollectionViewCell.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingGroupDeviceFilterCellItem : ThingCollectionReusableViewItem
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *roomId;
@property (nonatomic, assign) BOOL selected;
- (instancetype)initWithTitle:(NSString *)title roomId:(NSString *)roomId selected:(BOOL)selected;
@end

@interface ThingGroupDeviceFilterCell : ThingCollectionViewCell

@end

NS_ASSUME_NONNULL_END

