
#import <Foundation/Foundation.h>
#import <TDSGlobalSDKCoreKit/TDSGlobalEntryType.h>

NS_ASSUME_NONNULL_BEGIN
@class TDSGlobalUser;

typedef NS_ENUM(NSInteger,TDSGlobalUserStateChangeCode) {
    TDSGlobalUserStateChangeCodeLogout          = 0x9001,   // user logout
    TDSGlobalUserStateChangeCodeBindSuccess     = 0x1001,   // user bind success,msg = entry type in string,eg: @"TAPTAP"
    TDSGlobalUserStateChangeCodeUnBindSuccess   = 0x1002,   // user unbind success,msg = entry type in string
};

/**
  Describes the call back to the TDSGlobalLoginManager
 @param result the result of the login request
 @param error error, if any.
 */
typedef void (^TDSGlobalLoginManagerRequestHandler)(TDSGlobalUser * _Nullable result, NSError * _Nullable error);

/**
  Describes the call back of state of current user
 @param userStateChangeCode user state change type code.
 */
typedef void (^TDSGlobalUserStateChangeHandler)(TDSGlobalUserStateChangeCode userStateChangeCode,NSString *_Nullable message);

@interface TDSGlobalLoginManager : NSObject
/// Open login view
/// @param handler login result handler
+ (void)login:(TDSGlobalLoginManagerRequestHandler)handler;

/// Get callback when user state changed
/// @param handler handler
+ (void)addUserStatusChangeCallback:(TDSGlobalUserStateChangeHandler)handler;

/// Logout current user
+ (void)logout;

/// Get current user
+ (void)getUser:(TDSGlobalLoginManagerRequestHandler)handler;

/// Open usercenter view
+ (void)userCenter;

/**
 You can customize login buttons in your own ways,and call this methods to login an user.
 Steps:
    1. use TDSGlobalSDKEntryTypeDefault ,check if there was an user logged last time,you will get a result.
    2. if step 1 failed, show login buttons ,and call with corresponding type when user tapped.
 */
+ (void)loginByType:(TDSGlobalSDKEntryType)loginType loginHandler:(TDSGlobalLoginManagerRequestHandler)handler;

+ (void)accountCancellation;
@end

NS_ASSUME_NONNULL_END
