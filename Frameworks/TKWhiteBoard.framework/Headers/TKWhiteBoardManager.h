//
//  TKWhiteBoardManager.h
//  TKWhiteBoard
//
//  Created by MAC-MiNi on 2018/4/9.
//  Copyright © 2018年 MAC-MiNi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TKWhiteBoardManagerDelegate.h"
@class TKDrawView;
@class DocShowView;

@class TKWBRoomConfiguration;
@class TKFileModel;

NS_ASSUME_NONNULL_BEGIN

typedef void(^pageControlRemarkBlock)(NSDictionary *remark);

@interface TKWhiteBoardManager : NSObject

@property (nonatomic, copy) pageControlRemarkBlock  pageControlMarkBlock;// 课件备注

@property (nonatomic, weak) id<TKWhiteBoardManagerDelegate> delegate;

@property (nonatomic, strong) TKFileModel * fModel;         // 当前加载的文档模型.
@property (nonatomic, assign, readonly) BOOL isShowOnWeb;   // 是否web加载;
@property (nonatomic, assign) BOOL isOnScreenShare;         // 是否正在屏幕共享中(不包含媒体共享)
@property (nonatomic, strong) UIColor * whiteBoardBgColor;  //白板背景色
@property (nonatomic, strong) UIView *contentView;
@property (nonatomic, strong) NSMutableDictionary * whiteBoardCustomBgDic;//自动以白板背景数据
@property (nonatomic, strong) NSMutableArray * usableServerHostArr;//可用的
@property (nonatomic, copy) NSString * serverDocAddrKey;    //文档服务器地址


/**
 单例
 */
+ (instancetype)shareInstance;

// 创建白板组件
- (UIView *)createWhiteBoardWithFrame:(CGRect)frame;

/**
 销毁白板
 */
+ (void)destroy;

/**
 注册白板 代理和配置
 */
- (void)registerDelegate:(id<TKWhiteBoardManagerDelegate>)delegate configration:(NSDictionary *)config;

// 加载课件
- (int)showDocumentWithFileDic:(NSDictionary *)fileDic isPubMsg:(BOOL)isPubMsg;

// 重置白板所有的数据
- (void)resetWhiteBoardAllData;

// 刷新白板
- (void)refreshWhiteBoard;

// 刷新 webview scrollview offset (键盘消失 webview 不弹回)
- (void)refreshWBWebViewOffset:(CGPoint) point;

/**
 清空所有数据
 */
- (void)clearAllData;

/**
 重新加载白板  @此方法仅供白板测试使用
 */
- (void)webViewReload;

// 音频录制
- (void)recordAudioUploadUrl:(NSString *)url_str;

//语音结束
- (void)speechEvaluatuonResult:(CGFloat)score isSuccess:(BOOL)success;

//语音开始回调
- (void)startSpeechEvaluatuonSuccess:(BOOL)success;
// 关闭动态ppt内部播放的mp4
//- (void)whiteBoardCloseDynamicPptWebPlay;

// 获取外播视图
- (UIView *)getWhiteBoardOutplayView;

// 获取drawView
- (NSDictionary *)getWhiteBoarddrawDictionary;

-(TKDrawView *)getWhiteBoardDraw;

-(DocShowView *)getWhiteBoardDocView;

#pragma mark - 画笔控制
// 选择工具
- (void)brushToolsDidSelect:(TKBrushToolType)BrushToolType;

// 选择图形
- (void)didSelectDrawType:(TKDrawType)type color:(NSString *)hexColor widthProgress:(float)progress;

#pragma mark - 课件控制
/**
 课件 上一页
 */
- (void)previousPage;

/**
 课件 下一页
 */
- (void)nextPage;

/**
 课件 跳转页

 @param pageNum 页码
 */
- (void)turnToPage:(int)pageNum;


/// 课件 跳转页
/// @param pageNum 页码
/// @param step 帧数
- (void)turnToPage:(int)pageNum frameStep:(int)step;

/**
 白板 放大
 */
- (void)enlarge;

/**
 白板 缩小
 */
- (void)narrow;

/**
 白板 重置大小
 */
- (void)resetEnlarge;

NS_ASSUME_NONNULL_END
@end
