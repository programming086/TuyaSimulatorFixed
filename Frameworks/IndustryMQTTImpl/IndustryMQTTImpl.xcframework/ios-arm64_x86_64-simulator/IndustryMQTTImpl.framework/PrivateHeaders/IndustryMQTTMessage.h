//
//  IndustryMQTTMessage.h
//  IndustryMQTTImpl
//
//  Created by ChenKun on 2023/5/9.
//

#import <Foundation/Foundation.h>
@import IndustryMQTTKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustryMQTTMessage : NSObject<IMQTTMessage>

@property (nonatomic, copy) NSString *devId;
@property (nonatomic, strong) id message;  // The mesh array.
@property (nonatomic, assign) NSInteger number; // The protocol number.
@property (nonatomic, copy) NSString *type;
@property (nonatomic, assign) NSInteger responseS; // The sequence.
@property (nonatomic, assign) NSInteger responseR; // The response ID.
@property (nonatomic, assign) NSTimeInterval time;

@end

NS_ASSUME_NONNULL_END
