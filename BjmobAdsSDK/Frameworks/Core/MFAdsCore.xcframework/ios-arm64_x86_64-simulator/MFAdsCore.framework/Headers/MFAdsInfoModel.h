//
//  MFFrequencyModel.h
//  MFAdsCore
//
//  Created by cc on 2022/8/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MFAdsInfoModel : NSObject<NSCoding>

/// 间隔时间
@property(nonatomic, assign) NSInteger interval;
/// 广告类型
@property(nonatomic, strong) NSString *adsType;
/// 当前展现的次数
@property(nonatomic, assign) NSInteger currShowCount;
/// 总共允许展现次数
@property(nonatomic, assign) NSInteger frequency;
/// 最后一次展现成功的时间
@property(nonatomic, assign) NSInteger lastDisplayedTime;
/// 标识
@property(nonatomic, copy) NSString * tag;

@end

NS_ASSUME_NONNULL_END
