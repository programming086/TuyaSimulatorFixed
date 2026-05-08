
#import <Foundation/Foundation.h>

#import "ThingSmartPlaybackEventProtocol.h"

@class ThingSmartAICloudTimePieceModel;

@interface ThingSmartAIAnalyzeModel : NSObject

@property (nonatomic, copy) NSString *aiCode;


@property (nonatomic, assign) NSInteger startTime;


@property (nonatomic, assign) NSInteger endTime;


@property (nonatomic, strong) id prefix;

@end

@interface ThingSmartCloudDayModel : NSObject

// [^en]video total length, (seconds).[$en]
@property (nonatomic, assign) NSInteger sumDuration;

// [^en]date, yyyy-MM-dd[$en]
@property (nonatomic, strong) NSString *uploadDay;

// [^en]unix timestamp of 00:00[$en]
@property (nonatomic, assign) NSInteger startTime;

// [^en]unix timestamp of 23:59[$en]
@property (nonatomic, assign) NSInteger endTime;

@property (nonatomic, assign) BOOL hasNoData;

- (instancetype)initWithDict:(NSDictionary *)dict;

+ (NSArray<ThingSmartCloudDayModel *> *)modelsWithDictArray:(NSArray<NSDictionary *> *)dictArray;

@end

@interface ThingSmartAIEventModel : NSObject <ThingSmartPlaybackEventProtocol>

@property (nonatomic, copy) NSString *aiCode;

@property (nonatomic, copy) NSString *aiCodeDesc;

@property (nonatomic, copy) NSString *aiCodeIcon;

@property (nonatomic, assign) NSInteger startTime;

@property (nonatomic, assign) NSInteger endTime;

@property (nonatomic, assign) NSInteger orderValue;

@property (nonatomic, assign) BOOL selected;

- (ThingSmartAIEventModel *)initAIEventModel:(NSDictionary *)dic;

+ (NSArray<ThingSmartAIEventModel *> *)modelsWithDictArray:(NSArray<NSDictionary *> *)dictArray;
@end

@interface ThingSmartCloudTimeEventModel : NSObject <ThingSmartPlaybackEventsProtocol>

// [^en]event description[$en]
@property (nonatomic, strong) NSString *describe;

// [^en]event start time[$en]
@property (nonatomic, assign) NSInteger startTime;

// [^en]event end time[$en]
@property (nonatomic, assign) NSInteger endTime;

// [^en]snapshot path[$en]
@property (nonatomic, strong) NSString *snapshotUrl;

@property (nonatomic, strong) NSArray<ThingSmartAIEventModel *> *aiDetectList;

- (instancetype)initWithDict:(NSDictionary *)dict;

@property (nonatomic, assign) BOOL isEncypt;

+ (NSArray<ThingSmartCloudTimeEventModel *> *)modelsWithDictArray:(NSArray<NSDictionary *> *)dictArray;

- (void)selectPlaybackEvent:(ThingSmartAIEventModel *)playbackEvent selected:(BOOL)selected;

@end

@interface ThingSmartCloudTimePieceModel : NSObject

// [^en]video start time[$en]
@property (nonatomic, assign) NSInteger startTime;

// [^en]start date[$en]
@property (nonatomic, strong) NSDate *startDate;

// [^en]video end time[$en]
@property (nonatomic, assign) NSInteger endTime;

// [^en]end date[$en]
@property (nonatomic, strong) NSDate *endDate;

// [^en]start play time[$en]
@property (nonatomic, assign) NSInteger playTime;

// [^en]prefix[$en]
@property (nonatomic, strong) id prefix;

@property (nonatomic, assign) NSInteger videoType;

- (instancetype)initWithDict:(NSDictionary *)dict;

+ (NSArray<ThingSmartCloudTimePieceModel *> *)modelsWithDictArray:(NSArray<NSDictionary *> *)dictArray;

@property (nonatomic, strong) NSArray<ThingSmartAICloudTimePieceModel *> *aiDetectList;

@end

@interface ThingSmartAICloudTimePieceModel : ThingSmartCloudTimePieceModel

@property (nonatomic, copy) NSString *aiCode;

+ (NSArray<ThingSmartAICloudTimePieceModel *> *)aiModelsWithDictArray:(NSArray<NSDictionary *> *)dictArray;

@end


