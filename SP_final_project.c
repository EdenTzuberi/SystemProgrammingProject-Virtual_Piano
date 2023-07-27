#include <cvirte.h>		
#include <userint.h>
#include <windows.h>
#include <utility.h>
#include <rs232.h>
#include <ansi_c.h>
#include <mmsystem.h>
#include <stdlib.h>  
#include "SP_final_project.h"

#define SIZE 100

// Sagi Barazani 206780314
// Eden Tzuberi  208945543

static int panelHandle;

int COM = 4;   // Communication port.
int mode = -1; // Mode:   mode = -1 for no mode was choosing.
               //         mode = 0  for writing to file from arduino.
               //         mode = 1  for reading from file.


int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "SP_final_project.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

int CVICALLBACK QuitCallback (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_ENABLED, 0);
			SetCtrlAttribute (panelHandle, PANEL_LED, ATTR_CTRL_VAL, 0);
			QuitUserInterface (0);
			break;
	}
	return 0;
}


// The function will play a sound through control and write to file if mode == 0 //
// When mode == 0 the function will write to file                                //
// The function uses PlaySound() from WinMM.lib - library for Multimedia API     //

int CVICALLBACK PlayControlSound (int panel, int control, int event,
					void *callbackData, int eventData1, int eventData2)
{
	FILE *fp;	//pointer to file
	
	switch (event)
	{
		case EVENT_COMMIT:
			switch(control)
			{
				case 10:
				{
			 		PlaySound ("316899__jaz_the_man_2__do-stretched_new", 0, SND_FILENAME);
					if(mode == 0)
					{
						fp = fopen("output.txt", "a");
						fprintf(fp, "%s\n", "do1");
						fclose(fp);
					}
			  		break;
				}
				case 9:
				{
			  		PlaySound ("316909__jaz_the_man_2__re-stretched_new.wav", 0, SND_FILENAME);
					if(mode == 0)
					{
						fp = fopen("output.txt", "a");
						fprintf(fp, "%s\n", "re");
						fclose(fp);
					}
			  		break;
				}
				case 8:
				{
			  		PlaySound ("316907__jaz_the_man_2__mi-stretched_new.wav", 0, SND_FILENAME);
					if(mode == 0)
					{
						fp = fopen("output.txt", "a");
						fprintf(fp, "%s\n", "mi");
						fclose(fp);
					}
			  		break;
				}
				case 7:
				{
			  		PlaySound ("316911__jaz_the_man_2__sol-stretched_new.wav", 0, SND_FILENAME);
					if(mode == 0)
					{
						fp = fopen("output.txt", "a");
						fprintf(fp, "%s\n", "sol");
						fclose(fp);
					}
			  		break;
				}
				case 6:
				{
			  		PlaySound ("316903__jaz_the_man_2__la-stretched_new.wav", 0, SND_FILENAME);
					if(mode == 0)
					{
						fp = fopen("output.txt", "a");
						fprintf(fp, "%s\n", "la");
						fclose(fp);
					}
			  		break;
				}
				case 5:
				{
			  		PlaySound ("316905__jaz_the_man_2__fa-stretched_new.wav", 0, SND_FILENAME);
					if(mode == 0)
					{
						fp = fopen("output.txt", "a");
						fprintf(fp, "%s\n", "fa");
						fclose(fp);
					}
			  		break;
				}
				case 4:
				{
			  		PlaySound ("386726__luckylux__si_new.wav", 0, SND_FILENAME);
					if(mode == 0)
					{
						fp = fopen("output.txt", "a");
						fprintf(fp, "%s\n", "si");
						fclose(fp);
					}
			  		break;
				}
				case 3:
				{
			  		PlaySound ("316901__jaz_the_man_2__do-octave_new.wav", 0, SND_FILENAME);
					if(mode == 0)
					{
						fp = fopen("output.txt", "a");
						fprintf(fp, "%s\n", "do2");
						fclose(fp);
					}
			  		break;
				}
		
			}
			
			break;
	}
	return 0;
}

// The function will play to text file the notes, by changing mode to 0 //
int CVICALLBACK play_to_file (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			mode = 0;
			SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_ENABLED, 0);
			break;
	}
	return 0;
}


// The function will load a text file with notes and will play it //

int CVICALLBACK load_file(int panel, int control, int event,
                          void* callbackData, int eventData1, int eventData2)
{
    
	char path_name[260];
	FILE* file;
    char note[100];
    
	
	switch (event)
    {
        case EVENT_COMMIT:
            mode = 1;
			SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_ENABLED, 0);
			
            // Prompt the user to select a file
            int ret = FileSelectPopup("", "*.*", ".txt", "Select a file", VAL_LOAD_BUTTON, 0, 0, 1, 0, path_name);
            if (ret == VAL_NO_FILE_SELECTED) {
                printf("No file selected.\n");
                return 0;
            }

            // Open the file in read mode
            file = fopen(path_name, "r");
            if (file == NULL) {
                printf("Unable to open the file.\n");
                return 0;
            }

            // Read and play each note from the file
            while (fgets(note, sizeof(note), file))
            {
                // Remove newline character from the note
                note[strcspn(note, "\n")] = '\0';

                // Play the note based on its value
				if (strcmp(note, "/n") == 0);
                else if (strcmp(note, "do1") == 0)
                    PlaySound("316899__jaz_the_man_2__do-stretched_new.wav", 0, SND_FILENAME);
                else if (strcmp(note, "re") == 0)
                    PlaySound("316909__jaz_the_man_2__re-stretched_new.wav", 0, SND_FILENAME);
                else if (strcmp(note, "mi") == 0)
                    PlaySound("316907__jaz_the_man_2__mi-stretched_new.wav", 0, SND_FILENAME);
                else if (strcmp(note, "sol") == 0)
                    PlaySound("316911__jaz_the_man_2__sol-stretched_new.wav", 0, SND_FILENAME);
                else if (strcmp(note, "la") == 0)
                    PlaySound("316903__jaz_the_man_2__la-stretched_new.wav", 0, SND_FILENAME);
                else if (strcmp(note, "fa") == 0)
                    PlaySound("316905__jaz_the_man_2__fa-stretched_new.wav", 0, SND_FILENAME);
                else if (strcmp(note, "si") == 0)
                    PlaySound("386726__luckylux__si_new.wav", 0, SND_FILENAME);
                else if (strcmp(note, "do2") == 0)
                    PlaySound("316901__jaz_the_man_2__do-octave_new.wav", 0, SND_FILENAME);
                
            }

            // Close the file
            fclose(file);

            break;
    }

    return 0;
}

int CVICALLBACK PlayFromArduino (int panel, int control, int event,
                                 void *callbackData, int eventData1, int eventData2)
{
    
	switch (event)
    {
        case EVENT_COMMIT:
            mode = 0;
			SetCtrlAttribute (panelHandle, PANEL_LED, ATTR_CTRL_VAL, 1);
			SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_ENABLED, 1);
            break;
    }

    return 0;
}



// The function TIMER will play the arduino sound, 			  //
// the function will be turn on through PlayFromArduino function //

int CVICALLBACK TIMER (int panel, int control, int event,
					   void *callbackData, int eventData1, int eventData2)
{
	FILE *fp = fopen("output.txt", "a");;	//pointer to file 
	
	switch (event)
	{
		case EVENT_TIMER_TICK:
			
			int arduinoValue = 0;
            char readBuffer[10];
            int bytesRead = 0;
			
            // Open the RS-232 port
			OpenComConfig (COM, "", 115200, 0, 8, 1, 512, 512);

            // Write a request to the Arduino
            char request[] = "READ_VALUE\n";
            int bytesWritten = ComWrt(COM, request, strlen(request));
            if (bytesWritten < 0) {
                printf("Failed to write request to the Arduino.\n");
                CloseCom(COM);
                return 0;
            }

			bytesRead = ComRdTerm(COM, readBuffer, sizeof(readBuffer) - 1, '\n');
			if (bytesRead >= 0) {
			    readBuffer[bytesRead] = '\0';  // Add null character at the end
			} else {
			    printf("Failed to read response from the Arduino.\n");
			    CloseCom(COM);
			    return 0;
			}

			SetCtrlAttribute (panelHandle, PANEL_do1, ATTR_DIMMED, 0);
			SetCtrlAttribute (panelHandle, PANEL_re, ATTR_DIMMED, 0);
			SetCtrlAttribute (panelHandle, PANEL_mi, ATTR_DIMMED, 0);
			SetCtrlAttribute (panelHandle, PANEL_fa, ATTR_DIMMED, 0);
			SetCtrlAttribute (panelHandle, PANEL_sol, ATTR_DIMMED, 0);
			SetCtrlAttribute (panelHandle, PANEL_la, ATTR_DIMMED, 0);
			SetCtrlAttribute (panelHandle, PANEL_si, ATTR_DIMMED, 0);
			SetCtrlAttribute (panelHandle, PANEL_do2, ATTR_DIMMED, 0);
			
            // Convert the read value to an integer
            if(readBuffer[0] != '\0')
			{
				arduinoValue = atoi(readBuffer);
				if (arduinoValue == 1)
				{
				   PlaySound("316899__jaz_the_man_2__do-stretched_new", 0, SND_FILENAME);
				   SetCtrlAttribute (panelHandle, PANEL_do1, ATTR_DIMMED, 1);
				   fprintf(fp, "%s\n", "do1");
				}
				else if (arduinoValue == 2)
				{
				   PlaySound("316909__jaz_the_man_2__re-stretched_new.wav", 0, SND_FILENAME);
				   SetCtrlAttribute (panelHandle, PANEL_re, ATTR_DIMMED, 1);
				   fprintf(fp, "%s\n", "re");
				   
				}
				else if (arduinoValue == 3)
				{
				   PlaySound("316907__jaz_the_man_2__mi-stretched_new.wav", 0, SND_FILENAME);
				   SetCtrlAttribute (panelHandle, PANEL_mi, ATTR_DIMMED, 1);
				   fprintf(fp, "%s\n", "mi");
				}
				else if (arduinoValue == 4)
				{
				   PlaySound("316905__jaz_the_man_2__fa-stretched_new.wav", 0, SND_FILENAME);
				   SetCtrlAttribute (panelHandle, PANEL_fa, ATTR_DIMMED, 1);
				   fprintf(fp, "%s\n", "fa");
				}
				else if (arduinoValue == 5)
				{
				   PlaySound("316911__jaz_the_man_2__sol-stretched_new.wav", 0, SND_FILENAME);
				   SetCtrlAttribute (panelHandle, PANEL_sol, ATTR_DIMMED, 1);
				   fprintf(fp, "%s\n", "sol");
				}
				
				else if (arduinoValue == 6)
				{
				   PlaySound("316903__jaz_the_man_2__la-stretched_new.wav", 0, SND_FILENAME);
				   SetCtrlAttribute (panelHandle, PANEL_la, ATTR_DIMMED, 1);
				   fprintf(fp, "%s\n", "la");
				}
				else if (arduinoValue == 7)
				{
				   PlaySound("386726__luckylux__si_new.wav", 0, SND_FILENAME);
				   SetCtrlAttribute (panelHandle, PANEL_si, ATTR_DIMMED, 1);
				   fprintf(fp, "%s\n", "si");
				}
					
				else if (arduinoValue == 8)
				{
				 	PlaySound("316901__jaz_the_man_2__do-octave_new.wav", 0, SND_FILENAME);
				    SetCtrlAttribute (panelHandle, PANEL_do2, ATTR_DIMMED, 1);
					fprintf(fp, "%s\n", "do2");
				}
				
				fclose(fp); 
			
			}
			
			

			break;
	}
	return 0;
}

// The function STOP will stop playing from the arduino by turning the timer function off//

int CVICALLBACK STOP (int panel, int control, int event,
					  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			mode = -1;
			SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_ENABLED, 0);
			SetCtrlAttribute (panelHandle, PANEL_LED, ATTR_CTRL_VAL, 0);
			break;
	}
	return 0;
}

// The function will print the text file to the default printer.

void CVICALLBACK print_text_file(int menubar, int menuItem, void *callbackData, int panel)
{
	SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_ENABLED, 0);
	PrintTextFile ("c:\\Users\\Eden Tzuberi\\Desktop\\SP_final_project\\output.txt", "");
}

// The function will open the text file through notepad.

void open_file (int menubar, int menuItem, void *callbackData, int panel) 
{
    SetCtrlAttribute (panelHandle, PANEL_TIMER, ATTR_ENABLED, 0);
	system ("notepad c:\\Users\\Eden Tzuberi\\Desktop\\SP_final_project\\output.txt");
}

