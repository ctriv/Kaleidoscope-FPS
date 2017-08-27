# Kaleidoscope-FPS

This is a plugin for [Kaleidoscope][fw], that adds a First-Person_shooter-specific
LED effect, along with a way to toggle to a fps layer, and apply the effect.
This plugin is a modified copy of the Kaleidoscope-Numlock plugin.

## Using This plugin

### Installations

You'll need to add this plugin to your arduino libraries directory with the rest
of your Kaleidoscope plugins and `&FPS` to the use statement in your `Model01-Firmware.ino`.
Then setup a keymap for FPS:

```
#define FPS_MAP KEYMAP_STACKED ( \
    ___,    Key_5,           Key_6,          Key_7,          Key_8,          Key_9,          Key_0, \
    ___,    Key_3,           Key_4,          Key_FPS_fwd,    Key_FPS_use1,   Key_FPS_reload, Key_FPS_board, \
    Key_2,  Key_FPS_last_wp, Key_FPS_left,   Key_FPS_bkwds,  Key_FPS_right,  Key_FPS_use2,      \
    Key_1,  Key_FPS_zoom,      ___,            ___,          ___,            Key_FPS_use3,   Key_FPS_console, \
    Key_FPS_crouch, Key_FPS_jump, Key_FPS_walk, Key_FPS_run,         \
                          Key_FPS_run,     \
\
    ___,       ___, ___, ___,     ___,      ___,         ___, \
    ___,     ___, ___, ___,     ___,      ___,         ___,       \
                   ___, ___, ___,     ___,      ___, ___,       \
    Key_ToggleFPS,  ___, ___, ___, ___, ___,     ___,       \
    ___, ___, ___, ___,                   \
    ___ \
)
```

There's a few more things you need add to your firmware such as setting up the
toggle macro and adding the map to memory.  See `Model01-Firmware.ino.example`
for more.  I also set the butterfly key to `Key_ToggleFPS` in the main keymap.

### Game Controls

I'm not a serious gamer, I just enjoy playing a few FPS games casually.  I've
come up with a set of controls that works well enough for the games that I like
to play.  More work is probably needed to make this work with a wide range of games.

That being said, I set my games to something like this:

| Action                   | Key      |
|--------------------------|----------|
| forward                  | w        |
| backwards                | s        |
| left                     | a        |
| right                    | d        |
| jump                     | space    |
| crouch                   | control  |
| run                      | shift    |
| walk                     | alt      |
| use1 (general use)       | e        |
| use2 (flashlight, etc..) | f        |
| use3 (game specific)     | g        |
| zoom                     | z        |
| reload                   | r        |
| goto last weapon         | q        |
| weapons                  | 0 thru 9 |
| console                  | `        |
| inventory/board          | tab      |
