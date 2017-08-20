#include "Kaleidoscope-FPS.h"
#include "LEDUtils.h"
#include "Kaleidoscope.h"
#include "layers.h"

byte FPS_::row = 255, FPS_::col = 255;
uint8_t FPS_::FPSLayer;
cRGB FPS_color = CRGB(0, 160, 0);
cRGB off_color = CRGB(0, 0, 0);

FPS_::FPS_(void) {
}

void FPS_::begin(void) {
  Kaleidoscope.useLoopHook(loopHook);
}

void FPS_::loopHook(bool postClear) {
  if (!postClear || !Layer.isOn(FPSLayer))
    return;

  for (uint8_t r = 0; r < ROWS; r++) {
    for (uint8_t c = 0; c < COLS; c++) {
      Key k = Layer.lookupOnActiveLayer(r, c);
      Key layer_key = Layer.getKey(FPSLayer, r, c);

      if ((k != layer_key) || (k.flags != KEY_FLAGS)) {
        LEDControl.setCrgbAt(r, c, off_color);
      } else {
        LEDControl.setCrgbAt(r, c, FPS_color);
      }
    }
  }
}

const macro_t *FPS_::toggle() {
  row = Macros.row;
  col = Macros.col;

  if (Layer.isOn(FPSLayer)) {
    Layer.off(FPSLayer);
    LEDControl.set_mode(LEDControl.get_mode_index());
  } else {
    Layer.on(FPSLayer);
  }

  return MACRO_NONE;
}

FPS_ FPS;
