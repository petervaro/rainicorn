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
#define decor(F) do {puts("\n"); F; puts("\n");} while (0)

/*----------------------------------------------------------------------------*/
int
main(void)
{
    /* doc-01 */
    decor(
    puts("\""
         RC_F(RC_RED, "Hello, ")
         RC_F(RC_YELLOW, "World!")
         RC_XFBS("\"\n"));
    );

    /* doc-02 */
    decor(
    puts("\""
         RC_F(RC_BLUE, "Hello, ")
         RC_B(RC_WHITE, "World!")
         RC_XFBS("\"\n"));
    );

    /* doc-03 */
    decor(
    puts("\""
         RC_F(RC_GREEN, "Hello, ")
         RC_FB(RC_DEFAULT, RC_MAGENTA, "World!")
         RC_XFBS("\"\n"));
    puts("\""
         RC_F(RC_GREEN, "Hello, ")
         RC_XF(RC_B(RC_MAGENTA, "World!"))
         RC_XFBS("\"\n"));
    );

    /* doc-04 */
    decor(
    puts("\""
         RC_FS(RC_CYAN, RC_BOLD, "Hello, ")
         RC_XF("World! ")
         RC_XFBS("Good bye!\"\n"));
    );

    return EXIT_SUCCESS;
}
