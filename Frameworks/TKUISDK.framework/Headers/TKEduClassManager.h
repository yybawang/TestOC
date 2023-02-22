//
//  TKEduClassManager.h
//  TKUISDK
//
//  Created by talkcloud on 2019/9/24.
//  Copyright © 2019 talkcloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TKEduRoomDelegate.h"
@class TKCheckDeviceVC;

NS_ASSUME_NONNULL_BEGIN

@interface TKEduClassManager : NSObject

/// 是否在刷新教室
@property (nonatomic,assign) BOOL isRefreshClassRoom;


/// 是否允许网络状态上传 默认为NO
@property (nonatomic, assign, readonly) BOOL upload;

/**
 checkRoom成功后 房间属性
 */
@property (nonatomic, strong)NSDictionary *roomJson;

// 外部连接打开
@property (nonatomic, assign) BOOL  isUrlOpen;


+ (instancetype)shareInstance;

/**
 进入房间的函数
 @param paramDic *号为必填
 	serial（* 课堂号）、
 	nickname（* 用户昵称）、
    userrole(* 用户角色 老师:"0", 学生:"2", 巡课:"4")、
    桌面共享:bundleid (桌面共享进程的bundleid,为空视为无共享功能) 、groupid (桌面共享的appGroupid)
 	可选:password(密码)、host（服务器地址）、port（服务器端口号）、userid(用户ID，可选)、server(主机, 可选)
 @param controller 视图控制器， 通常与下边delegate相同
 @param delegate 遵循TKEduRoomDelegate代理
 @param isFromWeb 是否是从网址链接进入进入(传NO)
 @return 是否成功 0成功
 */
- (int)joinRoomWithParamDic:(NSDictionary*)paramDic

             ViewController:(UIViewController*)controller
                   Delegate:(id<TKEduRoomDelegate>)delegate
                  isFromWeb:(BOOL)isFromWeb;

/**
 进入回放房间的函数
 
 @param paramDic *号为必填
 	serial（* 课堂号）、
 	path（* 回放路径)、
 	recordtitle(*)、
 	可选:host（服务器地址）、port（服务器端口号)、
    userid (userid 只播放老师和该userid学生)
 @param controller 视图控制器，通常与下边delegate相同
 @param delegate 遵循TKEduRoomDelegate代理，供给用户进行处理
 @param isFromWeb 是否是从网址链接进入进入
 @return 是否成功 0成功  
 */
- (int)joinPlaybackRoomWithParamDic:(NSDictionary *)paramDic
                     ViewController:(UIViewController*)controller
                           Delegate:(id<TKEduRoomDelegate>)delegate
                          isFromWeb:(BOOL)isFromWeb;

/// 从网页链接进入房间(直播\回放)
/// @param url 网页url userid (&拼接userid 只播放老师和该userid学生)
- (void)joinRoomWithUrl:(NSString*)url;


/// ⚠️⚠️⚠️废弃：API_DEPRECATED：use -playVideo:path:style: instead.
/// @param path MP4回放地址
/// @param controller 代理
- (void)joinRoomWithPlaybackPath:(NSString*)path ViewController:(UIViewController*)controller;


/// 进入MP4回放页面
/// @param path MP4回放地址
/// @param controller 代理
/// @param skipTime 时间点
/// @param breakurl breakurl
- (void)joinRoomWithPlaybackPath:(NSString*)path ViewController:(UIViewController*)controller skipTime:(NSString *)skipTime breakurl:(NSString *)breakurl;


/// 播放视频
/// @param vc 控制器用于弹出播放页面
/// @param path 视频路径
/// @param style 播放器主题  0:默认主题；1：暗色主题； 2：黑色主题
-(void)playVideo:(UIViewController *)vc path:(NSString *)path style:(NSInteger)style;

/*
 通过教室号播放MP4回放
 @param paramDic *号为必填
     serial（* 课堂号）
 */
//- (void)enterMP4PlayBackViewWithController:(UIViewController *)controller param:(NSDictionary *)param;

/// 离开房间
- (void)leaveRoom;

/// AppDelegate  applicationDidBecomeActive 请调用此方法
- (void)applicationDidBecomeActive;


/// 是否显示课程结束后的web页面, 默认根据后台配置的地址 是否显示.
/// @param isShow 是否显示
- (void)showEndClassWebPage:(BOOL)isShow;


/// 更新语音识别的令牌
- (void)refreshVoiceSign;


/// 课程结束后的web页面, 默认显示后台配置地址.
/// @param url 地址, 默认拼接 教室号和教室名称
- (void)endClassUrl:(NSString *)url;



/// 设备检测
/// @param domain  企业域名
/// @param userid  用户id
/// @param checkCallback 摄像头是正常使用 麦克风是否开启 系统音量 延迟数据(ms) 上传速率(kbps) 下载速率(kbps)
-(void)showDeviceStatusCheckDomain:(NSString *)domain  userid:(NSString *)userid callBack:(void (^_Nullable)(BOOL, BOOL, NSInteger, NSInteger, NSInteger, NSInteger))checkCallback;



/// 是否允许网络状态上传
/// @param upload 默认为no
-(void)allowUploadCheckResult:(BOOL)upload;


// 进程将被杀死
- (void)applicationWillTerminate;

@end


NS_ASSUME_NONNULL_END
