//
//  MFAdNativeExpress.h
//  

#import <MFAdsCore/MFAdBaseAdapter.h>
#import <MFAdsAdspot/MFAdNativeExpressDelegate.h>

NS_ASSUME_NONNULL_BEGIN

@interface MFAdNativeExpress : MFAdBaseAdapter

/// 广告方法回调代理
@property (nonatomic, weak) id<MFAdNativeExpressDelegate> delegate;
@property (nonatomic, assign) CGSize adSize;

/// 构造函数
/// @param viewController viewController
/// @param size 尺寸
- (instancetype)initWithViewController:(UIViewController *)viewController
                                adSize:(CGSize)size;
#ifdef DEBUG
/// 仅限于debug模式下使用
- (instancetype)initWithJsonDic:(NSDictionary *)jsonDic
                 viewController:(UIViewController *)viewController
                         adSize:(CGSize)size;
#endif
@end

NS_ASSUME_NONNULL_END
