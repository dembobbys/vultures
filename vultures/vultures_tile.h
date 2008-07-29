/* Copyright (c) Daniel Thaler, 2006, 2008                        */
/* NetHack may be freely redistributed.  See license for details. */

#ifndef _vultures_tile_h_
#define _vultures_tile_h_


#include "hack.h"


extern void vultures_put_tile_shaded(int x, int y, int tile_id, int shadelevel);
extern int vultures_load_gametiles(void);
extern vultures_tile * vultures_load_tile(int tile_id);
extern void vultures_unload_gametiles(void);
extern vultures_tile * vultures_get_tile_shaded(int tile_id, int shadelevel);
extern void vultures_tilecache_discard(void);
extern void vultures_tilecache_age(void);
extern void vultures_put_tilehighlight(int x, int y, int tile_id);

extern int glassgems[CLR_MAX];

#define vultures_put_tile(x, y, tile_id) vultures_put_tile_shaded(x, y, tile_id, 0)
#define vultures_get_tile(tile_id) vultures_get_tile_shaded(tile_id, 0)


enum tiletypes {
    TT_OBJECT,
    TT_OBJICON,
    TT_MONSTER,
    TT_STATUE,
    TT_FIGURINE,
    TT_EXPL,
    TT_CURSOR,
    TT_MISC,
    TT_EDGE,
    TT_FLOOR,
    TT_WALL,

    NUM_TILETYPES
};

extern int vultures_typecount[NUM_TILETYPES];


#define OBJTILEOFFSET  0
#define OBJTILECOUNT  NUM_OBJECTS

#define ICOTILEOFFSET  (OBJTILEOFFSET + OBJTILECOUNT)
#define ICOTILECOUNT  NUM_OBJECTS

#define MONTILEOFFSET  (ICOTILEOFFSET + ICOTILECOUNT)
#define MONTILECOUNT  NUMMONS

#define STATILEOFFSET  (MONTILEOFFSET + MONTILECOUNT)
#define STATILECOUNT  NUMMONS

#define FIGTILEOFFSET  (STATILEOFFSET + STATILECOUNT)
#define FIGTILECOUNT  NUMMONS

#define EXPTILEOFFSET  (FIGTILEOFFSET + FIGTILECOUNT)
#define EXPTILECOUNT  EXPL_MAX * 9

enum mcursor {
    V_CURSOR_NORMAL,
    V_CURSOR_SCROLLRIGHT,
    V_CURSOR_SCROLLLEFT,
    V_CURSOR_SCROLLUP,
    V_CURSOR_SCROLLDOWN,
    V_CURSOR_SCROLLUPLEFT,
    V_CURSOR_SCROLLUPRIGHT,
    V_CURSOR_SCROLLDOWNLEFT,
    V_CURSOR_SCROLLDOWNRIGHT,
    V_CURSOR_TARGET_GREEN,
    V_CURSOR_TARGET_RED,
    V_CURSOR_TARGET_INVALID,
    V_CURSOR_TARGET_HELP,
    V_CURSOR_HOURGLASS,
    V_CURSOR_OPENDOOR,
    V_CURSOR_STAIRS,
    V_CURSOR_GOBLET,
    V_CURSOR_MAX
};

#define CURTILEOFFSET  (EXPTILEOFFSET + EXPTILECOUNT)
#define CURTILECOUNT  V_CURSOR_MAX

#define MISCTILEOFFSET  (CURTILEOFFSET + CURTILECOUNT)
enum misctiles {
    V_MISC_PLAYER_INVIS = MISCTILEOFFSET,
    V_MISC_FLOOR_NOT_VISIBLE,
    V_MISC_DOOR_WOOD_BROKEN,
    V_MISC_HDOOR_WOOD_CLOSED,
    V_MISC_VDOOR_WOOD_CLOSED,
    V_MISC_VDOOR_WOOD_OPEN,
    V_MISC_HDOOR_WOOD_OPEN,
    V_MISC_TRAP_BEAR,
    V_MISC_GRAVE,
    V_MISC_ALTAR,
    V_MISC_FOUNTAIN,
    V_MISC_STAIRS_UP,
    V_MISC_STAIRS_DOWN,
    V_MISC_SINK,
    V_MISC_GAS_TRAP,
    V_MISC_TRAP_PIT,
    V_MISC_TRAP_POLYMORPH,
    V_MISC_TREE,
    V_MISC_TRAP_MAGIC,
    V_MISC_TRAP_DOOR,
    V_MISC_TRAP_WATER,
    V_MISC_TRAP_TELEPORTER,
    V_MISC_UNMAPPED_AREA,
    V_MISC_HILITE_PET,
    V_MISC_BARS,
    V_MISC_THRONE,
    V_MISC_TRAP_ANTI_MAGIC,
    V_MISC_TRAP_ARROW,
    V_MISC_TRAP_FIRE,
    V_MISC_ROLLING_BOULDER_TRAP,
    V_MISC_TRAP_SLEEPGAS,
    V_MISC_ZAP_SLANT_RIGHT,
    V_MISC_ZAP_SLANT_LEFT,
    V_MISC_ZAP_HORIZONTAL,
    V_MISC_ZAP_VERTICAL,
    V_MISC_LADDER_UP,
    V_MISC_LADDER_DOWN,
    V_MISC_RESIST_SPELL_1,
    V_MISC_RESIST_SPELL_2,
    V_MISC_RESIST_SPELL_3,
    V_MISC_RESIST_SPELL_4,
    V_MISC_WEB_TRAP,
    V_MISC_DART_TRAP,
    V_MISC_FALLING_ROCK_TRAP,
    V_MISC_SQUEAKY_BOARD,
    V_MISC_MAGIC_PORTAL,
    V_MISC_SPIKED_PIT,
    V_MISC_HOLE,
    V_MISC_LEVEL_TELEPORTER,
    V_MISC_MAGIC_TRAP,
    V_MISC_DIGBEAM,
    V_MISC_FLASHBEAM,
    V_MISC_BOOMLEFT,
    V_MISC_BOOMRIGHT,
    V_MISC_HCDBRIDGE,
    V_MISC_VCDBRIDGE,
    V_MISC_VODBRIDGE,
    V_MISC_HODBRIDGE,
    V_MISC_CLOUD,
    V_MISC_OFF_MAP,
    V_MISC_FLOOR_HIGHLIGHT,
    V_MISC_LAND_MINE,
    V_MISC_LAWFUL_PRIEST,
    V_MISC_CHAOTIC_PRIEST,
    V_MISC_NEUTRAL_PRIEST,
    V_MISC_UNALIGNED_PRIEST,
#if defined(REINCARNATION)
    V_MISC_ROGUE_LEVEL_A,
    V_MISC_ROGUE_LEVEL_B,
    V_MISC_ROGUE_LEVEL_C,
    V_MISC_ROGUE_LEVEL_D,
    V_MISC_ROGUE_LEVEL_E,
    V_MISC_ROGUE_LEVEL_F,
    V_MISC_ROGUE_LEVEL_G,
    V_MISC_ROGUE_LEVEL_H,
    V_MISC_ROGUE_LEVEL_I,
    V_MISC_ROGUE_LEVEL_J,
    V_MISC_ROGUE_LEVEL_K,
    V_MISC_ROGUE_LEVEL_L,
    V_MISC_ROGUE_LEVEL_M,
    V_MISC_ROGUE_LEVEL_N,
    V_MISC_ROGUE_LEVEL_O,
    V_MISC_ROGUE_LEVEL_P,
    V_MISC_ROGUE_LEVEL_Q,
    V_MISC_ROGUE_LEVEL_R,
    V_MISC_ROGUE_LEVEL_S,
    V_MISC_ROGUE_LEVEL_T,
    V_MISC_ROGUE_LEVEL_U,
    V_MISC_ROGUE_LEVEL_V,
    V_MISC_ROGUE_LEVEL_W,
    V_MISC_ROGUE_LEVEL_X,
    V_MISC_ROGUE_LEVEL_Y,
    V_MISC_ROGUE_LEVEL_Z,
#endif
    V_MISC_ENGULF_FIRE_VORTEX,
    V_MISC_ENGULF_FOG_CLOUD,
    V_MISC_ENGULF_AIR_ELEMENTAL,
    V_MISC_ENGULF_STEAM_VORTEX,
    V_MISC_ENGULF_PURPLE_WORM,
    V_MISC_ENGULF_JUIBLEX,
    V_MISC_ENGULF_OCHRE_JELLY,
    V_MISC_ENGULF_LURKER_ABOVE,
    V_MISC_ENGULF_TRAPPER,
    V_MISC_ENGULF_DUST_VORTEX,
    V_MISC_ENGULF_ICE_VORTEX,
    V_MISC_ENGULF_ENERGY_VORTEX,
    V_MISC_WARNLEV_1,
    V_MISC_WARNLEV_2,
    V_MISC_WARNLEV_3,
    V_MISC_WARNLEV_4,
    V_MISC_WARNLEV_5,
    V_MISC_WARNLEV_6,
    V_MISC_INVISIBLE_MONSTER,
    V_MISC_STINKING_CLOUD,
#ifdef VULTURESCLAW
    V_MISC_TOILET,
#endif
    V_MISC_MAX
};
#define MISCTILECOUNT  V_MISC_MAX - MISCTILEOFFSET

#define EDGETILEOFFSET  (MISCTILEOFFSET + MISCTILECOUNT)
#define EDGETILECOUNT  vultures_typecount[TT_EDGE]

#define FLOTILEOFFSET  (EDGETILEOFFSET + EDGETILECOUNT)
#define FLOTILECOUNT  vultures_typecount[TT_FLOOR]

#define WALTILEOFFSET  (FLOTILEOFFSET + FLOTILECOUNT)
#define WALTILECOUNT  vultures_typecount[TT_WALL]

#define GAMETILECOUNT  (WALTILEOFFSET + WALTILECOUNT)



#define TILE_IS_OBJECT(x)  (((x) >= OBJTILEOFFSET) &&((x) < (OBJTILEOFFSET + OBJTILECOUNT)))
#define TILE_IS_OBJICON(x) (((x) >= ICOTILEOFFSET) &&((x) < (ICOTILEOFFSET + ICOTILECOUNT)))
#define TILE_IS_FLOOR(x)   (((x) >= FLOTILEOFFSET) &&((x) < (FLOTILEOFFSET + FLOTILECOUNT)))
#define TILE_IS_WALL(x)    (((x) >= WALTILEOFFSET) &&((x) < (WALTILEOFFSET + WALTILECOUNT)))




#define OBJECT_TO_VTILE(obj_id) ((obj_id) + OBJTILEOFFSET)
#define OBJICON_TO_VTILE(obj_id) ((obj_id) + ICOTILEOFFSET)
#define MONSTER_TO_VTILE(mon_id) ((mon_id) + MONTILEOFFSET)
#define STATUE_TO_VTILE(mon_id) ((mon_id) + STATILEOFFSET)
#define FIGURINE_TO_VTILE(mon_id) ((mon_id) + FIGTILEOFFSET)


enum special_tiles {
/* make sure all these are negative to prevent clashes with normal tile numbers */
    V_TILE_NONE = -1000,
    V_TILE_WALL_GENERIC,
    V_TILE_FLOOR_COBBLESTONE,
    V_TILE_FLOOR_ROUGH,
    V_TILE_FLOOR_WATER,
    V_TILE_FLOOR_ICE,
    V_TILE_FLOOR_LAVA,
    V_TILE_FLOOR_ROUGH_LIT,
    V_TILE_FLOOR_AIR,
    V_TILE_FLOOR_DARK
};


struct gametiles {
    char *filename;
    int ptr;
    int hs_x;
    int hs_y;
};

struct fstyles {
    int x;
    int y;
    int * array;
};

struct walls {
    int north;
    int east;
    int south;
    int west;
};

struct fedges {
    int dir[12];
};


enum floorstyles {
    V_FLOOR_COBBLESTONE,
    V_FLOOR_ROUGH,
    V_FLOOR_CERAMIC,
    V_FLOOR_LAVA,
    V_FLOOR_WATER,
    V_FLOOR_ICE,
    V_FLOOR_MURAL,
    V_FLOOR_MURAL2,
    V_FLOOR_CARPET,
    V_FLOOR_MOSS_COVERED,
    V_FLOOR_MARBLE,
    V_FLOOR_ROUGH_LIT,
    V_FLOOR_AIR,
    V_FLOOR_DARK,
    V_FLOOR_STYLE_MAX
};

enum flooredges {
    V_FLOOR_EDGE_COBBLESTONE,
    V_FLOOR_EDGE_MAX
};

enum wallstyles {
    V_WALL_BRICK,
    V_WALL_BRICK_BANNER,
    V_WALL_BRICK_PAINTING,
    V_WALL_BRICK_POCKET,
    V_WALL_BRICK_PILLAR,
    V_WALL_MARBLE,
    V_WALL_VINE_COVERED,
    V_WALL_STUCCO,
    V_WALL_ROUGH,
    V_WALL_DARK,
    V_WALL_LIGHT,
    V_WALL_STYLE_MAX
};



extern struct walls walls_full[];
extern struct walls walls_half[];
extern struct fedges flooredges[];
extern struct fstyles floorstyles[];


#endif
