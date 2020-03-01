# toy_car
Arduino を使って, モータ駆動の車のおもちゃを制御してみようという試みです.

***

## ファイル一覧
### テキストファイル
- [parts_list.md](./parts_list.md) ; 必要なパーツをリストアップしたものです.

### Test programs
- [./test/test_drv8835_01.ino](./test/test_dev8835.ino) ; test program for DRV8835 motor driver (You can buy it at http://akizukidenshi.com/catalog/ .)
  - memo (https://www.arduino.cc/reference/jp/language/functions/analog-io/analogwrite/)
    1. PWM signals can be used at Pin #3, #5, #6, #9, #10, #11.
    2. Freqency of #5 and #6 is about 980Hz, and that of the rests is about 490Hz.
