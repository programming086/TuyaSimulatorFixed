
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSweeperP2PIndexItemModel : NSObject
/// Unique identifier
@property (nonatomic, assign) NSInteger idx;

@property (nonatomic, assign) NSInteger channel;
/// File type, 0: Image, 2: mp4,  3: Panoramic stitching file
@property (nonatomic, assign) NSInteger type;
/// 0: File, 1: Folder. Reserved fields, currently all are 0
@property (nonatomic, assign) NSInteger dir;
@property (nonatomic, strong) NSString *filename;
@property (nonatomic, assign) NSInteger createTime;
@property (nonatomic, assign) NSInteger duration;
@end

NS_ASSUME_NONNULL_END
