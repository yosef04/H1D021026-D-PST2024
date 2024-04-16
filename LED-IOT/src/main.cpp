#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266WiFi.h>

int led1 = D0, led2 = D1, led3 = LED_BUILTIN;

// ssid & pass access point
const char *ap_ssid = "ofa";
const char *ap_password = "12345678";

// ssid & pass access point
const char *sta_ssid = "POCO F3";
const char *sta_password = "satusampaisepuluh";

AsyncWebServer server(80); // port servernya
String webpage;


// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600); // 9600 tuh frekuensi, serial begin buat komunikasi antara nodeMCU dengan perangkat lain, ex : platformIO
  delay(10);

  // setting mode access point
  // Serial.println("Configuring access point...");
  // WiFi.mode(WIFI_AP); // wifi_ap buat acces point
  // WiFi.softAP(ap_ssid, ap_password); // klo gamau pake pass ap_password bisa diilangin
  // Serial.print("Wifi: ");
  // Serial.println(ap_ssid);
  // Serial.print("IP address: ");
  // Serial.println(WiFi.softAPIP());

  // setting mode station
  Serial.print("Connecting to ");
  Serial.println(sta_ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(sta_ssid, sta_password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Isi dari Webpage
  webpage+= "<h1> Web Control ESP8266</h1>";
  webpage+= "<p>LED 1: ";
  webpage+= "<a href=\"LED1ON\"\"><button>ON</button></a><a href=\"LED1OFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED 2: ";
  webpage+= "<a href=\"LED2ON\"\"><button>ON</button></a><a href=\"LED2OFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED 3: ";
  webpage+= "<a href=\"LED3ON\"\"><button>ON</button></a><a href=\"LED3OFF\"\"><button>OFF</button></a></p>";

  // inisialisasi href (routing)
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", webpage);
  });
  
  server.on("/LED1ON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led1, HIGH);
    request->send(200, "text/html", webpage);
  });
  
  server.on("/LED2ON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led2, HIGH);
    request->send(200, "text/html", webpage);
  });

  server.on("/LED3ON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led3, LOW);
    request->send(200, "text/html", webpage);
  });

  server.on("/LED1OFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led1, LOW);
    request->send(200, "text/html", webpage);
  });
  
  server.on("/LED2OFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led2, LOW);
    request->send(200, "text/html", webpage);
  });

  server.on("/LED3OFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led3, HIGH);
    request->send(200, "text/html", webpage);
  });

  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(led1, LOW);
  // digitalWrite(led2, HIGH);
  // delay(1000);
  // digitalWrite(led2, LOW);
  // digitalWrite(led3, LOW);
  // // klo LED Built in kebalik LOW=nyala, HIGH=mati
  // delay(5000);
  // digitalWrite(led3, HIGH);
  // digitalWrite(led1, HIGH);
  // delay(1000);


}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}