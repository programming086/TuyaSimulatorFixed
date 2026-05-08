
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingMatterMultipleFabricPasscodeModel : NSObject


@property (nonatomic, assign)NSUInteger limitCount;
/**
         * Setup Code， 000000001-99999998
*/
@property (nonatomic, assign)NSUInteger passcode;
/**
        * PBKDF_Iterations， 1000~100000
        */
@property (nonatomic, assign)NSUInteger iteration;

       /**
        * passcode
        */
@property (nonatomic, assign)NSUInteger expired;

       /**
        * 180~900，s
        */
@property (nonatomic, assign)NSUInteger duration;

       /**
        *  0x000-0xfff
        */
@property (nonatomic, assign)NSUInteger  discriminator;

@property (nonatomic, assign)NSUInteger  version;
       /**
        * matter vid
        */
@property (nonatomic, assign)NSUInteger  vendorId;
       /**
        * matter pid
        */
@property (nonatomic, assign)NSUInteger  pid;

@property (nonatomic, assign)NSUInteger  discoveryCapabilities;


@end

NS_ASSUME_NONNULL_END
