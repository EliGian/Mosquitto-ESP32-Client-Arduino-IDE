#include <WiFi.h>
#include <PubSubClient.h>

// GPIOs acccording to your wiring
#define LED 2

// Wi-Fi ssid and password
const char* ssid = "";
const char* password = "";


// Your Mosquitto Webserver IP Adress
IPAddress server(192, 168, 178, 30); 

// Callback function, listen  to the incoming message
void callback(char* topic, byte* payload, unsigned int length) {

  Serial.print("Incoming message - ASCII decimal: ");
  Serial.println(payload);

// Add you Logic here! 
}

WiFiClient esp32Client;
PubSubClient client(server, 1883, callback, esp32Client);

void startWifi() {
  Serial.print("\nEsp32 connect with ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Starting wifi connect...");
    WiFi.begin(ssid, password);
    delay(2000);
  }
  Serial.println("Wifi connected!");
  Serial.print("Esp32 IP address: ");
  Serial.println(WiFi.localIP());
}

void connectBroker() {
  // User and password configured in the broker
  if (client.connect("espClient", "mqtt_user", "mqtt_password")) {
    client.publish("outTopic", "Ready to publish in <outTopic>"); //Esp32 publish in outTopic
    client.subscribe("test"); //Esp32 subscribe inTopic. See callback function
    Serial.println("Broker connected!");
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  startWifi();
  connectBroker();
}

void loop()
{
  client.loop();
}
