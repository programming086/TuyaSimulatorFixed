//
//  TYBLEAudioToDoListModel.h
//  TuyaSmartBLEKit
//
//  Created by tjl on 2021/7/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYBLEAudioTextFieldModel : NSObject

@property (nonatomic, copy) NSString *leftTextField;

@property (nonatomic, copy) NSString *rightTextField;

@end

@interface TYBLEAudioToDoListModel : NSObject

@property (nonatomic, copy) NSString *mainTitle;

@property (nonatomic, copy) NSString *subTitle;

@property (nonatomic, strong) NSMutableArray<TYBLEAudioTextFieldModel *> *listItems;

@end

NS_ASSUME_NONNULL_END
