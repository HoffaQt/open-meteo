#include <stdio.h>
#include "weather.h"

int main()
{
    printf("Welcome!\n");
    while (1)
    {
        char* url = getWeather();
        char temp[10];
        
        if (url == NULL) break; // Exit the loop if user chose to exit
     
        //Print weather api url then wait for user to press enter before continuing
        printf("URL: \"%s\"\r\n", url);
        printf("Press Enter to continue...\n");
        fgets(temp, sizeof(temp), stdin);
    }
    return 0;
}