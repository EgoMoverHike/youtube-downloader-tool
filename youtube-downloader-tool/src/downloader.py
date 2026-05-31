from pytube import YouTube
import os

class YouTubeDownloader:
    def __init__(self, output_dir: str = "./downloads"):
        self.output_dir = output_dir
        os.makedirs(self.output_dir, exist_ok=True)

    def download_video(self, url: str, filename: str = None) -> str:
        yt = YouTube(url)
        stream = yt.streams.get_highest_resolution()
        out_path = stream.download(output_path=self.output_dir, filename=filename)
        return out_path

    def get_video_info(self, url: str) -> dict:
        yt = YouTube(url)
        return {
            "title": yt.title,
            "author": yt.author,
            "length": yt.length,
            "views": yt.views,
        }