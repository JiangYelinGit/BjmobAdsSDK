//
//  MFAdSplash.h
//

#import <Foundation/Foundation.h>
#if __has_include(<MFAdsCore/MFAdBaseAdapter.h>)
#import <MFAdsAdspot/MFAdSplashDelegate.h>
#import <MFAdsCore/MFAdBaseAdapter.h>
#else
#import "MFAdSplashDelegate.h"
#import "MFAdBaseAdapter.h"

#endif
NS_ASSUME_NONNULL_BEGIN

@interface MFAdSplash : MFAdBaseAdapter

/// 广告方法回调代理
@property (nonatomic, weak) id<MFAdSplashDelegate> delegate;
/// 是否必须展示Logo 默认: NO 注意: 强制展示Logo可能会影响收益 !!!
@property (nonatomic, assign) BOOL showLogoRequire;
/// 广告Logo
@property(nonatomic, strong) UIImage *logoImage;
/// 标题
@property(nonatomic, copy) NSString *title;
/// 广告未加载出来时的占位图
@property(nonatomic, strong) UIImage *backgroundImage;
/// 总超时时间
@property (nonatomic, assign) NSInteger timeout;

/// 构造方法
- (instancetype)initWithViewController:(UIViewController *)viewController;
#ifdef DEBUG
/// 构造方法
/// 仅适用于Debug模式 Release下调用无效
- (instancetype)initWithJsonDic:(NSDictionary *)jsonDic viewController:(UIViewController *)viewController;
#endif

@end

NS_ASSUME_NONNULL_END
