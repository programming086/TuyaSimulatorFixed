
/// The two types of feedback. Provides question and answer types.
typedef enum : NSUInteger {
    /// The question feedback type.
    ThingSmartFeedbackQuestion,
    /// The answer feedback type.
    ThingSmartFeedbackAnswer,
} ThingSmartFeedbackType;

@interface ThingSmartFeedbackModel : NSObject

/// The feedback type.
@property (nonatomic, assign) ThingSmartFeedbackType     type;

/// The time when the feedback opened.
@property (nonatomic, assign) NSTimeInterval            ctime;

/// The feedback ID.
@property (nonatomic, assign) NSUInteger                uniqueId;

/// The content of the feedback.
@property (nonatomic, strong) NSString                  *content;

@end
