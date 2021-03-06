/* Copyright (c) Daniel Thaler, 2006   */
/* NetHack may be freely redistributed under the Nethack General Public License
 * See nethack/dat/license for details */

#ifndef _vultures_gfl_h_
#define _vultures_gfl_h_


extern SDL_Surface *vultures_load_surface(char *srcbuf, unsigned int buflen);
extern SDL_Surface *vultures_load_graphic(const char *subdir, const char *name);

extern void vultures_save_png(SDL_Surface * surface, char* filename, int with_alpha);

extern void vultures_save_screenshot(void);

#endif
