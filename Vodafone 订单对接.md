## 1.收单-设备收到新订单

设备不停轮训新订单，收到新订单就会回调此接口

**回调参数列表**

| 参数名 | 参数类型 | 说明 |
| -- | -- | -- |
| numid | string | 唯一订单号，回调可能会重复请求，可根据此单号如果存在则无需再次处理业务逻辑 |
| payee | string | 收款卡姓名 |
| payeeCard | string | 收款卡卡号/手机号 |
| money | string | 订单金额，单位元，精确到两位小数，注意非float类型 |
| payTime | string | 支付时间，形如 "2022-10-09 08:22:03" |


## 2.付单-获取所有可用设备--弃用


**返回参数列表**

```javascript
{
  "code": 0,  // 0成功，其他都为失败，并会有 message 提示
  "message": "错误提示",
  "data": [
    {
      "id": 12, // 设备ID
      "name": "账户名称",
      "alias_name": "设备名",
      "card_no": "手机号",
    }
  ]
}
```

## 3. 付单-推送新代付订单给设备

**POST url**

`URL: http://47.236.27.43:8081/gateway/payment-order`

**推送参数列表**

| 参数名 | 参数类型 | 说明 |
| -- | -- | -- |
| card_id | int | 设备ID，出款设备，传0则不指定使用自动有余额的设备出款 |
| order_no | string | 上游商户唯一订单号 |
| bank_name | string | 固定传值：paymentVodafone |
| account_name | string | 付款给谁的账户名，有则传，否则空字符串 |
| account_no | string | 付款给谁的手机号 |
| amount | string | 付款金额，金额单位元，精确到两位小数 |
| notify_url | string | 成功/失败通知地址，带 http://  |


## 4. 付单-设备处理状态

**POST url**

`推单时的 notify_url 参数地址`

**状态参数列表**


| 参数名 | 参数类型 | 说明 |
| -- | -- | -- |
| order_id | string | 脚本唯一订单ID |
| order_no | string | 上游商户唯一订单号 |
| state | int | 0失败，1成功 |
| out_bank_name | string | 固定传值：paymentVodafone |
| out_account_name | string | 出款账户名，失败时为空字符串 |
| out_account_no | string | 出款账户手机号，失败时为空字符串 |
| remarks | string | 空字符串 |


