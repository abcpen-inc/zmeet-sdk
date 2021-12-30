//
//  AppDelegate.m
//  ZPhotoDemo
//
//  Created by bingo on 2021/12/22.
//

#import "AppDelegate.h"
#import <ZmeetPhotoKit/ZmeetPhotoKit.h>
#import "ViewController.h"

static NSString *APP_ID = ;
static NSString *APP_SECRET =;

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [[ZPhotoEngineKit sharedEngine] initWithAppId:APP_ID appSecret:APP_SECRET];
    return YES;
}

@end
