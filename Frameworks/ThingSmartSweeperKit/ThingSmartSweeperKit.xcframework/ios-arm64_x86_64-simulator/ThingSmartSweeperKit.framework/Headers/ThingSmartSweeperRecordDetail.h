
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSweeperRecordDetail : NSObject

@property (copy, nonatomic) NSString *devId;
@property (copy, nonatomic) NSString *startRow;
@property (copy, nonatomic) NSArray<NSString*> *dataList;
@property (copy, nonatomic) NSString *subRecordId;
@property (assign, nonatomic) BOOL hasNext;
@property (assign, nonatomic) long long startTime;
@property (assign, nonatomic) long long endTime;

@end

NS_ASSUME_NONNULL_END
