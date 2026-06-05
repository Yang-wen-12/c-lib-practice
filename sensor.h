#ifndef SENSOR_H
#define SENSOR_H
typedef struct {
    float water;
    float vapor;
} Sensor;
void show(Sensor s);
#endif
