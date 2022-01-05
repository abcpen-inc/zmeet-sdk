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

typedef NS_ENUM(NSUInteger, JoinFailReason) {
    JoinFailReasonAuth = -1, //授权失败
    JoinFailReasonLimit = 1002, //人数上限
    JoinFailReasonServerLimit = 1001, //全网同时进行会议数限制 （根据具体服务器情况）
    JoinFailReasonRoomNotExsit =2001// 房间不存在
};

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

#pragma mark - meet
/**
 用户加入成功
 */
-(void) onJoinSuccess:(NSString *) channelId targetId:(NSString *) targetId;

/**
 远端用户加入
 */
-(void) onRemoteUserJoined:(NSString *) targetId name:(NSString *) name;

/**
 远端用户离开
 */
-(void) onRemoteUserOffline:(NSString *) targetId;

/**
 会议结束
 */
-(void) onMeetFinish;
```