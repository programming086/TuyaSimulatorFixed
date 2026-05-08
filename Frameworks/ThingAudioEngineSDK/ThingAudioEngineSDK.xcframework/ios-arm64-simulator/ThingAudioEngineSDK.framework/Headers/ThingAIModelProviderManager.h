
#import <Foundation/Foundation.h>

/**
 * AI 模型提供者管理器
 */
@interface ThingAIModelProviderManager : NSObject

/**
 * 获取 AI 模型提供者实例
 * @return ThingAIModelProviderManager 单例实例
 */
+ (instancetype)sharedInstance;

/**
 * 设置 Silero VAD 模型路径
 * @param path 模型文件绝对路径
 * @return 0 成功，<0 失败
 */
- (int)setSileroVADModel:(NSString *)path;

/**
 * 设置 DeepFilterNet 模型路径
 * @param path 模型文件绝对路径
 * @return 0 成功，<0 失败
 */
- (int)setDeepFilterModel:(NSString *)path;

/**
 * 设置 DTLN 模型路径（多文件）
 * @param paths 各子模型文件路径数组
 * @return 0 成功，<0 失败
 */
- (int)setDTLNModelPaths:(NSArray<NSString *> *)paths;

/**
 * 通用：设置单文件模型
 * @param modelType 模型类型 (0=SileroVAD, 1=DTLN, 2=DeepFilter)
 * @param path 路径
 * @return 0 成功，<0 失败
 */
- (int)setModelPath:(int)modelType path:(NSString *)path;

/**
 * 通用：设置多文件模型
 * @param modelType 模型类型
 * @param paths 路径数组
 * @return 0 成功，<0 失败
 */
- (int)setModelPaths:(int)modelType paths:(NSArray<NSString *> *)paths;

@end
