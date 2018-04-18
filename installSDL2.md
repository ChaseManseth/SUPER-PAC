# SUPER-PAC
This is a PAC-MAN game made in c++. Authors include Chase Manseth, Zachary Steudel, Meghan Bibb, Will Rhoden, and Bailey Stone.

# Installation of SDL Plotter + SDL Mixer (Windows Only || RIP MAC)
As you might have noticed there are two files in this project. The SDL files contains all header files you'll need for the Pac-Man project. The DLL files are also present as a runtime library for your computer.

1. Download the project as a zip file by clicking the green button that says clone or download. ![Download Button](https://i.gyazo.com/e27cb695392d5288e8901810911eeff4.png "Download Button")

2. Save the SDL file somewhere on your computer. In my case I have it in C:\SDL
![SDL](https://i.gyazo.com/66a0866aa7c79696b0e7e63953137b70.png "SDL")

3. Copy the dll files (Not the folder) and paste it in C:\Windows\SysWOW64 and you're almost there!

4. Create a test project in Code Blocks and copy Dr. Booth's [SDL_Plotter.h](http://csi-info.baylor.edu/upload/download/SDL_Plotter.h) into your project and in your main.cpp also add Dr. Booth's sample program to test [SDL_Plotter API](https://classnotes.ecs.baylor.edu/wiki/SDL_Plotter_API) 

5. In Code Blocks click Project - > Properties 
![Project Properties](https://i.gyazo.com/0422e04f491946bb9c34d31e09e22226.png "Project Properties")

A prompt like such should open 
![Project Properties Prompt](https://i.gyazo.com/e66a32ebfcbf0e2f59c353ee4d237c3d.png "Project Properties Prompt")

Click "Project's Build options..." on the bottom right hand corner of the prompt and another prompt should open up 
![Project Properties build Prompt](https://i.gyazo.com/0c131ae8509fadf08888c5208f492c5e.png "Project Properties build Prompt")

6. Click the Linker Settings tab and add -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer to the Other linker options input box like so: 
![Linker options](https://i.gyazo.com/5e0a4f80d60227d8fc65fb10300ee7f1.png "Linker options")

7. Click on the Search directories tab next then click the Compiler sub-tab. Click add and file the SDL include file. Once you find the file location it will ask you if you want to save it as a relative path. Click NO. If you saved the SDL file in the same location as me it should look like this: 
![Compiler settings](https://i.gyazo.com/e0495041846190d9289becfe47f40b33.png "Compiler settings")

8. Next Click on the Linker sub-tab and add a new reference. Find your SDL lib file and add it to the linker refrence. It will ask again if you would like to save this as a relitave path, just click no. If you saved your SDL file in the same directory as me it should look like this:
![Linker settings](https://i.gyazo.com/5963fbf8a499b7f0f028c42ee093216d.png "Linker settings")

9. Click OK on both prompts and you should be good to go. Build and Run the project and you should be good to go!

If you have any questions with the installation just message me in the group chat and I should respond ASAP! Hope it works first time.
