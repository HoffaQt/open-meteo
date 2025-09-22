#include "apihandler.h"
#include <curl/curl.h>
#include <string.h>

size_t callback( char* in, size_t size, size_t num, char* out) 
{
    size_t totalBytes = size * num;
    strncat(out, in, totalBytes);
    return totalBytes;
}

char* getApiResponse(const char* url) 
{
    CURL* curl;
    CURLcode res;
    static char response[4096]; // Static to ensure it persists after function returns
    response[0] = '\0'; // Initialize response to an empty string
    curl = curl_easy_init();
    
    if(curl) 
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK) 
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            strcpy(response, "Error fetching data");
        }
        
        curl_easy_cleanup(curl);
    }
    else 
    {
        strcpy(response, "Error initializing curl");
    }

    return response;
}