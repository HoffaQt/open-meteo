#include <stdio.h>
#include "weather.h"
#include "apihandler.h"
#include "jsonparser.h"
#include <cjson/cJSON.h>

int main()
{
    initCityData();
    printf("Welcome!\n");
    
    while (1)
    {
        char temp[10];
        char* jsonResponse;
        const char* url = getWeather();
        //Response resp;
//
        //if (url == NULL) break; // Exit the loop if user chose to exit
//
        //jsonResponse = getApiResponse(url);
        //
        //if (parse_response(jsonResponse, &resp)) 
        //{
        //    printf("Lat: %.2f, Lon: %.2f, Temp: %.1f\n", resp.latitude, resp.longitude, resp.current_weather.temperature);
        //} 
        //else 
        //{
        //    printf("Parse error\n");
        //}
        cJSON* json = cJSON_Parse(url);
        char* string = cJSON_Print(json);
        
        
        
        //Print weather api url then wait for user to press enter before continuing
        printf("Press Enter to continue...\n");
        fgets(temp, sizeof(temp), stdin);
    }
    
    return 0;
}