#include "Kaleidoscope-FPS.h"
#include "LEDUtils.h"
#include "Kaleidoscope.h"
#include "layers.h"

byte FPS_::row = 255, FPS_::col = 255;
uint8_t FPS_::FPSLayer;

cRGB basic_movement_color = CRGB(200, 0, 0);
cRGB movement_modifier_color = CRGB(0, 150, 0);
cRGB actions_color = CRGB(0, 0, 200);
cRGB meta_color = CRGB(100, 0, 100);
cRGB toggle_color = CRGB(140, 70, 0);
cRGB weapon_color = CRGB(100, 100, 100);
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
      //Key k = Layer.lookupOnActiveLayer(r, c);
      //Key layer_key = Layer.getKey(FPSLayer, r, c);
      Key k = Layer.getKey(FPSLayer, r, c);

      if ((k == Key_FPS_fwd) || (k == Key_FPS_bkwds) || (k == Key_FPS_left) || (k == Key_FPS_right)) {
          LEDControl.setCrgbAt(r, c, basic_movement_color);
      }
      else if ((k == Key_FPS_crouch) || (k == Key_FPS_run) || (k == Key_FPS_jump)|| (k == Key_FPS_walk)) {
          LEDControl.setCrgbAt(r, c, movement_modifier_color);
      }
      else if ((k == Key_FPS_use1) || (k == Key_FPS_use2) || (k == Key_FPS_use3) || (k == Key_FPS_reload) || (k == Key_FPS_zoom)) {
          LEDControl.setCrgbAt(r, c, actions_color);
      }
      else if ((k == Key_FPS_console) || (k == Key_FPS_board)) {
          LEDControl.setCrgbAt(r, c, meta_color);
      }
      else if ((k == Key_ToggleFPS)) {
          LEDControl.setCrgbAt(r, c, toggle_color);
      }
      else if ((Key_1 <= k) && (k <= Key_0)) {
          LEDControl.setCrgbAt(r, c, weapon_color);
      }
      else {
          LEDControl.setCrgbAt(r, c, off_color);
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
