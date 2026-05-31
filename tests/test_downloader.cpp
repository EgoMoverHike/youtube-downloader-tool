#include "../src/downloader.h"
#include "../src/utils.h"
#include <cassert>

void testValidYouTubeUrl() {
    assert(isValidYouTubeUrl("https://www.youtube.com/watch?v=dQw4w9WgXcQ"));
    assert(isValidYouTubeUrl("https://youtu.be/dQw4w9WgXcQ"));
    assert(!isValidYouTubeUrl("https://example.com"));
}

void testExtractVideoId() {
    assert(extractVideoId("https://www.youtube.com/watch?v=dQw4w9WgXcQ") == "dQw4w9WgXcQ");
    assert(extractVideoId("https://youtu.be/dQw4w9WgXcQ") == "dQw4w9WgXcQ");
    assert(extractVideoId("invalid-url").empty());
}

int main() {
    testValidYouTubeUrl();
    testExtractVideoId();
    return 0;
}