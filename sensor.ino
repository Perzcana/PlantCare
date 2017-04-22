static int temp = 0;
static int humidity =0;

void sensor_init(){
    #ifdef DEBUG
      Serial.println("sensor_init");
    #endif
    pinMode(DHTPIN, INPUT_PULLUP);
    pinMode(DHT_POWER_PIN, OUTPUT);
}
void update_sensor(){
    digitalWrite(DHT_POWER_PIN, HIGH);
    dht.begin();
    delay(DHT_INIT_INTERVAL);
    temp = dht.readTemperature();
    humidity = dht.readHumidity();
    digitalWrite(DHT_POWER_PIN, LOW);
    #ifdef DEBUG
      Serial.println("sensor_update");
      Serial.print(TEMP_MIN);
      Serial.print(" <------temp------>");
      Serial.println(TEMP_MAX);
      Serial.print(temp);
      Serial.print(" <-temp  humidity->");
      Serial.println(humidity);
    #endif
  
    if (temp > TEMP_MAX){
        if (humidity > HUMIDITY_MAX){
            state = WARM_HUMID;
        }
        else if (humidity < HUMIDITY_MIN){
            state = WARM_DRY;
        }
        else{
            state = WARM_SUIT;
        }
    }
    else if (temp < TEMP_MIN){
        if (humidity > HUMIDITY_MAX){
            state = COOL_SUIT;
        }
        else if (humidity < HUMIDITY_MIN){
            state = COOL_DRY;
        }
        else{
            state = COOL_SUIT;
        }
    }
    // else if (humidity > HUMIDITY_MAX){
    //     state = SUIT_HUMID;
    // }
    // else if (humidity < HUMIDITY_MIN){
    //     state = SUIT_DRY;
    // }
    else{
        state = SUIT;
    }
}
