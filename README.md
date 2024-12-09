# Google-Sheet
การใช้บอร์ด esp32 ส่งขอมูลขึ้น Google Sheet โดยใช้วิธีการส่งข้อมูลขึ้นไปยัง http ที่ใช้ URL ของ Apps Script

<br/>

## <a name="content"></a> สารบัญ
1. [รูปแบบของโค้ด](#code)


## <a name="code"></a> รูปแบบของโค้ด
"#include <Wire.h>
#include<WiFi.h>
#include<PubSubClient.h>
#include<NTPClient.h>
#include<WiFiUdp.h>
#include <HTTPClient.h>
#include <LiquidCrystal_I2C.h>
#include <esp_sleep.h>"
