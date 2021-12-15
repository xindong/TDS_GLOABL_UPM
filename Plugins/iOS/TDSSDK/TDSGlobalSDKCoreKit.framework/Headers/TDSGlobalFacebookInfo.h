//
//  TDSGlobalFacebookInfo.h
//  TDSGlobalSDKCoreKit
//
//  Created by JiangJiahao on 2020/11/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TDSGlobalFacebookInfo : NSObject

@property (nonatomic) NSString *appId;

+ (instancetype)instanceWithInfoDic:(NSDictionary *)infoDic;
@end

NS_ASSUME_NONNULL_END
