
#import <Foundation/Foundation.h>
#import "ThingSmartMessageDNDTimerModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @class ThingSmartMessageDNDListEntity
 * @brief Entity for managing Do Not Disturb (DND) data lists.
 *
 * This class provides properties to store and manage DND periods, including
 * weekly periodic DND periods and one-time DND periods. It also includes
 * readonly model lists for accessing structured DND data.
 *
 * Note: `periodDNDList` and `periodDNDModelList` represent the same data,
 * with `periodDNDList` being the raw dictionary format and `periodDNDModelList`
 * being the structured model format.
 */
@interface ThingSmartMessageDNDListEntity : NSObject

/**
 * An array that stores weekly periodic do-not-disturb periods as dictionaries.
 * This is the raw representation of the data.
 */
@property (nonatomic, copy, nullable) NSArray<NSDictionary *> *periodDNDList;

/**
 * An array that stores one-time do-not-disturb periods as dictionaries.
 * This is the raw representation of the data.
 */
@property (nonatomic, copy, nullable) NSArray<NSDictionary *> *onceDNDList;

/**
 * A readonly model list that represents the structured weekly periodic DND periods.
 * This is derived from `periodDNDList` and represents the same data in a structured format.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<ThingSmartMessageDNDTimerModel *> *periodDNDModelList;

/**
 * A readonly model list that represents the structured one-time DND periods.
 * This is derived from `onceDNDList` and represents the same data in a structured format.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<ThingSmartMessageDNDTimerModel *> *onceDNDModelList;

@end

NS_ASSUME_NONNULL_END
