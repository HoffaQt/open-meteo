#ifndef WEATHER_H
#define WEATHER_H
#include <stdio.h>

typedef struct CityData{
    char city[100];
    double lat;
    double lon;
    char url[200];
} CityData;

typedef struct City City;

typedef struct City
{
    char name[100];
    double lat;
    double lon;
    char url[200];
    struct City* next;
    struct City* prev;
};

typedef struct {
    City* head;
} CityList;


void initCityData();

char* getWeather();

#endif // WEATHER_H