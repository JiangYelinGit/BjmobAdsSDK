//
//  MFAdBaseDelegate.h
//

#ifndef MFAdBaseDelegate_h
#define MFAdBaseDelegate_h

#import <MFAdsAdspot/MFAdCommonDelegate.h>

// 策略相关的代理
@protocol MFAdBaseDelegate <MFAdCommonDelegate>

@optional
/// 广告数据请求成功
- (void)ad_loadSuccessWithAdsType:(adsType)adsType;
/// 广告数据加载失败
- (void)ad_loadFailure:(NSError *)error withAdsType:(adsType)adsType;
/// 广告曝光成功
- (void)ad_exposuredWithAdsType:(adsType)adsType;
/// 广告曝光失败
- (void)ad_exposuredFailed:(NSError *)error withAdsType:(adsType)adsType;
/// 广告点击
- (void)ad_clickedWithAdsType:(adsType)adsType;
/// 广告关闭
- (void)ad_didCloseWithAdsType:(adsType)adsType;

@end

#endif /* MFAdBaseDelegate_h */
