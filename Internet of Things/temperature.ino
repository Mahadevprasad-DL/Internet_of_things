#define DHTPIN 3 
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600); 
    dht.begin(); 

    float temperature = dht.readTemperature();
    
    if (!isnan(temperature)) {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" °C");
    }
}

