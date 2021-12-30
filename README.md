# ``ZmeetPhotoKit``

### REVISION HISTORY

| Version | Date       | Changed By | Changes |
| ------- | ---------- | ---------- | ------- |
| 0.0.1   | 2021-12-22 | Bing       | init    |

### 准备环境

请确保满足以下开发环境要求：

- iOS 10.0或以上版本
- ZmeetPhotoKit
- ZmeetCoreKit
- GoogleWebRTC

### 添加 framework

- 添加ZmeetCoreKit.framework, ZmeetPhotoKit.framework，GoogleWebRTC.framework

### POD 导入(TODO)

```
pod 'ZMeetSDK/ZmeetPhotoKits', '~>0.0.1'
pod 'ZMeetSDK/ZmeetCoreKit','~>0.0.1'
pod 'GoogleWebRTC','~1.1.31999'
```



### 接口

#### 初始化sdk

```objective-c
#import <ZmeetPhotoKit/ZPhotoEngineKit>

/*!
 @param appId zmeet appid
 @param appSecret zmeet appSecret
  */
-(instancetype) initWithAppId:(NSString *) appId
                    appSecret:(NSString *) appSecret;

/**
 @param viewCtrl 唤起的viewCtrl
 @param userInfo 用户信息，targetId必填
 */
-(void) join:(UIViewController *) viewCtrl userInfo:(ZPhotoUserInfo *) userInfo;
```

#### model



```objective-c
typedef enum : NSInteger{
    ZPhotoRole_OWNER, //会议发起者
    ZPhotoRole_OTHER //会议参与者
} ZPhotoRole;

@interface ZPhotoUserInfo : NSObject

/**
 必填
 targetId   zmeet 用户身份（用户唯一标识（手机号））
 */
@property(nonatomic,strong) NSString *targetId;

/**
 头像
 */
@property(nonatomic,strong) NSString *avatar;

/**
 名字
 */
@property(nonatomic,strong) NSString *name;

/**
 角色
 */
@property(nonatomic,assign) ZPhotoRole role;


@end
```



### 回调

```objective-c
[ZPhotoEngineKit sharedEngine].delegate = self;
/*!
 加入会议回调
 
 @param reason  失败原因
 */
-(void) joinRoomError:(JoinFailReason *) reason;


/*!
 ViewController dismiss
 */
-(void) didViewControllerDismiss;
```