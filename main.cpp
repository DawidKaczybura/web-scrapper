#include <iostream>
#include <string>
#include "curl/curl.h"

size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

const char *url = "http://www.google.pl";

int main()
{
    curl_global_init(CURL_GLOBAL_ALL);

    CURL* easyHandle = curl_easy_init();
    std::string readBuffer;

    curl_easy_setopt(easyHandle, CURLOPT_URL, url);
    curl_easy_setopt(easyHandle, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(easyHandle, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(easyHandle, CURLOPT_WRITEDATA, &readBuffer);

    curl_easy_perform(easyHandle);

    std::cout << readBuffer << std::endl;

    int a;
    std::cin >> a;
    return 0;
}