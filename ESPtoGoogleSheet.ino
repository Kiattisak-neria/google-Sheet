#include<WiFi.h> //ใช้ในการเชื่อมต่อ WiFi
#include <HTTPClient.h> //ใช้ในการส่งข้อมูลขึ้น HTTP

void setup() {
  Serial.begin(115200);
}

//ฟังก์ชันในการส่งข้อมูลขึ้น Google Sheet
void Google_Sheet{
  HTTPClient http; //สร้างตัวแปรในการในการเลียกใช้ฟังก์ชั้นของ HTTP
  String url = "Your Apps Script url ?ชื่อข้อมูล1"+String("ข้อมูล1")+"ชื่อข้อมูล2"+String("ข้อมูล2"); //urlของApps Script ที่ต้องการส่งตามด้วยสัญลักษ ? ชื่อข้อมูลและข้อมูล
  http.begin(url.c_str()); //ทำการส่งข้อมูลขึ้น Google Sheet
  http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);//ทำการติกตามข้อมูลที่ถูกส่งไป
  int httpCode = http.GET();//ทำการรับผลลัพธ์ที่ทำการติดตาม
  if (httpCode > 0) { //สร้างเงื่อนไขเมื่อข้อมูลส่งได้สำเร็จ
    payload = http.getString();
    Serial.println(httpCode);
    Serial.println(payload);
        }
  else {//สร้างเงื่อนไขเมื่อข้อมูลส่งได้ไม่สำเร็จ
    Serial.println("Error on HTTP request");
    }
  http.end();//ทำการสิ้นสุดการส่งข้อมูลขึ้น Google Sheet
}
void loop() {
  Google_Sheet();
  delay(1000);

}
