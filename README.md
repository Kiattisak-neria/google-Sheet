# Google-Sheet
การใช้บอร์ด esp32 ส่งขอมูลขึ้น Google Sheet โดยใช้วิธีการส่งข้อมูลขึ้นไปยัง http ที่ใช้ URL ของ Apps Script

<br/>

## <a name="content"></a> สารบัญ
1. [รูปแบบของโค้ด](#code)
2. [การสร้าง Apps Script](#AppsScript)
<br/>

## <a name="code"></a> รูปแบบของโค้ด
ไลบรารี่ที่จำเป็นต้องใช้ในการส่งข้อมูขึ้น Google Sheet มีดังนี้
1. WiFi เพื่อใช้ในการเชื่อมต่อ internet
2. HTTPClient เพื่อใช้ในการส่งข้อมูลขึ้น Google Sheet

ฟังชัน
1. WiFi.begin("ชื่อ WiFi","รหัส WiFi") : ใช้ในการเชื่อต่อ WiFi
2. while(WiFi.status() != WL_CONNECTED){} : เพื่อใช้ตรวจสอบการเชื่อมต่อ WiFi
3. HTTPClient http(สามารถตั้งชื่อ http เป็นชื่ออื่นๆได้ ในที่ใช้ชื่อเป็น http) : ทำการตั้งชื่อของ http
4. http.begin(url(urlของ Apps Scriptและข้อมูลที่ต้องการส่ง).c_str()) : ทำการส่งข้อมูลขึ้น HTTP
5. http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS) : ทำการติดตามข้อมูลที่ได้ทำการส่ง
6. http.GET() : ทำการตรวจสอบว่าข้อมูลถูกส่งไปถึงหรื่อไม่ หาหส่งไปถึง http.GET() จะมีค่ามากกว่า 0
7. http.gtString() : ทำการรับข้อมูลที่ได้ทำการติดตามเปลี่ยนมาเป็นข้อความ
8. http.end() : ทำการจบการส่งข้อมูล

ในฟังชันข้อที่ 4 ทำการนำ url รวมกับข้อมูลโดยการนำ url ที่ได้มากจาก Apps Script แล้วเพิ่ม ? จากนั้นเพิ่มชื่อของข้อมูลตามด้วย = ตามด้วยข้อมูลที่ต้องการส่ง
<br/>

## <a name="AppsScript"></a> การสร้าง Apps Script
1. ทำการเปิด Google Drive เลือกไปที่ ใหม่>เพิ่มเติม>สคริปต์ของ Google Apps
<p align="center">
<img src=https://github.com/user-attachments/assets/f10a5365-44a3-4977-b58d-9c6f0af26329>
</p> 

