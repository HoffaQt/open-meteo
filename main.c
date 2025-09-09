#include <stdio.h>
#include <string.h>
#include "weather.h"

int main()
{
    //const char* cities = "Stockholm:59.3293:18.0686\n" "G�teborg:57.7089:11.9746\n" "Malm�:55.6050:13.0038\n" "Uppsala:59.8586:17.6389\n" "V�ster�s:59.6099:16.5448\n" "�rebro:59.2741:15.2066\n" "Link�ping:58.4109:15.6216\n" "Helsingborg:56.0465:12.6945\n" "J�nk�ping:57.7815:14.1562\n" "Norrk�ping:58.5877:16.1924\n" "Lund:55.7047:13.1910\n" "G�vle:60.6749:17.1413\n" "Sundsvall:62.3908:17.3069\n" "Ume�:63.8258:20.2630\n" "Lule�:65.5848:22.1567\n" "Kiruna:67.8558:20.2253\n"; 
    printf("Welcome!\n");
    while (1)
    {
        char* url = getWeather();
        
        if (url == NULL) 
        {
            break; // Exit the loop if user chose to exit
        }
        
        printf("URL: \"%s\"\r\n", url); 
        //Wait for user to press enter before continuing
        printf("Press Enter to continue...\n");
        char temp[10];
        fgets(temp, sizeof(temp), stdin);
    }
    //char* url = getWeather();
    //printf("URL: \"%s\"\r\n", url); 
    return 0;
}