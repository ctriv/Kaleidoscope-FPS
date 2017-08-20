#pragma once

#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-Macros.h"
#include "LEDUtils.h"

#define TOGGLEFPS 3
#define Key_ToggleFPS M(TOGGLEFPS)

#define Key_FPS_fwd   Key_W
#define Key_FPS_left  Key_A
#define Key_FPS_right Key_D
#define Key_FPS_bkwds Key_S

#define Key_FPS_jump   Key_Spacebar
#define Key_FPS_crouch Key_LeftControl
#define Key_FPS_run    Key_LeftShift
#define Key_FPS_walk   Key_LeftAlt

#define Key_FPS_use1   Key_E
#define Key_FPS_use2   Key_F
#define Key_FPS_use3   Key_G
#define Key_FPS_reload Key_R
#define Key_FPS_zoom   Key_Z

#define Key_FPS_console Key_Backtick
#define Key_FPS_board   Key_Tab


class FPS_ : public KaleidoscopePlugin {
 public:
  FPS_(void);

  void begin(void) final;

  static const macro_t *toggle();
  static void loopHook(const bool postClear);

  static uint8_t FPSLayer;

 private:
  static byte row, col;
};

extern FPS_ FPS;
