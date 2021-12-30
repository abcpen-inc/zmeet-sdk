//
//  ViewController.m
//  ZPhotoDemo
//
//  Created by bingo on 2021/12/22.
//

#import "ViewController.h"
#import <ZmeetPhotoKit/ZmeetPhotoKit.h>
#import <SVProgressHUD/SVProgressHUD.h>
#import "UIView+Toast.h"

@interface ViewController ()<ZPhotoEngineKitDelegate>

@property (weak, nonatomic) IBOutlet UITextField *textMeetingId;

@property(nonatomic, strong) NSString *userId;
@end

@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Do any additional setup after loading the view.
    NSString *uid = [[NSUserDefaults standardUserDefaults] objectForKey:@"userId"];
    int y =100 +  (arc4random() % 10001);
    self.userId = uid?uid:[NSString stringWithFormat:@"%d",y];
    [[NSUserDefaults standardUserDefaults]  setObject:self.userId forKey:@"userId"];
    [ZPhotoEngineKit sharedEngine].delegate = self;
}

- (IBAction)ownerJoin:(id)sender {
    ZPhotoUserInfo *userInfo = [[ZPhotoUserInfo alloc] init];
    userInfo.targetId = self.userId;
    userInfo.role = ZPhotoRole_OWNER;
    [[ZPhotoEngineKit sharedEngine] join:self userInfo:userInfo channelId:self.textMeetingId.text];
}

- (IBAction)otherJoin:(id)sender {
    ZPhotoUserInfo *userInfo = [[ZPhotoUserInfo alloc] init];
    userInfo.targetId = self.userId;
    userInfo.role = ZPhotoRole_OTHER;
    [[ZPhotoEngineKit sharedEngine] join:self userInfo:userInfo channelId:self.textMeetingId.text];
}

#pragma mark - ZPhotoEngineKitDelegate
-(void) joinRoomError:(JoinFailReason) reason
{
    switch (reason) {
        case JoinFailReasonAuth:
            [self.view makeToast:@"授权失败"];
            break;
        case JoinFailReasonTokenInvalid:
            [self.view makeToast:@"token校验失败"];
            break;
        case JoinFailReasonRoom:
            [self.view makeToast:@"加入房间失败"];
            break;
        default:
            break;
    }
}


/*!
ViewController dismiss
*/
-(void) meetingViewControllerDismiss
{
    
}

/**
show 加载框
*/
-(void) showProgress
{
    [SVProgressHUD show];
}


/**
dismiss 加载框
*/
-(void) dismissProgress
{
    [SVProgressHUD dismiss];
}

@end
