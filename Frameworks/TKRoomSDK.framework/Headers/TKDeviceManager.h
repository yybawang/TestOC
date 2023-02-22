//
//  TKDeviceManager.h
//  TKRoomSDK
//
//  Created by tuyuanyou on 2022/8/19.
//  Copyright © 2022 MAC-MiNi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TKRoomDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface TKDeviceManager : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 * 测试视频设备
 *
 * @param canvas  承载视频画面的控件
 * @param frontCamera YES：前置摄像头；NO：后置摄像头。
 * @note 如果retrun值 返回-2，表示多次调用startVideoTest，需在startVideoTest之前调用stopVideoTest。
 */
- (int)startVideoTest:(TKVideoCanvas *)canvas isFront:(BOOL)frontCamera;
- (void)stopVideoTest;


@end

NS_ASSUME_NONNULL_END
