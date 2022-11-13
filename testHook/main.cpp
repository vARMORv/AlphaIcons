#include "main.h"
#include <memory>

void __cdecl DrawSpriteHook(unsigned short spriteId, float x, float y, int8_t alpha) {
    if (x > 155 && x < 195 && y > 885 && y < 925)
        alpha = 100;
    return hookRadar->call(spriteId, x, y, alpha);
}

void __cdecl RadarTraceHook(float x, float y, unsigned int size, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha, unsigned char type) {
    if (x > 155 && x < 195 && y > 885 && y < 925)
        alpha = 5;
    return radarTraceHook->call(x, y, size, red, green, blue, alpha, type);
}

AsiPlugin::AsiPlugin() {
    hookRadar = std::make_unique<memwrapper::memhook<CRadar__DrawSprite>>(0x585FF0, &DrawSpriteHook);
    hookRadar->install();

    radarTraceHook = std::make_unique<memwrapper::memhook<CRadar__ShowRadarTrace>>(0x584070, &RadarTraceHook);
    radarTraceHook->install();
}

AsiPlugin::~AsiPlugin() {
    hookRadar->remove();
    radarTraceHook->remove();
}

