#ifndef WEATHER_H
#define WEATHER_H
#include <stdio.h>

typedef struct {
    char city[100];
    double lat;
    double lon;
    char url[200];
} CityData;

void initCityData();

char* getWeather();

#endif // WEATHER_H