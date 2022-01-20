//
//  AppDelegate.m
//  ZPhotoDemo
//
//  Created by bingo on 2021/12/22.
//

#import "AppDelegate.h"
#import <ZmeetPhotoKit/ZmeetPhotoKit.h>
#import "ViewController.h"

static NSString *APP_ID = @"7b79df73a7744e6ba7e9373a3f989808";
static NSString *APP_SECRET = @"2ca16515b25649b5a4aac8f931d3b983";

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [[ZPhotoEngineKit sharedEngine] initWithAppId:APP_ID appSecret:APP_SECRET];
    return YES;
}

@end
