/* Definitions for decoding the bonjour opcode table.
   Copyright (C) 2009-2020 Free Software Foundation, Inc.
   Contributed by Anthony Green (green@bonjourlogic.com).

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA
   02110-1301, USA.  */

/* Form 1 instructions come in different flavors:

    Some have no arguments                          (BONJOUR_F1_NARG)
    Some only use the A operand                     (BONJOUR_F1_A)
    Some use A and B registers                      (BONJOUR_F1_AB)
    Some use A and consume a 4 byte immediate value (BONJOUR_F1_A4)
    Some use just a 4 byte immediate value          (BONJOUR_F1_4)
    Some use just a 4 byte memory address           (BONJOUR_F1_M)
    Some use B and an indirect A                    (BONJOUR_F1_AiB)
    Some use A and an indirect B                    (BONJOUR_F1_ABi)
    Some consume a 4 byte immediate value and use X (BONJOUR_F1_4A)
    Some use B and an indirect A plus 2 byte offset (BONJOUR_F1_AiB2)
    Some use A and an indirect B plus 2 byte offset (BONJOUR_F1_ABi2)

  Form 2 instructions also come in different flavors:

    Some have no arguments                          (BONJOUR_F2_NARG)
    Some use the A register and an 8-bit value      (BONJOUR_F2_A8V)

  Form 3 instructions also come in different flavors:

    Some have no arguments                          (BONJOUR_F3_NARG)
    Some have a 10-bit PC relative operand          (BONJOUR_F3_PCREL).  */

#define BONJOUR_F1_NARG 0x100
#define BONJOUR_F1_A    0x101
#define BONJOUR_F1_AB   0x102
/* #define BONJOUR_F1_ABC  0x103 */
#define BONJOUR_F1_A4   0x104
#define BONJOUR_F1_4    0x105
#define BONJOUR_F1_AiB  0x106
#define BONJOUR_F1_ABi  0x107
#define BONJOUR_F1_4A   0x108
#define BONJOUR_F1_AiB2 0x109
#define BONJOUR_F1_ABi2 0x10a
#define BONJOUR_F1_M    0x10b

#define BONJOUR_F2_NARG 0x200
#define BONJOUR_F2_A8V  0x201

#define BONJOUR_F3_NARG  0x300
#define BONJOUR_F3_PCREL 0x301

#define BONJOUR_BAD     0x400

typedef struct bonjour_opc_info_t
{
  short         opcode;
  unsigned      itype;
  const char *  name;
} bonjour_opc_info_t;

extern const bonjour_opc_info_t bonjour_form1_opc_info[128];
extern const bonjour_opc_info_t bonjour_form2_opc_info[4];
extern const bonjour_opc_info_t bonjour_form3_opc_info[16];
