/*
* (C) Copyright 2007-2013
* Allwinner Technology Co., Ltd. <www.allwinnertech.com>
* Martin zheng <zhengjiewen@allwinnertech.com>
*
* See file CREDITS for list of people who contributed to this
* project.
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston,
* MA 02111-1307 USA
*/
#include "include.h"
#include "common_res.h"


#define   BAT_VOL_ACTIVE     (10)

int    power_ops_int_status = 0;
__u32  pic_layer_para;

static int show_battery_full(int *status);
static int shut_battery_full(void);

__s32 check_file_to_fel(char *name)
{
    H_FILE  hfile = NULL;

    hfile = wBoot_fopen(name, "r");
    if(hfile)
    {
        wBoot_fclose(hfile);
        wBoot_rmfile(name);
        hfile = NULL;
    	hfile = wBoot_fopen(name, "r");
    	if(!hfile)
    	{
    		__inf("dest file is not exist\n");
    	}
    	else
    	{
    		wBoot_fclose(hfile);
    	}

    	return 0;
    }

    return -1;
}

__s32 check_natch_time(char *file_name, __u32 work_mode)
{
    H_FILE  hfile = NULL;
    __s32   ret = -1;

    hfile = wBoot_fopen(file_name, "r");
    if(hfile)
    {
        if(work_mode == WORK_MODE_PRODUCT)
        {
            ret = 0;
        }
        wBoot_fclose(hfile);
        wBoot_rmfile(file_name);
    }

    return ret;
}

__s32 check_power_status(void)
{
	return 0;
}

static int show_battery_full(int *status)
{
	return 0;
}

static int shut_battery_full(void)
{
	return 0;
}

