/*  SSNES - A Super Nintendo Entertainment System (SNES) Emulator frontend for libsnes.
 *  Copyright (C) 2010-2012 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2012 - Daniel De Matteis
 *
 *  Some code herein may be based on code found in BSNES.
 * 
 *  SSNES is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  SSNES is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with SSNES.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#include <xtl.h>
#include <stddef.h>
#include <xbdm.h>
#include "menu.h"
#include "xdk360_video.h"
#include "../general.h"
#include "shared.h"

uint32_t mode_switch = MODE_MENU;

int ssnes_main(int argc, char *argv[]);

#undef main

int main(int argc, char *argv[])
{
	//for devkits only, we will need to mount all partitions for retail
	//in a different way
	//DmMapDevkitDrive();
	ssnes_main_clear_state();

	config_set_defaults();

	xdk360_video_init();

   char arg1[] = "ssnes";
   char arg2[] = "d:\\roms\\mario.sfc";
   char arg3[] = "-v";
   char arg4[] = "-c";
   char arg5[] = "d:\\ssnes.cfg";
   char *argv_[] = { arg1, arg2, arg3, arg4, arg5, NULL };
   int argc_ = sizeof(argv_) / sizeof(argv_[0]) - 1;
   int init_ret = ssnes_main_init(argc_, argv_);
   while(ssnes_main_iterate());
   ssnes_main_deinit();
   xdk360_video_deinit();
}

