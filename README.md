# 概要  
こちらはロボットシステム学課題1デバイスドライバ作成のリポジトリです。  
このデバイスドライバは[ryuichiuedaのデバイスドライバ](https://github.com/ryuichiueda/robosys_device_drivers)を元にモールス信号と三三七拍子を行えるよう作成しています。  

# 用意するもの  
- Raspberry Pi 4 ModelB   × 1  
- ブレッドボード           × 1  
- LED                     × 2  
- 電子ブザー            　× 1
- ジャンパー線(オス・メス) × 3
- ジャンパー線(オス・オス) × 5  
- 抵抗(100Ω)              × 2  

# 回路　　
![課題1配線](https://user-images.githubusercontent.com/71488443/145738515-3950397f-6359-453f-9b49-017e2d8fa1a3.png)  
写真のように、GPIO25番は電子ブザーとLED1つを並列に組んでいます。

# セットアップ手順  
## このまま動かしたい場合
### ①  
```  
$ git clone https://github.com/YugoNishio/robot_system.git  
$ cd robot_system  
```  
### ②  
```  
$ make  
$ sudo insmod myled.ko  
$ sudo chmod 666 /dev/myled0  
```  
## 変更・改良した場合  
こちらを実行してから②をお願いします。
```  
$ sudo rmmod myled  
```  

# 実行手順  
```  
echo 〇 > /dev/myled0  
```  
〇に入る文字は、 a(A)～z(Z), 0～9, !, _ です。  

# 実行時の様子  
画像をクリックしてYouTubeに飛びます。  
[![サムネ](https://user-images.githubusercontent.com/71488443/145987914-3515dbe5-f8a3-4fe5-92c5-e41671626957.png)](https://www.youtube.com/watch?v=QGr94sr9Y7I)
