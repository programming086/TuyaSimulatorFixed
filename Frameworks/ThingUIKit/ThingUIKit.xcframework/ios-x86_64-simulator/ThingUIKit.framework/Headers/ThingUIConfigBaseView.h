
#import <UIKit/UIKit.h>
#import "ThingUIConfigFeatureProtocol.h"

@protocol ThingUIConfigBaseViewLayoutTask <NSObject>

@required
- (void)configUITask;

- (void)addSubViewTask;

- (void)layoutSubViewTask;

//For external and internal use, you can get the attributes under the feature
@property (nonatomic,strong,class) NSObject<ThingUIConfigFeatureProtocol>* feature;

//For external use, to facilitate external acquisition of component height
+ (CGFloat)getHeight;

@optional

- (void)bindSubViewTask;

@end

@interface ThingUIConfigBaseView : UIView<ThingUIConfigBaseViewLayoutTask>


@end

