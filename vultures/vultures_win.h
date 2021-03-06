/* Copyright (c) Daniel Thaler, 2006				  */
/* NetHack may be freely redistributed.  See license for details. */

#ifndef _vultures_win_h_
#define _vultures_win_h_

#include "vultures_types.h"


/* 
 * External files used by the GUI.
 * Note: The intro sequence may use other
 * external images, listed in the script file.
 */
#define V_MAX_FILENAME_LENGTH 1024

#define V_FILENAME_INTRO_SCRIPT  "vultures_intro.txt"
#define V_FILENAME_OPTIONS       "vultures.conf"
#define V_FILENAME_SOUNDS_CONFIG "vultures_sounds.conf"

/*
 * graphics files, without ".png" extension
 */
#ifdef VULTURESEYE
#define V_FILENAME_NETHACK_LOGO         "nh_ve_1"
#define V_FILENAME_MAP_SYMBOLS          "nh_tiles"
#endif
#ifdef VULTURESCLAW
#define V_FILENAME_NETHACK_LOGO         "se_vc_1"
#define V_FILENAME_MAP_SYMBOLS          "se_tiles"
#endif
#define V_FILENAME_CHARACTER_GENERATION "chargen2"
#define V_FILENAME_FONT                 "VeraSe.ttf"
#define V_FILENAME_WINDOW_STYLE         "winelem"
#define V_FILENAME_MAP_PARCHMENT        "parchment"

/*
 * Ending scenes. Eventually these could
 * be made configurable.
 */
#define V_FILENAME_ENDING_DIED          "cairn"
#define V_FILENAME_ENDING_ASCENDED      "night"
#define V_FILENAME_ENDING_QUIT          "quitgame"
#define V_FILENAME_ENDING_ESCAPED       "quitgame"

/*
 * Subdirectories used by Vulture's. 
 * These should be under the main directory.
 */
#define V_CONFIG_DIRECTORY   "config"
#define V_GRAPHICS_DIRECTORY "graphics"
#define V_SOUND_DIRECTORY    "sound"
#define V_MUSIC_DIRECTORY    "music"
#define V_MANUAL_DIRECTORY   "manual"
#define V_FONTS_DIRECTORY    "fonts"


#define V_FILENAME_STATUS_BAR           "statusbar"
#define V_FILENAME_TOOLBAR1             "tb1"
#define V_FILENAME_TOOLBAR2             "tb2"
#define V_FILENAME_ENHANCE              "enhance"
#define V_FILENAME_MINIMAPBG            "minimapbg"


#define V_MENU_MAXHEIGHT  450


/* Font indices. Currently, there're only 2 fonts (large & small). */
#define V_FONT_SMALL 0
#define V_FONT_LARGE 1
#define V_FONT_INTRO     V_FONT_LARGE
#define V_FONT_MENU      V_FONT_SMALL
#define V_FONT_HEADLINE  V_FONT_LARGE
#define V_FONT_BUTTON    V_FONT_LARGE
#define V_FONT_TOOLTIP   V_FONT_SMALL
#define V_FONT_STATUS    V_FONT_SMALL
#define V_FONT_MESSAGE   V_FONT_SMALL
#define V_FONT_INPUT     V_FONT_SMALL

/* Message shading: old messages grow darker */
#define V_MAX_MESSAGE_COLORS 16

/* how many ms must the mouse remain stationary until a tooltip is displayed */
#define HOVERTIMEOUT 400

/*
 * colors used to draw text
 */
#define V_COLOR_TEXT       0xffffffff
#define V_COLOR_INTRO_TEXT 0xffffffff

#define V_COLOR_BACKGROUND CLR32_BLACK


/* Indices into warning colors */
enum vultures_warn_type {
    V_WARN_NONE = 0,
    V_WARN_NORMAL,
    V_WARN_MORE,
    V_WARN_ALERT,
    V_WARN_CRITICAL,
    V_MAX_WARN
};



enum eventresult {
    V_EVENT_UNHANDLED,
    V_EVENT_UNHANDLED_REDRAW, /* pass the event on to a parent win and redraw */
    V_EVENT_HANDLED_NOREDRAW, /* don't pass it on and don't redraw */
    V_EVENT_HANDLED_REDRAW,   /* don't pass it on and redraw */
    V_EVENT_HANDLED_FINAL     /* redraw and leave the event dispatcher */
};

enum responses {
    V_RESPOND_ANY,
    V_RESPOND_CHARACTER,
    V_RESPOND_INT,
    V_RESPOND_POSKEY
};


typedef struct {
    SDL_Surface * border_top;
    SDL_Surface * border_bottom;
    SDL_Surface * border_left;
    SDL_Surface * border_right;
    SDL_Surface * corner_tl;
    SDL_Surface * corner_tr;
    SDL_Surface * corner_bl;
    SDL_Surface * corner_br;
    SDL_Surface * center;
    SDL_Surface * radiobutton_on;
    SDL_Surface * radiobutton_off;
    SDL_Surface * checkbox_on;
    SDL_Surface * checkbox_count;
    SDL_Surface * checkbox_off;
    SDL_Surface * scrollbar;
    SDL_Surface * scrollbutton_up;
    SDL_Surface * scrollbutton_down;
    SDL_Surface * scroll_indicator;
    SDL_Surface * direction_arrows;
    SDL_Surface * invarrow_left;
    SDL_Surface * invarrow_right;
    SDL_Surface * closebutton;
} vultures_window_graphics;



typedef struct event {
    int x, y;
    int num;
    int rtype;
} vultures_event;



/* exported functions */

/* window management */
extern void vultures_create_root_window(void);
extern void vultures_cleanup_windows(void);
extern struct window * vultures_create_window_internal(int nh_type, struct window * parent, enum wintypes wintype);
extern void vultures_destroy_window_internal(struct window * win);
extern void vultures_hide_window(struct window * win);
extern int vultures_create_hotspot(int x, int y, int w, int h, int menu_id, struct window * parent, const char * name);
extern struct window * vultures_create_button(struct window * parent, const char * caption, int menu_id);
extern struct window * vultures_get_window(int winid);
extern void vultures_init_wintype(struct window * win, enum wintypes wintype);

/* high-level window functions */
extern void vultures_messagebox(const char * message);
extern int vultures_get_input(int x, int y, const char *ques, char *input);

/* message window buffer */
extern void vultures_messages_add(const char * str);
extern char * vultures_messages_get(int offset, int * age);
extern void vultures_messages_setshown(int first);
extern int vultures_messages_getshown(void);
extern void vultures_messages_destroy(void);
extern void vultures_messages_view(void);

/* window "builders" */
extern struct window * vultures_query_choices(const char * ques, const char *choices, char defchoice);
extern struct window * vultures_query_direction(const char * ques);
extern struct window * vultures_query_anykey(const char * ques);


/* drawing functions */
extern void vultures_draw_windows(struct window * topwin);
extern void vultures_refresh_window_region(void);

extern int vultures_draw_img(struct window * win);
extern int vultures_draw_messages(struct window * win);
extern int vultures_draw_dirarrows(struct window * win);
extern int vultures_draw_menu(struct window * win);

extern void vultures_layout_itemwin(struct window * win);
extern void vultures_layout_menu(struct window * win);
extern void vultures_layout_dropdown(struct window *win);

extern void vultures_invalidate_region(int, int, int, int);



/* eventstack handling */
extern void vultures_eventstack_add(int, int, int, int);
extern vultures_event * vultures_eventstack_get(void);
extern void vultures_eventstack_destroy(void);


/* event handling */
extern void vultures_event_dispatcher(void * result, int resulttype, struct window * topwin);
extern int vultures_event_dispatcher_nonblocking(void * result, struct window * topwin);

/* misc functions */
extern int vultures_need_recenter(int map_x, int map_y);
extern void vultures_parse_statusline(struct window * statuswin, const char * str);
extern struct window * vultures_get_window_from_point(struct window * topwin, point mouse);
extern struct window * vultures_accel_to_win(struct window * parent, char accel);
extern void vultures_win_resize(int width, int height);
extern void vultures_show_mainmenu(void);


/* exported variables */
extern Uint32 vultures_message_colors[V_MAX_MESSAGE_COLORS];
extern Uint32 vultures_warn_colors[V_MAX_WARN];
extern vultures_window_graphics vultures_winelem;
extern int vultures_suppress_helpmsg;
extern int vultures_winid_map;
extern int vultures_winid_minimap;
extern int vultures_winid_enhance;
extern SDL_Surface * vultures_statusbar;
extern int vultures_whatis_singleshot;
extern int vultures_windows_inited;


#endif
/* End of vultures_win.h */
