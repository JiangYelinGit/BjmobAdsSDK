//
//  MFAdSupplierDelegate.h
//  

#ifndef MFAdSupplierDelegate_h
#define MFAdSupplierDelegate_h

@protocol MFAdSupplierDelegate <NSObject>

@optional

/// 加载策略Model成功
- (void)ad_AdBaseAdapterLoadSuccess:(nonnull MFAdSupplierModel *)model;
/// 加载策略Model失败
- (void)ad_AdBaseAdapterLoadError:(nullable NSError *)error;
/// 加载的 sortTag
- (void)ad_AdBaseAdapterLoadSortTag:(NSString *_Nonnull)sortTag;
/// 加载并展示
- (void)ad_AdBaseAdapterLoadAndShow;
/// 返回下一个渠道的参数
/// @param supplier 被加载的渠道
/// @param error 异常信息
- (void)ad_AdBaseAdapterLoadSuppluer:(nullable MFAdSupplier *)supplier error:(nullable NSError *)error;

@end

#endif /* MFAdSupplierDelegate_h */
