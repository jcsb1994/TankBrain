#include <bracket.h>

bool bracket::waitForFirstReading(HX711_ADC &scale)
{
    float scaleReading = 0;
    uint16_t timeout = 10000;
    while (timeout && (scaleReading == 0))
    {
        scale.update();
        scaleReading = scale.getData();
        timeout--;
    }
    if (timeout)
        return true;
    else
        return false;
}

void bracket::changeReadingMode()
{
    readingMode++;
    if (readingMode == endReadingMode)
        readingMode = 0;
}

bool bracket::init(HX711_ADC &scale)
{
        if (waitForFirstReading(scale))
        return true;
    else
        return false;
}

float bracket::calculateTorque(float hx711_value)
{
    /*     Serial.print("raw: ");
    Serial.println(hx711_value); */

    hx711_value += ((HX711_24_BIT_ADC_MAX_VAL / 2) - _zeroTorqueValue);

    long in_min = 0;
    long in_max = HX711_24_BIT_ADC_MAX_VAL;
    float out_min = -(1000 * (4.3 / 2) / 128.0);
    float out_max = (1000 * (4.3 / 2) / 128.0);

    float mV = (float)(hx711_value - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;

    

    /*     Serial.print("mapped: ");
    Serial.println(mV); */
    mV /= HX711_EXCITATION_V;
    float torque_Nm = (37.399 * mV) - 0.0535;
    /*     Serial.print("torque: ");
    Serial.println(torque_Nm); */

    return torque_Nm;
}

void bracket::setZeroTorqueValue(float hx711_tare_value)
{
    _zeroTorqueValue = hx711_tare_value;
}

/* bool bracket::checkRefreshPeakValue(float newValue)
{
    if (readingMode != compressionPeakReading)
        return false;

    if ((newValue > _displayedTorqueValue) | ((millis() - _displayedTorqueTimeStamp) > PEAK_READING_PERIOD))
    {
        this->displayTorque(newValue);
        _displayedTorqueTimeStamp = millis();
        return true;
    }
    else
        return false;
}
 */
bool bracket::isRefreshNeeded(float newValue)
{
    bool ret = false;
    switch (readingMode)
    {
    case extensionPeakReading:
        if ((newValue < _displayedTorqueValue) | ((millis() - _displayedTorqueTimeStamp) > PEAK_READING_PERIOD))
        {
            this->displayTorque(newValue);
            _displayedTorqueTimeStamp = millis();
            ret = true;
        }
        break;

    case compressionPeakReading:
        if ((newValue > _displayedTorqueValue) | ((millis() - _displayedTorqueTimeStamp) > PEAK_READING_PERIOD))
        {
            this->displayTorque(newValue);
            _displayedTorqueTimeStamp = millis();
            ret = true;
        }
        break;

    case liveReading:
        this->displayTorque(newValue);

        ret = true;
        break;

    default:
        break;
    }
    return ret;
}