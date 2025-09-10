#include <stdio.h>
#include <string.h>
#include "weather.h"

char* getWeather()
{
    struct CityData cityArr[16];
    const char* cities = "Stockholm:59.3293:18.0686\n" "Göteborg:57.7089:11.9746\n" "Malmö:55.6050:13.0038\n" "Uppsala:59.8586:17.6389\n" "Västerås:59.6099:16.5448\n" "Örebro:59.2741:15.2066\n" "Linköping:58.4109:15.6216\n" "Helsingborg:56.0465:12.6945\n" "Jönköping:57.7815:14.1562\n" "Norrköping:58.5877:16.1924\n" "Lund:55.7047:13.1910\n" "Gävle:60.6749:17.1413\n" "Sundsvall:62.3908:17.3069\n" "Umeå:63.8258:20.2630\n" "Luleå:65.5848:22.1567\n" "Kiruna:67.8558:20.2253\n"; 
    char input[100];
    char url[100];
    int choice;
    int counter = 0;

    //Read in data
    const char* ptr = cities;
    while (*ptr) 
    {
        char city[100];
        double lat, lon;
        int n = sscanf(ptr, "%99[^:]:%lf:%lf\n", city, &lat, &lon);
        
        if (n == 3) 
        {
            strcpy(cityArr[counter].city, city);
            cityArr[counter].lat = lat;
            cityArr[counter].lon = lon;
            counter++;
        }
        
        //Move ptr to next line
        const char* next = strchr(ptr, '\n');
        if (!next) break;
        ptr = next + 1;
    }

    printf("Choose a city and enter number to view or type 0 to exit:\n");
    for(int i = 0; i < counter; i++)
    {
        printf("%i.%s\n", i+1, cityArr[i].city);
    }
    
    //Read user input
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &choice);
    choice = choice - 1; //Adjust for 0 index array

    if(choice >= 0 && choice <= counter)
    {
        printf("%s\n", cityArr[choice].city);
        sprintf(url, "https://api.open-meteo.com/v1/forecast?latitude=%.4f&longitude=%.4f&current_weather=true\n", cityArr[choice].lat, cityArr[choice].lon);
        char* weatherUrl = url;
        return weatherUrl;
    }
    else if(choice < -1 || choice >= counter)
    {
        return("City not found\n");
    }
    else if(choice == -1)
    {
        return NULL;
    }
    return NULL;
}