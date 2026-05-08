
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingSmartPlaybackEventSubType) {
    ThingSmartPlaybackEventSubTypeNormal,
    ThingSmartPlaybackEventSubTypeAI,
};

@protocol ThingSmartPlaybackEventProtocol <NSObject>

@property (nonatomic, copy, readonly) NSString *code;
@property (nonatomic, copy, readonly) NSString *codeDesc;
@property (nullable, nonatomic, copy, readonly) NSString *codeIconUrl;
@property (nonatomic, assign, readonly) NSInteger orderValue;
@property (nonatomic, assign, readonly) NSInteger switchState;
@property (nonatomic, assign, readonly) ThingSmartPlaybackEventSubType subType;

@property (nonatomic, assign, readonly) BOOL selected;

@property (nonatomic, assign, readonly) BOOL isCustomCode;

@property (nonatomic, assign, readonly) NSInteger startTime;

@property (nonatomic, assign, readonly) NSInteger endTime;

@end

@protocol ThingSmartPlaybackEventsProtocol <NSObject>

@property (nonatomic, assign, readonly) BOOL hasAIEvent;

@property (nonatomic, assign, readonly) NSInteger switchState;


// [^en]event description[$en]
@property (nonatomic, strong, readonly) NSString *describe;

// [^en]event start time[$en]
@property (nonatomic, assign, readonly) NSInteger startTime;

// [^en]event end time[$en]
@property (nonatomic, assign, readonly) NSInteger endTime;

// [^en]snapshot path[$en]
@property (nonatomic, strong, readonly) NSString *snapshotUrl;

@property (nonatomic, copy, readonly) NSString *encryptKey;

@property (nonatomic, copy, readonly) NSArray<id<ThingSmartPlaybackEventProtocol>> *events;

@property (nonatomic, assign, readonly) BOOL isEncypt;

@optional

- (void)selectPlaybackEvent:(id<ThingSmartPlaybackEventProtocol>)playbackEvent selected:(BOOL)selected;

@end



NS_ASSUME_NONNULL_END
