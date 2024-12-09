# Google-Sheet
การใช้บอร์ด esp32 ส่งขอมูลขึ้น Google Sheet โดยใช้วิธีการส่งข้อมูลขึ้นไปยัง http ที่ใช้ URL ของ Apps Script

<br/>

## <a name="content"></a> สารบัญ
1. [รูปแบบของโค้ด](#code)
2. [การสร้าง Apps Script](#Apps)
<br/>

## <a name="code"></a> รูปแบบของโค้ด
### ไลบรารี่ที่จำเป็นต้องใช้ในการส่งข้อมูขึ้น Google Sheet มีดังนี้
1. WiFi เพื่อใช้ในการเชื่อมต่อ internet
2. HTTPClient เพื่อใช้ในการส่งข้อมูลขึ้น Google Sheet

### ฟังชัน
1. WiFi.begin("ชื่อ WiFi","รหัส WiFi") : ใช้ในการเชื่อต่อ WiFi
2. while(WiFi.status() != WL_CONNECTED){} : เพื่อใช้ตรวจสอบการเชื่อมต่อ WiFi
3. HTTPClient http(สามารถตั้งชื่อ http เป็นชื่ออื่นๆได้ ในที่ใช้ชื่อเป็น http) : ทำการตั้งชื่อของ http
4. http.begin(url(urlของ Apps Scriptและข้อมูลที่ต้องการส่ง).c_str()) : ทำการส่งข้อมูลขึ้น HTTP
5. http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS) : ทำการติดตามข้อมูลที่ได้ทำการส่ง
6. http.GET() : ทำการตรวจสอบว่าข้อมูลถูกส่งไปถึงหรื่อไม่ หาหส่งไปถึง http.GET() จะมีค่ามากกว่า 0
7. http.gtString() : ทำการรับข้อมูลที่ได้ทำการติดตามเปลี่ยนมาเป็นข้อความ
8. http.end() : ทำการจบการส่งข้อมูล

ในฟังชันข้อที่ 4 ทำการนำ url รวมกับข้อมูลโดยการนำ url ที่ได้มากจาก Apps Script แล้วเพิ่ม ? จากนั้นเพิ่มชื่อของข้อมูลตามด้วย = ตามด้วยข้อมูลที่ต้องการส่ง

[กลับไปยังสารบัญ](#content)
<br/>

## <a name="Apps"></a> การสร้าง Apps Script
1. ทำการเปิด Google Drive เลือกไปที่ ใหม่>เพิ่มเติม>สคริปต์ของ Google Apps
<p align="center">
<img src=https://github.com/user-attachments/assets/f10a5365-44a3-4977-b58d-9c6f0af26329>

2. เมื่อทำการเปิด Apps Script จึงจะสามารถเขียนฟังชันในการรับส่งข้อมูลขึ้น Google Sheet ซึ่งมีฟังชั่นดังต่อไปนี้
> - function doGet(e){} : เป็นการสร้างฟังชันหลักที่ต้องนำฟังชันอื่นๆนำมาใส่ในเครื่องหมายปีกกา(สามารถตั้งชื่อฟังชันและตัวแปลในวงเล็บได้ตามต้องการ)
> - var ตั้งชื่อตัวแปร : เป็นการสร้างตัว
> - e.paramiter.ชื่อข้อมูล : เป็นการรับค่าข้อมูลที่ทำการส่งมาจาก esp32 โดยที่ชื่อของข้อมูลของApps Script และ esp32 ต้องเป็นชื่อเดียวกัน
> - new Date() : เป็นฟังชันในการดึงค่าเวลาแบบออนไลน์
> - ชื่อตัวแปรที่ได้ทำการรับค่ามาจาก new Date().getHours() : เป็นฟังชันในการดึงค่าเวลาเป็น ชม.
> - ชื่อตัวแปรที่ได้ทำการรับค่ามาจาก new Date().getMinutes() : เป็นฟังชันในการดึงค่าเวลาเป็น นาที
> - ชื่อตัวแปรที่ได้ทำการรับค่ามาจาก new Date().getSeconds() : เป็นฟังชันในการดึงค่าเวลาเป็น วินาที
> - SpreadsheetApp.openByUrl(urls) : เป็นฟังชั้นที่จะเลือกที่อยู่ของ Google Sheet ที่จะทำการส่งซึ่ง urls นำมาจากแถบ urls ของ Google Sheet ที่ต้องการส่ง
> - ชื่อตัวแปรที่ได้รับค่ามาจากSpreadsheetApp.openByUrl(urls).getSheetByName("ชีต1") : เป็นฟังชันในการเลือกชีตของ Google Sheet ที่ต้องการส่ง
> - ชื่อตัวแปรที่ได้รับค่ามาจากgetSheetByName("ชีต1").appendRow(ชื่อข้อมูล1,ชื่อข้อมูล2) : เป็นฟังชันในการจัดเรียงข้อมูลที่จะทำการส่งขึ้น Google Sheet

3. เมื่อเสร็จสิ้นการเขียนโค้ดจะสามารถทำให้ Apps Script สามารถใช้งานได้โดยเลือกดังต่อไปนี้ การทำให้ใช้งนได้ > จัดการทำให้ใช้งานได้ > สร้างการทำให้ใช้งานได้ > ฟันเฟือง > เว็บแอป > การทำให้ใช้งานได้ > ให้สิทธิ์เข้าถึง > เลือก email > advanced > go to ชื่อโครงการ > Allow > จากนั้นจะได้ url เพื่อนำไปใช้ในการเขียนโค้ด
<p align="center">
<img src=https://github.com/user-attachments/assets/d696e300-3249-45c9-b80a-e45bb60ac846>

[กลับไปยังสารบัญ](#content)
<br/>
