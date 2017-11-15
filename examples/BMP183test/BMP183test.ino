#include <Adafruit_BMP183.h>

//BMP183 片选信号
#define BMP183_CS   A4

//平均海平线气压值
#define SENSORS_PRESSURE_SEALEVELHPA      (1013.25F)

//使用硬件SPI
Adafruit_BMP183 bmp = Adafruit_BMP183(BMP183_CS);

void setup(void)
{
    Serial.begin(115200);
    Serial.println("BMP183 Pressure Sensor Test"); Serial.println("");

    if(!bmp.begin())
    {
        Serial.print("Ooops, no BMP183 detected ... Check your wiring!");
        while(1);
    }
}

void loop(void)
{
    //输出大气压强
    Serial.print("Pressure:    ");
    Serial.print(bmp.getPressure());
    Serial.print(" Pascals / ");
    Serial.print(bmp.getPressure() / 100);
    Serial.println(" millibar (hPa)");

    // 获取温度
    float temperature;
    temperature = bmp.getTemperature();
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    //获取海拔高度
    float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA; // should be ~1000
    Serial.print("Sea level pressure: ");
    Serial.print(SENSORS_PRESSURE_SEALEVELHPA);
    Serial.println(" millibar/hPa");

    Serial.print("Altitude:    ");
    Serial.print(bmp.getAltitude(seaLevelPressure));
    Serial.println(" m");
    Serial.println("");

    delay(1000);
}

