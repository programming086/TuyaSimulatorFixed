
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSocketWriteModel : NSObject <NSCopying, NSMutableCopying>

@property (nonatomic, strong) NSString          *gwId;
@property (nonatomic, assign) BOOL              encrypt;

@property (nonatomic, assign) int               index; // The sequence number.
@property (nonatomic, assign) int               type; // The protocol.
@property (nonatomic, strong) NSString          *lpv; // The version.
@property (nonatomic, strong) NSDictionary      *body; // The body.
@property (nonatomic, strong) NSString          *localKey; // The local key.
@property (nonatomic, strong) NSData            *data; // The data.
@property (nonatomic, strong) NSData            *localKeyData; // The local key.


@property (nonatomic, copy) ThingSuccessDict       successBlock;
@property (nonatomic, copy) ThingFailureError      failureErrorBlock;
@property (nonatomic, copy) ThingFailureHandler    failureBlock;

// Encrypts data.
- (NSData *)buildRequestData;

- (NSDictionary *)attributes;

// Encrypts data.
+ (NSData *)buildRequestUDPDataWithType:(int)type
                                   body:(NSDictionary *)body
                                    lpv:(NSString *)lpv;

@end

NS_ASSUME_NONNULL_END
