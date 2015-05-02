/**
    This is a Arduino code template for connecting to SmartHome cloud server.
    It can be used to get or post through HTTP protocol via Ethernet connection.
    Code surrounded by '*' comments should be modified by programmers using the given example.
    HTTP REST API for connecting with the cloud server is available at 
      https://github.com/potatolylc/SmartHomeRapidPrototype/wiki/Open-RESTful-API
*/

#include <SPI.h>
#include <Ethernet.h>


/**************** Sensor Init ***************/
/*
  Example:
TKThermistor therm(I0);
TKLightSensor ldr(I1);
*/
/******** Change your own sensors ***********/

/************************  Wifi Init ****************************/
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // MAC address printed on the sticker on the shield
IPAddress server(/* YourCloudServerIPAddress */);     // Cloud server IP address
IPAddress ip(192, 168, 0, 2);                        // Set static IP address if DHCP fails to assign automatically
int port = /* YourCloudServerHostPort */;                       // Cloud server port number
/******** Change to your own WiFi and cloud server IP ***********/

EthernetClient client;

/****************************** Device utils ******************************/
// Device serial number obtained via device registration
const char* device_serial_num       = "YourDeviceSerialNum";    
// Sensor names defined by users via sensor registration
const char* sensor_name_name1       = "YourSensorName1";                
const char* sensor_name_name2       = "YourSensorName2";
/******************** Change to your own device information ***************/

void setup() {
  // Init serial
  Serial.begin(115200);
  // Attempt to connect to Ethernet
  connectToEthernet();
}

void loop() {
  /**************** Get sensor data ****************/
  /* 
    Example:
  int brightnessVal = getBrightness();
  Serial.print("brightness = ");
  Serial.println(brightnessVal);
  */
  /*********** Get your own sensor data ************/
  
  sendHTTPRequest(/* Your Parameters */);
   
  disconnectClient();
  
  /******** Send data every 5 minutes *********/
  delay(/* YourTimeInterval */);
  /******** Change to your time interval ******/
}

// Attempt to connect to Ethernet network
void connectToEthernet(void) 
{
  if(Ethernet.begin(mac) == 0) 
  {
    Serial.println("Failed to configure Ethernet");
    Ethernet.begin(mac, ip);
  }
  // Delay 3 seconds for initialization
  delay(3000);
  Serial.println("Connecting...");
}

void sendHTTPRequest(/* Example: int brightnessVal, float temperatureVal */)
{
  Serial.println("\nStarting connection to server...");
  if (client.connect(server, port)) {
    Serial.println("connected to server");
    /************ Make a HTTP request: *************/
    /*
      Example:
    client.print("POST /MavenIoEData/sensorData/all?deviceSerialNum=");
    client.print(device_serial_num);
    client.print("&");
    client.print(sensor_name_light);
    client.print("=");
    client.print(brightnessVal);
    client.print("&");
    client.print(sensor_name_temperature);
    client.print("=");
    client.print(temperatureVal);
    */
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("Connection: Keep-Alive");
    client.println();
    /********* Make your own HTTP requests *********/
    // Wait for 3 seconds
    delay(3000);
  } else {
    Serial.println("Connection failed.");
  }
}

void disconnectClient()
{
  // Disconnect client and return sockets
  if(client.connected()) {
    client.flush();
    client.stop();
    Serial.println("Connection is closed.");
  }
}

/************* Get sensor data methods *************/
/*
  Example:
int getBrightness() 
{
  return ldr.read();
}
*/
/***************************************************/
