#include "UnionAfx.h"
#include "RealTimeModCore.h"

namespace GOTHIC_ENGINE {
    bool RealTimeModCore::clockEnabled = true;

    void RealTimeModCore::Init() {
        ReadOptions();
        SyncGameTimeWithSystem();
    }

    void RealTimeModCore::Update() {
        if (!IsWorldReady()) return;
        
        ScaleGameTimeToRealTime();
        
        static int lastSyncMinute = -1;
        int currentHour, currentMinute;
        ogame->wldTimer->GetTime(currentHour, currentMinute);
        
        if (currentMinute != lastSyncMinute && currentMinute % 5 == 0) {
            SyncGameTimeWithSystem();
            lastSyncMinute = currentMinute;
        }
    }

    void RealTimeModCore::SyncGameTimeWithSystem() {
        SYSTEMTIME sysTime;
        GetLocalTime(&sysTime);
        
        int minute = (sysTime.wMinute + 1) % 60;
        int hour = sysTime.wHour;
        if (minute == 0) {
            hour = (hour + 1) % 24;
        }
        
        ogame->wldTimer->SetTime(hour, minute);
    }

    void RealTimeModCore::ScaleGameTimeToRealTime() {
        if (!ogame || !ogame->wldTimer) return;
        
        float frameTime = ztimer->frameTimeFloat;
        float acceleration = (float)gameScaleToRealScaleApprox / 100000000.0f;
        float worldTime = frameTime * (acceleration - 1.0f);
        ogame->wldTimer->worldTime += worldTime;
        
        if (clockEnabled && !ogame->game_showtime) {
            ogame->game_showtime = TRUE;
        }
    }

    void RealTimeModCore::ReadOptions() {
        if (!zoptions) return;
        clockEnabled = zoptions->ReadBool("RealTimeMod", "showClock", true);
    }

    bool RealTimeModCore::IsWorldReady() {
        return ogame && ogame->GetWorld() && player && !ogame->inScriptStartup && 
               !ogame->inLoadSaveGame && !ogame->inLevelChange;
    }
}