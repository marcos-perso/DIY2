#include <Arduino.h>
#include <WiFi.h>

const char *ssid = "YM-Casa";
const char *psswd = "zumarraga0000";

#define LED 2

void get_network_info(){
    if(WiFi.status() == WL_CONNECTED) {
        Serial.print("[*] Network information for ");
        Serial.println(ssid);

        Serial.println("[+] BSSID : " + WiFi.BSSIDstr());
        Serial.print("[+] Gateway IP : ");
        Serial.println(WiFi.gatewayIP());
        Serial.print("[+] Subnet Mask : ");
        Serial.println(WiFi.subnetMask());
        Serial.println((String)"[+] RSSI : " + WiFi.RSSI() + " dB");
        Serial.print("[+] ESP32 IP : ");
        Serial.println(WiFi.localIP());
    }
}

void setup()
{
  // put your setup code here, to run once:
  // Serial.begin(115200);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  WiFi.begin(ssid,psswd);
  Serial.println("\nConnecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }

  Serial.println("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());
  get_network_info();
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  Serial.println("LED is on");
  delay(500);
  digitalWrite(LED, LOW);
  Serial.println("LED is off");
  delay(500);
  Serial.println("\nH");
}