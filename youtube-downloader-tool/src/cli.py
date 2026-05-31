import argparse
from .downloader import YouTubeDownloader

def main():
    parser = argparse.ArgumentParser(description="Download YouTube videos")
    parser.add_argument("url", help="YouTube video URL")
    parser.add_argument("-o", "--output", default="./downloads", help="Output directory")
    parser.add_argument("-n", "--name", default=None, help="Output filename")
    args = parser.parse_args()

    downloader = YouTubeDownloader(output_dir=args.output)
    path = downloader.download_video(args.url, filename=args.name)
    print(f"Downloaded to: {path}")

if __name__ == "__main__":
    main()