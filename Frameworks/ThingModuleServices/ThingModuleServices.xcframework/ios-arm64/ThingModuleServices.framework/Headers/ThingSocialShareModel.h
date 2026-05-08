//
//  ThingSocialShareModel.h
//  ThingSocial
//
//  Created by ThingInc on 2018/5/31.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ThingSocialProtocol.h"

@interface ThingSocialShareModel : NSObject

@property (copy, nonatomic) NSString *title;///< 标题
@property (copy, nonatomic) NSString *content;///< 内容
@property (strong, nonatomic) UIImage *image;///< 分享图片内容
@property (copy, nonatomic) NSString *imageUrl;///< 分享图片地址
@property (copy, nonatomic) NSString *url;///< 分享地址
@property (copy, nonatomic) NSURL *fileURL;///< 分享文件URL
@property (copy, nonatomic) NSString *desc;///< 分享具体描述
@property (copy, nonatomic) NSArray<NSString *> *recipients;///< 收件人
@property (copy, nonatomic) NSArray<NSString *> *ccRecipients;///< 抄送人
@property (copy, nonatomic) NSArray<NSString *> *bccRecipients;///< 密件抄送人

@property (assign, nonatomic) ThingSocialShareContentType mediaType;///< 分享内容类型
@property (assign, nonatomic) ThingSocialType shareType;///< 分享渠道

@property (nonatomic, assign) BOOL needCopyLink;/// < 是否需要复制链接
@property (nonatomic, strong) NSArray<NSNumber/*ThingSocialType*/ *> *blackList; /// < 不需要分享的TYSocialType

+ (instancetype)modelWithShareType:(ThingSocialType)shareType;
- (instancetype)initWithShareType:(ThingSocialType)shareType;

@end
