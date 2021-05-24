
#import <Foundation/Foundation.h>
#import <TDSGlobalSDKCoreKit/TDSGlobalEntryType.h>

NS_ASSUME_NONNULL_BEGIN

@interface TDSGlobalTrackManager : NSObject
/// 跟踪用户
/// @param userId 用户唯一ID，非角色ID
+ (void)trackUser:(NSString *)userId;

+ (void)trackUser:(NSString *)userId
        loginType:(TDSGlobalSDKEntryType)loginType
       properties:(NSDictionary *)properties;

/// 跟踪角色
/// @param roleId 角色ID
/// @param roleName 角色名
/// @param serverId 服务器ID
/// @param level 角色等级
+ (void)trackRoleWithRoleId:(NSString *)roleId
                   roleName:(NSString *)roleName
                   serverId:(NSString *)serverId
                      level:(NSInteger)level;

/// 跟踪自定义事件
/// @param eventName 事件名
+ (void)trackEvent:(NSString *)eventName;

/// 跟踪完成成就
+ (void)trackAchievement;

/// 跟踪完成新手引导接口
+ (void)eventCompletedTutorial;

/// 跟踪完成创角
+ (void)eventCreateRole;

@end

NS_ASSUME_NONNULL_END
