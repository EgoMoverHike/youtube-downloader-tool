import pytest
from src.downloader import YouTubeDownloader

class TestYouTubeDownloader:
    def test_init_creates_directory(self, tmpdir):
        output = str(tmpdir.join("videos"))
        downloader = YouTubeDownloader(output_dir=output)
        assert tmpdir.join("videos").exists()

    def test_get_video_info_returns_dict(self, mocker):
        mock_yt = mocker.patch("src.downloader.YouTube")
        mock_instance = mock_yt.return_value
        mock_instance.title = "Test Video"
        mock_instance.author = "Test Author"
        mock_instance.length = 120
        mock_instance.views = 1000

        downloader = YouTubeDownloader()
        info = downloader.get_video_info("https://youtube.com/watch?v=test")
        assert info["title"] == "Test Video"
        assert info["author"] == "Test Author"

    def test_download_video_returns_path(self, mocker, tmpdir):
        mock_yt = mocker.patch("src.downloader.YouTube")
        mock_instance = mock_yt.return_value
        mock_stream = mock_instance.streams.get_highest_resolution.return_value
        mock_stream.download.return_value = str(tmpdir.join("test.mp4"))

        downloader = YouTubeDownloader(output_dir=str(tmpdir))
        result = downloader.download_video("https://youtube.com/watch?v=test")
        assert result.endswith("test.mp4")