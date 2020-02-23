# パーツリスト

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
