//
//  ZVideoView.h
//  ZmeetCoreKit
//
//  Created by bingo on 2021/12/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ZVideoView;

typedef NS_ENUM(NSInteger, ZVideoViewObjectFit) {
  /**
   * 视频等比
   *
   */
  ZVideoViewObjectFitContain,
  /**
   * 填充
   *
   */
  ZVideoViewObjectFitCover
};

@protocol ZVideoViewDelegate <NSObject>

- (void)videoView:(ZVideoView *)videoView didChangeVideoSize:(CGSize)size;


@end

@interface ZVideoView : UIView

@property(nonatomic) ZVideoViewObjectFit objectFit;
    
@property (nullable, weak, nonatomic) id<ZVideoViewDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
