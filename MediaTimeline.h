#pragma once
#include <imgui.h>
#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui_internal.h>
#include <imgui_json.h>
#include "MediaOverview.h"
#include "MediaSnapshot.h"
#include "MediaReader.h"
#include "MultiTrackVideoReader.h"
#include "AudioRender.hpp"
#include "UI.h"
#include <thread>
#include <string>
#include <vector>
#include <list>
#include <chrono>

#define ICON_MEDIA_TIMELINE u8"\uf538"
#define ICON_MEDIA_BANK     u8"\ue907"
#define ICON_MEDIA_TRANS    u8"\ue927"
#define ICON_MEDIA_FILTERS  u8"\ue663"
#define ICON_MEDIA_OUTPUT   u8"\uf197"
#define ICON_MEDIA_PREVIEW  u8"\ue04a"
#define ICON_MEDIA_VIDEO    u8"\ue04b"
#define ICON_MEDIA_AUDIO    u8"\ue050"
#define ICON_MEDIA_WAVE     u8"\ue495"
#define ICON_MEDIA_DIAGNOSIS u8"\uf551"
#define ICON_SLIDER_MINIMUM u8"\uf424"
#define ICON_SLIDER_MAXIMUM u8"\uf422"
#define ICON_VIEW           u8"\uf06e"
#define ICON_VIEW_DISABLE   u8"\uf070"
#define ICON_ENABLE         u8"\uf205"
#define ICON_DISABLE        u8"\uf204"
#define ICON_ZOOM_IN        u8"\uf00e"
#define ICON_ZOOM_OUT       u8"\uf010"
#define ICON_ITEM_CUT       u8"\ue14e"
#define ICON_SPEAKER        u8"\ue050"
#define ICON_SPEAKER_MUTE   u8"\ue04f"
#define ICON_FILTER         u8"\uf331"
#define ICON_MUSIC          u8"\ue3a1"
#define ICON_MUSIC_DISABLE  u8"\ue440"
#define ICON_MUSIC_RECT     u8"\ue030"
#define ICON_MAGIC_3        u8"\ue663"
#define ICON_MAGIC_1        u8"\ue664"
#define ICON_MAGIC_DISABlE  u8"\ue665"
#define ICON_HDR            u8"\ue3ee"
#define ICON_HDR_DISABLE    u8"\ue3ed"
#define ICON_PALETTE        u8"\uf53f"
#define ICON_STRAW          u8"\ue3b8"
#define ICON_CROP           u8"\uf125"
#define ICON_ROTATE         u8"\ue437"
#define ICON_LOCKED         u8"\uf023"
#define ICON_UNLOCK         u8"\uf09c"
#define ICON_TRASH          u8"\uf014"
#define ICON_CLONE          u8"\uf2d2"
#define ICON_ADD            u8"\uf067"
#define ICON_ALIGN_START    u8"\ue419"
#define ICON_CROPPING_LEFT  u8"\ue00d"
#define ICON_CROPPING_RIGHT u8"\ue010"
#define ICON_REMOVE_CUT     u8"\ue011"
#define ICON_CUTTING        u8"\uf0c4"
#define ICON_MOVING         u8"\ue41f"
#define ICON_TRANS          u8"\ue882"
#define ICON_BANK           u8"\uf1b3"
#define ICON_BLUE_PRINT     u8"\uf55B"
#define ICON_BRAIN          u8"\uf5dc"
#define ICON_NEW_PROJECT    u8"\uf271"
#define ICON_OPEN_PROJECT   u8"\uf115"
#define ICON_SAVE_PROJECT   u8"\uf0c7"

#define ICON_PLAY           u8"\uf04b"
#define ICON_PAUSE          u8"\uf04c"
#define ICON_STOP           u8"\uf04d"
#define ICON_FAST_BACKWARD  u8"\uf04a"
#define ICON_FAST_FORWARD   u8"\uf04e"
#define ICON_FAST_TO_START  u8"\uf049"
#define ICON_TO_START       u8"\uf048"   
#define ICON_FAST_TO_END    u8"\uf050"
#define ICON_TO_END         u8"\uf051"
#define ICON_EJECT          u8"\uf052"
#define ICON_STEP_BACKWARD  u8"\uf053"
#define ICON_STEP_FORWARD   u8"\uf054"
#define ICON_LOOP           u8"\ue9d6"
#define ICON_LOOP_ONE       u8"\ue9d7"

#define ICON_CROPED         u8"\ue3e8"
#define ICON_SCALED         u8"\ue433"
#define ICON_UI_DEBUG       u8"\uf085"

#define ICON_1K             u8"\ue95c"
#define ICON_1K_PLUS        u8"\ue95d"
#define ICON_2K             u8"\ue963"
#define ICON_2K_PLUS        u8"\ue964"
#define ICON_3K             u8"\ue966"
#define ICON_3K_PLUS        u8"\ue967"
#define ICON_4K_PLUS        u8"\ue969"
#define ICON_5K             u8"\ue96b"
#define ICON_5K_PLUS        u8"\ue96c"
#define ICON_6K             u8"\ue96e"
#define ICON_6K_PLUS        u8"\ue96f"
#define ICON_7K             u8"\ue971"
#define ICON_7K_PLUS        u8"\ue972"
#define ICON_8K             u8"\ue974"
#define ICON_8K_PLUS        u8"\ue975"
#define ICON_9K             u8"\ue977"
#define ICON_9K_PLUS        u8"\ue978"
#define ICON_10K            u8"\ue951"

#define ICON_STEREO         u8"\uf58f"
#define ICON_MONO           u8"\uf590"

#define COL_FRAME_RECT      IM_COL32( 16,  16,  96, 255)
#define COL_LIGHT_BLUR      IM_COL32( 16, 128, 255, 255)
#define COL_CANVAS_BG       IM_COL32( 36,  36,  36, 255)
#define COL_LEGEND_BG       IM_COL32( 33,  33,  38, 255)
#define COL_MARK            IM_COL32(255, 255, 255, 255)
#define COL_MARK_HALF       IM_COL32(128, 128, 128, 255)
#define COL_RULE_TEXT       IM_COL32(224, 224, 224, 255)
#define COL_SLOT_DEFAULT    IM_COL32( 80,  80, 100, 255)
#define COL_SLOT_ODD        IM_COL32( 58,  58,  58, 255)
#define COL_SLOT_EVEN       IM_COL32( 64,  64,  64, 255)
#define COL_SLOT_SELECTED   IM_COL32(255,  64,  64, 255)
#define COL_SLOT_V_LINE     IM_COL32( 32,  32,  32,  96)
#define COL_SLIDER_BG       IM_COL32( 32,  32,  48, 255)
#define COL_SLIDER_IN       IM_COL32(192, 192, 192, 255)
#define COL_SLIDER_MOVING   IM_COL32(144, 144, 144, 255)
#define COL_SLIDER_HANDLE   IM_COL32(112, 112, 112, 255)
#define COL_SLIDER_SIZING   IM_COL32(170, 170, 170, 255)
#define COL_CURSOR_ARROW    IM_COL32(  0, 255,   0, 255)
#define COL_CURSOR_TEXT_BG  IM_COL32(  0, 128,   0, 144)
#define COL_CURSOR_TEXT     IM_COL32(  0, 255,   0, 255)
#define COL_DARK_ONE        IM_COL32( 33,  33,  38, 255)
#define COL_DARK_TWO        IM_COL32( 40,  40,  46, 255)
#define COL_DARK_PANEL      IM_COL32( 48,  48,  54, 255)
#define COL_DEEP_DARK       IM_COL32( 23,  24,  26, 255)

#define HALF_COLOR(c)       (c & 0xFFFFFF) | 0x40000000;
#define TIMELINE_OVER_LENGTH    5000        // add 5 seconds end of timeline

namespace MediaTimeline
{
#define DEFAULT_TRACK_HEIGHT        0
#define DEFAULT_VIDEO_TRACK_HEIGHT  60
#define DEFAULT_AUDIO_TRACK_HEIGHT  30
#define DEFAULT_IMAGE_TRACK_HEIGHT  40
#define DEFAULT_TEXT_TRACK_HEIGHT   20

enum MEDIA_TYPE : int
{
    MEDIA_UNKNOWN = -1,
    MEDIA_VIDEO = 0,
    MEDIA_AUDIO = 1,
    MEDIA_PICTURE = 2,
    MEDIA_TEXT = 3,
    // ...
};

struct IDGenerator
{
    int64_t GenerateID();

    void SetState(int64_t state);
    int64_t State() const;

private:
    int64_t m_State = ImGui::get_current_time_usec();
};

struct MediaItem
{
    int64_t mID;                            // media ID
    std::string mName;
    std::string mPath;
    int64_t mStart  {0};                    // whole Media start in ms
    int64_t mEnd    {0};                    // whole Media end in ms
    MediaOverview * mMediaOverview;
    MEDIA_TYPE mMediaType {MEDIA_UNKNOWN};
    std::vector<ImTextureID> mMediaThumbnail;
    MediaItem(const std::string& name, const std::string& path, MEDIA_TYPE type, void* handle);
    ~MediaItem();
    void UpdateThumbnail();
};

struct VideoSnapshotInfo
{
    ImRect rc;
    int64_t time_stamp;
    int64_t duration;
    float frame_width;
};

struct Snapshot
{
    ImTextureID texture {nullptr};
    int64_t     time_stamp {0};
    int64_t     estimate_time {0};
    bool        available{false};
};

struct Overlap
{
    int64_t mID                     {-1};       // overlap ID, project saved
    int64_t mStart                  {0};        // overlap start time at timeline, project saved
    int64_t mEnd                    {0};        // overlap end time at timeline, project saved
    int64_t mCurrent                {0};        // overlap current time, project saved
    bool bPlay                      {false};    // overlap play status
    bool bForward                   {true};     // overlap play direction
    bool bSeeking                   {false};    // overlap is seeking
    bool bEditing                   {false};    // overlap is editing, project saved
    std::pair<int64_t, int64_t>     m_Clip;     // overlaped clip's pair, project saved
    imgui_json::value mFusionBP;                // overlap transion blueprint, project saved
    void * mHandle                  {nullptr};  // overlap belong to timeline 
    Overlap(int64_t start, int64_t end, int64_t clip_first, int64_t clip_second, void* handle);
    ~Overlap();

    bool IsOverlapValid();
    void Update(int64_t start, int64_t start_clip_id, int64_t end, int64_t end_clip_id);
    void Seek();
    static Overlap * Load(const imgui_json::value& value, void * handle);
    void Save(imgui_json::value& value);
};

struct Clip
{
    int64_t mID                 {-1};               // clip ID, project saved
    int64_t mMediaID            {-1};               // clip media ID in media bank, project saved
    int64_t mGroupID            {-1};               // Group ID clip belong, project saved
    MEDIA_TYPE mType            {MEDIA_UNKNOWN};    // clip type, project saved
    std::string mName;                              // clip name, project saved
    std::string mPath;                              // clip media path, project saved
    int64_t mStart              {0};                // clip start time in timeline, project saved
    int64_t mEnd                {0};                // clip end time in timeline, project saved
    int64_t mStartOffset        {0};                // clip start time in media, project saved
    int64_t mEndOffset          {0};                // clip end time in media, project saved
    int64_t mLength             {0};                // clip length, = mEnd - mStart
    bool bSelected              {false};            // clip is selected, project saved
    bool bEditing               {false};            // clip is Editing by double click selected, project saved
    std::mutex mLock;                               // clip mutex, not using yet
    void * mHandle              {nullptr};          // clip belong to timeline 
    MediaParserHolder mMediaParser;
    int64_t mViewWndDur         {0};
    float mPixPerMs             {0};
    int mTrackHeight            {0};

    imgui_json::value mFilterBP;                    // clip filter blue print, project saved

    Clip(int64_t start, int64_t end, int64_t id, MediaParserHolder mediaParser, void * handle);
    virtual ~Clip();

    int64_t Moving(int64_t diff, int mouse_track);
    int64_t Cropping(int64_t diff, int type);
    void Cutting(int64_t pos);
    bool isLinkedWith(Clip * clip);
    
    virtual void ConfigViewWindow(int64_t wndDur, float pixPerMs) { mViewWndDur = wndDur; mPixPerMs = pixPerMs; }
    virtual void SetTrackHeight(int trackHeight) { mTrackHeight = trackHeight; }
    virtual void SetViewWindowStart(int64_t millisec) {}
    virtual void DrawContent(ImDrawList* drawList, const ImVec2& leftTop, const ImVec2& rightBottom, const ImRect& clipRect) { drawList->AddRect(leftTop, rightBottom, IM_COL32_BLACK); }
    static void Load(Clip * clip, const imgui_json::value& value);
    virtual void Save(imgui_json::value& value) = 0;
};

struct VideoClip : Clip
{
    SnapshotGenerator::ViewerHolder mSsViewer;
    std::vector<VideoSnapshotInfo> mVideoSnapshotInfos; // clip snapshots info, with all croped range
    std::list<Snapshot> mVideoSnapshots;                // clip snapshots, including texture and timestamp info
    MediaInfo::Ratio mClipFrameRate {25, 1};            // clip Frame rate, project saved

    VideoClip(int64_t start, int64_t end, int64_t id, std::string name, MediaParserHolder hParser, SnapshotGenerator::ViewerHolder viewer, void* handle);
    ~VideoClip();

    void ConfigViewWindow(int64_t wndDur, float pixPerMs) override;
    void SetTrackHeight(int trackHeight) override;
    void SetViewWindowStart(int64_t millisec) override;
    void DrawContent(ImDrawList* drawList, const ImVec2& leftTop, const ImVec2& rightBottom, const ImRect& clipRect) override;

    static Clip * Load(const imgui_json::value& value, void * handle);
    void Save(imgui_json::value& value) override;

private:
    void CalcDisplayParams();

private:
    float mSnapWidth                {0};
    float mSnapHeight               {0};
    int64_t mClipViewStartPos;
    std::vector<SnapshotGenerator::ImageHolder> mSnapImages;
};

struct AudioClip : Clip
{
    int mAudioChannels  {2};                // clip audio channels, project saved
    int mAudioSampleRate {44100};           // clip audio sample rate, project saved
    AudioRender::PcmFormat mAudioFormat {AudioRender::PcmFormat::FLOAT32}; // clip audio type, project saved
    MediaOverview::WaveformHolder mWaveform {nullptr};  // clip audio snapshot
    MediaOverview * mOverview {nullptr};

    AudioClip(int64_t start, int64_t end, int64_t id, std::string name, MediaOverview * overview, void* handle);
    ~AudioClip();

    void DrawContent(ImDrawList* drawList, const ImVec2& leftTop, const ImVec2& rightBottom, const ImRect& clipRect) override;
    static Clip * Load(const imgui_json::value& value, void * handle);
    void Save(imgui_json::value& value) override;
};

struct ImageClip : Clip
{
    int mWidth          {0};        // image width, project saved
    int mHeight         {0};        // image height, project saved
    int mColorFormat    {0};        // image color format, project saved
    MediaOverview * mOverview   {nullptr};

    ImageClip(int64_t start, int64_t end, int64_t id, std::string name, MediaOverview * overview, void* handle);
    ~ImageClip();

    void SetTrackHeight(int trackHeight) override;
    void SetViewWindowStart(int64_t millisec) override;
    void DrawContent(ImDrawList* drawList, const ImVec2& leftTop, const ImVec2& rightBottom, const ImRect& clipRect) override;

    static Clip * Load(const imgui_json::value& value, void * handle);
    void Save(imgui_json::value& value) override;

private:
    void PrepareSnapImage();

private:
    float mSnapWidth            {0};
    float mSnapHeight           {0};
    std::vector<ImGui::ImMat> mSnapImages;
    ImTextureID mImgTexture     {0};
    int64_t mClipViewStartPos;
};

struct TextClip : Clip
{
    TextClip(int64_t start, int64_t end, int64_t id, std::string name, MediaParserHolder hParser, void* handle);
    ~TextClip();

    static Clip * Load(const imgui_json::value& value, void * handle);
    void Save(imgui_json::value& value);
};

class BluePrintVideoFilter : public DataLayer::VideoFilter
{
public:
    virtual ~BluePrintVideoFilter();

    void ApplyTo(DataLayer::VideoClip* clip) override {}
    ImGui::ImMat FilterImage(const ImGui::ImMat& vmat, int64_t pos) override;

    void SetBluePrintFromJson(imgui_json::value& bpJson);

private:
    BluePrint::BluePrintUI* mBp{nullptr};
    std::mutex mBpLock;
};

class BluePrintVideoTransition : public DataLayer::VideoTransition
{
public:
    virtual ~BluePrintVideoTransition();

    void ApplyTo(DataLayer::VideoOverlap* overlap) override { mOverlap = overlap; }
    ImGui::ImMat MixTwoImages(const ImGui::ImMat& vmat1, const ImGui::ImMat& vmat2, int64_t pos) override;

    void SetBluePrintFromJson(imgui_json::value& bpJson);

private:
    DataLayer::VideoOverlap* mOverlap;
    BluePrint::BluePrintUI* mBp{nullptr};
    std::mutex mBpLock;
};

struct BaseEditingClip
{
    int64_t mID                 {-1};                   // editing clip ID
    MEDIA_TYPE mType            {MEDIA_UNKNOWN};
    int64_t mStart              {0};
    int64_t mEnd                {0};
    int64_t mStartOffset        {0};                    // editing clip start time in media
    int64_t mEndOffset          {0};                    // editing clip end time in media
    int64_t mDuration           {0};
    int64_t mCurrPos            {0};
    bool bPlay                  {false};                // editing clip play status
    bool bForward               {true};                 // editing clip play direction
    bool bSeeking               {false};
    int64_t mLastTime           {-1};
    ImVec2 mViewWndSize         {0, 0};

    void* mHandle               {nullptr};              // main timeline handle
    MediaReader* mMediaReader   {nullptr};              // editing clip media reader

    BaseEditingClip(int64_t id, MEDIA_TYPE type, int64_t start, int64_t end, int64_t startOffset, int64_t endOffset, void* handle)
        : mID(id), mType(type), mStart(start), mEnd(end), mStartOffset(startOffset), mEndOffset(endOffset), mHandle(handle)
    {}

    virtual void UpdateClipRange(Clip* clip) = 0;
    virtual void Seek(int64_t pos) = 0;
    virtual void Step(bool forward, int64_t step = 0) = 0;
    virtual void Save() = 0;
    virtual bool GetFrame(std::pair<ImGui::ImMat, ImGui::ImMat>& in_out_frame) = 0;
    virtual void DrawContent(ImDrawList* drawList, const ImVec2& leftTop, const ImVec2& rightBottom) = 0;
};

struct EditingVideoClip : BaseEditingClip
{
    MediaSnapshot* mSnapshot    {nullptr};
    ImVec2 mSnapSize            {0, 0};
    MediaInfo::Ratio mClipFrameRate {25, 1};                    // clip Frame rate
    int mMaxCachedVideoFrame    {10};                           // clip Media Video Frame cache size

    std::mutex mFrameLock;                                      // clip frame mutex
    std::list<std::pair<ImGui::ImMat, ImGui::ImMat>> mFrame;    // clip timeline input/output frame pair

    EditingVideoClip(VideoClip* vidclip);
    virtual ~EditingVideoClip();

    void UpdateClipRange(Clip* clip) override;
    void Seek(int64_t pos) override;
    void Step(bool forward, int64_t step = 0) override;
    void Save() override;
    bool GetFrame(std::pair<ImGui::ImMat, ImGui::ImMat>& in_out_frame) override;
    void DrawContent(ImDrawList* drawList, const ImVec2& leftTop, const ImVec2& rightBottom) override;

    void CalcDisplayParams();
};

struct EditingAudioClip : BaseEditingClip
{
    EditingAudioClip(AudioClip* vidclip);
    virtual ~EditingAudioClip();

    void UpdateClipRange(Clip* clip) override;
    void Seek(int64_t pos) override;
    void Step(bool forward, int64_t step = 0) override;
    void Save() override;
    bool GetFrame(std::pair<ImGui::ImMat, ImGui::ImMat>& in_out_frame) override;
    void DrawContent(ImDrawList* drawList, const ImVec2& leftTop, const ImVec2& rightBottom) override;
};

struct MediaTrack
{
    int64_t mID             {-1};               // track ID, project saved
    MEDIA_TYPE mType        {MEDIA_UNKNOWN};    // track type, project saved
    std::string mName;                          // track name, project saved
    std::vector<Clip *> m_Clips;                // track clips, project saved(id only)
    std::vector<Overlap *> m_Overlaps;          // track overlaps, project saved(id only)
    void * m_Handle         {nullptr};          // user handle

    int mTrackHeight {DEFAULT_TRACK_HEIGHT};    // track custom view height, project saved
    int64_t mLinkedTrack    {-1};               // relative track ID, project saved
    bool mExpanded  {false};                    // track is compact view, project saved
    bool mView      {true};                     // track is viewable, project saved
    bool mLocked    {false};                    // track is locked(can't moving or cropping by locked), project saved
    bool mSelected  {false};                    // track is selected, project saved
    int64_t mViewWndDur     {0};
    float mPixPerMs         {0};

    MediaTrack(std::string name, MEDIA_TYPE type, void * handle);
    ~MediaTrack();

    bool DrawTrackControlBar(ImDrawList *draw_list, ImRect rc);
    bool CanInsertClip(Clip * clip, int64_t pos);
    void InsertClip(Clip * clip, int64_t pos = 0);
    void PushBackClip(Clip * clip);
    void SelectClip(Clip * clip, bool appand);
    void SelectEditingClip(Clip * clip);
    void EditingOverlap(Overlap * overlap);
    void DeleteClip(int64_t id);
    Clip * FindPrevClip(int64_t id);                // find prev clip in track, if not found then return null
    Clip * FindNextClip(int64_t id);                // find next clip in track, if not found then return null
    Clip * FindClips(int64_t time, int& count);     // find clips at time, count means clip number at time
    void CreateOverlap(int64_t start, int64_t start_clip_id, int64_t end, int64_t end_clip_id);
    Overlap * FindExistOverlap(int64_t start_clip_id, int64_t end_clip_id);
    void Update();                                  // update track clip include clip order and overlap area
    static MediaTrack* Load(const imgui_json::value& value, void * handle);
    void Save(imgui_json::value& value);

    void ConfigViewWindow(int64_t wndDur, float pixPerMs)
    {
        if (mViewWndDur == wndDur && mPixPerMs == pixPerMs)
            return;
        mViewWndDur = wndDur;
        mPixPerMs = pixPerMs;
        for (auto& clip : m_Clips)
            clip->ConfigViewWindow(wndDur, pixPerMs);
    }
};

struct TimelineCustomDraw
{
    int index;
    ImRect customRect;
    ImRect titleRect;
    ImRect clippingTitleRect;
    ImRect legendRect;
    ImRect clippingRect;
    ImRect legendClippingRect;
};

struct ClipGroup
{
    int64_t mID;
    ImU32 mColor;
    std::vector<int64_t> m_Grouped_Clips;
    ClipGroup(void * handle);
    void Load(const imgui_json::value& value);
    void Save(imgui_json::value& value);
};

typedef int (*TimeLineCallback)(int type, void* handle);
typedef struct TimeLineCallbackFunctions
{
    TimeLineCallback  EditingClip       {nullptr};
    TimeLineCallback  EditingOverlap    {nullptr};
} TimeLineCallbackFunctions;

struct TimeLine
{
    TimeLine();
    ~TimeLine();
    IDGenerator m_IDGenerator;              // Timeline ID generator
    std::vector<MediaItem *> media_items;   // Media Bank, project saved
    std::vector<MediaTrack *> m_Tracks;     // timeline tracks, project saved
    std::vector<Clip *> m_Clips;            // timeline clips, project saved
    std::vector<ClipGroup> m_Groups;        // timeline clip groups, project saved
    std::vector<Overlap *> m_Overlaps;      // timeline clip overlap, project saved
    std::unordered_map<int64_t, SnapshotGeneratorHolder> m_VidSsGenTable;  // Snapshot generator for video media item, provide snapshots for VideoClip
    int64_t mStart   {0};                   // whole timeline start in ms, project saved
    int64_t mEnd     {0};                   // whole timeline end in ms, project saved

    bool mShowHelpTooltips      {true};     // timeline show help tooltips, project saved, configured
    int mWidth  {1920};                     // timeline Media Width, project saved, configured
    int mHeight {1080};                     // timeline Media Height, project saved, configured
    MediaInfo::Ratio mFrameRate {25, 1};    // timeline Media Frame rate, project saved, configured
    int mMaxCachedVideoFrame    {10};       // timeline Media Video Frame cache size, project saved, configured

    int mAudioChannels {2};                 // timeline audio channels, project saved, configured
    int mAudioSampleRate {44100};           // timeline audio sample rate, project saved, configured
    AudioRender::PcmFormat mAudioFormat {AudioRender::PcmFormat::FLOAT32}; // timeline audio format, project saved, configured
    
    std::vector<int> mAudioLevel;           // timeline audio levels

    int64_t attract_docking_pixels {10};    // clip attract docking sucking in pixels range, pulling range is 1/5
    int64_t mConnectedPoints = -1;

    int64_t currentTime = 0;
    int64_t firstTime = 0;
    int64_t lastTime = 0;
    int64_t visibleTime = 0;
    float msPixelWidthTarget = 0.1f;

    bool bSeeking = false;
    bool bLoop = false;                     // project saved
    bool bSelectLinked = true;              // project saved

    std::mutex mVidFilterClipLock;          // timeline clip mutex
    EditingVideoClip* mVidFilterClip    {nullptr};
    std::mutex mAudFilterClipLock;          // timeline clip mutex
    EditingAudioClip* mAudFilterClip    {nullptr};

    MultiTrackVideoReader* mMtvReader   {nullptr};
    double mPreviewPos                      {0};
    double mPreviewResumePos                {0};
    bool mIsPreviewPlaying                  {false};
    bool mIsPreviewForward                  {true};
    using PlayerClock = std::chrono::steady_clock;
    PlayerClock::time_point mPlayTriggerTp;

    imgui_json::value mOngoingAction;
    std::list<imgui_json::value> mUiActions;
    void PerformUiActions();

    std::mutex mTrackLock;                  // timeline track mutex
    
    // BP CallBacks
    static int OnBluePrintChange(int type, std::string name, void* handle);

    BluePrint::BluePrintUI * mVideoFilterBluePrint {nullptr};
    std::mutex mVideoFilterBluePrintLock;   // Video Filter BluePrint mutex
    bool mVideoFilterNeedUpdate {false};

    ImTextureID mVideoFilterInputTexture {nullptr};  // clip video filter input texture
    ImTextureID mVideoFilterOutputTexture {nullptr};  // clip video filter output texture

    BluePrint::BluePrintUI * mAudioFilterBluePrint {nullptr};
    std::mutex mAudioFilterBluePrintLock;   // Audio Filter BluePrint mutex
    bool mAudioFilterNeedUpdate {false};

    BluePrint::BluePrintUI * mVideoFusionBluePrint {nullptr};
    std::mutex mVideoFusionBluePrintLock;   // Video Fusion BluePrint mutex
    bool mVideoFusionNeedUpdate {false};

    BluePrint::BluePrintUI * mAudioFusionBluePrint {nullptr};
    std::mutex mAudioFusionBluePrintLock;   // Video Fusion BluePrint mutex
    bool mAudioFusionNeedUpdate {false};

    std::mutex mFrameLock;                      // timeline frame mutex
    std::list<ImGui::ImMat> mFrame;             // timeline output frame
    ImTextureID mMainPreviewTexture {nullptr};  // main preview texture

    std::thread * mVideoFilterThread {nullptr}; // Video Filter Thread, which is only one item/clip read from media
    bool mVideoFilterDone {false};              // Video Filter Thread should finished
    bool mVideoFilterRunning {false};           // Video Filter Thread is running

    TimeLineCallbackFunctions  m_CallBacks;

    int64_t GetStart() const { return mStart; }
    int64_t GetEnd() const { return mEnd; }
    void SetStart(int64_t pos) { mStart = pos; }
    void SetEnd(int64_t pos) { mEnd = pos; }
    size_t GetCustomHeight(int index) { return (index < m_Tracks.size() && m_Tracks[index]->mExpanded) ? m_Tracks[index]->mTrackHeight : 0; }
    void Updata();
    void AlignTime(int64_t& time);

    int GetTrackCount() const { return (int)m_Tracks.size(); }
    int GetTrackCount(MEDIA_TYPE type);
    int NewTrack(const std::string& name, MEDIA_TYPE type, bool expand);
    int64_t DeleteTrack(int index);
    void SelectTrack(int index);
    void MovingTrack(int& index, int& dst_index);

    void MovingClip(int64_t id, int from_track_index, int to_track_index);
    void DeleteClip(int64_t id);

    void DeleteOverlap(int64_t id);

    void DoubleClick(int index, int64_t time);
    void Click(int index, int64_t time);

    void CustomDraw(int index, ImDrawList *draw_list, const ImRect &view_rc, const ImRect &rc, const ImRect &titleRect, const ImRect &clippingTitleRect, const ImRect &legendRect, const ImRect &clippingRect, const ImRect &legendClippingRect, bool is_moving, bool enable_select);
    
    ImGui::ImMat GetPreviewFrame();
    int GetAudioLevel(int channel);

    void Play(bool play, bool forward = true);
    void Seek(int64_t msPos);
    void Step(bool forward = true);
    void Loop(bool loop);
    void ToStart();
    void ToEnd();
    void UpdateCurrent();

    AudioRender* mAudioRender {nullptr};                // audio render(SDL)

    MediaItem* FindMediaItemByName(std::string name);   // Find media from bank by name
    MediaItem* FindMediaItemByID(int64_t id);           // Find media from bank by ID
    MediaTrack * FindTrackByID(int64_t id);             // Find track by ID
    MediaTrack * FindTrackByClipID(int64_t id);         // Find track by clip ID
    int FindTrackIndexByClipID(int64_t id);             // Find track by clip ID
    Clip * FindClipByID(int64_t id);                    // Find clip with clip ID
    Clip * FindEditingClip();                           // Find clip which is editing
    Overlap * FindOverlapByID(int64_t id);              // Find overlap with overlap ID
    Overlap * FindEditingOverlap();                     // Find overlap which is editing
    int GetSelectedClipCount();                         // Get current selected clip count
    int64_t NextClipStart(Clip * clip);                 // Get next clip start pos by clip, if don't have next clip, then return -1
    int64_t NextClipStart(int64_t pos);                 // Get next clip start pos by time, if don't have next clip, then return -1
    int64_t NewGroup(Clip * clip);                      // Create a new group with clip ID
    void AddClipIntoGroup(Clip * clip, int64_t group_id); // Insert clip into group
    void DeleteClipFromGroup(Clip *clip, int64_t group_id); // Delete clip from group
    ImU32 GetGroupColor(int64_t group_id);              // Get Group color by id
    int Load(const imgui_json::value& value);
    void Save(imgui_json::value& value);

    void ConfigureDataLayer();
    void SyncDataLayer();
    SnapshotGeneratorHolder GetSnapshotGenerator(int64_t mediaItemId);
    void ConfigSnapshotWindow(int64_t viewWndDur);
};

bool DrawTimeLine(TimeLine *timeline, bool *expanded);
bool DrawClipTimeLine(BaseEditingClip * editingClip);
bool DrawOverlapTimeLine(Overlap * overlap);
} // namespace MediaTimeline
