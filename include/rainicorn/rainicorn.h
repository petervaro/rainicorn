/* INFO **
** INFO */

/* Header guard */
#ifndef RAINICORN_H_5627173524822710
#define RAINICORN_H_5627173524822710 1

/* Variables:
   V: value
   C: color
   T: text
   F: foreground
   B: background
   S: style

   Prefices:
   X : remove */

/*----------------------------------------------------------------------------*/
#ifdef RC_MONOCORN /* If monochrome */

    #define RC__CSI(V)                  ""
    #define RC__CSI_SGR_2(V1, V2)       ""
    #define RC__CSI_SGR_3(V1, V2, V3)   ""
    #define RC_NONE                     ""
    #define RC_BOLD                     ""
    #define RC_NORMAL                   ""
    #define RC_BLACK                    ""
    #define RC_RED                      ""
    #define RC_GREEN                    ""
    #define RC_YELLOW                   ""
    #define RC_BLUE                     ""
    #define RC_MAGENTA                  ""
    #define RC_CYAN                     ""
    #define RC_WHITE                    ""
    #define RC_DEFAULT                  ""
    #define RC_FG(C)                    ""
    #define RC_BG(C)                    ""
    #define RC_DEF_FG                   ""
    #define RC_DEF_BG                   ""
    #define RC_F(F, T)                  T
    #define RC_B(B, T)                  T
    #define RC_S(S, T)                  T
    #define RC_FB(F, B, T)              T
    #define RC_FS(F, S, T)              T
    #define RC_BS(B, S, T)              T
    #define RC_FBS(F, B, S, T)          T
    #define RC_XF(T)                    T
    #define RC_XB(T)                    T
    #define RC_XS(T)                    T
    #define RC_XFB(T)                   T
    #define RC_XFS(T)                   T
    #define RC_XBS(T)                   T
    #define RC_XFBS(T)                  T


/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#else /* If colorful */

    /*----- Control Sequence Introducer --------------------------------------*/
    #define RC__CSI(V)                  "\x1b[" V "m"
    #define RC__CSI_SGR_2(V1, V2)       RC__CSI(V1 ";" V2)
    #define RC__CSI_SGR_3(V1, V2, V3)   RC__CSI(V1 ";" V2 ";" V3)


    /*----- Style constants --------------------------------------------------*/
    #define RC_NONE                     "0"
    #define RC_BOLD                     "1"
    #define RC_NORMAL                   "22"


    /*----- Colors constants -------------------------------------------------*/
    #define RC_BLACK                    "0"
    #define RC_RED                      "1"
    #define RC_GREEN                    "2"
    #define RC_YELLOW                   "3"
    #define RC_BLUE                     "4"
    #define RC_MAGENTA                  "5"
    #define RC_CYAN                     "6"
    #define RC_WHITE                    "7"
    #define RC_DEFAULT                  "9"


    /*----- Set attributes ---------------------------------------------------*/
    /* Set foreground */
    #define RC_FG(C)                    "3" C
    /* Set background */
    #define RC_BG(C)                    "4" C
    /* Set default foreground */
    #define RC_DEF_FG                   RC_FG(RC_DEFAULT)
    /* Set default background */
    #define RC_DEF_BG                   RC_BG(RC_DEFAULT)


    /*----- Set attributes for text ------------------------------------------*/
    /* Set foreground color */
    #define RC_F(F, T)                  RC__CSI(RC_FG(F)) T
    /* Set background color */
    #define RC_B(B, T)                  RC__CSI(RC_BG(B)) T
    /* Set style */
    #define RC_S(S, T)                  RC__CSI(S) T
    /* Set both foreground and background colors */
    #define RC_FB(F, B, T)              RC__CSI_SGR_2(RC_FG(F), RC_BG(B)) T
    /* Set both foreground color and style */
    #define RC_FS(F, S, T)              RC__CSI_SGR_2(RC_FG(F), S) T
    /* Set both background color and style */
    #define RC_BS(B, S, T)              RC__CSI_SGR_2(RC_BG(B), S) T
    /* Set all foreground and background colors and style */
    #define RC_FBS(F, B, S, T)          RC__CSI_SGR_3(RC_FG(F), RC_BG(B), S) T


    /*----- Remove attributes from text --------------------------------------*/
    /* Remove foreground color */
    #define RC_XF(T)                    RC__CSI(RC_DEF_FG) T
    /* Remove background color */
    #define RC_XB(T)                    RC__CSI(RC_DEF_BG) T
    /* Remove style */
    #define RC_XS(T)                    RC__CSI(RC_NORMAL) T
    /* Remove both foreground and background colors */
    #define RC_XFB(T)                   RC__CSI_SGR_2(RC_DEF_FG, RC_DEF_BG) T
    /* Remove both foreground color and style */
    #define RC_XFS(T)                   RC__CSI_SGR_2(RC_DEF_FG, RC_NORMAL) T
    /* Remove both background color and style */
    #define RC_XBS(T)                   RC__CSI_SGR_2(RC_DEF_BG, RC_NORMAL) T
    /* Remove all foreground and background colors and style */
    #define RC_XFBS(T)                  RC__CSI(RC_NONE) T

#endif /* MONOCORN */
#endif /* RAINICORN_H_5627173524822710 */
