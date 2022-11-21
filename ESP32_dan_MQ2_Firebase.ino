#include <FirebaseESP32.h>  //Khai báo các thư viện Firebase cho ESP32
#include <WiFi.h> //Khai báo các thư viện Wifi

#define FIREBASE_HOST "https://mq2-esp32-default-rtdb.firebaseio.com/"   //URL Realtime database
#define FIREBASE_AUTH "U7ORPM1YULidokyXd9VyTFI2erfeUtXdg0XgCEca" //Mã xác thực 

#define WIFI_SSID "Dinh Thanh"
#define WIFI_PASSWORD "thanhdat16"

FirebaseData fbdo; //PUT dữ liệu vào Firebase 

#define PinDigital 15         //gán chân Digital của MQ2 vào chân 15 của ESP32   
#define led 5                            //gán Led
int digital;

void setup() {                                //Chương trình cài đặt 
  Serial.begin(9600);
  pinMode(PinDigital, INPUT);
  pinMode(led, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH );
}

void loop() {

  digital = digitalRead(PinDigital);              //gán lệnh analog là giá trị đọc được từ Pin Digital

  Serial.print("Gas Sensor: ");                 // in ra màn hình giá trị đọc được
  Serial.println(digital);                                 
  Firebase.setFloat(fbdo, "Gas Sensor", digital);    //hiển thị trên hệ thống Firebase
  delay(100);

  if (digital == 0)                  //nếu có khí gas digital = 0 thì đèn led sẽ sáng
  {
    digitalWrite(led,HIGH);
  }
  else 
  {
    digitalWrite(led,LOW);     // nếu không có thì đèn led sẽ tắt
  }
}
