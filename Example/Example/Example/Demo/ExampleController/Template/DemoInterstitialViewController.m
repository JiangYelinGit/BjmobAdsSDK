//
//  DemoInterstitialViewController.m
//  advancelib
//
//  Created by allen on 2019/12/31.
//  Copyright © 2019 Bayescom. All rights reserved.
//

#import "DemoInterstitialViewController.h"
#import <BJAdsAdspot/BJAdInterstitial.h>
@interface DemoInterstitialViewController () <BJAdInterstitialDelegate>
@property (nonatomic, strong) BJAdInterstitial *adInterstitial;
@property (nonatomic) bool isAdLoaded;
//@property (nonatomic, strong) NSDictionary *dic;

@end

@implementation DemoInterstitialViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"插屏广告";
    self.dic = [[AdDataJsonManager shared] loadAdDataWithType:JsonDataType_interstitial];
}

- (void)loadAd {
    [super loadAd];
    [self deallocAd];
    [self loadAdWithState:AdState_Normal];
    _isAdLoaded=false;
    [self.adInterstitial loadAd];
    [self loadAdWithState:AdState_Loading];
}

- (void)showAd {
//    if (!self.adInterstitial || !self.isLoaded) {
//        [DemoUtils showToast:@"请先加载广告"];
//        return;
//    }
    [self.adInterstitial showAd];
}

- (void)loadAndShowAd {
    [super loadAndShowAd];
    [self loadAdWithState:AdState_Normal];
    _isAdLoaded=false;
    [self.adInterstitial loadAndShowAd];
    [self loadAdWithState:AdState_Loading];
}

- (void)deallocAd {
    if (_adInterstitial) {
        _adInterstitial = nil;
        _adInterstitial.delegate = nil;
    }
    self.isLoaded = NO;
    [self loadAdWithState:AdState_Normal];
}

#pragma mark - BJAdInterstitialDelegate
/// 请求广告数据成功后调用
- (void)ad_loadSuccessWithAdsType:(adsType)adsType {
    NSLog(@"广告数据拉取成功 %s", __func__);
    self.isLoaded = YES;
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告数据拉取成功", __func__]];
    [self loadAdWithState:AdState_LoadSucceed];
//    [JDStatusBarNotification showWithStatus:@"广告加载成功" dismissAfter:1.5];
//    [self loadAdBtn2Action];
}

- (void)ad_loadFailure:(NSError *)error withAdsType:(adsType)adsType {
    NSLog(@"广告数据拉取失败 %@", error);
}

/// 广告曝光
- (void)ad_exposuredWithAdsType:(adsType)adsType {
    NSLog(@"广告曝光回调 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告曝光成功", __func__]];
}

/// 广告点击
- (void)ad_clickedWithAdsType:(adsType)adsType {
    NSLog(@"广告点击 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告点击成功", __func__]];

}

/// 广告展示失败
- (void)ad_failedWithError:(NSError *)error description:(NSDictionary *)description {
    NSLog(@"广告展示失败 %s  error: %@ 详情:%@", __func__, error, description);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告加载失败", __func__]];
    [self showErrorWithDescription:description];
    [self loadAdWithState:AdState_LoadFailed];
    [self deallocAd];

}

/// 内部渠道开始加载时调用
- (void)ad_supplierWillLoad:(NSString *)supplierId {
    NSLog(@"内部渠道开始加载 %s  supplierId: %@", __func__, supplierId);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 内部渠道开始加载", __func__]];

}

/// 广告关闭了
- (void)ad_didCloseWithAdsType:(adsType)adsType {
    NSLog(@"广告关闭了 %s", __func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 广告关闭了", __func__]];
    [self deallocAd];
}

- (void)ad_successSortTag:(NSString *)sortTag {
    NSLog(@"选中了 rule '%@' %s", sortTag,__func__);
    [self showProcessWithText:[NSString stringWithFormat:@"%s\r\n 选中了 rule '%@' ", __func__, sortTag]];
}


#pragma mark - lazy
- (BJAdInterstitial *)adInterstitial{
    if(!_adInterstitial){
        if ([self isDebug]) {
//            _adInterstitial = [[BJAdInterstitial alloc] initWithJsonDic:self.dic viewController:self];
        }else {
            _adInterstitial = [[BJAdInterstitial alloc] initWithViewController:self];
        }
        _adInterstitial.delegate = self;
    }
    return _adInterstitial;
}
@end
