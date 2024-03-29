#ifndef CONTROLMSG_H
#define CONTROLMSG_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

//#include "config.h"
#include "android/input.h"
#include "android/keycodes.h"
#include "common.h"

#define CONTROL_MSG_TEXT_MAX_LENGTH 300
#define CONTROL_MSG_CLIPBOARD_TEXT_MAX_LENGTH 4093
#define CONTROL_MSG_SERIALIZED_MAX_SIZE \
    (3 + CONTROL_MSG_CLIPBOARD_TEXT_MAX_LENGTH)

enum control_msg_type {
    CONTROL_MSG_TYPE_INJECT_KEYCODE,
    CONTROL_MSG_TYPE_INJECT_TEXT,
    CONTROL_MSG_TYPE_INJECT_MOUSE_EVENT,
    CONTROL_MSG_TYPE_INJECT_SCROLL_EVENT,
    CONTROL_MSG_TYPE_BACK_OR_SCREEN_ON,
    CONTROL_MSG_TYPE_EXPAND_NOTIFICATION_PANEL,
    CONTROL_MSG_TYPE_COLLAPSE_NOTIFICATION_PANEL,
    CONTROL_MSG_TYPE_GET_CLIPBOARD,
    CONTROL_MSG_TYPE_SET_CLIPBOARD,
    CONTROL_MSG_TYPE_SET_SCREEN_POWER_MODE,
};

enum screen_power_mode {
    // see <https://android.googlesource.com/platform/frameworks/base.git/+/pie-release-2/core/java/android/view/SurfaceControl.java#305>
    SCREEN_POWER_MODE_OFF = 0,
    SCREEN_POWER_MODE_NORMAL = 2,
};

struct control_msg {
    enum control_msg_type type;
    union {
        struct {
            enum android_keyevent_action action;
            enum android_keycode keycode;
            enum android_metastate metastate;
        } inject_keycode;
        struct {
            char *text; // owned, to be freed by SDL_free()
        } inject_text;
        struct {
            enum android_motionevent_action action;
            enum android_motionevent_buttons buttons;
            struct position position;
        } inject_mouse_event;
        struct {
            struct position position;
            int32_t hscroll;
            int32_t vscroll;
        } inject_scroll_event;
        struct {
            char *text; // owned, to be freed by SDL_free()
        } set_clipboard;
        struct {
            enum screen_power_mode mode;
        } set_screen_power_mode;
    };
};

// buf size must be at least CONTROL_MSG_SERIALIZED_MAX_SIZE
// return the number of bytes written
size_t
control_msg_serialize(const struct control_msg *msg, unsigned char *buf);

void
control_msg_destroy(struct control_msg *msg);

#endif
