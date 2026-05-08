
#ifndef ThingSmartMessageUtils_h
#define ThingSmartMessageUtils_h

/// The type of message. Valid values: alert messages, home messages and notifications.
typedef NS_ENUM(NSInteger, ThingMessageType) {
    /// The alert message type.
    ThingMessageTypeAlarm = 1,
    /// The home message type.
    ThingMessageTypeFamily,
    /// The notification type.
    ThingMessageTypeNotice,
};

#endif /* ThingSmartMessageUtils_h */
