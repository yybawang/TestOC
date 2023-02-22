//
//  ViewController.m
//  TestOC
//
//  Created by Eric on 2023/2/21.
//

#import "ViewController.h"
#import <TKUISDK/TKUISDK.h>
#import <TKRoomSDK/TKRoomSDK.h>

@interface ViewController ()<TKEduRoomDelegate, UITextFieldDelegate>

@property (strong, nonatomic) UIButton *firstButton;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = UIColor.whiteColor;
}

- (void)awakeFromNib {
    [super awakeFromNib];

    self.firstButton = [self buttonWithFrame:CGRectMake(75, 50, 300, 30)];
    [self.firstButton setTitle:@"通过参数进教室" forState:UIControlStateNormal];
    [self.firstButton addTarget:self action:@selector(firstBtnClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:self.firstButton];
}

- (void) firstBtnClick {

        NSDictionary *param = @ {
            // 房间号
            @"serial":@"1725549729",
            // 用户角色 老师(0) 助教(1) 学生(2)
            @"userrole": @(2),
            // 用户昵称
            @"nickname": @"BB!",
            // 密码（没有可不填）
            @"password": @(222222),
            /*
             用户ID,可选字段(不可传空字符),如果不传，SDK 会自动生成用户唯一ID
             注意:教室内唯一ID , 多个相同ID 会互踢.
             */
            @"userid" : @"3",
        };

    
        [[TKEduClassManager shareInstance] joinRoomWithParamDic:param
                 ViewController:self
                       Delegate:self
                      isFromWeb:NO];
}


- (UIButton *) buttonWithFrame:(CGRect)frame {

    UIButton * btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.frame = frame;
    btn.titleLabel.font = [UIFont systemFontOfSize:20];
    [btn setTitleColor:UIColor.blackColor forState:UIControlStateNormal];
    btn.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
    [self.view addSubview:btn];
    return btn;
}

- (void) showErrorMsg:(NSString *)msg {
    
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"提示" message:msg preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction *action2 = [UIAlertAction actionWithTitle:@"确认" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [alert dismissViewControllerAnimated:YES completion:nil];
    }];
    [alert addAction:action2];
    
    [self presentViewController:alert animated:YES completion:nil];
}

@end
