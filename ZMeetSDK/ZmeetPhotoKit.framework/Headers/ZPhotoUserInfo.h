//
//  ZPhotoUserInfo.h
//  ZmeetPhotoKit
//
//  Created by bingo on 2021/12/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

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

NS_ASSUME_NONNULL_END
