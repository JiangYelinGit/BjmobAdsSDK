
#if __has_include(<MFAdsCore/MFAdBaseAdapter.h>)
#import <MFAdsCore/MFAdBaseAdapter.h>
#import <MFAdsAdspot/MFAdBannerDelegate.h>
#else
#import "MFAdBaseAdapter.h"
#import "MFAdBannerDelegate.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface MFAdBanner : MFAdBaseAdapter

/// 广告方法回调代理
@property (nonatomic, weak) id<MFAdBannerDelegate> delegate;
/// banner 容器view
@property(nonatomic, weak) UIView *adContainer;
/// 更新间隔
@property(nonatomic, assign) int refreshInterval;
/// 展现类型 0:锚定  1：内嵌   默认为锚定类型
@property(nonatomic, assign) int showType;
/// Y轴位置(只对banner生效)
@property(nonatomic, assign) CGFloat y;

#pragma mark - 构造方法

- (instancetype)initWithAdViewController:(nonnull UIViewController *)viewController;

#ifdef DEBUG
/// 仅限于debug模式下使用
- (instancetype)initWithJsonDic:(NSDictionary *)jsonDic
                 viewController:(nonnull UIViewController *)viewController;
#endif
@end

NS_ASSUME_NONNULL_END
