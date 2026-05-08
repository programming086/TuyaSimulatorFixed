
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingActivatorPairingDeviceRoomInfo : NSObject
@property (nonatomic, copy) NSString *name; ///< Room name
@property (nonatomic, assign) long long roomId; // Room Id
@end

@interface ThingActivatorPairingDeviceEditInfo : NSObject<NSCopying>

/// The subscript value when the room is not selected.
@property (class, nonatomic, assign, readonly) NSInteger unSelectIndex;

///  Selectable rooms
@property (nonatomic, strong) NSMutableArray <ThingActivatorPairingDeviceRoomInfo *>*roomList;

/// The currently selected room, or `unSelectIndex` for unselected.
@property (nonatomic, assign) NSInteger selectedIndex;

/// Name of the currently selected room
@property (nonatomic, strong, readonly, nullable) NSString *selectedRoomName;

@property (nonatomic, copy) NSString *name;

@property (nonatomic, copy) NSString *uniqueID;

@property (nonatomic, copy) NSString *devId;

@property (nonatomic, assign) BOOL canEditName;

//whether to automatically add device cards to the whole house home page
@property (nonatomic, assign) BOOL addDeviceToDiyHome;
@end

NS_ASSUME_NONNULL_END
