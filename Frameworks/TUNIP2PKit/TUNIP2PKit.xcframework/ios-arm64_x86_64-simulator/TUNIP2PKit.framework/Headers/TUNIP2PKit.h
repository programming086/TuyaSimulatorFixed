
#import <Foundation/Foundation.h>

#import <TUNINativeBridgeManager/TUNINativeModuleKit.h>
    

@protocol TUNIP2pFileManagerProtocol; // #import <TUNIP2pFileManager/TUNIP2pFileManagerProtocol.h>
@protocol TUNIP2pFileManagerDelegate; // #import <TUNIP2pFileManager/TUNIP2pFileManagerDelegate.h>


NS_ASSUME_NONNULL_BEGIN

@interface TUNIP2PKit : TUNINativeModuleKit<TUNIP2pFileManagerProtocol>
 
 @property (nonatomic, weak) id <TUNIP2pFileManagerDelegate> p2pFileManagerDelegate;


@end

NS_ASSUME_NONNULL_END
