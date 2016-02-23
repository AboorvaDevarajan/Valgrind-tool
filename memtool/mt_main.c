
/*--------------------------------------------------------------------*/
/*--- Nulgrind: The minimal Valgrind tool.               mt_main.c ---*/
/*--------------------------------------------------------------------*/

/*
   This file is part of Nulgrind, the minimal Valgrind tool,
   which does no instrumentation or analysis.

   Copyright (C) 2002-2015 Nicholas Nethercote
      njn@valgrind.org

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307, USA.

   The GNU General Public License is contained in the file COPYING.
*/

#include "pub_tool_basics.h"
#include "pub_tool_tooliface.h"

static void mt_post_clo_init(void)
{
}

static
IRSB* mt_instrument ( VgCallbackClosure* closure,
                      IRSB* bb,
                      const VexGuestLayout* layout, 
                      const VexGuestExtents* vge,
                      const VexArchInfo* archinfo_host,
                      IRType gWordTy, IRType hWordTy )
{
    return bb;
}

static void mt_fini(Int exitcode)
{
}

static void mt_pre_clo_init(void)
{
   VG_(details_name)            ("Memory tool");
   VG_(details_version)         ("v0.1");
   VG_(details_description)     ("simple custom valgrind tool :)");
   VG_(details_copyright_author)(
      "Copyright (C) 2002-2015, and GNU GPL'd, by Aboorva Devarajan.");
   VG_(details_bug_reports_to)  (VG_BUGS_TO);

   VG_(details_avg_translation_sizeB) ( 275 );

   VG_(basic_tool_funcs)        (mt_post_clo_init,
                                 mt_instrument,
                                 mt_fini);

   /* No needs, no core events to track */
}

VG_DETERMINE_INTERFACE_VERSION(mt_pre_clo_init)

/*--------------------------------------------------------------------*/
/*--- end                                                          ---*/
/*--------------------------------------------------------------------*/
