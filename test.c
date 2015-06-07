/* INFO ************************************************************************
**                                                                            **
**                                 rainicorn                                  **
**                                 =========                                  **
**                                                                            **
**          Macros for ANSI escape sequences in a single header file          **
**                       Version: 0.1.1.025 (20150607)                        **
**                                File: test.c                                **
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

/* Include standard headers */
#include <stdio.h> /*
    const : stderr
    func  : printf
            fprintf
*/
#include <stdlib.h> /*
    const : EXIT_SUCCESS
*/

// #define MONOCORN

/* Include rainicorn headers */
#include "rainicorn.h" /*
    macro : rc_WHITE
            rc_GREEN
            rc_YELLOW
            rc_RED
            rc_BOLD
            rc_NORMAL
            rc_F
            rc_FS
            rc_RESET
*/

#define PREFIXER(C, P, T) rc_F(rc_WHITE, "[ ")                                 \
                          rc_FS(C, rc_BOLD, P)                                 \
                          rc_FS(rc_WHITE, rc_NORMAL, " ]")                     \
                          rc_RESET(" " T "\n")

int
main(void)
{
    printf(PREFIXER(rc_GREEN , "OKAY", "Everything is fine")
           PREFIXER(rc_YELLOW, "WARN", "Final warning...")
           PREFIXER(rc_RED   , "FAIL", "Exterminate!"));

    return EXIT_SUCCESS;
}
