# パーツリスト
***
## Arduino (格安完成品を買うなら)
### Arduino UNO 互換
- KKHMF UNO R3 開発ボード USB ケーブル付属 Arduinoと互換
  - 商品 ; https://www.amazon.co.jp/KKHMF-UNO-R3%E9%96%8B%E7%99%BA%E3%83%9C%E3%83%BC%E3%83%89-USB%E3%82%B1%E3%83%BC%E3%83%96%E3%83%AB%E4%BB%98%E5%B1%9E-Arduino%E3%81%A8%E4%BA%92%E6%8F%9B/dp/B018VYJIEU/ (482 円)
***

## Arduino (パーツを集めて作るなら)
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
- タクトスイッチ
  - 商品 ; http://akizukidenshi.com/catalog/g/gP-03647/ (10 円)
- カーボン抵抗 (炭素被膜抵抗) 1/4-10kΩ (100 本入)
  - 商品 ; http://akizukidenshi.com/catalog/g/gR-25103/ (100 円)
- 参考
  - 電源電圧は 3.78 ～ 5.5V (https://synapse.kyoto/hard/miniaturize_arduino_project/page003.html)
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

- メモ ; 距離センサの検出状況を LED で見えるようにしたい. でも I/O の数を考えると無理っぽい

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

### 車体
- ユニバーサルプレート (2 枚セット)
  - 商品 ; https://www.tamiya.com/japan/products/70157/index.html (定価 600 円)
  - サイズ ; 160 x 60 x 3
- ユニバーサルアームセット (オレンジ)
  - 商品 ; https://www.tamiya.com/japan/products/70183/index.html (定価 462 円)
- 3mm プッシュリベットセット
  - 商品 ; https://www.tamiya.com/japan/products/70155/index.html (定価 396 円)
- プラバン 1.0mm 厚 B4 サイズ (2 枚入)
  - 商品 ; https://www.tamiya.com/japan/products/70124/index.html (定価 792 円)
  - 用途 ; モータの固定など

### タイヤ
- トラックタイヤセット (36mm 径)
  - 商品 ; https://www.tamiya.com/japan/products/70101/index.html (定価 396 円)
- ボールキャスター (2 セット入り)
  - 商品 ; https://www.tamiya.com/japan/products/70144/index.html (定価 396 円)
- 32mm 径スプロケット & クローラーセット
  - 商品 ; https://www.tamiya.com/japan/products/70229/index.html (定価 550 円)

### 電池ボックス
- 電池ボックス, 単三 x 2 本, B スナップ
  - 商品 ; http://akizukidenshi.com/catalog/g/gP-00208/ (定価 40 円)
  - ジャンパーワイヤ付バッテリースナップ ; http://akizukidenshi.com/catalog/g/gP-09032/ (定価 40 円)
- 電池ボックス, 単三 x 3 本, B スナップ
  - 商品 ; http://akizukidenshi.com/catalog/g/gP-02677/ (定価 50 円)
- 単三電池ボックス (2 本用 / スイッチ付き)
  - 商品 ; https://www.tamiya.com/japan/products/70151/index.html (定価 396 円)


### メモ
  - メモ ; タミヤ関係はヨドバシドットコムで買える. 送料無料なので, 一度にたくさん購入する必要はない

***

## その他
### ワイヤ
- ジャンパーワイヤ
  - 商品 ; http://akizukidenshi.com/catalog/g/gC-05159/ (定価 220 円)
- スズメッキ線
  - 商品 ; http://akizukidenshi.com/catalog/g/gP-02220/ (定価 210 円)
- プラネジ
  - 商品 1 ; http://akizukidenshi.com/catalog/g/gP-01861/ (定価 50 円)
  - 商品 2 ; http://akizukidenshi.com/catalog/g/gP-01885/ (定価 130 円)
- ミニカードスペーサ
  - 商品 ; http://akizukidenshi.com/catalog/g/gP-10089/ (定価 15 円)
- 接着式サポート
  - 商品 ; http://akizukidenshi.com/catalog/g/gP-09950/ (定価 60 円)
