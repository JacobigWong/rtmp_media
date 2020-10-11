# rtmp
基于librtmp和ffmpeg实现rtmp推流和拉流
# 开发环境的搭建参考
1. 开发环境的搭建参考：《3-QT+FFmpeg4.2.1 Windows开发环境搭建.docx》
需要需要dll的拷贝。
如果不安装命令行，则需要自己将对应的dll拷贝到build-rtmp_publish-Desktop_Qt_5_10_1_MSVC2015_32bit-Debug的目录。
# 最新源码
2. 最新源码：
http://gitlab.0voice.com/liaoqingfu/rtmp
# 需要注意的工作
3. 需要注意的工作
（1）从文件提取pcm数据
ffmpeg -i buweishui.mp3 -ar 48000 -ac 2 -f s16le 48000_2_s16le.pcm

（2）从文件提取yuv数据
ffmpeg -i 720x480_25fps.mp4 -an -c:v rawvideo -pix_fmt yuv420p 720x480_25fps_420p.yuv

将他们都放到
build-rtmp_publish-Desktop_Qt_5_10_1_MSVC2015_32bit-Debug
目录下面供读取。

# 工程名
rtmp_publish.pro  推流工程

rtmp_play.pro	拉流工程