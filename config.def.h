/* macro for conveniently specifying pathu and pathc below */
#define PATH(name)                      "/home/gioele/.local/bin/dwmblocks/"name

/* buffer size for capturing output of the programs used for updating blocks */
#define CMDOUTLENGTH                    50

/* DELIMITERENDCHAR must be less than 32.
 * At max, DELIMITERENDCHAR - 1 number of clickable blocks are allowed.
 * Raw characters larger than DELIMITERENDCHAR and smaller than ' ' in ASCII
   character set can be used for signaling color change in status.
 * The character corresponding to DELIMITERENDCHAR + 1 ('\x0b' when
   DELIMITERENDCHAR is 10) will switch the active colorscheme to the first one
   defined in colors array in dwm's config.h and so on.
 * If you wish to change DELIMITERENDCHAR, don't forget to update its value in
   dwm.c and color codes in your pathu programs. */
#define DELIMITERENDCHAR                10

/* delimiter specified as an array of characters
 * (don't remove DELIMITERENDCHAR at the end) */
static const char delimiter[] = { ' ', '|', ' ', DELIMITERENDCHAR };

#include "block.h"

/* If interval of a block is set to 0, the block will only be updated once at
   startup.
 * If interval is set to a negative value, the block will never be updated in
   the main loop.
 * Set pathc to NULL if clickability is not required for the block.
 * Set signal to 0 if both clickability and signaling are not required for the
   block.
 * Signal must be less than DELIMITERENDCHAR for clickable blocks.
 * If multiple signals are pending, then the lowest numbered one will be
   delivered first. */

/* pathu - path of the program whose output is used as status text of the block
           (output of the program should be a single line of text with at most
            one newline character at the end)
 * pathc - path of the program used for handling clicks on the block */

/* 1 interval = INTERVALs seconds, INTERVALn nanoseconds */
#define INTERVALs                       1
#define INTERVALn                       0

static Block blocks[] = {
/*      pathu                           pathc                           interval        signal */
        { PATH("st_media.sh"),          PATH("st_media_toggle.sh"),     1,              1},
        { PATH("st_volume.sh"),         PATH("st_volume_button.sh"),    0,              8},
        { PATH("st_net.sh"),            PATH("st_net_button.sh"),       5,              2},
        { PATH("st_battery.sh"),        NULL,                           30,             0},
        { PATH("st_calendar.sh"),       NULL,                           10,             0},
        { NULL } /* just to mark the end of the array */
};
