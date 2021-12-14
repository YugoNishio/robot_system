# 概要  
ロボットシステム学　デバイスドライバ作成リポジトリ

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
$ git clone  
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
