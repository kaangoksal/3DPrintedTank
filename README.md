# ArduinoBluetoothTank

![alt tag](http://www.kaangoksal.com/uploads/3/7/1/5/37152203/8261370_orig.jpg)


This is code is for controlling an Arduino based tank. 

Components used
HC-06 Bluetooth Module  
Arduino Mega / Nano / UNO  
L298N  
Some power source - I use Li-po.  





-----------------------------------------------------------------------------------------------------------------------


Merhaba arkadaşlar, bu projede Arduino tabanlı bir aracı kontrol etmek için yazdığım kod var.

Kullandığım Kartlar

Arduino Mega / Nano / Uno  ( / veya anlamına geliyor)  
L298N  (Motor sürücü)  
HC-06 (Bluetooth iletişim)  
Li-po 3S 2000mAh  


Arduino Uno'nuz varsa nano_uno olan kodu kullanın. Arduino Uno'nun ekstradan hardware serial'ı olmadığından software serial kullandım.

Eğer arduino Mega'nız varsa MEGA yazan kodu kullanmanızı öneririm. Arduino Mega'nın fazladan hardware serial'ı var! Serial1 e bağladım ben bluetooth modülünü
