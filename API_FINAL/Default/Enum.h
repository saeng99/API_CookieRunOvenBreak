#pragma once

enum DIRECTION {DIR_LEFT, DIR_UP, DIR_RIGHT, DIR_DOWN ,DIR_END};

enum OBJID {OBJ_PLAYER, OBJ_BULLET, OBJ_BLOCK, OBJ_JELLY, OBJ_MONSTER, OBJ_MOUSE, OBJ_SHIELD, OBJ_BUTTON, OBJ_END };

enum SCENEID { SC_LOGO, SC_MENU, SC_EDIT, SC_STAGE, SC_END };

enum RENDERID { RENDER_BACKGROUND, RENDER_GAMEOBJECT, RENDER_EFFECT, RENDER_UI, RENDER_END };

// 최대 32개 채널까지 동시 재생이 가능
enum CHANNELID { SOUND_EFFECT, SOUND_BGM, SOUND_PLAYER, SOUND_MONSTER, MAXCHANNEL };

enum BLOCKID { BLK_BLOCK, BLK_FLOATINGBLOCK, BLK_THORN, BLK_FORK, BLK_COIN, BLK_END };