/* INFO **
** INFO */

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include standard headers */
#include <stdio.h>
/*  func  : puts */
#include <stdlib.h>
/*  const : EXIT_SUCCESS */

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include rainicorn headers */
#include "rainicorn/rainicorn.h"
/*  macro : RC_WHITE
            RC_GREEN
            RC_YELLOW
            RC_RED
            RC_BOLD
            RC_NORMAL
            RC_F
            RC_FS
            RC_XFBS */


/*----------------------------------------------------------------------------*/
#define PREFIXER(C, P, T) RC_F(RC_WHITE, "[ ")                                 \
                          RC_FS(C, RC_BOLD, P)                                 \
                          RC_FS(RC_WHITE, RC_NORMAL, " ]")                     \
                          RC_XFBS(" " T "\n")


/*----------------------------------------------------------------------------*/
int
main(void)
{
    puts(PREFIXER(RC_GREEN , "OKAY", "Everything is fine")
         PREFIXER(RC_YELLOW, "WARN", "Final warning...")
         PREFIXER(RC_RED   , "FAIL", "Exterminate!"));

    return EXIT_SUCCESS;
}
