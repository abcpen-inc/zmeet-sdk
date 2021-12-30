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
    JoinFailReasonTokenInvalid = 0, //token失效
    JoinFailReasonRoom = 1, //加入会议失败
    JoinFailReasonAuth = 2 //授权失败
};


@protocol ZPhotoEngineKitDelegate<NSObject>


@optional
/*!
 加入会议回调
 
 @param reason  失败原因
 */
-(void) joinRoomError:(JoinFailReason) reason;


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

@end

NS_ASSUME_NONNULL_END
