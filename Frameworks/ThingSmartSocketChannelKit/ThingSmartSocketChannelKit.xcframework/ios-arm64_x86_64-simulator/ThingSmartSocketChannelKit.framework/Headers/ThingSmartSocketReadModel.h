
#import <Foundation/Foundation.h>

//NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSocketReadModel : NSObject <NSCopying>

@property (nonatomic, assign) int               index; // The sequence number.
@property (nonatomic, assign) int               type; // The protocol.
@property (nonatomic, assign) int               code; // The success code.
@property (nonatomic, strong) NSDictionary      *body; // The message.
@property (nonatomic, strong) NSString          *error; // An error occurs while processing the request.
@property (nonatomic, strong) NSData            *data;

// Decrypts TCP data.
+ (NSArray <ThingSmartSocketReadModel *> *)tcpResponseWithData:(NSData *)data gwId:(NSString *)gwId lpv:(NSString *)lpv localKey:(NSString *)localKey localKeyData:(NSData *)localKeyData;

// Decrypts UDP data.
+ (NSArray <ThingSmartSocketReadModel *> *)udpResponseWithData:(NSData *)data;

- (NSDictionary *)attribute;

@end

//NS_ASSUME_NONNULL_END
