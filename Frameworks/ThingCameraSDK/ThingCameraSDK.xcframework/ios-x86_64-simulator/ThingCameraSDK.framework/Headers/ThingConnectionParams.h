
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingConnectionParams : NSObject

@property (nonatomic, copy) NSString *username;       // 远程 ID
@property (nonatomic, copy) NSString *password;       // 设备 ID
@property (nonatomic, copy) NSString *skill;          // 技能
@property (nonatomic, copy) NSString *token;          // 令牌
@property (nonatomic, copy) NSString *traceId;        // 跟踪 ID
@property (nonatomic, assign) NSInteger lanMode;      // 局域网模式
@property (nonatomic, assign) NSInteger connectOption;// 连接选项
@property (nonatomic, copy) NSString *localKey;       // 本地密钥
@property (nonatomic, copy) NSString *extConfg;       // 本地密钥

@end

NS_ASSUME_NONNULL_END
