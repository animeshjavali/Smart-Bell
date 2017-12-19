
#include <DS3231.h>
DS3231  rtc(SDA, SCL);
Time  t;
void setup() {
  Serial.begin(115200);
 rtc.begin(); 
  
}

void loop() {
    t = rtc.getTime();
   Serial.print(t.hour,DEC);
   Serial.print(" : ");
   Serial.print(t.min,DEC);
    Serial.print(" : ");
    Serial.print(t.sec,DEC);
    Serial.print("\n");
   delay(1000);
   if(t.hour==16 && t.min==12 && t.sec==00 )
   {
    Serial.println("ATD9535939593;");
    delay(25000);
 Serial.println("ATH");
 Serial.println("AT+CMGF=1");
  delay(5000);
   Serial.print("AT+CMGS=\"");
  Serial.print("9535939593");
  Serial.println("\"");
  delay(2000);
  Serial.print("Good evening mam. Your class for 7TH sem starts in 5 mins");
  Serial.write(0x1A);
  
    }
 
  
}
