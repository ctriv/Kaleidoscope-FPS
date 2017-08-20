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
  loop_hook_use(loopHook);
}

void FPS_::loopHook(bool postClear) {
  if (!postClear || !Layer.isOn(FPSLayer))
    return;

  for (uint8_t r = 0; r < ROWS; r++) {
    for (uint8_t c = 0; c < COLS; c++) {
      Key k = Layer.lookup(r, c);
      Key layer_key = Layer.getKey(FPSLayer, r, c);

      if ((k != layer_key) || (k.flags != KEY_FLAGS)) {
        LEDControl.setCrgbAt(r, c, off_color);
      } else {
        LEDControl.setCrgbAt(r, c, FPS_color);
      }
    }
  }

  if (row > ROWS || col > COLS)
    return;

  cRGB color = breath_compute();
  LEDControl.setCrgbAt(row, col, color);
}

const macro_t *FPS_::toggle() {
  row = Macros.row;
  col = Macros.col;

  if (Layer.isOn(FPSLayer)) {
    Layer.off(FPSLayer);
    // Reset all LEDs to off to hopefully give the previous LED effect
    // a better starting state
    LEDControl.set_all_leds_to({0, 0, 0});
    LEDControl.init_mode();
  } else {
    Layer.on(FPSLayer);
  }

  return MACRO_NONE;
}

FPS_ FPS;
