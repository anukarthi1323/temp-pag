#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Replace with your network credentials
const char* ssid = "GalaxyA10";
const char* password = "karthickkkk";

#define DHTPIN 5     // Digital pin D1 connected to the DHT sensor

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

// current temperature & humidity, updated in loop()
float t = 0.0;
float h = 0.0;

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;    // will store last time DHT was updated

// Updates DHT readings every 10 seconds
const long interval = 10000;  

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cotton Industry</title>
    <link rel="stylesheet" href="style.css">
    <link href='https://unpkg.com/boxicons@2.1.4/css/boxicons.min.css' rel='stylesheet'>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'poppins', sans-serif;
        }

        body {
             background-color: #081b29;
             color: #ededed;
        }

        .header {
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            padding: 20px 10%;
            background: transparent;
            display: flex;
            justify-content: space-between;
            align-items: center;
            z-index: 100;
        }

        .logo {
            font-size: 25px;
            color: #ededed;
            text-decoration: none;
            font-weight: 600;
        }

        .navbar a {
            font-size: 18px;
            color: #ededed;
            text-decoration: none;
            font-weight: 500;
            margin-left: 35px;
            transition: .3s;
        }

        .navbar a:hover,
        .navbar a.active {
            color: #00abf0;
        }

        .home {
            height: 100vh;
            background: url('cotton.jpg') no-repeat;
            background-size: cover;
            background-position: center;
            display: flex;
            align-items: center;
            padding: 0 10%;
        }

        .home-content {
            max-width: 600px;
        }

        .home-content h1 {
            font-size: 56px;
            font-weight: 700;
            line-height: 1.2;
        }

        .home-content h3 {
            font-size: 32px;
            font-weight: 700;
            color: #00abf0;
        }

        .home-content p {
            font-size: 16px;
            margin: 20px 0 40px;
        }

        .home-content .btn-box {
            display: flex;
            justify-content: space-between;
            width: 345px;
            height: 30px;
        }

        .btn-box a {
            position: relative;
            display: inline-flex;
            justify-content: center;
            align-items: center;
            width: 150px;
            height: 100%;
            background: #00abf0;
            border: 2px solid #00abf0;
            border-radius: 8px;
            font-size: 19px;
            color: #081b29;
            text-decoration: none;
            font-weight: 600;
            letter-spacing: 1px;
            z-index: 1;
            overflow: hidden;
            transition: .5s;
        }

        .btn-box a:hover {
            color: #00abf0;
        }

        .btn-box a:nth-child(2) {
            background: transparent;
            color: #00abf0;
        }

        .btn-box a:nth-child(2):hover {
            color: #081b29;
        }

        .btn-box a:nth-child(2)::before {
            background: #00abf0;
        }

        .btn-box a::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            width: 0;
            height: 100%;
            background-color: #081b29;
            z-index: -1;
            transition: .5s;
        }

        .btn-box a:hover::before {
            width: 100%;
        }

        .home-sci {
            position: absolute;
            bottom: 40px;
            width: 170px;
            display: flex;
            justify-content: space-between;
        }

        .home-sci a {
            position: relative;
            display: inline-flex;
            justify-content: center;
            align-items: center;
            width: 40px;
            height: 40px;
            background: transparent;
            border: 2px solid #00abf0;
            border-radius: 50%;
            font-size: 20px;
            color: #00abf0;
            text-decoration: none;
            z-index: 1;
            overflow: hidden;
        }

        .home-sci a::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            width: 0;
            height: 100%;
            background: #00abf0;
            z-index: -1;
            transition: .5s;
        }

        .home-sci a:hover::before {
            width: 100%;
        }
    </style>
</head>
<body>
    <header class="header">
        <a href="#" class="logo">Cotton</a>
        <nav class="navbar">
            <a href="pg1.html" class="active">Home</a>
            <a href=" <p>
      <script src="https://apps.elfsight.com/p/platform.js" defer></script>
<div class="elfsight-app-65e091b0-d33c-4191-81f3-be77c921660a"></div>
    </P>
  <p>
    <i class="fab fa-youtube" style="font-size:1.0rem;color:red;"></i>
    <span style="font-size:1.0rem;"> </span>
    <a href=" https://anukarthi1323.github.io/check/" target="_blank" style="font-size:1.0rem;">monit</a>
    </P></a>
            <a href="pg4.html">About</a>
            <a href="pg5.html">Contact</a>
        </nav>
    </header>
    <section class="home">
        <div class="home-content">
            <h1>Cotton industry</h1>
            <h3>Spinning </h3>
            <p>India is the largest producer of cotton globally India is the largest producer of cotton globally</p>
            <div class="btn-box">
                <a href="#">Explore</a>
            </div>
        </div>
        <div class="home-sci">
            <a href="#"><i class='bx bxl-facebook'></i></a>
            <a href="#"><i class='bx bxl-twitter'></i></a>
            <a href="#"><i class='bx bxl-linkedin'></i></a>
        </div>
    </section>
  <p>
      <script src="https://apps.elfsight.com/p/platform.js" defer></script>
<div class="elfsight-app-65e091b0-d33c-4191-81f3-be77c921660a"></div>
    </P>
  <p>
    <i class="fab fa-youtube" style="font-size:1.0rem;color:red;"></i>
    <span style="font-size:1.0rem;">click to </span>
    <a href=" https://anukarthi1323.github.io/monit.com/" target="_blank" style="font-size:1.0rem;">The IoT Projects YouTube Channel</a>
  </P>
</body>
</html>)rawliteral";

// Replaces placeholder with DHT values
String processor(const String& var){
  //Serial.println(var);
  if(var == "TEMPERATURE"){
    return String(t);
  }
  else if(var == "HUMIDITY"){
    return String(h);
  }
  return String();
}

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  dht.begin();
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println(".");
  }

  // Print ESP8266 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(t).c_str());
  });
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(h).c_str());
  });

  // Start server
  server.begin();
}
 
void loop(){  
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you updated the DHT values
    previousMillis = currentMillis;
    // Read temperature as Celsius (the default)
    float newT = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    //float newT = dht.readTemperature(true);
    // if temperature read failed, don't change t value
    if (isnan(newT)) {
      Serial.println("Failed to read from DHT sensor!");
    }
    else {
      t = newT;
      Serial.println(t);
    }
    // Read Humidity
    float newH = dht.readHumidity();
    // if humidity read failed, don't change h value 
    if (isnan(newH)) {
      Serial.println("Failed to read from DHT sensor!");
    }
    else {
      h = newH;
      Serial.println(h);
    }
  }
}