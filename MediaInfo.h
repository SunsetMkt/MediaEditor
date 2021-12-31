#pragma once
#include <cstdint>
#include <string>
#include <memory>
#include <vector>

namespace MediaInfo
{
    enum Type
    {
        UNKNOWN = 0,
        VIDEO,
        AUDIO,
    };

    struct Ratio
    {
        int32_t num{0};
        int32_t den{0};
    };

    struct Stream
    {
        virtual ~Stream() {}
        Type type{UNKNOWN};
        uint64_t bitRate{0};
        double startTime;
        double duration;
        Ratio timebase;
    };

    using StreamHolder = std::shared_ptr<Stream>;

    struct VideoStream : public Stream
    {
        VideoStream() { type = VIDEO; }
        uint32_t width{0};
        uint32_t height{0};
        Ratio sampleAspectRatio;
        Ratio avgFrameRate;
        Ratio realFrameRate;
        uint64_t frameNum{0};
    };

    struct AudioStream : public Stream
    {
        AudioStream() { type = AUDIO; }
        uint32_t channels{0};
        uint32_t sampleRate{0};
    };
    

    struct Info
    {
        std::string url;
        std::vector<StreamHolder> streams;
        double startTime;
        double duration;
    };

    using InfoHolder = std::shared_ptr<Info>;
}
