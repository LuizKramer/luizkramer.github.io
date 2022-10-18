#include "heltec.h"
#define ARRAY_SIZE(array) ((sizeof(array))/(sizeof(array[0])))

class LoraData {
private:
  const uint8_t qtdSensors = 4;
  uint32_t packetSize;
  const String jsonKeys[3] = {
    "\":{\"distance\":\"",
    "\",\"angle\":\"",
    "\",\"battery\":\""
  };



public:
  String recive_lora_data();
  void send_lora_data(String);
  String json_decode(String);
  String json_packet_encode(String*);
  String json_encode(String, String);
  void parse_packet(String, String*);
};

void LoraData::parse_packet(String packet, String * arr) {

  uint8_t count = 0;
  
  
  for (uint32_t i = 0; i < this->packetSize; i++) {
      if ((char)packet[i] != '/') {
        arr[count] += packet[i];
      } else {
        count++;
      }
    }  
}




String LoraData::recive_lora_data() {
  String received = "";
  uint32_t packetSize = LoRa.parsePacket();

  if (!packetSize) {
  
    return "";
  }

  // read packet
  this->packetSize = packetSize;
  while (LoRa.available()) {
    received += (char)LoRa.read();
  }

  String data = received;
  return data;
}

String LoraData::json_packet_encode(String * arr) {
  String jsonPacket;
  jsonPacket += "\"" + arr[0];
  for(int i = 0; i < this->qtdSensors-1; i++){
    jsonPacket += this->jsonKeys[i] + arr[i+1];
  }
  return jsonPacket + "\"}";
}



String LoraData::json_encode(String jsonPacket, String jsonObj) {

}

void LoraData::send_lora_data(String loraData) {
  Serial.print("Sending packet: ");
  Serial.println(loraData);

  // Send packet
  LoRa.beginPacket();

  /*
   * LoRa.setTxPower(txPower,RFOUT_pin);
   * txPower -- 0 ~ 20
   * RFOUT_pin could be RF_PACONFIG_PASELECT_PABOOST or RF_PACONFIG_PASELECT_RFO
   */
  LoRa.setTxPower(20, RF_PACONFIG_PASELECT_PABOOST);
  LoRa.print(loraData);
  LoRa.endPacket();
}