#include <Arduino.h>
#include <HX711_ADC.h>

#define PEAK_READING_PERIOD (20000)

#define HX711_GAIN (128)                                       // default is 128, can be set to 32 or 64 with .setGain();
#define HX711_EXCITATION_V (4.3)                               // HX711 module has an onboard 4.3V regulator for precise excitation of load cells
#define HX711_OUTPUT_V_RANGE ((float)HX711_EXCITATION_V / HX711_GAIN) // in millivolts, is converted from the 24bit ADC of the HX711
#define HX711_24_BIT_ADC_MAX_VAL (16777215 - 1)                //2^24 -1, since 0 counts as a bit configuration

/*
Compressing the bracket increases the Voltage reading, 
extension (pushing outwards) reduces it
*/

enum torqueReadingMode
{
    liveReading,
    extensionPeakReading,
    compressionPeakReading,
    endReadingMode  // end of enum indicator
};

class bracket
{
private:
    /* data */

    uint8_t readingMode = compressionPeakReading;
    float _zeroTorqueValue =  (HX711_24_BIT_ADC_MAX_VAL / 2); //= 7830000; // Hard coded to be around 0, but init calibration will find correct 0
    float _displayedTorqueValue;  // Reading currently displayed on screen

    // PEAK MODE VARIABLES
    unsigned _displayedTorqueTimeStamp = 0; // Time in ms at which shown value was displayed

    bool waitForFirstReading(HX711_ADC &scale);

public:
    bracket(/* args */) {}
    ~bracket() {}

    void changeReadingMode();
    uint8_t getReadingMode() { return readingMode; }

    void displayTorque(float torqueValue) { _displayedTorqueValue = torqueValue; }
    float getDisplayedTorque() { return _displayedTorqueValue; }

    bool init(HX711_ADC &scale);

    float calculateTorque(float hx711_value);
    void setZeroTorqueValue(float hx711_tare_value);

    //bool checkRefreshPeakValue(float newValue);
    bool isRefreshNeeded(float newValue);
};

 