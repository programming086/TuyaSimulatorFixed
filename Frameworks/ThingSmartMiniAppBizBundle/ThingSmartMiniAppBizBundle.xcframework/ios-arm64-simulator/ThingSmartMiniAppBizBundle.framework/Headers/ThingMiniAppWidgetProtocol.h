
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingMiniAppWidgetProtocol <NSObject>

/// Create a pop-up widget and display it
/// - Parameters:
///   - view: The parent view that displays the widget
///   - url: The url for creating the widget, the format is described in the subsequent parameter description section
- (UIView *)showWidgetDialogInView:(nonnull UIView *)view url:(nonnull NSString *)url;

/// Create a pop-up widget and display it
/// - Parameters:
///   - view: The parent view that displays the widget
///   - url: The url for creating the widget, the format is described in the subsequent parameter description section
///   - dismissCallback: The callback when the widget disappears
- (UIView *)showWidgetDialogInView:(nonnull UIView *)view url:(nonnull NSString *)url
                   dismissCallback:(nullable void(^)(void))dismissCallback;

/// Create a widget view
/// - Parameter url: The url for creating the widget, the format is described in the subsequent parameter description section
- (UIView *)createWidgetViewWithUrl:(nonnull NSString *)url;

/// Create a widget view. When multiple urls are passed in, multiple widgets will be merged and displayed together
/// - Parameter urls: The urls array for creating the widget, the format is described in the subsequent parameter description section
- (UIView *)createWidgetViewWithMultiUrls:(nonnull NSArray<NSString *> *)urls;

/// Widget pop-up disappears
/// - Parameter view: The widget instance returned when creating the widget pop-up
- (void)dismissWidgetDialog:(nonnull UIView *)view;

/// Preload widget
/// - Parameter appId: The widget appId, which is the appId of the corresponding mini-program
- (void)preloadWidgetWithAppId:(nonnull NSString *)appId;

/// Preload widget
/// - Parameters:
///   - appId: The widget appId, which is the appId of the corresponding mini-program
///   - completeCallback: The callback when the preload is complete
- (void)preloadWidgetWithAppId:(nonnull NSString *)appId
              completeCallback:(nullable void(^)(BOOL success, NSError *error))completeCallback;

@end

NS_ASSUME_NONNULL_END
