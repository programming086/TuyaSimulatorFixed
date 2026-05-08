
#ifndef ThingSmartBaseKitErrors_h
#define ThingSmartBaseKitErrors_h

/*
 *  ThingBaseKitError
 *
 *  Discussion:
 *    Error returned as code to NSError from ThingSmartBaseKit.
 */

extern NSString *const kThingBaseKitErrorDomain;

typedef NS_ENUM(NSInteger, ThingBaseKitError) {
    /// Request Error.
    kThingBaseKitErrorAPIRequestError                       = 2000,
    /// Return data type is illegal.
    kThingBaseKitErrorAPIResponseDataTypeIllegal            = 2001,
    /// The returned data sign is inconsistent.
    kThingBaseKitErrorAPIResponseDataSignInconsistent       = 2002,
    /// Return data decode error.
    kThingBaseKitErrorAPIResponseDataDecodeError            = 2003,
    /// Network Error.
    kThingBaseKitErrorNetworkError                          = 2004,
    
};

#endif /* ThingSmartBaseKitErrors_h */
