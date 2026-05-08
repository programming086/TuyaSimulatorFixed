
#import <UIKit/UIKit.h>
#import "ThingTimelineViewSource.h"

typedef NS_ENUM(NSUInteger, ThingTimelineUnitMode) {
    ThingTimelineUnitMode_60,    ///< 60s
    ThingTimelineUnitMode_300,   ///< 300s
    ThingTimelineUnitMode_600,   ///< 600s
    ThingTimelineUnitMode_900,   ///< 900s
    ThingTimelineUnitMode_1800,  ///< 1800
    ThingTimelineUnitMode_3600,  ///< 3600s
};

typedef NS_ENUM(NSInteger, ThingPlaybackRecordType) {
    ThingPlaybackRecordNormal, 
    ThingPlaybackRecordAOV,    
};

@class ThingTimelineView, ThingAsyncDisplayLayer;

@protocol ThingTimelineViewDelegate <NSObject>

@optional

/// timeline view begin dragging
- (void)timelineViewWillBeginDragging:(ThingTimelineView *)timeLineView;

/// time line view did end dragging. decelerate is true if it will continue moving afterwards
- (void)timelineViewDidEndDragging:(ThingTimelineView *)timeLineView willDecelerate:(BOOL)decelerate;

/// time line view did scroll to time interval. isDragging is true if it is being dragging
- (void)timelineViewDidScroll:(ThingTimelineView *)timeLineView time:(NSTimeInterval)timeInterval isDragging:(BOOL)isDragging;

/// time line view did end scrolling.
/// @param timeInterval selected time when scrolling end
/// @param source if source is not nil which contains the selected time
- (void)timelineView:(ThingTimelineView *)timeLineView didEndScrollingAtTime:(NSTimeInterval)timeInterval inSource:(id<ThingTimelineViewSource>)source;

// time line view is scaled
- (void)timelineView:(ThingTimelineView *)timeLineView scaleToUnitMode:(ThingTimelineUnitMode)unitMode;

@end

@interface ThingTimelineView : UIView 

/// the space of two long tick mark
@property (nonatomic, assign) CGFloat spacePerUnit;

/// the seconds of two long tick mark
@property (nonatomic, assign) ThingTimelineUnitMode unitMode;

/// color of tick mark
@property (nonatomic, strong) UIColor *tickMarkColor;

@property (nonatomic, strong) NSArray *backgroundGradientColors;
@property (nonatomic, strong) NSArray *backgroundGradientLocations;

/// time slice source color
@property (nonatomic, strong) UIColor *contentColor;

@property (nonatomic, copy) NSArray *contentGradientColors;
@property (nonatomic, copy) NSArray *contentAovGradientColors;
@property (nonatomic, strong) NSArray *contentGradientLocations;
@property (nonatomic, copy) NSArray *eventGradientColors;

/// height of the time text bar in the top
@property (nonatomic, assign) CGFloat timeHeaderHeight;
/// top space of the time text bar
@property (nonatomic, assign) CGFloat timeTextTop;

/// time text attributes
@property (nonatomic, strong) NSDictionary *timeStringAttributes;

/// is show the time string
@property (nonatomic, assign) BOOL showTimeText;

/// is show short tick mark between two long tick mark
@property (nonatomic, assign) BOOL showShortMark;

/// selected time
@property (nonatomic, assign) NSTimeInterval currentTime;

/// the day
@property (nonatomic, strong) NSDate *date;

/// time zone
@property (nonatomic, strong) NSTimeZone *timeZone;

/// is being dragging
@property (nonatomic, assign, readonly) BOOL isDragging;

/// is continue moving afterwards
@property (nonatomic, assign, readonly) BOOL isDecelerating;

///color of  selection line at the midle
@property (nonatomic, strong) UIColor *midLineColor;

/// tint color of selection box
@property (nonatomic, strong) UIColor *selectionBoxColor;
/// selected time range
@property (nonatomic, assign, readonly) NSRange selectedTimeRange;
/// is in selection mode
@property (nonatomic, assign, readonly) BOOL isSelectionEnabled;

/// the selected time when dragging selection box
@property (nonatomic, strong) UIColor *selectionTimeBackgroundColor;
@property (nonatomic, strong) UIColor *selectionTimeTextColor;
@property (nonatomic, assign) NSUInteger selectionTimeTextFontSize;

/// time slices
@property (nonatomic, copy) NSArray<id<ThingTimelineViewSource>> *sourceModels;

/// ai detection datasource
@property (nonatomic, copy) NSArray<id<ThingTimelineViewSource>> *AIDetectionSourceModels;

/// ai background color
@property (nonatomic, copy) NSArray *aiEventContentGradientColors;
/// delegate
@property (nonatomic, weak) id<ThingTimelineViewDelegate> delegate;


/// enable selection mode
/// @param min min seconds to selected
/// @param max max seconds to selected
- (void)enableSelectionModeWithMinLength:(NSInteger)min maxLength:(NSInteger)max;

/// exit selection mode
- (NSRange)finishSelection;

/// set current time
- (void)setCurrentTime:(NSTimeInterval)currentTime animated:(BOOL)animated;

@end
