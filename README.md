# TDSGlobal-Unity

## 1.基本要求
### 环境要求
* 安装Unity **2018.3**或更高版本

* IOS **10**或更高版本，xcode 12.3+

* Android 目标为**API21**或更高版本

### 权限声明
#### Android
android.permission.WRITE_EXTERNAL_STORAG 允许应用读取外部储存，用于内嵌动态、TapDB  
android.permission.READ_EXTERNAL_STORAGE 允许应用写入外部储存，用于内嵌动态、TapDB

#### iOS
NSUserTrackingUsageDescription iOS14以上获取IDFA需要配置改权限，用TapDB  
NSPhotoLibraryUsageDescription 相册权限，用于内嵌动态  
NSCameraUsageDescription 相机，用于内嵌动态  
NSMicrophoneUsageDescription 麦克风，用于内嵌动态  

## 2.导入SDK

* 使用Unity Package Manager 添加SDK到项目中。

```json
//在Packages/manifest.json 中添加TDSGlobal SDK
{
    "dependencies":{
        "com.tds.sdk":"https://github.com/xindong/TAPSDK_UPM.git#1.0.6",
        "com.tds.global":"https://github.com/xindong/TDS_GLOBAL_UPM.git#1.0.0",
    }
}
```

## 3.配置SDK

获取针对当前平台的TDSGlobal配置文件 ，请联系平台获取以下四个文件 

- IOS 将**TDSGlobal-Info.plist**、**TDS-Info.plist**配置文件复制到**Assets/Plugins/iOS/Resource**中  
- Android 将**TDSGlobal_info.json**、**google-Service.json** 文件复制到**Assets/Plugins/Android/assets**中

自动配置脚本参考 [注意事项](#tips)

### 3.1 [IOS](https://git.gametaptap.com/tds-public/tdsglobal/-/blob/master/doc/iOS/ios_doc.md)

TDSGlobal Unity SDK会自动配置iOS相关依赖，但需要开发者确认是否配置正确。

#### 3.1.1 配置编译选项

在**Capabilities**中打开In-App Purchase、Push Notifications、Sign In With Apple功能。

#### 3.1.2 检查系统依赖

请检查项目中是否已自动添加以下依赖项：

	AdSupport.framework
	LocalAuthentication.framework
	AuthenticationServices.framework
	SystemConfiguration.framework
	Accelerate.framework
	SafariServices.framework
	Webkit.framework
	CoreTelephony.framework
	Security.framework
	libc++.tdb
	AppTrackingTransparency.framework
	AdServices.framework
	iAd.framework
	
若运行时遇到相关依赖库加载报错，可改为 Optional 尝试。

#### 3.1.3 检查配置的URL Types

选择应用 **TARGETS**，点击 **Info** 标签，展开 **URL Types** 。检查是否添加以下几项 URL Scheme.大括号内为游戏App对应参数，在开发者后台获取。

	TapTap	:	tt{taptap-client-id}	
	Facebook:	fb{facebook-app-id}
	Google	:	{reversed-google-client-id}
	Line	: 	line3rdp.{product_bundle_identify}

### 3.2 [Android](https://git.gametaptap.com/tds-public/tdsglobal/-/blob/master/doc/Android/android_doc.md)

#### 配置AndroidManifest.xml文件

打开Project Settings/Player/Publishing Settings/Build/Custom Main Manifest 配置，编辑Manifest.xml文件

添加SDK权限

```xml
    <!-- 添加权限 -->
    <uses-permission android:name="com.android.vending.BILLING" />
    <!-- 获取用户设备信息用 -->
    <uses-permission android:name="android.permission.READ_PHONE_STATE" />
```

facebook相关配置，如未使用到可以不配

```xml
 <meta-data
android:name="com.facebook.sdk.ApplicationId"
android:value="{facebook-cliendId}" />

     <activity
        android:name="com.facebook.FacebookActivity"
        android:configChanges="keyboard|keyboardHidden|screenLayout|screenSize|orientation"
        android:label="@string/app_name" />

    <activity
        android:name="com.facebook.CustomTabActivity"
        android:exported="true">
        <intent-filter>
            <action android:name="android.intent.action.VIEW" />
            <category android:name="android.intent.category.DEFAULT" />
            <category android:name="android.intent.category.BROWSABLE" />
            <data android:scheme="{facebook-scheme}" />
        </intent-filter>
    </activity>

    <!-- Facebook 分享图片使用 -->
    <provider
        android:name="com.facebook.FacebookContentProvider"
        android:authorities="com.facebook.app.FacebookContentProvider{facebook-cliendId}"
        android:exported="true" />
```

##4 4.接口使用
引入命名空间`using TDSGlobal;`

### 4.1 初始化

```c#
TDSGlobal.TDSGlobalSDK.Init((success)=
{
    // 是否初始化成功
});
```

### 4.2 设置SDK语言

```c#
TDSGlobal.TDSGlobalSDK.SetLanguage(TDSGlobal.TDSGlobalLanguage.ZH_CN);
```
##### 语言类型说明

```c#
public class TDSGlobalLanguage
{
    //简体
    public static int ZH_CN = 0;
    //繁体
    public static int ZH_TW = 1;
    //英文
    public static int EN = 2;
    //泰文
    public static int TH = 3;
    //印尼
    public static int ID = 4;
}
```

### 4.3 用户

#### 4.3.1 登陆
```c#
TDSGlobal.TDSGlobalSDK.Login((tdsUser)=>
{
    //返回用户信息
},(tdsError)=>
{
    //登陆失败
});
```

#### 4.3.2 获取用户信息
```c#
TDSGlobal.TDSGlobalSDK.GetUser((tdsUser)=>
{
    //返回用户信息
},(tdsError)=>
{
    //获取失败
});
```
#### 4.3.3 添加用户状态回调
```c#
TDSGlobal.TDSGlobalSDK.AddUserStatusChangeCallback((code,message)=>
{
    if(code == TDSGlobalUserStatusCode.LOGOUT)
    {
        //退出登录
    }else if(code == TDSGlobalUserStatusCode.BIND_CHANGE)
    {
        //绑定状态变更
    }else if(code == TDSGlobalUserStatusCode.DELETE)
    {
        //删除账号
    }
});
```
#### 4.3.4 用户中心
```c#
TDSGlobal.TDSGlobalSDK.UserCenter();
```

##### 用户信息说明

```c#
public class TDSGlobalUser
{
    [Serializable]
    public class TDSGlobalUser
    {   
        // user id
        public string id;
        // user id in string
        public string sub;
        // use Name
        public string name;
        // Token
        public TDSGlobalAccessToken token;
    
    }

    [Serializable]
    public class TDSGlobalAccessToken
    {
        //认证码
        public string accessToken;
        //唯一标示
        public string kid;
        //mac密钥
        public string macKey;
        //mac密钥计算方式
        public string macAlgorithm;
        //认证码类型
        public string tokenType;
        
    }
}
```

#### 4.4 支付

##### 4.4.1 购买商品
```c#
/*
 * orderId 订单ID。游戏侧订单号，服务端支付回调会包含该字段
 * productId 商品ID。到AppStore购买的商品ID
 * roleId 角色ID。支付角色ID，服务端支付回调会包含该字段
 * serverId 服务器ID。所在服务器ID，不能有特殊字符，服务端支付回调会包含该字段
 * ext 透传参数。服务端支付回调会包含该字段。可用于标记区分充值回调地址，如需使用该功能，请联系平台进行配置。
 */
TDSGlobal.TDSGlobalSDK.PayWithProduct(orderId,productId,roleId,serverId,ext,(orderInfo)=>
{
    //支付成功
},(tdsError)=>
{
    //支付失败
});
```

##### 4.4.2 查询商品信息
```c#
/**
 * productIds 查询的商品Id数组
 */
TDSGlobal.TDSGlobalSDK.QueryWithProductIds(productIds,(skuList)=>
{
    //返回商品 TDSGlobalSkuDetail list
},(tdsError)=>
{
    //查询失败
});
```

##### 4.4.3 查询未完成的订单
```c#
TDSGlobal.TDSGlobalSDK.QueryRestoredPurchases((transactions)=>
{
    // 返回结果
});
```

##### 4.4.4 网页支付(Android)
```c#
TDSGlobal.TDSGlobalSDK.PayWithWeb(serverId,roleId,(tdsError)=>{
    // 返回结果
});
```

#### 4.5 客服反馈

```c#
TDSGlobal.TDSGlobalSDK.Report(serverId,roleId,roleName);
```

#### 4.6 分享

```c#
//分享回调
public interface TDSGlobalShareCallback
{
    void ShareSuccess();

    void ShareCancel();

    void ShareError(string error);
}

```

```c#
//分享URL和链接
TDSGlobal.TDSGlobalSDK.Share(shareType,url,message,tdsShareCallback);
//分享图片
TDSGlobal.TDSGlobalSDK.Share(shareType,imagePath,tdsShareCallback);
```

#### 4.7 日志上报

```c#
//用户信息上报
TDSGlobal.TDSGlobalSDK.TrackUser(roleId,roleName,serverId,level);
// 成就上报
TDSGlobal.TDSGlobalSDK.TrackAchievement()；
//创建角色
TDSGlobal.TDSGlobalSDK.EventCreateRole();
//完成新手指引
TDSGlobal.TDSGlobalSDK.EventCompletedTutorial();
```

#### 4.8 跳转到应用商店

```c#
TDSGlobal.TDSGlobalSDK.StoreReview();
```

### 5.注意事项<a id="tips"></a>

TDSGlobal/Script/Editor目录下的脚本，会帮助游戏自动配置。

#### 4.1 Android
确保TDSGlobal_info.json、google-Service.json 拷贝到 Asssets/Plugins/Android/Assets目录中。

```c#
//TDSGlobal/Script/Editor/TDSGlobakAndroidPostBuildProcessor.cs
//脚本会自动把 Assets中的google-Service.json 文件copy到主工程一级目录下
if(File.Exists(googleServiceOriginPath)){
    //copy google-service.json 到目录下
    File.Copy(googleServiceOriginPath,targetServicePath,true);
}

// 修改project级别的build.gradle 添加GMS插件和TDS私有仓库
writerHelper.WriteBelow(@"task clean(type: Delete) {
    delete rootProject.buildDir
}",@"allprojects {
    buildscript {
        dependencies {
            classpath 'com.google.gms:google-services:4.0.2'
        }
    }
}");

//添加 firebase和GMS插件。如果项目使用GMS或者firebase，请酌情修改。
writerHelper.WriteBelow(@"apply plugin: 'com.android.application'",@"apply plugin: 'com.google.gms.google-services'");

//添加项目所需要的依赖
writerHelper.WriteBelow(@"implementation fileTree(dir: 'libs', include: ['*.jar'])",@"
        implementation 'com.google.firebase:firebase-core:16.0.1'
        implementation 'com.google.firebase:firebase-analytics:15.0.1'
        implementation 'com.google.firebase:firebase-messaging:17.3.4'

        implementation 'com.google.android.gms:play-services-auth:16.0.1'
        implementation 'com.facebook.android:facebook-login:5.15.3'
        implementation 'com.facebook.android:facebook-share:5.15.3'
        implementation 'com.appsflyer:af-android-sdk:4.11.0'
        implementation 'com.adjust.sdk:adjust-android:4.24.1'
        implementation 'com.android.installreferrer:installreferrer:2.1'
        implementation 'com.android.billingclient:billing:3.0.0'
    
        implementation 'com.android.support:support-annotations:28.0.0'
        implementation 'com.android.support:appcompat-v7:28.0.0'
        implementation 'com.android.support:recyclerview-v7:28.0.0'
    ");
```

#### 4.2 IOS

确保TDSGlobal-Info.plist 拷贝到 Assets/Plugins/IOS目录中，脚本会自动配置依赖项。

```c#

//脚本拷贝 TDSGlobal/Plugins/IOS/Resource 下的资源文件并且添加到framework的依赖中
List<string> names = new List<string>();    
names.Add("TDSGlobalSDKResources.bundle");
names.Add("LineSDKResource.bundle");
names.Add("GoogleSignIn.bundle");
names.Add("TDSGlobal-Info.plist");
foreach (var name in names)
{
    proj.AddFileToBuild(target, proj.AddFile(Path.Combine(resourcePath,name), Path.Combine(resourcePath,name), PBXSourceTree.Source));
}

//脚本自动添加plist
List<string> items = new List<string>()
{
    "tapsdk",
    "tapiosdk",
    "fbapi",
    "fbapi20130214",
    "fbapi20130410",
    "fbapi20130702",
    "fbapi20131010",
    "fbapi20131219",
    "fbapi20140410",
    "fbapi20140116",
    "fbapi20150313",
    "fbapi20150629",
    "fbapi20160328",
    "fb-messenger-share-api",
    "fbauth2",
    "fbshareextension",
    "lineauth2"
};

//自动添加 Global-Info.plist 中的facebook、Google、TapTap、Line等第三方SDK的ClientId
if(taptapId!=null)
{
    dict2.SetString("CFBundleURLName", "TapTap");
    PlistElementArray array2 = dict2.CreateArray("CFBundleURLSchemes");
    array2.AddString(taptapId);
}
if(googleId!=null)
{
    dict2 = array.AddDict();
    dict2.SetString("CFBundleURLName", "Google");
    PlistElementArray array2 = dict2.CreateArray("CFBundleURLSchemes");
    array2 = dict2.CreateArray("CFBundleURLSchemes");
    array2.AddString(googleId); 
}
if(facebookId!=null)
{
    dict2 = array.AddDict();
    dict2.SetString("CFBundleURLName", "Facebook");
    PlistElementArray array2 = dict2.CreateArray("CFBundleURLSchemes");
    array2 = dict2.CreateArray("CFBundleURLSchemes");
    array2.AddString(facebookId);
}
File.WriteAllText(_plistPath, _plist.WriteToString());

//自动修改UnityAppController.mm文件，进行TDSGlobalSDK的配置
string unityAppControllerPath = pathToBuildProject + "/Classes/UnityAppController.mm";
TDSGlobalEditor.TDSGlobalScriptStreamWriterHelper UnityAppController = new TDSGlobalEditor.TDSGlobalScriptStreamWriterHelper(unityAppControllerPath);
//在指定代码后面增加一行代码
UnityAppController.WriteBelow(@"#import <OpenGLES/ES2/glext.h>", @"#import <TDSGlobalSDKCoreKit/TDSGlobalSDK.h>");
UnityAppController.WriteBelow(@"[KeyboardDelegate Initialize];",@"[TDSGlobalSDK application:application didFinishLaunchingWithOptions:launchOptions];");
UnityAppController.WriteBelow(@"AppController_SendNotificationWithArg(kUnityOnOpenURL, notifData);",@"[TDSGlobalSDK application:app openURL:url options:options];");
UnityAppController.WriteBelow(@"NSURL* url = userActivity.webpageURL;",@"[TDSGlobalSDK application:application continueUserActivity:userActivity restorationHandler:restorationHandler];");
UnityAppController.WriteBelow(@"handler(UIBackgroundFetchResultNoData);",@"[TDSGlobalSDK application:application didReceiveRemoteNotification:userInfo fetchCompletionHandler:completionHandler];");
Debug.Log("修改代码成功");
```