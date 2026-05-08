
#import <Foundation/Foundation.h>

#import "ThingSearchBarAppearance.h"
#import "ThingSearchTableCustomProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSearchControllerAppearance : NSObject

@property (nonatomic, strong) ThingSearchBarAppearance *searchBarAppearance;

@property (nonatomic) UIEdgeInsets searchBarBoundsInsets;

@property (nonatomic, strong) Class<ThingSearchTableCustomProtocol> searchTableClass;
@property (nonatomic, strong) UIColor *searchTableBackgroundColor;

+ (instancetype)appearance;

@end

NS_ASSUME_NONNULL_END
