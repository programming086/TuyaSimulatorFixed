//
//  ThingLampPackedGroupProtocol.h
//  Pods
//
//  Created by bawn on 2020/12/17.
//

#ifndef ThingLampPackedGroupProtocol_h
#define ThingLampPackedGroupProtocol_h

@protocol ThingLampPackedGroupProtocol

- (void)pushToPackedGroupInfoViewController:(NSString *)groupId;

- (UIViewController *)packedGroupListViewController:(long long)areaId;

- (void)presentToAddOrEditPackedGroupViewController:(long long)areaId;

@end


#endif /* ThingLampPackedGroupProtocol_h */
