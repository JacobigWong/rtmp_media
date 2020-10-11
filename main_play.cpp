﻿#include <stdio.h>
#include <iostream>
#include <memory>
#include "dlog.h"
//#include "audio.h"
//#include "aacencoder.h"
//#include "audioresample.h"
using namespace std;

extern "C" {
#include <libavcodec/avcodec.h>
#include <libswresample/swresample.h>
#include <libavutil/opt.h>
#include <libavutil/audio_fifo.h>
}

#include "pushwork.h"
#include "pullwork.h"
using namespace LQF;
extern int rtmpPull(int argc, char* argv[]);
extern int rtmpPublish(int argc, char* argv[]);
extern int testAacEncoder(const char *pcmFileName, const char* aacFileName);
#undef main

//#define RTMP_URL "rtmp://111.229.231.225/live/livestream"
#define RTMP_URL "rtmp://192.168.1.11/live/livestream"
// ffmpeg -re -i  rtmp_test_hd.flv  -vcodec copy -acodec copy  -f flv -y rtmp://111.229.231.225/live/livestream
//// ffmpeg -re -i  1920x832_25fps.flv  -vcodec copy -acodec copy  -f flv -y rtmp://111.229.231.225/live/livestream
int main(int argc, char* argv[])
{
    init_logger("rtmp_push.log", S_INFO);
    {
        PullWork pullwork;
        Properties   pull_properties;
        pull_properties.SetProperty("rtmp_url", RTMP_URL);
        if(pullwork.Init(pull_properties) != RET_OK)
        {
            LogError("pullwork.Init failed");
        }


        int count = 0;
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            //            if(count++ > 1200)
            //                break;
        }

    } // 测试析构
    LogError("~~析构");
    getchar();
    return 0;
}



