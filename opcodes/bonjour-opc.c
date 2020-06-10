/* bonjour-opc.c -- Definitions for bonjour opcodes.
   Copyright (C) 2009-2020 Free Software Foundation, Inc.
   Contributed by Anthony Green (green@bonjourlogic.com).

   This file is part of the GNU opcodes library.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this file; see the file COPYING.  If not, write to the
   Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include "opcode/bonjour.h"

/* The bonjour processor's 16-bit instructions come in two forms:

  FORM 1 instructions start with a 0 bit...

    0oooooooaaaabbbb
    0              F

   ooooooo - form 1 opcode number
   aaaa    - operand A
   bbbb    - operand B

  FORM 2 instructions start with bits "10"...

    10ooaaaavvvvvvvv
    0              F

   oo       - form 2 opcode number
   aaaa     - operand A
   vvvvvvvv - 8-bit immediate value

  FORM 3 instructions start with a bits "11"...

    11oooovvvvvvvvvv
    0              F

   oooo         - form 3 opcode number
   vvvvvvvvvv   - 10-bit immediate value.  */

const bonjour_opc_info_t bonjour_form1_opc_info[128] =
  {
    { 0x00, BONJOUR_BAD,     "bad" },  // Reserved as bad.
    { 0x01, BONJOUR_F1_A4,   "ldi.l" },
    { 0x02, BONJOUR_F1_AB,   "mov" },
    { 0x03, BONJOUR_F1_M,    "jsra" },
    { 0x04, BONJOUR_F1_NARG, "ret" },
    { 0x05, BONJOUR_F1_AB,   "add" },
    { 0x06, BONJOUR_F1_AB,   "push" },
    { 0x07, BONJOUR_F1_AB,   "pop" },
    { 0x08, BONJOUR_F1_A4,   "lda.l" },
    { 0x09, BONJOUR_F1_4A,   "sta.l" },
    { 0x0a, BONJOUR_F1_ABi,  "ld.l" },
    { 0x0b, BONJOUR_F1_AiB,  "st.l" },
    { 0x0c, BONJOUR_F1_ABi2, "ldo.l" },
    { 0x0d, BONJOUR_F1_AiB2, "sto.l" },
    { 0x0e, BONJOUR_F1_AB,   "cmp" },
    { 0x0f, BONJOUR_F1_NARG, "nop" },
    { 0x10, BONJOUR_F1_AB,   "sex.b" },
    { 0x11, BONJOUR_F1_AB,   "sex.s" },
    { 0x12, BONJOUR_F1_AB,   "zex.b" },
    { 0x13, BONJOUR_F1_AB,   "zex.s" },
    { 0x14, BONJOUR_F1_AB,   "umul.x" },
    { 0x15, BONJOUR_F1_AB,   "mul.x" },
    { 0x16, BONJOUR_BAD,     "bad" },
    { 0x17, BONJOUR_BAD,     "bad" },
    { 0x18, BONJOUR_BAD,     "bad" },
    { 0x19, BONJOUR_F1_A,    "jsr" },
    { 0x1a, BONJOUR_F1_M,    "jmpa" },
    { 0x1b, BONJOUR_F1_A4,   "ldi.b" },
    { 0x1c, BONJOUR_F1_ABi,  "ld.b" },
    { 0x1d, BONJOUR_F1_A4,   "lda.b" },
    { 0x1e, BONJOUR_F1_AiB,  "st.b" },
    { 0x1f, BONJOUR_F1_4A,   "sta.b" },
    { 0x20, BONJOUR_F1_A4,   "ldi.s" },
    { 0x21, BONJOUR_F1_ABi,  "ld.s" },
    { 0x22, BONJOUR_F1_A4,   "lda.s" },
    { 0x23, BONJOUR_F1_AiB,  "st.s" },
    { 0x24, BONJOUR_F1_4A,   "sta.s" },
    { 0x25, BONJOUR_F1_A,    "jmp" },
    { 0x26, BONJOUR_F1_AB,   "and" },
    { 0x27, BONJOUR_F1_AB,   "lshr" },
    { 0x28, BONJOUR_F1_AB,   "ashl" },
    { 0x29, BONJOUR_F1_AB,   "sub" },
    { 0x2a, BONJOUR_F1_AB,   "neg" },
    { 0x2b, BONJOUR_F1_AB,   "or" },
    { 0x2c, BONJOUR_F1_AB,   "not" },
    { 0x2d, BONJOUR_F1_AB,   "ashr" },
    { 0x2e, BONJOUR_F1_AB,   "xor" },
    { 0x2f, BONJOUR_F1_AB,   "mul" },
    { 0x30, BONJOUR_F1_4,    "swi" },
    { 0x31, BONJOUR_F1_AB,   "div" },
    { 0x32, BONJOUR_F1_AB,   "udiv" },
    { 0x33, BONJOUR_F1_AB,   "mod" },
    { 0x34, BONJOUR_F1_AB,   "umod" },
    { 0x35, BONJOUR_F1_NARG, "brk" },
    { 0x36, BONJOUR_F1_ABi2, "ldo.b" },
    { 0x37, BONJOUR_F1_AiB2, "sto.b" },
    { 0x38, BONJOUR_F1_ABi2, "ldo.s" },
    { 0x39, BONJOUR_F1_AiB2, "sto.s" },
    { 0x3a, BONJOUR_BAD,     "bad" },
    { 0x3b, BONJOUR_BAD,     "bad" },
    { 0x3c, BONJOUR_BAD,     "bad" },
    { 0x3d, BONJOUR_BAD,     "bad" },
    { 0x3e, BONJOUR_BAD,     "bad" },
    { 0x3f, BONJOUR_BAD,     "bad" },
    { 0x40, BONJOUR_BAD,     "bad" },
    { 0x41, BONJOUR_BAD,     "bad" },
    { 0x42, BONJOUR_BAD,     "bad" },
    { 0x43, BONJOUR_BAD,     "bad" },
    { 0x44, BONJOUR_BAD,     "bad" },
    { 0x45, BONJOUR_BAD,     "bad" },
    { 0x46, BONJOUR_BAD,     "bad" },
    { 0x47, BONJOUR_BAD,     "bad" },
    { 0x48, BONJOUR_BAD,     "bad" },
    { 0x49, BONJOUR_BAD,     "bad" },
    { 0x4a, BONJOUR_BAD,     "bad" },
    { 0x4b, BONJOUR_BAD,     "bad" },
    { 0x4c, BONJOUR_BAD,     "bad" },
    { 0x4d, BONJOUR_BAD,     "bad" },
    { 0x4e, BONJOUR_BAD,     "bad" },
    { 0x4f, BONJOUR_BAD,     "bad" },
    { 0x50, BONJOUR_BAD,     "bad" },
    { 0x51, BONJOUR_BAD,     "bad" },
    { 0x52, BONJOUR_BAD,     "bad" },
    { 0x53, BONJOUR_BAD,     "bad" },
    { 0x54, BONJOUR_BAD,     "bad" },
    { 0x55, BONJOUR_BAD,     "bad" },
    { 0x56, BONJOUR_BAD,     "bad" },
    { 0x57, BONJOUR_BAD,     "bad" },
    { 0x58, BONJOUR_BAD,     "bad" },
    { 0x59, BONJOUR_BAD,     "bad" },
    { 0x5a, BONJOUR_BAD,     "bad" },
    { 0x5b, BONJOUR_BAD,     "bad" },
    { 0x5c, BONJOUR_BAD,     "bad" },
    { 0x5d, BONJOUR_BAD,     "bad" },
    { 0x5e, BONJOUR_BAD,     "bad" },
    { 0x5f, BONJOUR_BAD,     "bad" },
    { 0x60, BONJOUR_BAD,     "bad" },
    { 0x61, BONJOUR_BAD,     "bad" },
    { 0x62, BONJOUR_BAD,     "bad" },
    { 0x63, BONJOUR_BAD,     "bad" },
    { 0x64, BONJOUR_BAD,     "bad" },
    { 0x65, BONJOUR_BAD,     "bad" },
    { 0x66, BONJOUR_BAD,     "bad" },
    { 0x67, BONJOUR_BAD,     "bad" },
    { 0x68, BONJOUR_BAD,     "bad" },
    { 0x69, BONJOUR_BAD,     "bad" },
    { 0x6a, BONJOUR_BAD,     "bad" },
    { 0x6b, BONJOUR_BAD,     "bad" },
    { 0x6c, BONJOUR_BAD,     "bad" },
    { 0x6d, BONJOUR_BAD,     "bad" },
    { 0x6e, BONJOUR_BAD,     "bad" },
    { 0x6f, BONJOUR_BAD,     "bad" },
    { 0x70, BONJOUR_BAD,     "bad" },
    { 0x71, BONJOUR_BAD,     "bad" },
    { 0x72, BONJOUR_BAD,     "bad" },
    { 0x73, BONJOUR_BAD,     "bad" },
    { 0x74, BONJOUR_BAD,     "bad" },
    { 0x75, BONJOUR_BAD,     "bad" },
    { 0x76, BONJOUR_BAD,     "bad" },
    { 0x77, BONJOUR_BAD,     "bad" },
    { 0x78, BONJOUR_BAD,     "bad" },
    { 0x79, BONJOUR_BAD,     "bad" },
    { 0x7a, BONJOUR_BAD,     "bad" },
    { 0x7b, BONJOUR_BAD,     "bad" },
    { 0x7c, BONJOUR_BAD,     "bad" },
    { 0x7d, BONJOUR_BAD,     "bad" },
    { 0x7e, BONJOUR_BAD,     "bad" },
    { 0x7f, BONJOUR_BAD,     "bad" }
  };

const bonjour_opc_info_t bonjour_form2_opc_info[4] =
  {
    { 0x00, BONJOUR_F2_A8V,  "inc" },
    { 0x01, BONJOUR_F2_A8V,  "dec" },
    { 0x02, BONJOUR_F2_A8V,  "gsr" },
    { 0x03, BONJOUR_F2_A8V,  "ssr" }
  };

const bonjour_opc_info_t bonjour_form3_opc_info[16] =
  {
    { 0x00, BONJOUR_F3_PCREL,"beq" },
    { 0x01, BONJOUR_F3_PCREL,"bne" },
    { 0x02, BONJOUR_F3_PCREL,"blt" },
    { 0x03, BONJOUR_F3_PCREL,"bgt" },
    { 0x04, BONJOUR_F3_PCREL,"bltu" },
    { 0x05, BONJOUR_F3_PCREL,"bgtu" },
    { 0x06, BONJOUR_F3_PCREL,"bge" },
    { 0x07, BONJOUR_F3_PCREL,"ble" },
    { 0x08, BONJOUR_F3_PCREL,"bgeu" },
    { 0x09, BONJOUR_F3_PCREL,"bleu" },
    { 0x0a, BONJOUR_BAD,     "bad" },
    { 0x0b, BONJOUR_BAD,     "bad" },
    { 0x0c, BONJOUR_BAD,     "bad" },
    { 0x0d, BONJOUR_BAD,     "bad" },
    { 0x0e, BONJOUR_BAD,     "bad" },
    { 0x0f, BONJOUR_BAD,     "bad" }  // Reserved as bad.
  };
