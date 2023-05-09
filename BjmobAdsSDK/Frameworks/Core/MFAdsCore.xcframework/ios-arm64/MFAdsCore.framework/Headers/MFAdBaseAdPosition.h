//
//  MFAdBaseAdPosition.h
//

#import <Foundation/Foundation.h>
#import <MFAdsCore/MFAdLog.h>
#import <MFAdsCore/MFAdSupplierModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface MFAdBaseAdPosition : NSObject

/// 标记并行渠道为了找到响应的adapter
@property (nonatomic, assign) NSInteger tag;
/// Y轴位置 (只对banner有效)
@property(nonatomic, assign) CGFloat banner_y;

/// 构造方法
- (instancetype)initWithSupplier:(MFAdSupplier *)supplier adspot:(id)adspot;
/// 加载必须条件
- (void)supplierStateLoad;
/// 加载广告
- (void)loadAd;
/// 显示广告
- (void)showAd;
/// 销毁
- (void)deallocAdapter;

@end

NS_ASSUME_NONNULL_END
