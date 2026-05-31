#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <string>

bool isValidYouTubeUrl(const std::string& url);
void downloadVideo(const std::string& url);

#endif