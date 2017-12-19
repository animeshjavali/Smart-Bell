
#include <DS3231.h>
DS3231  rtc(SDA, SCL);// Parse data and clock input.
Time  t;
void setup() {
 Serial.begin(115200);//Set serial commn at 115200 baudrate.
 rtc.begin(); 
  
}

void loop() {
   t = rtc.getTime();// 't'contains time info.
   Serial.print(t.hour,DEC);// print time.
   Serial.print(" : ");
   Serial.print(t.min,DEC);  
   Serial.print(" : ");
   Serial.print(t.sec,DEC);
   Serial.print("\n");
   delay(1000);
   if(t.hour==10 && t.min==40 && t.sec==00 ) // Data Analytics for deciding time to notify lecturers.
   {
    Serial.println("ATD9535939***;"); // Place call at the required time.
    delay(25000);
 Serial.println("ATH");// Auto-Hang up the call.
 Serial.println("AT+CMGF=1");
  delay(5000);
   Serial.print("AT+CMGS=\"");
  Serial.print("95359395***");
  Serial.println("\"");
  delay(2000);
  Serial.print("Good evening mam. Your class for 7TH sem starts in 5 mins");// The text message.
  Serial.write(0x1A);
  
    }
 
  
}
