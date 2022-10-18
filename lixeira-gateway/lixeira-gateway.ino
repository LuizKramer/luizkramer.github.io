#include "heltec.h"
#include "LoraData.h"
#define ARRAY_SIZE(array) ((sizeof(array))/(sizeof(array[0])))

#define BAND    915E6  //you can set band here directly,e.g. 868E6,915E6

LoraData gateway;
String packet;
void setup() {
    //WIFI Kit series V1 not support Vext control
  Heltec.begin(false /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);

}

void loop() {
  packet = gateway.recive_lora_data();
 
  if(packet != ""){
    String arr[4];
    gateway.parse_packet(packet, arr);
    Serial.println( gateway.json_packet_encode(arr));
  }

 
  delay(1000);
}