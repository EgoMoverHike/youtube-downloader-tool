#include <iostream>
#include "downloader.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <youtube-url>\n";
        return 1;
    }

    std::string url = argv[1];
    if (!isValidYouTubeUrl(url)) {
        std::cerr << "Invalid YouTube URL\n";
        return 1;
    }

    std::cout << "Downloading: " << url << "\n";
    downloadVideo(url);
    return 0;
}