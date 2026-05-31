#include "downloader.h"
#include "utils.h"
#include <curl/curl.h>
#include <iostream>
#include <regex>

bool isValidYouTubeUrl(const std::string& url) {
    std::regex pattern(R"(^(https?\:\/\/)?(www\.)?(youtube\.com|youtu\.?be)\/.+$)");
    return std::regex_match(url, pattern);
}

size_t writeData(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return fwrite(ptr, size, nmemb, stream);
}

void downloadVideo(const std::string& url) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize CURL\n";
        return;
    }

    std::string videoId = extractVideoId(url);
    std::string outputFile = videoId + ".mp4";

    FILE* fp = fopen(outputFile.c_str(), "wb");
    if (!fp) {
        std::cerr << "Failed to create file\n";
        curl_easy_cleanup(curl);
        return;
    }

    curl_easy_setopt(curl, CURLOPT_URL, ("https://www.youtube.com/watch?v=" + videoId).c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "CURL error: " << curl_easy_strerror(res) << "\n";
    }

    fclose(fp);
    curl_easy_cleanup(curl);
}