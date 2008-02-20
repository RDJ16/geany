/*
 *      build.h - this file is part of Geany, a fast and lightweight IDE
 *
 *      Copyright 2005-2008 Enrico Tröger <enrico(dot)troeger(at)uvena(dot)de>
 *      Copyright 2006-2008 Nick Treleaven <nick(dot)treleaven(at)btinternet(dot)com>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * $Id$
 */


#ifndef GEANY_BUILD_H
#define GEANY_BUILD_H 1

typedef enum	// Geany Build Options
{
	GBO_COMPILE,
	GBO_BUILD,
	GBO_MAKE_ALL,
	GBO_MAKE_CUSTOM,
	GBO_MAKE_OBJECT
} build_type;

typedef struct BuildInfo
{
	build_type	type;	// current action(one of the above enumeration)
	GPid		pid;	// process id of the spawned process
	gchar		*dir;
	guint		file_type_id;
	gchar		*custom_target;
} BuildInfo;

extern BuildInfo build_info;


typedef struct BuildMenuItems
{
	GtkWidget		*menu;
	GtkWidget		*item_compile;
	GtkWidget		*item_link;
	GtkWidget		*item_make_all;
	GtkWidget		*item_make_custom;
	GtkWidget		*item_make_object;
	GtkWidget		*item_next_error;
	GtkWidget		*item_exec;
	GtkWidget		*item_exec2;
	GtkWidget		*item_set_args;
} BuildMenuItems;



void build_init(void);

void build_finalize(void);


gboolean build_parse_make_dir(const gchar *string, gchar **prefix);

void build_menu_update(gint idx);

BuildMenuItems *build_get_menu_items(gint filetype_idx);


#endif
