//
//  MFRequestURL.h
//  Pods
//
//  Created by cc on 2022/5/4.
//

/**
 
 https://api-cn.ifssn.com
 ==>
 https://api-cn.stillonline.cn

 https://api-global.ifssn.com
 ==>
 https://api-global.stillonline.cn

 https://alert.immft.com
 ==>
 https://alert.stillonline.cn
 
 
 */




#ifndef MFRequestURL_h
#define MFRequestURL_h

#ifdef DEBUG

#define BaseURL         @"https://api-cn.stillonline.cn"      // 国内API
#define BaseURLOS       @"https://api-global.stillonline.cn"  // 海外API
#define BaseURLAlert    @"https://alert.stillonline.cn"       // 日志

#else

#define BaseURL         @"https://api-cn.stillonline.cn"      // 国内API
#define BaseURLOS       @"https://api-global.stillonline.cn"  // 海外API
#define BaseURLAlert    @"https://alert.stillonline.cn"       // 日志

#endif

/// 获取广告规则状态
#define URL_ADS_STATUS          @"/ads/router/status"
/// 刷新广告规则状态
#define URL_ADS_STATUSv2        @"/ads/v2/router/status"
/// 刷新广告规则状态
#define URL_ADS_STATUSv3        @"/ads/v3/router/status"
/// 获取广告信息
#define URL_ADS_ROUTER          @"/ads/routerInfo"
/// 状态上报
#define URL_ADS_REPORTSTATE     @"/statistics/reportState"
/// 加密广告信息接口
#define  URL_ADS_RULE           @"/ads/ruleInfo"


#endif /* MFRequestURL_h */
