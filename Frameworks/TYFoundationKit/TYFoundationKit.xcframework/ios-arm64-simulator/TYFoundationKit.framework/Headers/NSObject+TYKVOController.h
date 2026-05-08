//
//  NSObject+TYKVOController.h
//  AFNetworking
//
//  Created by 尼奥 on 2020/7/24.
//

#import <Foundation/Foundation.h>

#import "TYKVOController.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Category that adds built-in `KVOController` and `KVOControllerNonRetaining` on any instance of `NSObject`.

 This makes it convenient to simply create and forget a `TYKVOController`, 
 and when this object gets dealloc'd, so will the associated controller and the observation info.
 */
@interface NSObject (TYKVOController)

/**
 @abstract Lazy-loaded TYKVOController for use with any object
 @return TYKVOController associated with this object, creating one if necessary
 @discussion This makes it convenient to simply create and forget a TYKVOController, and when this object gets dealloc'd, so will the associated controller and the observation info.
 */
@property (nonatomic, strong) TYKVOController *ty_KVOController;

/**
 @abstract Lazy-loaded TYKVOController for use with any object
 @return TYKVOController associated with this object, creating one if necessary
 @discussion This makes it convenient to simply create and forget a TYKVOController.
 Use this version when a strong reference between controller and observed object would create a retain cycle.
 When not retaining observed objects, special care must be taken to remove observation info prior to deallocation of the observed object.
 */
@property (nonatomic, strong) TYKVOController *ty_KVOControllerNonRetaining;

@end

NS_ASSUME_NONNULL_END
