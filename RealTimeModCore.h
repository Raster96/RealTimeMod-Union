#pragma once

namespace GOTHIC_ENGINE {

    class RealTimeModCore {
    public:
        static bool clockEnabled;
        static const int gameScaleToRealScaleApprox = 6616225;
        
        static void Init();
        static void Update();
        static void SyncGameTimeWithSystem();
        static void ScaleGameTimeToRealTime();
        static void ReadOptions();
        static bool IsWorldReady();
    };
}