# toy_car
Arduino を使って, モータ駆動の車のおもちゃを制御してみようという試みです.

***

## ファイル一覧
### テキストファイル
- [parts_list.md](./parts_list.md) ; 必要なパーツをリストアップしたものです.

### Test programs
- [./test_drv8835_01/test_drv8835_01.ino](./test_drv8835_01/test_drv8835.ino) ; test program for DRV8835 motor driver (You can buy it at http://akizukidenshi.com/catalog/ .)
  - memo (https://www.arduino.cc/reference/jp/language/functions/analog-io/analogwrite/)
    1. PWM signals can be used at Pin #3, #5, #6, #9, #10, #11.
    2. Freqency of #5 and #6 is about 980Hz, and that of the rests is about 490Hz.


- ./test_drv8835_02/
  - drv8835.h ; header file of Drv8835 class
  - drv8835.cpp ; cpp file of Drv8835 class
  - [test_drv8835_02.ino](./test_drv8835_02/test_drv8835_02.ino) ; test program for DRV8835 motor driver using Drv8835 class

- ./buying_list/
  - lists of part I bought
