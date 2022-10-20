#include "heltec.h"
#include "CONSTANTS.h"

class LoraData {
private:
  const uint8_t qtdSensors = QTD_SENSORS;
  uint32_t packetSize;
  const String jsonKeys[3] = {
    "\":{\"distance\":\"",
    "\",\"angle\":\"",
    "\",\"battery\":\""
  };
  String devicesJson[DEVICES];
  String devices[DEVICES];
  uint8_t activeDevices = 0;

public:
  String recive_lora_data();
  void send_lora_data(String);
  String json_decode(String);
  String json_packet_encode(String*);
  String json_encode();
  String parse_packet(String);
  bool verify_existing(String a);
};

String LoraData::parse_packet(String packet) {

  uint8_t count = 0;
  String arr[QTD_SENSORS];
  
  for (uint32_t i = 0; i < this->packetSize; i++) {
      if ((char)packet[i] != '/') {
        arr[count] += packet[i];
      } else {
        count++;
      }
    }

    return this->json_packet_encode(arr);
    
    
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
  if(!verify_existing(arr[0]) && this->activeDevices < DEVICES){
    
    jsonPacket += "\"" + arr[0];
    for(int i = 0; i < this->qtdSensors-1; i++){
      jsonPacket += this->jsonKeys[i] + arr[i+1];
    }
    jsonPacket += "\"}";
    devicesJson[this->activeDevices] = jsonPacket;
    devices[this->activeDevices] = arr[0];
    this->activeDevices++;
  }

  return jsonPacket;
}

bool LoraData::verify_existing(String a){
  for(int i =0; i< this->activeDevices; i++){
    if(a == this->devices[i]){
      return true;
    }
  }
  return false;
}

String LoraData::json_encode() {
  if (this->activeDevices == 0)
    return "";
  String json = "{"; 
  for(int i =0; i < this->activeDevices -1; i++){
    json += this->devicesJson[i] + ",";
  }
  json += this->devicesJson[this->activeDevices-1] + "}";

  return json;
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