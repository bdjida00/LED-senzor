#ifndef main_h
#define main_h

// Payload that child sends to the parent
struct SensorData
{
    int dst;
};

typedef enum
{
    READ_SERIAL,
    READ_SENSORS,
    RADIO_TX,
    SLEEP,
    NUM_STATES
} StateType;

#endif