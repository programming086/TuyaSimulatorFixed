#ifndef THINGSMART_CAMERA_SHELL_THINGMP4JNIRECORDER_H
#define THINGSMART_CAMERA_SHELL_THINGMP4JNIRECORDER_H

//#ifndef __ANDROID__

#include "mp4_recorder_interface.h"
#include <mutex>

class FrameMp4Recorder : public Mp4RecorderInterface {
public:
    FrameMp4Recorder(int port_id);

    ~FrameMp4Recorder() override;

public:
    virtual int CreateMp4File(const MP4_CONFIG_INFO &stream_info, const std::string &filepath, const std::string &filename) override;
    
    virtual int Stop() override;

    void WriteAudioFrame(MP4_AUDIO_FRAME_INPUT_INFO& audio_frame_info) override;

    void WriteVideoFrame(MP4_FRAME_INPUT_INFO& input_frame) override;
    
private:
    void* mp4_recorder_handle_;
    bool is_real_time_;
};

//#endif
#endif //THINGSMART_CAMERA_SHELL_THINGMP4JNIRECORDER_H
