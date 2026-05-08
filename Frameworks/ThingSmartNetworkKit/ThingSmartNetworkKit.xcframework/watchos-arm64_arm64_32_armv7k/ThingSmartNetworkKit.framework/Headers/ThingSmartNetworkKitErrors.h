
#ifndef ThingSmartNetworkKitErrors_h
#define ThingSmartNetworkKitErrors_h

extern NSString *const kThingNetworkKitErrorDomain;

typedef NS_ENUM(NSInteger, ThingNetworkKitError) {
    /// Request Error.
    kThingNetworkKitErrorAPIRequestError                       = 2000,
    /// Return data type is illegal.
    kThingNetworkKitErrorAPIResponseDataTypeIllegal            = 2001,
    /// The returned data sign is inconsistent.
    kThingNetworkKitErrorAPIResponseDataSignInconsistent       = 2002,
    /// Return data decode error.
    kThingNetworkKitErrorAPIResponseDataDecodeError            = 2003,
    /// Network Error.
    kThingNetworkKitErrorNetworkError                          = 2004,
    
};

#endif /* ThingSmartNetworkKitErrors_h */
