# Google-Sheet
การใช้บอร์ด esp32 ส่งขอมูลขึ้น Google Sheet โดยใช้วิธีการส่งข้อมูลขึ้นไปยัง http ที่ใช้ URL ของ Apps Script

<br/>

## <a name="content"></a> สารบัญ
1. [รูปแบบของโค้ด](#code)


## <a name="code"></a> รูปแบบของโค้ด
ไลบรารี่ที่จำเป็นต้องใช้ในการส่งข้อมูขึ้น Google Sheet มีดังนี้
1. WiFi เพื่อใช้ในการเชื่อมต่อ internet
2. HTTPClient เพื่อใช้ในการส่งข้อมูลขึ้น Google Sheet

ฟังชัน
1. WiFi.begin("ชื่อ WiFi","รหัส WiFi") ใช้ในการเชื่อต่อ WiFi
2. while(WiFi.status() != WL_CONNECTED){} เพื่อใช้ตรวจสอบการเชื่อมต่อ WiFi
