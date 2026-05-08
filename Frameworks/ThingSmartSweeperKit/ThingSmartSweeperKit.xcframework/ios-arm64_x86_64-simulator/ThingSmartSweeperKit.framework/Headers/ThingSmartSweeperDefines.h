
#ifndef ThingSmartSweeperDefines_h
#define ThingSmartSweeperDefines_h

typedef NS_ENUM(NSInteger, ThingSmartSweeperFileDownloadStatus) {
    ThingSmartSweeperFileDownloadUpgrading = 1,   // downloading
    ThingSmartSweeperFileDownloadFinish    = 2,          // download finsh
    ThingSmartSweeperFileDownloadFailure   = 3,         // download fail
};
typedef NS_ENUM(NSInteger,ThingSmartSweeperP2PDownloadType){
    /// download once
    ThingSmartSweeperP2PDownloadTypeOnce  = 0,
    /// continuous download when device update.
    ThingSmartSweeperP2PDownloadTypeStill = 1,
};

typedef NS_ENUM(NSInteger,ThingSmartSweeperP2PErrorCode){
    // ThingSmartSweeperDevice init error, please check devId.
    ThingSmartSweeperP2PErrorCodeNoDevice  = -9000,
    // Is connencting, please wait.
    ThingSmartSweeperP2PErrorCodeConnecting  = -9002,
    // timeout
    ThingSmartSweeperP2PErrorCodeTimeout  = -9004,
    // Disconnect
    ThingSmartSweeperP2PErrorCodeDisConnect  = -9006,
    
    // SDK dependency error or init error, please check dependency.
    ThingSmartSweeperP2PErrorCodeDependency  = -9001,
    // Offline
    ThingSmartSweeperP2PErrorCodeOffline  = -9003,
    // No file data
    ThingSmartSweeperP2PErrorCodeNoFile  = -9005,
};
#endif /* ThingSmartSweeperDefines_h */
