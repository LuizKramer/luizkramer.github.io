#include "heltec.h"
#include "LoraData.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include "CONSTANTS.h"
#include <elapsedMillis.h>

elapsedMillis elapsedTime;

const char* serverName = "http://192.168.1.66:81/api/lixeira/create_multiple.php";

const char* ssid = "SMCTI";
const char* password = "SMCTI@6080";

#define BAND 915E6  //you can set band here directly,e.g. 868E6,915E6

LoraData gateway;
String packet;
String jsonPacket = "{}";

String received = "";
String httpRequestData = "";
int httpResponseCode;

void setup() {
  //WIFI Kit series V1 not support Vext control
  
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  Heltec.begin(false /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
}

void loop() {
  packet = gateway.recive_lora_data();

  if (packet != "") {
    gateway.parse_packet(packet);
    httpRequestData = gateway.json_encode();
    Serial.println(httpRequestData);
    Serial.println(gateway.get_active_devices());
    Serial.println((WiFi.status()));
    if (WiFi.status() == WL_CONNECTED && (gateway.get_active_devices() == DEVICES || elapsedTime > 15000)) {
      
      WiFiClient client;
      HTTPClient http;
      // Domain name with URL path or IP address with path
      http.begin(client, serverName);
      http.addHeader("Content-Type", "application/json");
      httpResponseCode = http.POST(httpRequestData);
      if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        Serial.println(httpRequestData);
        Serial.println();
        gateway.clear_data();
      } else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
        Serial.println();
      }
      elapsedTime = 0;
    }


    delay(1000);
  }
}