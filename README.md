# SystemProgrammingProject-Virtual_Piano
This is my system programming final project: Virtual Piano.

In the project, there are both hardware and software parts. 
In the hardware part, we built a piano with 8 pushbuttons and LEDs connected to an Arduino Nano. 
Each button press will light up its corresponding LED, according to the order of the buttons.
After programming the Arduino controller, you can connect it to the software using the RS-232 protocol. 
Every time a specific button is pressed, the corresponding note will be played, and the note will be written to a txt file.
You can operate the file from within our software and play what was previously played through the Arduino.

Additional features:
- You can play directly from the software.
- You can play and record into a file directly from the software.
- You can open the file containing the recorded data and view it using Notepad.
- You can send the recorded file for printing and print the musical notes.
- You can load a txt file containing musical notes into the software for playing.

* I've downloaded the audio from https://freesound.org/ 


arduino circuit:

![image](https://github.com/EdenTzuberi/SystemProgrammingProject-Virtual_Piano/assets/78656006/02cf0ab0-8059-4c85-8fbc-642bc5fe8fc1)

GUI:

![image](https://github.com/EdenTzuberi/SystemProgrammingProject-Virtual_Piano/assets/78656006/69e191a3-1793-40a4-8acf-09815a06a35d)

