//
//  ThingLightSceneMusicLibDataModel.h
//  ThingLightSceneKit
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightSceneMusicLibDataParamModel : NSObject

@property (nonatomic, assign) long long musicDataId;

@property (nonatomic, copy) NSString *dpCode;

@property (nonatomic, assign) NSInteger issueInterval;

@property (nonatomic, assign) NSInteger minBrightness;

@property (nonatomic, assign) NSInteger maxBrightness;

@property (nonatomic, assign) NSInteger colorRhythmStyle;

@property (nonatomic, assign) NSInteger decibelDiff;

@property (nonatomic, assign) NSInteger toneDiff;

@property (nonatomic, assign) NSInteger timeInterval;

@property (nonatomic, assign) NSInteger brightnessRhythmStyle;

@property (nonatomic, assign) NSInteger constantLight;

@property (nonatomic, assign) NSInteger minDecibel;

@property (nonatomic, assign) NSInteger maxDecibel;

@property (nonatomic, assign) NSInteger changeIntensity;

@property (nonatomic, copy) NSString *colorData;

@property (nonatomic, assign) NSInteger changeStyle;

@end

@interface ThingLightSceneMusicLibDataItemModel : NSObject

@property (nonatomic, assign) long long musicId;

@property (nonatomic, assign) long long libraryId;

@property (nonatomic, copy) NSString *name;

@property (nonatomic, copy) NSString *nameRosettaKey;

@property (nonatomic, assign) NSInteger musicIconDisplayType;

@property (nonatomic, copy) NSString *musicIconDisplaySize;

@property (nonatomic, copy) NSString *musicIconUrl;

@property (nonatomic, copy) NSString *musicLibraryIconUrl;

@property (nonatomic, copy) NSString *gmtCreate;

@property (nonatomic, copy) NSString *gmtModified;

@property (nonatomic, strong) ThingLightSceneMusicLibDataParamModel *param;

@end

@interface ThingLightSceneMusicLibDataModel : NSObject

@property (nonatomic, assign) NSInteger iconDisplayType;

@property (nonatomic, strong) NSString *iconDisplaySize;

@property (nonatomic, strong) NSArray<ThingLightSceneMusicLibDataItemModel *>*items;

@end

NS_ASSUME_NONNULL_END
