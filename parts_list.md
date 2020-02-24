# パーツリスト
***
## Arduino
### Arduino 本体
- Arduino Bootloader 書き込み済み (5V, 16MHz 仕様)
  - 商品 ; http://akizukidenshi.com/catalog/g/gI-12774/ (320 円)
- AVR マイコン　ATMEGA328P-PU
  - 商品 ; http://akizukidenshi.com/catalog/g/gI-03142/ (230 円)
- IC ソケット (28P) スリム 300mil タイプ (10 個入)
  - 商品 ; http://akizukidenshi.com/catalog/g/gP-00013/ (200 円)

### 周辺部品
- LED 5mm 赤色
  - 商品 ; http://akizukidenshi.com/catalog/g/gI-11655/ (20 円)
- カーボン抵抗 (炭素皮膜抵抗) 1/4-330Ω (100 本入)
  - 商品 ; http://akizukidenshi.com/catalog/g/gR-25331/ (100 円)
- クリスタル (水晶発振子) 16MHz
  - 商品 ; http://akizukidenshi.com/catalog/g/gP-08671/ (20 円)
- 積層セラミックコンデンサ 22pF (10 個入)
  - 商品 ; http://akizukidenshi.com/catalog/g/gP-04060/ (100 円)
- 片面紙エポキシ・ユニバーサル基板 B タイプ (95 × 72mm)
  - 商品 ; http://akizukidenshi.com/catalog/g/gP-00181/ (120 円)
- ジャンパーワイヤ付バッテリースナップ (縦型)
  - 商品 ; http://akizukidenshi.com/catalog/g/gP-09032/ (40 円)
- ブレッドボード BB-801
  - 商品 ; http://akizukidenshi.com/catalog/g/gP-05294/ (200 円)

***

## モータ周辺

### モータ
- FA-130 で決まり
  - 電圧 ; 3V (乾電池 2 個) で使えそう

### モータードライバ
- BD6211F-E2
  - 電源電圧 (Vcc) ; 7V (推奨 3.0 ～ 5.5V)
  - 出力電流 (IoMAX) ; 1.0A
  - VREF 可変設定電圧 (VREF) ; 1.5 ～ 5.5V
  - 回路 ; 1ch
  - 購入先 ; http://akizukidenshi.com/catalog/g/gI-05087/ (100 円 + 基板など)
  - 参考
    - https://meideru.com/archives/437

- DRV8835 ← これがお手軽か?
  - 電源電圧 (Vcc) ; 2 ～ 7V
  - 出力電流 ; 1.5A
  - 回路 ; 2ch
  - 購入先
    - http://akizukidenshi.com/catalog/g/gK-09848/ (300 円)
  - 参考
    - https://qiita.com/mat-MUNET/items/d2b7e02c55ab30a9db10
    - https://www.switch-science.com/catalog/1637/ (使用中に熱くなるとのこと)
    - https://kftamang.github.io/post/inverse_pendulum_1/
  - メモ
    - 秋月の例 (DC モータ) では, IN/IN モード (MODE=L) にして, H に PWM 信号を入れている
    - qiita の例では, PHASE/ENABLE モード (MODE=H) にして, M1 (A1, B1) の H/L で正転/逆転を指定, E1 (A2, B2) に PWM を入れている

### コンデンサ
- 積層セラミックコンデンサ (?uF くらい)
  - モータの入力に付ける
  - 購入先
  - 参考
    - https://www.denshi.club/parts/2017/10/mosfet3-dc.html (0.1uF)
    - https://monoist.atmarkit.co.jp/mn/articles/1602/19/news010_3.html (0.1uF + 22uF)

***

## 距離センサ
### 赤外線センサ
- シャープ測距モジュール (GP2Y0A21YK) ← これか?
  - 測距距離 ; 10 ～ 80cm
  - 出力 ; アナログ電圧出力
  - 電源 ; 4.5 ～ 5.5V
  - 購入先 ; http://akizukidenshi.com/catalog/g/gI-02551/ (450円)
  - メモ ; データシート的にはギリギリ 6cm くらいまでいけそう

### 超音波センサ
- 超音波距離センサー (HC-SR04)
  - 測距範囲 ; 2 ～ 400cm
  - 電源電圧 ; 5.0V
  - 購入先 ; http://akizukidenshi.com/catalog/g/gM-11009/ (450円)

### LED
- LED 5mm 赤色
  - 商品 ; http://akizukidenshi.com/catalog/g/gI-11655/ (20 円)
- LED 5mm 黄緑色
  - 商品 ; http://akizukidenshi.com/catalog/g/gI-11656/ (20 円)
- LED 5mm 黄色
  - 商品 ; http://akizukidenshi.com/catalog/g/gI-11657/ (20 円)
- カーボン抵抗 (炭素皮膜抵抗) 1/4-330Ω (100 本入)
  - 商品 ; http://akizukidenshi.com/catalog/g/gR-25331/ (100 円)

- メモ ; 距離センサの検出状況を LED で見えるようにしたい

***

## 車周辺
### ギアボックス
- 3 速クランクギアーボックスセット
  - 出力シャフト長 ; 100mm
  - ギア比 ; 16.6:1, 58.2:1, 203.7:1
  - 商品 ; https://www.tamiya.com/japan/products/70093/index.html (定価 726 円)
- ツインモーターギアーボックス
  - 出力シャフト長 ; 100mm
  - ギア比 ; 58.2:1, 203.7:1
  - 商品 ; https://www.tamiya.com/japan/products/70097/index.html (定価 924 円)
- ダブルギアボックス (左右独立 4 速タイプ)
  - ユニバーサルプレートに固定する際は, プレートの一部を切り取る
  - ギア比 ; 12.7:1, 38.2:1, 114.7:1, 344.2:1
  - 商品 ; https://www.tamiya.com/japan/products/70168/index.html (定価 924 円)
- メモ ; タミヤ関係はヨドバシドットコムで買える

### 車体
- ユニバーサルプレート (2 枚セット)
  - 商品 ; https://www.tamiya.com/japan/products/70157/index.html (定価 600 円)

### タイヤ
- トラックタイヤセット (36mm 径)
  - 商品 ; https://www.tamiya.com/japan/products/70101/index.html (定価 396 円)

### 電池ボックス
- 単三電池ボックス (2 本用 / スイッチ付き)
  - 商品 ; https://www.tamiya.com/japan/products/70151/index.html (定価 396 円)

***

## その他
### ワイヤ
- ジャンパーワイヤ
  - 商品 ; http://akizukidenshi.com/catalog/g/gC-05159/ (220 円)
