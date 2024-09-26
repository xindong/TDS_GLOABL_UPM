# ChangeLog

## v1.7.0

Feature

[Android]
- 升级 Google 结算库版本至 7.0.0
- 适配 Android 14 (ApiLeve 34)

## v1.6.0

Feature

[Android]
- 升级 Google 结算库版本至 5.2.0
- 适配 Android 13 (ApiLeve 33)

## v1.5.1

Feature

[iOS]
- 支付接口新增 region_code 字段

## v1.5.0

Feature

[Android]
- 更新 Google 结算库版本至 4.1.0

## v1.3.1

Feature

[Android]
* 内嵌支付增加 game_ext 字段
* 内嵌支付、网页支付支持现有 Intent Scheme 跳转三方 App 规则

## v1.3.0

Feature

[Android]

* 新增内嵌网页支付功能
* 升级 AppsFlyer SDK 版本 (4.11.0 -> 6.4.3、installReferrerVersion: 2.1 -> 2.2)
* 升级 FirebaseCore SDK 版本 (17.2.2 -> 18.0.0)

[iOS]

* 账号注销功能
* 升级 Firebase 库 -> 8.3.0

## v1.2.4

* 更新 Android 设备唯一标识机制

## v1.2.3

### Feature

* Android targetSdkVersion 升级 30 适配
* 游客账号逻辑适配 Android 11
* 增加 Android 11 及以上、是否有外部存储管理权限、跳转系统设置外部存储权限三个方法
* Facebook SDK 版本升级到 12.0.0

## v1.2.2

### Feature

* WebView 支持 LocalStorage、SessionStorage、DatabaseStorage
* 客服系统支持上传视频文件类型

### Dependencies

* TapSDk v1.1.6

## v1.2.1

### Feature

* Android WebView 支持唤起外部应用
* Android 游客数据可保存至外部存储空间

### BugFix

* Android 修复因初始化之前调用单点登录可能导致崩溃的问题

### Dependencies

* TapSDk v1.1.6

## v1.2.0

### Feature

* iOS 登录界面底部 Logo 尺寸改为 62*14,建议用 3x 图保证清晰度
* iOS 韩国地区协议界面推送通知开关默认改为 关闭
* iOS libs 更新，FacebookSDK 更新为 9.3.0 ； TwitterLoginKit 更新
* iOS 新增 TDSGlobalSDKSettings 类，SDK 相关配置调用类方法
* iOS 支持 Bitcode
* 登录弹窗LOGO放大
* Android TapDB初始化参数更换
* 补款流程订单新增 UserId
* 上报角色名称修改

### BugFix

* iOS 修复 IDFA 开关无效 bug

### Dependencies

* TapSDk v1.1.6

## v1.1.6

### BugFix

* 修复 Android Bridge 方法匹配错误

### Dependencies

* TapSDK v1.1.6

## v1.1.5

### Feature

* 部分日文翻译更改
* 登录界面默认展开所有登录方式
* 可配置账号中心解绑绑定开关（是否显示解绑按钮）
* 账号安全中心的解绑/绑定/删除账号功能由后端字段控制
* iOS Appsflyer 升级

### Dependencies

* TapSDK v1.1.6

## v1.1.4

### BugFix

* 修复 iOS 查询商品时 JSON 解析错误导致的崩溃
* 修复 iOS ALWAYS_EMBED_SWIFT_STANDARD_LIBRARIES 设置问题可能导致的 AppStore 审核无法通过

### Dependencies

* TapSDK v1.1.6

## v1.1.3

### Feature

* 新增 Firebase Crashlytics
* 新增 IDFA 开关
* Android support library migrate to AndroidX
* 多语言 日语部分更新

### Dependencies

* TapSDK v1.1.5

## v1.1.2

### Feature

- 更新 iOS Twitter

## v1.1.1

### Feature

- 更新 iOS AppsFlyer

## v1.1.0

### Feature

- 新增自定义登陆接口
- tds 域名切换
- 支持海外域名动态切换
- 网络稳定性日志上报
- 登陆新增 twitter、Line
- 分享新增 twitter、Line

### BugFix

- 修复 TapDB 数据上报错误

### Dependencies

- TapSDK 1.1.2