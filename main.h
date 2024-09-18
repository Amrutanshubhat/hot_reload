#ifndef _HOT_RELOAD
#define _HOT_RELOAD

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <dlfcn.h>

#include "raylib.h"

extern void (*update_plug)(void);
const int w_height = 50*9;
const int w_width = 50*16;
const char* hot_path = "libhot.so";
static void* hotplug = NULL;


#endif
