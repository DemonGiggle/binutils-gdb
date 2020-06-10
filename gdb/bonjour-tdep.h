/* Target-dependent code for Bonjour

   Copyright (C) 2009-2020 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef BONJOUR_TDEP_H
#define BONJOUR_TDEP_H

struct gdbarch_tdep
{
  /* gdbarch target dependent data here.  Currently unused for BONJOUR.  */
};

enum bonjour_regnum
{
  BONJOUR_FP_REGNUM = 0,
  BONJOUR_SP_REGNUM = 1,
  R0_REGNUM = 2,
  R1_REGNUM = 3,
  BONJOUR_PC_REGNUM = 16,
  BONJOUR_CC_REGNUM = 17,
  RET1_REGNUM = R0_REGNUM,
  ARG1_REGNUM = R0_REGNUM,
  ARGN_REGNUM = R1_REGNUM,
};

#define BONJOUR_NUM_REGS 18

#endif /* bonjour-tdep.h */
