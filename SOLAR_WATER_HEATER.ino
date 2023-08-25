#include <OneWire.h>
#include <DallasTemperature.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

const int TEMP_SENSOR_PIN = 12;
const int RELAY_PIN = A3;
const int LED = 13;
const int ROW_NUM = 4;
const int COLUMN_NUM = 4;

char keys[ROW_NUM][COLUMN_NUM] =
{
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_row[ROW_NUM] = {9, 8, 7, 6};
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys),
pin_row, pin_column, ROW_NUM, COLUMN_NUM);
LiquidCrystal_I2C lcd(0x27, 16, 2);
OneWire MyWire(TEMP_SENSOR_PIN);
DallasTemperature tempSensor(&MyWire);

String inputString;
int temp;
float tempCelsius;
int i = tempCelsius;

void setup()
{
  Serial.begin(9600);
  Serial.println("Serial done");
  pinMode(LED, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  inputString.reserve(5);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Solar Water");
  lcd.setCursor(5,1);
  lcd.print("Bottle");
  delay(2000);
  tempSensor.begin();
  tempSensor.requestTemperatures();
  tempCelsius =
  tempSensor.getTempCByIndex(0);
  tempCelsius = i;
  Serial.println(tempCelsius);
  Serial.println("Initial setup done");
  Serial.println("Enter temperature: ");
  digitalWrite(RELAY_PIN, HIGH);
  Serial.println(i);
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter Temp ");
}

void loop()
{
  char key = keypad.getKey();
  if(key)
  {
    if(key >= '0' && key <= '9')
    {
      Serial.print(key);
      inputString += key;
      lcd.clear();
      lcd.setCursor(12,0);
      lcd.print(key);
      delay(1000);
    }
    
    else if(key == '#')
    {
      if(inputString.length() > 0)
      {
        int temp = inputString.toInt();
        Serial.print("Temp input = ");
        Serial.println(temp);
        inputString = "";
        digitalWrite(RELAY_PIN, LOW);
        Serial.println("HEATER ON");
        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print("HEATER ON");
        delay(2000);
        tempSensor.requestTemperatures();
        tempCelsius =
        tempSensor.getTempCByIndex(0);
        
        for(;i==temp;)
        {
          tempSensor.requestTemperatures();
          tempCelsius =
          tempSensor.getTempCByIndex(0);
          int i = tempCelsius;
          if(i==temp)
          {
            digitalWrite(RELAY_PIN, HIGH);
            Serial.println("HEATER OFF");
            Serial.println
            ("Process Completed!");
            lcd.clear();
            lcd.setCursor(3,0);
            lcd.print("Process");
            lcd.setCursor(1,1);
            lcd.print("Completed!");
            digitalWrite(LED, HIGH);
          }
        }
        
        while(i<=temp)
        {
          tempSensor.requestTemperatures();
          tempCelsius =
          tempSensor.getTempCByIndex(0);
          int i = tempCelsius;
          Serial.println(tempCelsius);
          delay(4000);
          if(i==temp)
          {
            digitalWrite(RELAY_PIN, LOW);
            Serial.println
            ("Process completed!");
            lcd.clear();
            lcd.setCursor(3,0);
            lcd.print("Process");
            lcd.setCursor(1,1);
            lcd.print("completed!");
            digitalWrite(LED, HIGH);
          }
        }
       }
      }
  }
}
