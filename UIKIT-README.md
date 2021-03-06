# ``ZmeetUIKit``

[![Version](https://img.shields.io/cocoapods/v/ZMeetSDK.svg?style=flat)](http://cocoapods.org/pods/ZMeetSDK)
[![License](https://img.shields.io/cocoapods/l/ZMeetSDK.svg?style=flat)](http://cocoapods.org/pods/ZMeetSDK)
[![Platform](https://img.shields.io/cocoapods/p/ZMeetSDK.svg?style=flat)](http://cocoapods.org/pods/ZMeetSDK)

### REVISION HISTORY

| Version | Date       | Changed By | Changes |
| ------- | ---------- | ---------- | ------- |
| 1.0.0   | 2022-04-26 |Bing        |  1.0.0  |

### 准备环境

请确保满足以下开发环境要求：

- iOS 10.0或以上版本
- ZmeetUIKit
- ZmeetCoreKit

### POD

```
pod 'ZMeetSDK/ZmeetUIKit'
pod 'ZMeetSDK/ZmeetCoreKit'
```



### 接口

#### 初始化sdk

```objective-c
#import <ZmeetUIKit/ZmeetUIKit.h>

/*!
 @param appId zmeet appid
 @param appSecret zmeet appSecret
  */
-(instancetype) initWithAppId:(NSString *) appId
                    appSecret:(NSString *) appSecret;

/**
 @param viewCtrl 唤起的viewCtrl
 @param userInfo 用户信息，targetId必填
 @param topic 会议主题
 */
-(void) createAndJoin:(UIViewController *) viewCtrl userInfo:(ZUserInfo *) userInfo topic:(NSString *) topic;

/**
 @param viewCtrl 唤起的viewCtrl
 @param userInfo 用户信息，targetId必填
 @param channelId 会议号
 */
-(void) join:(UIViewController *) viewCtrl userInfo:(ZPhotoUserInfo *) userInfo channelId:(NSString *) channelId;


/**
 参与者加入会议
 join with userInfo 保留
 @param viewCtrl 唤起的viewCtrl
 @param mobile 用户手机号
 @param meetId 会议号 同channelId
 */
-(void) join:(UIViewController *) viewCtrl mobile:(NSString *) mobile meetId:(NSString *) meetId;

/**
 主持人开启会议
 @param viewCtrl 唤起的viewCtrl
 @param mobile 用户手机号
 */
-(void) lauch:(UIViewController *) viewCtrl mobile:(NSString *) mobile topic:(NSString *) topic;

/**
 外部结束会议
 */
-(void) finishMeeting;

/**
 外部离开会议
 */
-(void) leaveMeeting;
```

#### model



```objective-c
typedef enum : NSInteger{
    ZUserRole_OWNER, //会议发起者
    ZPhotoRole_OTHER //会议参与者
} ZPhotoRole;

@interface ZUserInfo : NSObject

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
@property(nonatomic,assign) ZUserRole role;


@end
```



### 回调
```objective-c
typedef NS_ENUM(NSUInteger, JoinFailReason) {
    JoinFailReasonNetError = -9999, //网络异常
    JoinFailReasonAuth = -1, //授权失败
    JoinFailReasonLimit = 1002, //人数上限
    JoinFailReasonServerLimit = 1001, //全网同时进行会议数限制 （根据具体服务器情况）
    JoinFailReasonRoomNotExsit =2001// 房间不存在
};

[ZmeetEngineKit sharedEngine].delegate = self;
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
 用户加入成功，带会议主题
 */
-(void) onJoinSuccess:(NSString *) channelId targetId:(NSString *) targetId topic:(NSString *) topic;


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

/**
 用户离开
 */
-(void) onLeave:(NSString *) channelId targetId:(NSString *) targetId;

/**
 用户踢出回调
 */
-(void) onKickOut:(NSString *) channelId targetId:(NSString *) targetId;
```


## 快速接入会议功能
### Step1 初始化SDK
token生成规则详见服务器文档（*建议把appid和appsecret放到服务器操作）
~~~
 [ZRtcEngineKit sharedEngine];
~~~
### Step2 加入会议
```
/**
  [[ZRtcEngineKit sharedEngine] initSDK];
 [[ZRtcEngineKit sharedEngine] joinChannelByToken:accessToken channelId:self.textField.text uid:self.userId displayName:@"demo1"];
            } failure:^(NSError * _Nonnull error) {
                [SVProgressHUD dismiss];
            }];
```

### 其它接口

#### 离开会议
```

/**
 离开
 */
-(void) leaveChannel;
```

#### 设置本地视频预览view
```
/**
 设置本地视频载体，canvas.uid 需与本地userId对应
 */
-(void) setupLocalVideo:(ZMeetVideoCanvas *) canvas;
```

#### 设置远程视频预览view
```
/**
 设置远端视频载体，canvas.uid与远端用户useerId对应，一般在firstRemoteVideoFrameOfUid 中掉用
 */
-(void) setupRemoteVideo:(ZMeetVideoCanvas *) canvas;
```

#### 开启本地音频
```
/**
 开启音频
 */
-(void) enableAudio;
```
#### 关闭本地音频
```
/**
 关闭音频
 */
-(void) disenableAudio;
```
#### 开启本地视频
```
/**
 开启视频
 */
-(void) enableVideo;
```

#### 关闭本地视频
```
/**
 关闭视频
 */
-(void) disEnableVideo;
```

#### 切换本地摄像头
```
/**
 切换视频方向，如果有前后置摄像头
 */
-(void) switchCamera;
```

#### mute  本地音频
```
/**
 mute  本地音频
 */
-(void) muteLocalAudioStream:(BOOL)mute;
```
#### mute  本地视频
```
/**
 mute 本地视频
 */
-(void) muteLocalVideoStream:(BOOL)mute;
```
