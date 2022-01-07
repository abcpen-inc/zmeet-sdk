//
//  ZPhotoEngineKit.h
//  ZmeetPhotoKit
//
//  Created by bingo on 2021/12/22.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "ZPhotoUserInfo.h"

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, JoinFailReason) {
    JoinFailReasonNetError = -9999, //网络异常
    JoinFailReasonRoomError = -8888, //加入会议失败
    JoinFailReasonAuth = -1, //授权失败
    JoinFailReasonLimit = 1002, //人数上限
    JoinFailReasonServerLimit = 1001, //全网同时进行会议数限制 （根据具体服务器情况）
    JoinFailReasonRoomNotExsit =2001// 房间不存在
};


@protocol ZPhotoEngineKitDelegate<NSObject>


@optional
/*!
 加入会议回调
 
 @param reason  失败原因
 */
-(void) joinRoomError:(JoinFailReason) reason ;


/*!
 ViewController dismiss
 */
-(void) meetingViewControllerDismiss;

/**
 show 加载框
 */
-(void) showProgress;


/**
 dismiss 加载框
 */
-(void) dismissProgress;

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
@end

@interface ZPhotoEngineKit : NSObject

@property (strong, nonatomic,readonly) NSString *currentTargetId;

@property (strong, nonatomic,readonly) NSString *currentChannelId;

@property (assign, nonatomic, readonly) ZPhotoRole currentRole;

@property (nullable, weak, nonatomic) id<ZPhotoEngineKitDelegate> delegate;


+ (instancetype)sharedEngine;

/*!
 @param appId zmeet appid
 @param appSecret zmeet appSecret
  */
-(void) initWithAppId:(NSString *) appId
            appSecret:(NSString *) appSecret;

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
-(void) lauch:(UIViewController *) viewCtrl mobile:(NSString *) mobile;


@end

NS_ASSUME_NONNULL_END
