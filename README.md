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

- [./test_motor_sensor_01/test_motor_sensor01.ino](./test_motor_sensor_01/test_motor_sensor01.ino) ; test program of motor (DRV8835) and ultrasonic sensor (HC-SR40)
  - memo
    1. speed of toy car ; 2.5m / 6.7s = 0.373m/s (at 3V)

- ./test_motor_sensor_02/
  - drv8835.h ; header file of Drv8835 class
  - drv8835.cpp ; cpp file of Drv8835 class
  - hcsr04.h ; header file of Hcsr04 class
  - hcsr04.cpp ; cpp file of Hcsr04 class
  - test_motor_sensor02.ico ; test program of motors (Twin gear box (Tamiya) controlled by DRV8835) and ultrasonic sensor (HC-SR04)

- ./test_motor_sensor_03/
  - drv8835.h ; header file of Drv8835 class
  - drv8835.cpp ; cpp file of Drv8835 class
  - hcsr04.h ; header file of Hcsr04 class
  - hcsr04.cpp ; header file of Hcsr04 class
  - ./test_motor_sensor_03.ino ; test program of motors (Twin gear box (Tamiya) controlled by DRV8835) and three ultrasonic sensors (HC-SR04)

- ./test_motor_sensor_11/
  - drv8835.h ; header file of Drv8835 class
  - drv8835.cpp ; cpp file of Drv8835 class
  - hcsr04.h ; header file of Hcsr04 class
  - hcsr04.cpp ; header file of Hcsr04 class
  - ./test_motor_sensor_11.ino ; test program of a motor (3-speed crank axle gearbox (Tamiya)) controlled by DRV8835) and three ultrasonic sensors (HC-SR04)
  - jpg file ; toy car photos

- ./test_ultrasonic_sensor_01/
  - test_ultrasonic_sensor_01.ino ; test program for ultrasonic sensor HC-SR04
  - hcsr04.h ; header file of Hcsr04 class
  - hcsr04.cpp ; cpp file of Hcsr04 class

- ./test_ultrasonic_sensor_02/
  - test_ultrasonic_sensor_02.ino ; test program for ultrasonic sensor HC-SR04
  - hcsr04tri.h ; header file of Hcsr04tri class (3 sensors in one object)
  - hcsr04tri.cpp ; cpp file of Hcsr04tri class (3 sensors in one object)

- ./test_servo
  - See [./test_servo/README.md](./test_servo/README.md)

- ./buying_list/
  - lists of part I bought
