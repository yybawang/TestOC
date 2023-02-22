//
//  TKRoomDefines.h
//  TKRoomSDK
//
//  Created by MAC-MiNi on 2018/4/20.
//  Copyright © 2018年 MAC-MiNi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define TK_Deprecated(string) __attribute__((deprecated(string)))

#
#pragma mark - joinroom 相关定义
#
//******调用joinroom 接口进入房间，roomParams字典参数所需 Key值定义******//
//房间ID @required
FOUNDATION_EXTERN NSString * const TKJoinRoomParamsRoomIDKey;
//密码key值 @required，如果该房间或者该用户角色没有密码，value：@""
FOUNDATION_EXTERN NSString * const TKJoinRoomParamsPasswordKey;

//用户角色key值 @optional
FOUNDATION_EXTERN NSString * const TKJoinRoomParamsUserRoleKey;
//用户ID的key值 @optional，如果不传用户ID，sdk会自动生成用户ID
FOUNDATION_EXTERN NSString * const TKJoinRoomParamsUserIDKey;

#pragma mark  joinroom token方式
//如果使用token的方式join room，需要roomParams中添加以下参数

//token
FOUNDATION_EXTERN NSString * const TKJoinRoomParamsToken;
//时间戳，token权限时间
FOUNDATION_EXTERN NSString * const TKJoinRoomParamsPrivilegeExpiredTs;


#
#pragma mark - pub/delete msg 相关定义
#
//******调用pubMsg以及delMsg 接口发送信令，toID参数相关传值；表示：此信令需要通知的对象******//
//所有人
FOUNDATION_EXTERN NSString * const TKRoomPubMsgTellAll;
//除自己以外的所有人
FOUNDATION_EXTERN NSString * const TKRoomPubMsgTellAllExceptSender;
//除旁听用户以外的所有人
FOUNDATION_EXTERN NSString * const TKRoomPubMsgTellAllExceptAuditor;
//不通知任何人
FOUNDATION_EXTERN NSString * const TKRoomPubMsgTellNone;

#
#pragma mark -  房间初始化相关设置
#
//******调用- (int)initWithAppKey:optional: 初始化设置 optional字典 key值定义*******//

//使用token方式进入教室，初始化需要传入企业域名
FOUNDATION_EXTERN NSString * const TKRoomSettingOptionalCompanyDomain;

//socekt 自动重连次数，默认是无限次
FOUNDATION_EXTERN NSString * const TKRoomSettingOptionalReconnectattempts;

//若有使用到sdk白板功能，需要设置此参数，表示会接收到白板消息通知。 若不是用sdk白板功能，可不需要设置。
//value：NSNumber类型 YES表示接受通知，NO表示不通知。
FOUNDATION_EXTERN NSString * const TKRoomSettingOptionalWhiteBoardNotify;

// 是否中断进入房间, 发送的TKRoomManagerContinueCheckRoomNotification通知以便继续进入房间.
// Paas 接入方式无需设置.
FOUNDATION_EXTERN NSString * const TKRoomSettingOptionalInteruptCheckRoom;

// UI Version
FOUNDATION_EXTERN NSString * const TKRoomSettingOptionalUIVersion;
//tk_ui_uniform_version
FOUNDATION_EXTERN NSString * const TKRoomSettingOptionalUIUniformVersion;

//设置编码格式 @optional Key值，可不传，若不传会根据房间属性设置。 value：NSNumber类型 TKVideoCodecType枚举值
FOUNDATION_EXTERN NSString * const TKRoomSettingOptionalVideoCodec;
//设置即时房间类型 @optional Key值，可不传，默认是一对多TKRoomType_More。 value：NSNumber类型 TKRoomTypes枚举值
FOUNDATION_EXTERN NSString * const TKRoomSettingOptionalRoomType;

FOUNDATION_EXTERN NSString * const TKRoomSettingOptionalGetRoomFile;

FOUNDATION_EXTERN NSString * const TKRoomSettingOptionalUserAgent;

FOUNDATION_EXTERN NSString * const TKRoomSettingOptionalByPassLocation; 

#pragma mark socekt使用协议参数
//value: NSNumber类型 YES:使用https wss, NO:使用http ws  默认为YES。
FOUNDATION_EXTERN NSString * const TKRoomSettingOptionalSecureSocket;

#pragma mark - 私有部署房间相关
//私有地址  默认为global.talk-cloud.net
FOUNDATION_EXTERN NSString * const TKRoomSettingOptionalPrivateHostAddress;
//私有端口  如果TKRoomSettingOptionalSecureSocket 设置为YES，默认为443；如果TKRoomSettingOptionalSecureSocket 设置为NO，默认为80.
// ***TKRoomSettingOptionalSecureSocket优先.***
FOUNDATION_EXTERN NSString * const TKRoomSettingOptionalPrivatePort;

#
#pragma mark - block重命名
#
typedef void (^completion_block)(NSError *error);
typedef void (^progress_block)(int playID, int64_t current, int64_t total);

#
#pragma mark - TKRoomWarningCode 警告码
#
typedef NS_ENUM(NSInteger, TKRoomWarningCode) {
    TKRoomWarning_UnKnow,
    TKRoomWarning_AudioRouteChange_Headphones           = 121,   //耳机
    TKRoomWarning_AudioRouteChange_BuiltInReceiver,    //听筒模式（手机靠近耳边）
    TKRoomWarning_AudioRouteChange_BuiltInSpeaker,     // 内置扬声器（外放）
    TKRoomWarning_AudioRouteChange_Bluetooth,          // 蓝牙
    
    
    TKRoomWarning_CheckRoom_Completed                   = 1001,    //CheckRoom 成功
    TKRoomWarning_GetConfig_Completed                   = 1002,    //GetConfig 成功
    
    
    TKRoomWarning_Stream_Connected                      = 1101,
    TKRoomWarning_Stream_Failed                         = 1102,
    TKRoomWarning_Stream_Closed                         = 1103,

    TKRoomWarning_ReConnectSocket_ServerChanged         = 5002,   //切换了服务器
    TKRoomWarning_DevicePerformance_Low                 = 5003,   //设备性能过低
    

    TKRoomWarning_ADM_Session_Began_Interrruption = 105,    //音频采集被系统中断，如系统来电，闹钟等
    TKRoomWarning_ADM_Session_Ended_Interrruption = 106,    //音频采集系统中断恢复
    TKRoomWarning_ADM_Record_Audio_Low_Volume = 107,        //录音设备采集到的音量过低
    TKRoomWarning_ADM_PlayOut_Audio_Low_Volume = 108,       //扬声器音量设置过低或被静音


    TKRoomWarning_VDM_Session_Began_Interrrupted  = 154,    //视频采集被系统中断。如 App 进入后台，启动其他使用视频的 App 等
    TKRoomWarning_VDM_Session_Ended_Interrrupted = 155,     //视频采集系统中断恢复
    
    
    
    TKRoomWarning_ADM_Category_Not_PlayAndRecord = 1511,    //在通话过程中，Audio Session 的 category 必须设置成 AVAudioSessionCategoryPlayAndRecord，SDK 会监控这个属性值。当这个值被修改成其他值的时候会触发这个告警，并强制设置回 AVAudioSessionCategoryPlayAndRecord。
    TKRoomWarning_VDM_Session_Began_Interrrupted_InBackground  = 1512,    //App 进入后台，视频采集被中断
    
};

#
#pragma mark - TKRoomErrorCode 错误码
#
typedef NS_ENUM(NSInteger, TKRoomErrorCode) {
    TKErrorCode_UnKnow              = -2,
    TKErrorCode_Internal_Exception  = -1,
    TKErrorCode_OK                  = 0,//isUnusualNetwork
    
    TKErrorCode_SentMsg_ContentTooLong              = 61,      //聊天消息内容过长
    TKErrorCode_SentMsg_HighFrequency               = 62,      //发送聊天消息频率太快
    TKErrorCode_JoinRoom_WrongParam                 = 63,      // join room 参数错误
    TKErrorCode_JoinRoom_Student_Limit_Exceed       = 64,      // join room 学生人数超限
    TKErrorCode_JoinGroup_Failed                    = 65,      // join group 失败
    TKErrorCode_JoinGroup_Repeated                  = 66,      // 前一次加入未完成时，重复调用join group
    TKErrorCode_JoinGroup_TimeOut                   = 67,       //joinGroup 超时
    TKErrorCode_JoinRoom_TeacherAlreadyExists,                  //教室中已有老师,不允许其他老师进入
     
    TKErrorCode_Network_Unusual     = 100,
    TKErrorCode_Not_Initialized     = 101,
    TKErrorCode_Bad_Parameters      = 102,
    
    
    TKErrorCode_ADM_Recording_Device_Not_Allowd = 103,    //麦克风没有授权
    
    TKErrorCode_Publish_StateError  = 104,
    TKErrorCode_VDM_Camera_Not_Allowed = 152,             //相机没有授权
    TKErrorCode_RenderView_ReUsed               = 156,    //渲染视图已被使用
    
    
    
    TKErrorCode_Publish_NoAck                    = 401,
    TKErrorCode_Publish_RoomNotExist             = 402,
    TKErrorCode_Publish_RoomMaxVideoLimited      = 403,//媒体链路超限
    TKErrorCode_Publish_ErizoJs_Timeout          = 404,
    TKErrorCode_Publish_Agent_Timeout            = 405,
    TKErrorCode_Publish_UndefinedRPC_Timeout     = 406,
    TKErrorCode_Publish_AddingInput_Error        = 407,
    TKErrorCode_Publish_DuplicatedExtensionId    = 408,
    TKErrorCode_Publish_Unauthorized             = 409,
    TKErrorCode_Publish_Failed                   = 410,//发布失败，自动重新发布
    TKErrorCode_Publish_Timeout                  = 411,//发布失败，自动重新发布
    
    TKErrorCode_Subscribe_RoomNotExist           = 501,
    TKErrorCode_Subscribe_StreamNotDefine        = 502,
    TKErrorCode_Subscribe_MediaRPC_Timeout       = 503,
    TKErrorCode_Subscribe_Fail                   = 504,//订阅失败，自动重新订阅
    TKErrorCode_Subscribe_Timeout                = 505,//订阅超时，自动重新订阅
    
    TKErrorCode_ConnectSocketError               = 601,

    
    
    TKErrorCode_CheckRoom_RequestFailed          = 801,    //CheckRoom 请求失败
    TKErrorCode_GetConfig_RequestFailed          = 802,    //getconfig 请求失败
    
    TKErrorCode_Room_StateError     = 1500,
    TKErrorCode_Stream_StateError   = 1501,
    TKErrorCode_Stream_NotFound     = 1502,
    TKErrorCode_FilePath_NotExist   = 1503,    //文件路劲不存在
    TKErrorCode_CreateFile_Failed   = 1504,    //创建文件失败
    
    TKErrorCode_VDM_Camera_Runtime_Error = 1505,            //相机运行出错
    TKErrorCode_ADM_AudioUnit_Initialize_Error = 1506,       // 音频设备初始化失败
    
    TKErrorCode_ServerRecord_ing     = 1510,     //正在录制中
    
    TKErrorCode_JoinRoom_Failed                  = 2507,   //joinroom 失败
    
    TKErrorCode_CheckRoom_ServerOverdue          = 3001,    //服务器过期
    TKErrorCode_CheckRoom_RoomFreeze             = 3002,    // 公司被冻结
    TKErrorCode_CheckRoom_RoomDeleteOrOrverdue   = 3003,    //房间已删除或过期
    TKErrorCode_CheckRoom_CompanyHasEnded		 = 3004,    //公司试用已结束

    TKErrorCode_CheckRoom_CompanyNotExist        = 4001,    //该公司不存在
    TKErrorCode_CheckRoom_RoomNonExistent        = 4007,    //房间不存在
    TKErrorCode_CheckRoom_PasswordError          = 4008,    //房间密码错误
    TKErrorCode_CheckRoom_WrongPasswordForRole   = 4012,    //密码与身份不符
    TKErrorCode_CheckRoom_RoomNumberOverRun      = 4103,    //房间人数超限
    TKErrorCode_CheckRoom_RoomAuthenError        = 4109,    //认证错误
    TKErrorCode_CheckRoom_NeedPassword           = 4110,    //该房间需要密码，请输入密码
    TKErrorCode_CheckRoom_RoomPointOverrun       = 4112,    //企业点数超限
    TKErrorCode_CheckRoom_RoomNSF				 = 4113,    //余额不足
    TKErrorCode_CheckRoom_RoomCancelled			 = 4020, 	//课程已取消
    
    TKErrorCode_NotAllowed_JoinTheRoom              = 4117,  // 暂不可进入教室
    TKErrorCode_NotAllowed_JoinLiveRoomForOnlooker = 5300,   // 旁听者不能进入大班课
    
};


#
#pragma mark - TKMediaType 媒体类型
#
typedef NS_ENUM(NSInteger, TKMediaType) {
    TKMediaSourceType_unknow    = -1,
    TKMediaSourceType_camera    = 0,      //视频
    TKMediaSourceType_mic       = 11,
    TKMediaSourceType_file      = 101,    //本地电影共享
    TKMediaSourceType_screen    = 102,    //屏幕共享
    TKMediaSourceType_media     = 103,    //媒体文件 mp4、mp3
};

#
#pragma mark - TKPublishState 发布状态
#
typedef NS_ENUM(NSInteger, TKPublishState) {
    TKUser_PublishState_UNKown          = -2,                //未知状态
    TKUser_PublishState_NONE            = 0,          //没有
    TKUser_PublishState_AUDIOONLY,                  //只有音频
    TKUser_PublishState_VIDEOONLY,                  //只有视频
    TKUser_PublishState_BOTH,                       //都有
    TKUser_PublishState_Extension,                 //4表示在台上，但音视频均为打开
};
#
#pragma mark - TKMediaState 媒体流发布状态
#
typedef NS_ENUM(NSInteger, TKMediaState) {
    TKMedia_Unpulished  = 0,  //未发布
    TKMedia_Pulished    = 1,    //发布
};

#
#pragma mark - TKVideoStreamType 视频流类型
#
typedef NS_ENUM(NSInteger, TKVideoStreamType) {
    TKVideoStream_Big   = 0,  //
    TKVideoStream_Small = 1,    //小流
};

#
#pragma mark - TKVideoCodecType 视频编码格式
#
typedef NS_ENUM(NSUInteger, TKVideoCodecType) {
    TKVideoCodec_VP8 = 0,       //vp8
    TKVideoCodec_H264 = 2,      //h264
};

#
#pragma mark - TKRoomType 即时房间类型
#
typedef NS_ENUM(NSUInteger, TKRoomTypes) {
    TKRoomType_One = 0,       //一对一房间
    TKRoomType_More = 1,      //一对多房间
};

#
#pragma mark - TKRenderMode 渲染模式
#
typedef NS_ENUM(NSInteger, TKRenderMode) {
    TKRenderMode_fit       = 0,  //等比拉伸
    TKRenderMode_adaptive  = 1,  //等比拉伸，并占满全屏
};

#
#pragma mark - TKRenderState 
#
typedef NS_ENUM(NSInteger, TKRenderState) {
    TKRenderState_Interruption  = 0,   //中断
    TKRenderState_Resumption    = 1,   //恢复
};

#
#pragma mark - TKVideoMirrorMode 视频渲染镜像模式
#
typedef NS_ENUM(NSUInteger, TKVideoMirrorMode) {
    TKVideoMirrorModeAuto       = 0,  //默认设置，前置摄像头时开启镜像模式，后置摄像头时不开启镜像
    TKVideoMirrorModeEnabled    = 1,  //前置和后置均开启镜像模式
    TKVideoMirrorModeDisabled   = 2,  //前置和后置均不开启镜像模式
};
#
#pragma mark - TKLogLevel 日志等级
#
typedef NS_ENUM(NSUInteger, TKLogLevel){
    /**
     *  No logs
     */
    TKLogLevelOff = 0,
    
    /**
     *  Error logs only
     */
    TKLogLevelError = (1 << 0),
    
    /**
     *  Error and warning logs
     */
    TKLogLevelWarning = (TKLogLevelError | 1 << 1),
    
    /**
     *  Error, warning and info logs
     */
    TKLogLevelInfo = (TKLogLevelWarning | 1 << 2),
    
    /**
     *  Error, warning, info and debug logs
     */
    TKLogLevelDebug = (TKLogLevelInfo | 1 << 3),
    
    /**
     *  Error, warning, info, debug and verbose logs
     */
    TKLogLevelVerbose = (TKLogLevelDebug | 1 << 4),
    
    /**
     *  All logs (1...11111)
     */
    TKLogLevelAll = NSUIntegerMax
};

#
#pragma mark - TKUserRoleType 用户角色
#
typedef NS_ENUM(NSInteger, TKUserRoleType) {
    TKUserType_Playback   	= -1,   //回放
    TKUserType_Teacher    	= 0,    //老师
    TKUserType_Assistant  	= 1,    //助教
    TKUserType_Student	  	= 2,    //学生
    TKUserType_Live		  	= 3,    //直播
    TKUserType_Patrol		= 4,    //巡课
    TKUserType_ClassTeacher	= 5,    //班主任
    TKUserType_Onlooker     = 6,    //旁听生
    TKUserType_SystemAdministrator = 26, //系统管理员
    TKUserType_Parent       = 27,   //家长
    TKUserType_WorkorderAdministrator = 31,// 工单管理员
    TKUserType_Record   	= 88,   //录制用户
    TKUserType_Interaction 	= 98,	//交互直播房间直播用户
    TKUserType_Bypass		= 99    //旁路直播房间直播用户
    
};

#
#pragma mark - TKRecordType 录制件类型
#
typedef NS_ENUM(NSInteger, TKRecordType) {
    TKRecordType_RecordFile     = 0,    //生成录制件
    TKRecordType_RecordList     = 1,    //生成录制列表
    TKRecordType_RecordMp3File  = 2, //只生成mp3
    TKRecordType_RecordMaxFile  = 3, //同时生产mp3和mp4
};

#
#pragma mark - TKRecordState 录制状态
#
typedef NS_ENUM(NSInteger, TKRecordState) {
    TKRecordState_IDLE            = 0,    //闲置状态
    TKRecordState_Started         = 1,    //开始录制
    TKRecordState_Suspended       = 2,    //暂停录制，预留状态，暂未实现暂停录制功能
    TKRecordState_Stoped          = 3,    //停止录制
};

typedef NS_ENUM(NSInteger, TKNetQuality) {
    TKNetQuality_Excellent  = 1, //优
    TKNetQuality_Good,          //良
    TKNetQuality_Accepted,      //中
    TKNetQuality_Bad,           //差
    TKNetQuality_VeryBad,       //极差
    TKNetQuality_Down,
};

typedef NS_ENUM(NSInteger, TKOperator) {
    TKOperator_Greater_Than             = 1,
    TKOperator_Less_Than                = 2,
    TKOperator_Not_Equal                = 3,
    TKOperator_Equal                    = 4,
    TKOperator_Greater_Than_Or_Equal    = 5,
    TKOperator_Less_Than_Or_Equal       = 6,
};

typedef NS_ENUM(NSInteger, TKSampleFormat) {

    TKSampleFormat_None = -1,
    TKSampleFormat_U8,          ///< unsigned 8 bits
    TKSampleFormat_S16,         ///< signed 16 bits
    TKSampleFormat_S32,         ///< signed 32 bits
    TKSampleFormat_FLT,         ///< float
    TKSampleFormat_DBL,         ///< double
    
    TKSampleFormat_U8P,         ///< unsigned 8 bits, planar
    TKSampleFormat_S16P,        ///< signed 16 bits, planar
    TKSampleFormat_S32P,        ///< signed 32 bits, planar
    TKSampleFormat_FLTP,        ///< float, planar
    TKSampleFormat_DBLP,        ///< double, planar
    TKSampleFormat_S64,         ///< signed 64 bits
    TKSampleFormat_S64P,        ///< signed 64 bits, planar
    
    TKAVSampleFormat_NB           ///< Number of sample formats. DO NOT USE if linking dynamically
};

typedef NS_ENUM(NSInteger, TKAudioRecordType) {
    TKAudioRecordType_Only_Mic             = 1, //仅录制麦克风的音频
    TKAudioRecordType_MicAndSpeaker        = 2, //录制麦克风、扬声器的音频
};

#
#pragma mark - TKULiveStreamInfo 云直播流信息
#
@interface TKULiveStreamInfo : NSObject
/// 流扩展ID， 组成方式为："用户ID:设备ID:流类型"， 设备ID只在多摄情况下才有值，流类型只有在非video时才有值。如："123:abc"，即表示这个流属于ID为123的用户，采集设备的ID为abc。
/// 1、用户为非多摄像头时：
///     1>、streamtype为 @“video” 时，extensionid 与 userid 相同，均为 @“123”
///     2>、streamtype为非 @“video” 时，extensionid 与 userid 不同，如userid：@“123”，extensionid：userid:streamtype(例如 @“123:media”，表示共享媒体流的扩展ID)
/// 2、用户为多摄像头时：
///     1>、streamtype为 @“video” 时, extensionid 与 userid 不同，如userid：@“123”，extensionid：userid:设备ID（如："123:abc"，即表示这个流属于ID为123的用户，采集设备的ID为abc）
///     2>、streamtype为非 @“video” 时，extensionid 与 userid 不同，如userid：@“123”，extensionid：userid:streamtype(例如 @“123:media”，表示共享媒体流的扩展ID)
@property (copy, nonatomic) NSString *extensionid;
/// 发布此流的用户ID
@property (copy, nonatomic) NSString *userid;
/// 流类型。可用值包括 "video"（摄像头/麦克风采集的流），"screen"（桌面共享流），"media"（媒体共享流，如Mp4课件），"file"（本地文件流）
@property (copy, nonatomic) NSString *streamtype;
/// 推流地址（根据 推流方式不同，可以有多种协议方式的推流url）
@property (copy, nonatomic) NSDictionary *pullurl;
@end


#
#pragma mark - TKLogInfo 媒体文件信息
#
@interface TKLogInfo : NSObject
///日志等级
@property (assign, nonatomic) TKLogLevel level;
///日志需要写入沙盒的路径; 默认路径为：沙盒Libary/Caches/TKSDKLogs。
@property (strong, nonatomic) NSString *logPath;
///是否时debug模式，debug模式：控制台打印，release模式：控制台不打印。
@property (assign, nonatomic) BOOL isDebug;
///日志前缀，打印日志时，在日志开始添加前缀。
@property (strong, nonatomic) NSString *logPrefix;
@end

#
#pragma mark - TKMediaFileInfo 媒体文件信息
#
@interface TKMediaFileInfo : NSObject
@property (assign, nonatomic) NSInteger duration;
@property (assign, nonatomic) NSInteger width;
@property (assign, nonatomic) NSInteger height;
@property (assign, nonatomic) NSInteger fps;
@property (assign, nonatomic) BOOL video;
@property (assign, nonatomic) BOOL audio;
@end

#
#pragma mark - TKVideoProfile 视频属性
#
@interface TKVideoProfile : NSObject
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;
@property (nonatomic, assign) NSInteger maxfps;
@end

#
#pragma mark - TKVideoCanvas 视频属性
#
@interface TKVideoCanvas : NSObject

@property (strong, nonatomic) UIView *view;// 视频渲染窗口
@property (assign, nonatomic) TKRenderMode renderMode;//渲染模式
@property (assign, nonatomic) BOOL isMirror;// 是否是镜像
@end

@interface TKAudioRecordInfo : NSObject
/// 采样率 Default: 16000
@property (nonatomic, assign) int sample_rate;
/// Default:  1 （单声道 ）
@property (nonatomic, assign) int number_of_channels;
/// Default: TKSampleFormat_S16
@property (nonatomic, assign) TKSampleFormat fromat;
/// Default: TKAudioRecordType_Only_Mic
@property (nonatomic, assign) TKAudioRecordType type;
@end

#
#pragma mark - TKAudioFrame 音频数据
#
@interface TKAudioFrame : NSObject
/**
 number of samples in this frame
 */
@property (assign, nonatomic) NSInteger samples;

/**
 number of bytes per sample: 2 for PCM16
 */
@property (assign, nonatomic) NSInteger bytesPerSample;

/**
 number of channels (data are interleaved if stereo)
 */
@property (assign, nonatomic) NSInteger channels;

/**
 sampling rate
 */
@property (assign, nonatomic) NSInteger samplesPerSec;

@property (assign, nonatomic) TKSampleFormat format;

/**
 data buffer
 */
@property (nonatomic) void *buffer;
@end
#
#pragma mark - TKVideoFrame 视频数据
#
@interface TKVideoFrame : NSObject

/**
 width of video frame
 */
@property (assign, nonatomic) NSInteger width;

/**
 height of video frame
 */
@property (assign, nonatomic) NSInteger height;

/**
 stride of Y data buffer
 */
@property (assign, nonatomic) NSInteger yStride;

/**
 stride of U data buffer
 */
@property (assign, nonatomic) NSInteger uStride;

/**
 stride of V data buffer
 */
@property (assign, nonatomic) NSInteger vStride;

/**
 Y data buffer
 */
@property (nonatomic) void *yBuffer;

/**
 U data buffer
 */
@property (nonatomic) void *uBuffer;

/**
 V data buffer
 */
@property (nonatomic) void *vBuffer;

/**
 rotation of this frame (0, 90, 180, 270)
 */
@property (assign, nonatomic) NSInteger rotation;

@end


#
#pragma mark - TKAudioStats 音频统计数据
#
@interface TKAudioStats : NSObject
/**
 带宽 bps
 */
@property (assign, nonatomic) NSInteger bitsPerSecond;

/**
 总字节数
 */
@property (assign, nonatomic) int64_t totalBytes;
/**
 丢包数
 */
@property (assign, nonatomic) NSInteger packetsLost;

/**
 总包数
 */
@property (assign, nonatomic) NSInteger totalPackets;

/**
 延迟 毫秒
 */
@property (assign, nonatomic) NSInteger currentDelay;

/**
 抖动
 */
@property (assign, nonatomic) NSInteger jitter;

/**
 网络质量
 */
@property (assign, nonatomic) TKNetQuality netLevel;
@property (assign, nonatomic) NSTimeInterval timeStamp;

@end
//丢包率  packetsLost/totalPackets  0~1%优 1%~3% 3%~5%中等 5~10%差  >10%极差
//延迟                              80ms  120ms  300ms  800ms  >800ms
#
#pragma mark - TKVideoStats 视频统计数据
#
@interface TKVideoStats : NSObject

/**
 带宽 bps
 */
@property (assign, nonatomic) NSInteger bitsPerSecond;

/**
 总字节数
 */
@property (assign, nonatomic) int64_t totalBytes;

/**
 丢包数
 */
@property (assign, nonatomic) NSInteger packetsLost;

/**
 总包数
 */
@property (assign, nonatomic) NSInteger totalPackets;

//@property (assign, nonatomic) NSInteger firsCount;
//@property (assign, nonatomic) NSInteger plisCount;

/**
 延迟
 */
@property (assign, nonatomic) NSInteger currentDelay;

/**
 帧率
 */
@property (assign, nonatomic) NSInteger frameRate;

/**
 视频宽
 */
@property (assign, nonatomic) NSInteger frameWidth;

/**
 视频高
 */
@property (assign, nonatomic) NSInteger frameHeight;
/**
 网络质量
 */
@property (assign, nonatomic) TKNetQuality netLevel;

@property (assign, nonatomic) NSTimeInterval timeStamp;
@end


#
#pragma mark - TKRtcStats 音视频总统计数据
#
@interface TKRtcStats : NSObject
/**
 上行总字节数
 */
@property (assign, nonatomic) int64_t outBytes;

/**
 下行总字节数
 */
@property (assign, nonatomic) int64_t inBytes;

/**
 上行总包数
 */
@property (assign, nonatomic) NSInteger outPackets;

/**
 下行总包数
 */
@property (assign, nonatomic) NSInteger inPackets;

/**
 上行音频码率 bps
 */
@property (assign, nonatomic) NSInteger outAudioBitRate;

/**
 下行音频码率 bps
 */
@property (assign, nonatomic) NSInteger inAudioBitRate;

/**
 上行视频码率 bps
 */
@property (assign, nonatomic) NSInteger outVideoBitRate;

/**
 下行视频码率 bps
 */
@property (assign, nonatomic) NSInteger inVideoBitRate;

/**
 上行音频丢包率
 */
@property (assign, nonatomic) CGFloat outAudioPacketLostRate;

/**
 下行音频丢包率
 */
@property (assign, nonatomic) CGFloat inAudioPacketLostRate;

/**
 上行视频丢包率
 */
@property (assign, nonatomic) CGFloat outVideoPacketLostRate;

/**
 下行视频丢包率
 */
@property (assign, nonatomic) CGFloat inVideoPacketLostRate;

/**
 上行网络质量
 */
@property (assign, nonatomic) TKNetQuality outNetQuality;

/**
 下行网络质量
 */
@property (assign, nonatomic) TKNetQuality inNetQuality;

/**
 网络质量
 */
@property (assign, nonatomic) TKNetQuality netQuality;

/**
 音频延迟
 */
@property (assign, nonatomic) NSInteger audioDelay;

/**
 视频延迟
 */
@property (assign, nonatomic) NSInteger videoDelay;

/**
 时长
 */
@property (assign, nonatomic) int64_t duration;

/**
 当前 App 的 CPU 使用率 (%)
 */
@property (assign, nonatomic) CGFloat cpuAppUsage;
/**
 当前系统的 CPU 使用率 (%)
 */
@property (assign, nonatomic) CGFloat cpuTotalUsage;
/**
 当前 App 的内存占比 (%)
 */
@property (assign, nonatomic) CGFloat memoryAppUsageRatio;
/**
 当前系统的内存占比 (%)
 */
@property (assign, nonatomic) CGFloat memoryTotalUsageRatio;
/**
 当前 App 的内存大小 (KB)
 */
@property (assign, nonatomic) uint64_t memoryAppUsageInKbytes;
@end

