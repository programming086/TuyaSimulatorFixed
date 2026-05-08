
#ifndef ThingSmartMatterKitErrors_h
#define ThingSmartMatterKitErrors_h

/// The definitions of ThingSmartMatter kit errors.
typedef NS_ENUM(NSInteger, ThingSmartMatterKitError) {
    // fetch nodeId from cloud failed
    kThingSmartMatterKitErrorFetchNodeIdError                       = 3000,
    // WIFI is not a support wifi
    kThingSmartMatterKitErrorWIFINotSupport                         = 3001,
    // WIFI password incorrect
    kThingSmartMatterKitErrorWIFIIncorrect                          = 3002,
    // IP resloved error
    kThingSmartMatterKitErrorMdnsResolvedError                      = 3003,
    // Mdns scan timeout
    kThingSmartMatterKitErrorDnsSDDiscoveryFailed                   = 3004,
    //commission failed
    kThingSmartMatterKitErrorCommissonFailed                        = 3005,
    //thing device activity to cloud failed
    kThingSmartMatterKitErrorActivityCloudFailed                    = 3006,
    //fetch devicemodel for origin matter device failed
    kThingSmartMatterKitErrorFetchMatterDeviceFailed                = 3007,
    //get thread network failed
    kThingSmartMatterKitErrorTimeout                                = 3008,
    //device not support for matter failed
    kThingSmartMatterKitErrorDeviceNotSupport                       = 3009,
    //acl failed
    kThingSmartMatterKitErrorACLFailed                              = 3010,
    //Pase failed
    kThingSmartMatterKitErrorPaseSessionFailed                      = 3011,
    //FabricInfo failed
    kThingSmartMatterKitErrorFabricInfoFailed                       = 3012,
    //Commonerror normal failed
    kThingSmartMatterKitErrorCommonError                            = 3013,
    //fetch passcode failed
    kThingSmartMatterKitErrorFetchPassCodeFailed                    = 3014,
    //get nil fabric
    kThingSmartMatterKitErrorFabricNullInfo                         = 3015,
    //fetch device from cloud failed
    kThingSmartMatterKitErrorFetchDeviceFailed                      = 3016,
    //third active failed
    kThingSmartMatterKitErrorThirdDeviceActiveFailed                = 3017,
    //Fetch Gateway Node ID failed
    kThingSmartMatterKitErrorFetchGatewayNodeIdFailed               = 3018,
    //Fetch gatway device failed
    kThingSmartMatterKitFetchGatewayDeviceFailed                    = 3019,
    //generate NOCChain failed
    kThingSmartMatterKitNOCChainFailed                              = 3020,
    //request acl failed
    kThingSmartMatterKitRequestACLFailed                            = 3021,
    //Fetch Node ID failed
    kThingSmartMatterKitErrorFetchNodeIdFailed                      = 3022,
    //node not empty
    kThingSmartMatterKitErrorNodeEmptyFailed                        = 3023,
    //acl nil
    kThingSmartMatterKitCloundACLEmpty                              = 3024,
    //write acl faield
    kThingSmartMatterKitWriteACLFailed                              = 3025,
    //write acl failed
    kThingSmartMatterKitNotifyAclFailed                             = 3026,
    //device not online
    kThingSmartMatterKitErrorDeviceOffLine                          = 3027,
    // controller failed
    kThingSmartMatterKitErrorControllerFailed                       = 3028,
    //invalid params
    kThingSmartMatterKitErrorInvaildParams                          = 3029,
    //Connect Close
    kThingSmartMatterKitErrorConnectClose                           = 3030,
    //ConnectDelete
    kThingSmartMatterKitErrorConnectDelete                          = 3031,
    //CommonFailed
    kThingSmartMatterKitErrorCommonFailed                           = 3032,
    // BLEScanFailed
    kThingSmartMatterKitErrorBLEScanFailed                          = 3033,
    // BLEScanTimeout
    kThingSmartMatterKitErrorBLEScanTimeout                         = 3034, //1
    //no uuid
    kThingSmartMatterKitErrorNoUUID                                 = 3035,
    // MatterConnectFailed
    kThingSmartMatterKitErrorMatterConnectFailed                    = 3036,
    // ReadAttribute failed
    kThingSmartMatterKitErrorReadAttributeFailed                    = 3037,
    // SendCommandFailed
    kThingSmartMatterKitErrorSendCommandFailed                      = 3038,
    //3UUIDNoExist
    kThingSmartMatterKitErrorC3UUIDNoExist                          = 3039,
    //C3UUIDEmpty
    kThingSmartMatterKitErrorC3UUIDEmpty                            = 3040,
    //C3ParseFailed
    kThingSmartMatterKitErrorC3ParseFailed                          = 3041,
    // NotSupportAttribute
    kThingSmartMatterKitErrorNotSupportAttribute                    = 3042,
    //get connect device
    kThingSmartMatterKitErrorNoChipDevice                           = 3043,
    //time out
    kThingSmartMatterKitErrorTimeOut                                = 3044,
    //FetchDPEngineFileFailed
    kThingSmartMatterKitFetchDPEngineFileFailed                     = 3045,
    //DPEngine addDeviceIndfo failed
    kThingSmartMatterKitDPEngineAddDevice                           = 3046,
    //DP Engine control failed
    kThingSmartMatterKitDPEngineControlFailed                       = 3047,
    //MatterModelEmpty
    kThingSmartMatterKitMatterModelEmpty                            = 3048,
    // ReadVendorIdfailed
    kThingSmartMatterKitErrorReadVendorIdFailed                     = 3049,
    // ReadProductID failed
    kThingSmartMatterKitErrorReadProductIDFailed                    = 3050,
    // open PairingWindow failed
    kThingSmartMatterKitErrorOpenPairingWindowFailed                = 3051,
    //get thread network failed
    kThingSmartMatterKitErrorGetThreadFailed                        = 3054,
    // Matter Attestion Canceled
    kThingSmartMatterKitErrorIgnoreAttestationFailure               = 3055,
    // remove fabric failed
    kThingSmartMatterKitErrorRemoveFabricFailed                     = 3056,
    // the http api request fail
    kThingSmartMatterKitErrorHttpApiRequestFailed                   = 3057,
    // revoke device commission window fail
    kThingSmartMatterKitErrorRevokeCommissioningFailed              = 3058,
    // multiple fabric share over limit
    kThingSmartMatterKitErrorShareOverLimit                         = 3059,
	// not support
    kThingSmartMatterFabricNOTSupport                               = 3060,
    // noc is exist
    kThingSmartFabricAlreadyExist                                   = 3061,
    // matter pid not exist
    kThingSmartMatterPidNotExist                                    = 3062,
    // No home permissions
    kThingSmartMatterNoPermissions                                  = 3063,
    // MatterSupport Failed
    kThingSmartMatterKitErrorMatterSupportFailed                    = 4000,
    // MatterSupport Wifi error
    kThingSmartMatterKitErrorMatterWIFIERROR                        = 4001,
    // MatterSupport Thread router confirm
    kThingSmartMatterKitErrorThreadRouteDiscoveryFailed             = 4002,
    // Failed to find OTBR Agent ID
    kThingSmartMatterKitErrorThreadAgentIDDiscoveryFailed           = 4002,
    // NOT_SUPPORT_MULTI_FABRIC
    kThingSmartMatterKitErrorNotSupportMultiFabric                  = 4003,
    // Matter Support Payload create failed
    kThingSmartMatterKitErrorMatterSupportPayloadCreateFailed       = 4004,
    // Matter Support Use Wrong verison,only support over iOS16.1
    kThingSmartMatterKitErrorMatterSupportVerisonLimit              = 4005,
    // Matter Support Missing public key
    kThingSmartMatterKitErrorMatterSupportMissPublicKey             = 4006,
    // BLE Active Failed
    kThingSmartMatterKitErrorBLEActiveFailed                        = 5001,
    // Current Device Has BLE Actived
    kThingSmartMatterKitErrorBLEHasActived                          = 5002,
    // Query Device Can Join matter time out
    kThingSmartMatterKitErrorBLEQueryJoinMatterStateFailed          = 5003,
    // Query Device to make matter open again
    kThingSmartMatterKitErrorBLEReopenMatterServiceFailed           = 5004,
    // BLE Matter Device Can not mutiple support
    kThingSmartMatterKitErrorBLENotSupportMutipleFabric             = 5005,
    // BLE has Actived but gateway Device not support bind
    kThingSmartMatterKitErrorBLEActivedNotSupportGateway            = 5006,
    
};

#define kThingSmartMatterKitErrorDomain     @"com.thing.smart.matterKit"

#endif /* ThingSmartMatterKitErrors_h */
