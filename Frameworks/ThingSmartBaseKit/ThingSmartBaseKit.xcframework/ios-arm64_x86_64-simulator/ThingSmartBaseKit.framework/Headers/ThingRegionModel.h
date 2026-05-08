
#ifndef ThingRegionModel_h
#define ThingRegionModel_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief ThingRegionModel is an object of server region.
@interface ThingRegionModel : NSObject

/// The region name.
@property (nonatomic, strong) NSString *name;

/// The region code.
@property (nonatomic, strong) NSString *region;

/// Indicates whether the region is the default region.
@property (nonatomic, assign) BOOL isDefault;

@end

NS_ASSUME_NONNULL_END

#endif /* ThingRegionModel_h */
