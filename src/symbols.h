/*
 *      symbols.h - this file is part of Geany, a fast and lightweight IDE
 *
 *      Copyright 2006-2008 Enrico Tröger <enrico(dot)troeger(at)uvena(dot)de>
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
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * $Id$
 */


#ifndef GEANY_SYMBOLS_H
#define GEANY_SYMBOLS_H 1

extern const guint TM_GLOBAL_TYPE_MASK;
extern gchar **c_tags_ignore;


void symbols_global_tags_loaded(gint file_type_idx);

GString *symbols_find_tags_as_string(GPtrArray *tags_array, guint tag_types, gint lang);

const gchar *symbols_get_context_separator(gint ft_id);

const GList *symbols_get_tag_list(gint idx, guint tag_types);

GString *symbols_get_macro_list(void);

const gchar **symbols_get_html_entities(void);

void symbols_finalize(void);

gboolean symbols_recreate_tag_list(gint idx, gboolean sort_by_name);

gint symbols_generate_global_tags(gint argc, gchar **argv, gboolean want_preprocess);

void symbols_show_load_tags_dialog(void);

gboolean symbols_goto_tag(const gchar *name, gboolean definition);

#endif
