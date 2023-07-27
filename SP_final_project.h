/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1
#define  PANEL_QUITBUTTON                 2       /* control type: command, callback function: QuitCallback */
#define  PANEL_do2                        3       /* control type: toggle, callback function: PlayControlSound */
#define  PANEL_si                         4       /* control type: toggle, callback function: PlayControlSound */
#define  PANEL_fa                         5       /* control type: toggle, callback function: PlayControlSound */
#define  PANEL_la                         6       /* control type: toggle, callback function: PlayControlSound */
#define  PANEL_sol                        7       /* control type: toggle, callback function: PlayControlSound */
#define  PANEL_mi                         8       /* control type: toggle, callback function: PlayControlSound */
#define  PANEL_re                         9       /* control type: toggle, callback function: PlayControlSound */
#define  PANEL_do1                        10      /* control type: toggle, callback function: PlayControlSound */
#define  PANEL_load_file                  11      /* control type: command, callback function: load_file */
#define  PANEL_play_to_file               12      /* control type: command, callback function: play_to_file */
#define  PANEL_STRING                     13      /* control type: string, callback function: (none) */
#define  PANEL_STRING_2                   14      /* control type: string, callback function: (none) */
#define  PANEL_PLAY_FROM_ARDUINO          15      /* control type: command, callback function: PlayFromArduino */
#define  PANEL_STOP                       16      /* control type: command, callback function: STOP */
#define  PANEL_TIMER                      17      /* control type: timer, callback function: TIMER */
#define  PANEL_LED                        18      /* control type: LED, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

#define  MENUBAR                          1
#define  MENUBAR_open_file                2       /* callback function: open_file */
#define  MENUBAR_print_text_file          3       /* callback function: print_text_file */


     /* Callback Prototypes: */

int  CVICALLBACK load_file(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK open_file(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK play_to_file(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PlayControlSound(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PlayFromArduino(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK print_text_file(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK STOP(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TIMER(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
