#pragma once
#include <TinyGPS++.h>
#include <HardwareSerial.h>

class gps
{
public:
    void init();
    bool checkGpsFix();
    void buildPacket(uint8_t txBuffer[9]);
    void encode();
    
    double getLatitude()
    {
        return tGps.location.lat();
    };
    
    double getLongitude()
    {
        return tGps.location.lng();
    };
    
    float getAltitude() 
    {
        return tGps.altitude.meters();
    }
    
    float getHdop() 
    {
        return tGps.hdop.hdop();
    }
    
    uint8_t getSats() 
    {
        return tGps.satellites.value();
    }
    
    double distanceTo(double lat2, double lon2);

private:
    uint32_t LatitudeBinary, LongitudeBinary;
    uint16_t altitudeGps;
    uint8_t hdopGps;
    uint32_t sats;
    char t[32]; // used to sprintf for Serial output
    TinyGPSPlus tGps;
    double distance;
};
