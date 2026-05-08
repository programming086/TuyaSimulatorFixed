
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartLogTrackHandleDelegate <NSObject>

- (void)logTrackStartWithAttribute:(NSDictionary *)attribute domesticExtensions:(NSDictionary *)extensions;

@required
- (void)logTrackStartWithAttribute:(NSDictionary *)attribute;

- (void)logTrackFullLinkWithAttribute:(NSDictionary *)attribute infos:(NSDictionary *)infos trackType:(NSString *)trackType;

- (void)logTrackDeviceWithAttribute:(NSDictionary *)attribute;
@end

@protocol ThingSmartLogTrackConfiguration <NSObject>

@required
@property (nonatomic, strong) NSString   *type;

@property (nonatomic, weak, nullable) id<ThingSmartLogTrackHandleDelegate> delegate;

@end

@interface ThingSmartLogTrackConfiguration : NSObject<ThingSmartLogTrackConfiguration>

@end

NS_ASSUME_NONNULL_END
