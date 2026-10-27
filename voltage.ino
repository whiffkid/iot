#define v_pin A0
#define led_pin 13

const float R1=10000.0;
const float R2=10000.0;

const float VREF=5.0;
const float low_amp=7.0;

void setup(){
  pinMode(led_pin,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  float absValue=analogRead(v_pin);
  float v_A0= (absValue*VREF)/1023.0;
  float v_battery= v_A0*((R1+R2)/R2);

  Serial.print("ADC Value");
  Serial.println(absValue);

  Serial.print("Battery voltage:");
  Serial.print(v_battery);
  Serial.println(" V");

  if(v_battery<low_amp){
    digitalWrite(led_pin,HIGH);
    Serial.println("LOW VOLTAGE");
  }
  else{
    digitalWrite(led_pin,LOW);
    Serial.println("NORMAL VOLTAGE");
  }
  delay(1000);
}