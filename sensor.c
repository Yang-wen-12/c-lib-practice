#include "sensor.h"
#include <stdio.h>
void show(Sensor s) {
    printf("水位:%.2f 水汽:%.2f\n", s.water, s.vapor);
}
