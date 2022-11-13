#ifndef _MAIN_H_
#define _MAIN_H_

#include <windows.h>
#include <memory>
#include "memwrapper/memwrapper.h"


using CRadar__DrawSprite = void(__cdecl*)(unsigned short spriteId, float x, float y, int8_t alpha);
std::unique_ptr<memwrapper::memhook<CRadar__DrawSprite>> hookRadar;

using CRadar__ShowRadarTrace = void(__cdecl*)(float x, float y, unsigned int size, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha, unsigned char type);
std::unique_ptr<memwrapper::memhook<CRadar__ShowRadarTrace>> radarTraceHook;

class AsiPlugin {

public:
    explicit AsiPlugin();
    virtual ~AsiPlugin();
} AsiPlugin;

#endif