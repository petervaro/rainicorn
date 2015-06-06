/* INFO ************************************************************************
**                                                                            **
**                                 rainicorn                                  **
**                                 =========                                  **
**                                                                            **
**          Macros for ANSI escape sequences in a single header file          **
**                       Version: 0.1.0.006 (20150607)                        **
**                             File: rainicorn.h                              **
**                                                                            **
**               For more information about the project, visit                **
**                 <https://github.com/petervaro/rainicorn>.                  **
**                       Copyright (C) 2015 Peter Varo                        **
**                                                                            **
**  This program is free software: you can redistribute it and/or modify it   **
**   under the terms of the GNU General Public License as published by the    **
**       Free Software Foundation, either version 3 of the License, or        **
**                    (at your option) any later version.                     **
**                                                                            **
**    This program is distributed in the hope that it will be useful, but     **
**         WITHOUT ANY WARRANTY; without even the implied warranty of         **
**            MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.            **
**            See the GNU General Public License for more details.            **
**                                                                            **
**     You should have received a copy of the GNU General Public License      **
**     along with this program, most likely a file in the root directory,     **
**        called 'LICENSE'. If not, see <http://www.gnu.org/licenses>.        **
**                                                                            **
************************************************************************ INFO */

#ifndef __RAINICORN_H_043542018096__
#define __RAINICORN_H_043542018096__

/* Control Sequence Introducer */
#define rc_CSI(V)                   "\x1b[" V "m"
#define rc_CSI_SGR_2(V1, V2)        rc_CSI(V1 ";" V2)
#define rc_CSI_SGR_3(V1, V2, V3)    rc_CSI(V1 ";" V2 ";" V3)

/* Select Graphic Rendition */
#define rc_NONE                     "0"
#define rc_BOLD                     "1"
#define rc_NORMAL                   "22"

/* Colors */
#define rc_BLACK                    "0"
#define rc_RED                      "1"
#define rc_GREEN                    "2"
#define rc_YELLOW                   "3"
#define rc_BLUE                     "4"
#define rc_MAGENTA                  "5"
#define rc_CYAN                     "6"
#define rc_WHITE                    "7"
#define rc_DEFAULT                  "9"

/* Types */
#define rc_FG(C)                    "3" C
#define rc_BG(C)                    "4" C
#define rc_DEF_FG                   rc_FG(rc_DEFAULT)
#define rc_DEF_BG                   rc_BG(rc_DEFAULT)

/* T: text
   R:
   F: foreground
   B: background
   S: style */

/* Set */
#define rc_F(F, T)                  rc_CSI(rc_FG(F)) T
#define rc_B(B, T)                  rc_CSI(rc_BG(B)) T
#define rc_S(S, T)                  rc_CSI(S) T
#define rc_FB(F, B, T)              rc_CSI_SGR_2(rc_FG(F), rc_BG(B)) T
#define rc_FS(F, S, T)              rc_CSI_SGR_2(rc_FG(F), S) T
#define rc_BS(B, S, T)              rc_CSI_SGR_2(rc_BG(B), S) T
#define rc_FBS(F, B, S, T)          rc_CSI_SGR_3(rc_FG(F), rc_BG(B), S) T

/* Remove */
#define rc_RF(T)                    rc_CSI(rc_DEF_FG) T
#define rc_RB(T)                    rc_CSI(rc_DEF_BG) T
#define rc_RS(T)                    rc_CSI(rc_NORMAL) T
#define rc_RFB(T)                   rc_CSI_SGR_2(rc_DEF_FG, rc_DEF_BG) T
#define rc_RFS(T)                   rc_CSI_SGR_2(rc_DEF_FG, rc_NORMAL) T
#define rc_RBS(T)                   rc_CSI_SGR_2(rc_DEF_BG, rc_NORMAL) T

/* Reset all */
#define rc_RESET(T)                 rc_CSI(rc_NONE) T

#endif /* __RAINICORN_H_043542018096__ */
