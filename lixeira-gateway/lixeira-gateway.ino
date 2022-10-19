#include "heltec.h"
#include "LoraData.h"
#define ARRAY_SIZE(array) ((sizeof(array))/(sizeof(array[0])))

#define BAND    915E6  //you can set band here directly,e.g. 868E6,915E6

LoraData gateway;
String packet;
String jsonPacket = "{}";

void setup() {
    //WIFI Kit series V1 not support Vext control
  Heltec.begin(false /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);

}

void loop() {
  packet = gateway.recive_lora_data();
 
  if(packet != ""){
    String arr[4];
    gateway.parse_packet(packet, arr);
    if(gateway.verify_existing(arr[0])){
      jsonPacket = gateway.json_packet_encode(arr);
      gateway.json_encode();
    }
  }

 
  delay(1000);
}