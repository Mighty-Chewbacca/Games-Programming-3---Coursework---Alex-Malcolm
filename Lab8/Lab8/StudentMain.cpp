#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN
#define GLX_GLXEXT_LEGACY //Must be declared so that our local glxext.h is picked up, rather than the system one
//#define _CRT_SECURE_NO_WARNINGS needed this to supress a warning from when i was attempting shaders


//#include <windows.h>
//#include "GL\glew.h"
#include "GameConstants.h"
#include "windowOGL.h"
#include "cWNDManager.h"
#include "cColours.h"
#include "cShapes.h"
#include "cPyramid.h"
#include "cCube.h"
#include "cSphere.h"
#include "cMaterial.h"
#include "cLight.h"
#include "cStarfield.h"
#include "cFontMgr.h"
#include "cCamera.h"
#include "cInputMgr.h"
#include "cModelLoader.h"
#include "cModel.h"
#include "cPlayer.h"
#include "cWall.h"
#include "wallManager.h"
#include "cFpsCamera.h"
#include "AIEnemy.h"
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include "cTopDownCamera.h"
#include "cSoundMgr.h"
#include "cSound.h"
#include "cRotatingCam.h"

//#include <assimp/Importer.hpp>      // C++ importer interface
//#include <assimp/scene.h>           // Output data structure
//#include <assimp/postprocess.h>     // Post processing fla

////global shader thingys
//GLuint p, v, f;
//
////using this from lighthouse 3d to read the shader from the file
//char *textFileRead(char *fn) 
//{
//
//
//	FILE *fp;
//	char *content = NULL;
//
//	int count = 0;
//
//	if (fn != NULL) {
//		fp = fopen(fn, "rt");
//
//		if (fp != NULL) {
//
//			fseek(fp, 0, SEEK_END);
//			count = ftell(fp);
//			rewind(fp);
//
//			if (count > 0) {
//				content = (char *)malloc(sizeof(char)* (count + 1));
//				count = fread(content, sizeof(char), count, fp);
//				content[count] = '\0';
//			}
//			fclose(fp);
//		}
//	}
//	return content;
//}
//
////using this to create, compile and cal the read for the shaders
//void setShaders() {
//
//	char *vs, *fs;
//
//	v = glCreateShader(GL_VERTEX_SHADER);
//	f = glCreateShader(GL_FRAGMENT_SHADER);
//
//	vs = textFileRead("/shaders/toon.vert");
//	fs = textFileRead("/shaders/toon.frag");
//
//	const char * vv = vs;
//	const char * ff = fs;
//
//	glShaderSource(v, 1, &vv, NULL);
//	glShaderSource(f, 1, &ff, NULL);
//
//	free(vs); free(fs);
//
//	glCompileShader(v);
//	glCompileShader(f);
//
//	p = glCreateProgram();
//
//	glAttachShader(p, v);
//	glAttachShader(p, f);
//
//	glLinkProgram(p);
//	glUseProgram(p);
//}

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR cmdLine,
	int cmdShow)
{

	//creating the output console, using this for debugging and to show the enemy ai pathfinding working to its extent.
	//it also shows messages when some important variables are changed such as debugging mode or sound
	AllocConsole();

	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	int hCrt = _open_osfhandle((long)handle_out, _O_TEXT);
	FILE* hf_out = _fdopen(hCrt, "w");
	setvbuf(hf_out, NULL, _IONBF, 1);
	*stdout = *hf_out;

	std::cout << "Console Window Created Successfully " << std::endl;

	//Set our window settings chose these as they are the size of my monitor and using the mouse for looking made sense to having it close to fullscreen
	//fonts will break if these values are different though, as they are static and not scaled depending on window size.

	const int windowWidth = 1920;
	const int windowHeight = 1080;
	const int windowBPP = 16;

	//This is our window
	static cWNDManager* pgmWNDMgr = cWNDManager::getInstance();

	// This is the input manager
	static cInputMgr* theInputMgr = cInputMgr::getInstance();

	// This is the Font manager
	static cFontMgr* theFontMgr = cFontMgr::getInstance();

	//creating the sound manager
	static cSoundMgr* theSoundMgr = cSoundMgr::getInstance();

	//The example OpenGL code
	windowOGL theOGLWnd;

	//Attach our example to our window
	pgmWNDMgr->attachOGLWnd(&theOGLWnd);

	// Attach the keyboard manager
	pgmWNDMgr->attachInputMgr(theInputMgr);

	//Attempt to create the window
	if (!pgmWNDMgr->createWND(windowWidth, windowHeight, windowBPP))
	{
		//If it fails

		MessageBox(NULL, "Unable to create the OpenGL Window", "An error occurred", MB_ICONERROR | MB_OK);
		pgmWNDMgr->destroyWND(); //Reset the display and exit
		return 1;
	}

	if (!theOGLWnd.initOGL(windowWidth, windowHeight)) //Initialize our example
	{
		MessageBox(NULL, "Could not initialize the application", "An error occurred", MB_ICONERROR | MB_OK);
		pgmWNDMgr->destroyWND(); //Reset the display and exit
		return 1;
	}

	//init glew and check that it is done properly -- need this for my shaders
	//glewInit();
	//if (glewIsSupported("GL_VERSION_2_0"))
	//	printf("Ready for OpenGL 2.0\n");
	//else {
	//	printf("OpenGL 2.0 not supported\n");
	//	exit(1);
	//}

	//if (glewInit() != GLEW_OK)
	//{
	//	printf("Glew did not init properly\n");
	//	exit(1);
	//}
	//else
	//{
	//	printf("Glew init properly\n");
	//};

	//setShaders();
	//glutMainLoop(); //NOT SURE IF THIS IS IN THE RIGHT PLACE    /shaders not working so disabled;

	// Create Textures - complex image textures didnt work or skin properly, so i created a small single colour image that shows that i can put
	//different textures on different objects
	cTexture redTexture, greenTexture, green2Texture, exitTex, starTexture;
	redTexture.createTexture("Models/RedIsh.jpg");
	greenTexture.createTexture("Models/GreenyBlue.jpg");
	green2Texture.createTexture("Models/Green.jpg");
	exitTex.createTexture("Models/Exit.jpg");
	starTexture.createTexture("Images/star.png");

	//enemy stuff
	//create enemy Ai class instance, creating this will ge tthe Ai to choose a destination and then find a path to it. ignoring spaces that would be a wall
	AIEnemy theenemy;
	//load in a model for the enemy, as it is not fully working I am just going to load one of the supplied models instead of taking time to create or
	//source a working model
	cModelLoader enemyModel;
	enemyModel.loadModel("Models/laser.obj", redTexture);
	//create an wall object to represent the enemy (really badly named class, its really more of a gameobject, it was just that it was my intention to create
	//a class for each gameobject type, then a realised that i dont need it.)
	cWall Enemy;
	Enemy.setMdlDimensions(enemyModel.getModelDimensions());
	Enemy.setPosition(theenemy.getFirstPosition());
	Enemy.setScale(glm::vec3(4, 4, 4));

	//create the wall manager, this will create the walls, place them and get ready to render them all
	wallManager theWallManager;

	// the starfield
	cStarfield theStarField(starTexture.getTexture(), glm::vec3(100.0f, 100.0f, 100.0f));

	// Create Materials for lights
	cMaterial sunMaterial(lightColour4(0.0f, 0.0f, 0.0f, 1.0f), lightColour4(1.0f, 1.0f, 1.0f, 1.0f), lightColour4(1.0f, 1.0f, 1.0f, 1.0f), lightColour4(0, 0, 0, 1.0f), 5.0f);
	//create the lights now, only one is used in the menu scene, then the others are all used in the levels - seem a bit buggy though
	// i think im passing in the wrong directions
	// Create Light1
	cLight sunLight1(GL_LIGHT0, lightColour4(0, 0, 0, 1), lightColour4(1, 1, 1, 1), lightColour4(1, 1, 1, 1), glm::vec4(0, 0, 20, 1),
		glm::vec3(0.0, 0.0, 1.0), 0.0f, 180.0f, 1.0f, 0.0f, 0.0f);
	// Create Light2
	cLight sunLight2(GL_LIGHT2, lightColour4(0, 0, 0, 1), lightColour4(1, 1, 1, 1), lightColour4(1, 1, 1, 1), glm::vec4(20, 0, 0, 1),
		glm::vec3(1.0, 0.0, 0.0), 0.0f, 180.0f, 1.0f, 0.0f, 0.0f);
	// Create Light3
	cLight sunLight3(GL_LIGHT3, lightColour4(0, 0, 0, 1), lightColour4(1, 1, 1, 1), lightColour4(1, 1, 1, 1), glm::vec4(0, 0, 0, 1),
		glm::vec3(1.0, 0.0, 1.0), 0.0f, 180.0f, 1.0f, 0.0f, 0.0f);
	// Create Light4
	cLight sunLight4(GL_LIGHT4, lightColour4(0, 0, 0, 1), lightColour4(1, 1, 1, 1), lightColour4(1, 1, 1, 1), glm::vec4(20, 0, 20, 1),
		glm::vec3(0.0, 0.0, 0.0), 0.0f, 180.0f, 1.0f, 0.0f, 0.0f);

	// Create torch light - doesnt work
	cLight torchLight(GL_LIGHT1, lightColour4(0, 0, 0, 1), lightColour4(1, 1, 1, 1), lightColour4(1, 1, 1, 1), glm::vec4(0, 0, 20, 1),
		glm::vec3(0.0, 0.0, 1.0), 0.0f, 90.0f, 1.0f, 0.0f, 0.0f);

	//Define Ambient light for scene
	GLfloat g_Ambient[] = { 0.2, 0.2, 0.2, 20.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, g_Ambient);

	// load game fonts
	// Load Fonts
	LPCSTR gameFonts[3] = { "Fonts/digital-7.ttf", "Fonts/space age.ttf", "Fonts/doctor_who.ttf" };

	theFontMgr->addFont("SevenSeg", gameFonts[0], 24);
	theFontMgr->addFont("Space", gameFonts[1], 24);
	theFontMgr->addFont("DrWho", gameFonts[2], 48);
	theFontMgr->addFont("DrWhoLarge", gameFonts[2], 72);
	theFontMgr->addFont("DrWhoXLarge", gameFonts[2], 96);


	// load game sounds
	LPCSTR gameSounds[7] = { "Audio/who10Edit.wav", "Audio/shot007.wav", "Audio/explosion2.wav", "Audio/bttf.wav", "Audio/footstep.wav",
		"Audio/pacman_eatfruit.wav", "Audio/pacman_death.wav"  };

	theSoundMgr->add("Theme", gameSounds[3]);
	theSoundMgr->add("Shot", gameSounds[1]);
	theSoundMgr->add("Explosion", gameSounds[2]);
	theSoundMgr->add("step", gameSounds[4]);
	theSoundMgr->add("success", gameSounds[5]);
	theSoundMgr->add("fail", gameSounds[6]);


	//create the first person camera (will be a mix of first and third person, as it is positions slightly above the player model.)
	//then i need to attach the input manager, as this is the only camera that is needing input
	cFpsCamera fpsCam;
	fpsCam.attachInputMgr(theInputMgr);
	fpsCam.Update(0.0f);

	//create the rotating camera that is used in the menu
	cRotatingCam menuCam;
	menuCam.Update(0.0f);

	//create the top down camera which is used as my map and toggled using numpad 8
	cTopDownCamera mapCam;
	mapCam.Update(0.0f);

	//Clear key buffers
	theInputMgr->clearBuffers(theInputMgr->KEYS_DOWN_BUFFER | theInputMgr->KEYS_PRESSED_BUFFER);

	// Models for the main objects
	//tardis model, used in main menu and as the player model. very hard to see in the level as its directly below you and the textures dont work!
	//but its there
	cModelLoader tardisMdl;
	tardisMdl.loadModel("Models/tardis1314.obj", redTexture); // Player
	//the ground plane
	cModelLoader groundModel;
	groundModel.loadModel("Models/groundPlane.obj", green2Texture);
	//the player model, this model is only used as the collision for the player as i am able to control the dimensions and such easier than the tardis,
	//because i modeled it myself (yeah i know, its only a cuboid :P)
	cModelLoader playerModel;
	playerModel.loadModel("Models/WallCube.obj", redTexture);
	//circle with the word exit in the centre - acts as the exit trigger
	cModelLoader exitModel;
	exitModel.loadModel("Models/exit.obj", exitTex);
	//eye shaped model, is the pickup to signify the ability to change views to the map
	cModelLoader mapPickupModel;
	mapPickupModel.loadModel("Models/mapEye.obj", exitTex);

	//create the pickup gameobject, give it its sizes and stuff
	cWall mapPickup;
	mapPickup.initialise(glm::vec3(7.5, 0, 7.5), 0.0f, glm::vec3(1, 1, 1), glm::vec3(0, 0, 0), 5.0f, true);
	mapPickup.setMdlDimensions(mapPickupModel.getModelDimensions());
	mapPickup.setScale(glm::vec3(0.25, 0.25, 0.25));
	//same with the exit
	cWall exit;
	exit.initialise(glm::vec3(10, 0, 10), 0.0f, glm::vec3(0.25f, 0.25f, 0.25f), glm::vec3(0, 0, 0), 5.0f, true);
	exit.setMdlDimensions(exitModel.getModelDimensions());
	//same with the test wall for the demo level
	cWall level0Wall;
	level0Wall.initialise(glm::vec3(15, 0, 15), 0.0f, glm::vec3(1, 1, 1), glm::vec3(0, 0, 0), 5.0f, true);
	level0Wall.setMdlDimensions(playerModel.getModelDimensions());

	//create theplayer, using the cuboid not the tardis, the tardis will just be rendered in place of the cube!
	cPlayer thePlayer;
	thePlayer.initialise(glm::vec3(2, 10, 2), 0.0f, glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0, 0, 0), 5.0f, true);
	thePlayer.setMdlDimensions(playerModel.getModelDimensions());
	thePlayer.setScale(glm::vec3(0.5f, 0.5f, 0.5f));
	thePlayer.attachInputMgr(theInputMgr);
	thePlayer.attachSoundMgr(theSoundMgr);

	//the time that the player has been in the game
	float tCount = 0.0f;
	string outputMsg;

	//game neccesary variables
	//is the play option highlighted in the menu
	bool playSelected = true;
	//is the exit option highlighted in the menu
	bool exitSelected = false;
	//is the help option highlighted in the menu
	bool helpSelected = false;
	//is the controls options highlighted in the menu
	bool controlsSelected = false;
	//is the about option highlighted in the menu
	bool aboutSelected = false;
	//are we in the first or second tier of the menu?
	bool inT2Menu = false;
	//is it the pause menu or regular
	bool pauseMenu = false;

	float previousElapsedTime = 0.0f;
	//current level, lowest 0, max 1
	int levelNumber = 0;
	//is the player in the map?
	bool inMap = false;
	//are we in the menu because all levels were completed
	bool endgame = false;
	//is the sound allowed to play?
	bool soundPlaying = true;
	//number of times the player can access the map
	int mapUses = 5;
	//was the map pickup picked up
	bool mapPickupGotten = false;
	//bool killed = false;

	//play the theme music and loop it
	theSoundMgr->getSnd("Theme")->playAudio(AL_LOOPING);

	//glClearColor(1, 1, 1, 1); changes background to white
	//set the mouse to the center of the screen at the start
	SetCursorPos(GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2); 

	//This is the mainloop, we render frames until isRunning returns false
	while (pgmWNDMgr->isWNDRunning())
	{
		pgmWNDMgr->processWNDEvents(); //Process any window events, do this for all loops of the game, menu and levels.

		//We get the time that passed since the last frame
		float elapsedTime = pgmWNDMgr->getElapsedSeconds();

		//as there is only level 0 and 1, as soon as level 1 is complete it will not let you leave the menu till you restart the game
		if (levelNumber > 1)
		{
			inMenu = true;
			endgame = true;

		}

		//if you are in the menu and not the game
		if (inMenu)
		{
			//initialise glstuffs and get the viewports ready with the view matrix from the camera
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			theOGLWnd.initOGL(windowWidth, windowHeight);

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			//use the menu camera, which rotates around the origin
			glLoadMatrixf((GLfloat*)&menuCam.getViewMatrix());

			//update the menu camera, pass in elapsed time so that we can make the rotate update
			menuCam.Update(tCount);

			//render the stars and use the light
			theStarField.render(0.0f);
			sunMaterial.useMaterial();
			sunLight1.lightOn();

			//get all menu input now
			if (theInputMgr->isKeyDown(VK_RETURN))//if enter/return pressed
			{
				if (soundPlaying)
				theSoundMgr->getSnd("Shot")->playAudio(AL_TRUE); //only play the sound if sound is not muted

				if (playSelected) //if play is highlighted, start the game -if game previously complete reset neccesary variables
				{
					if (endgame) //reset to the first level if the game has been previously completed
					{
						levelNumber = 0;
						thePlayer.setPosition(glm::vec3(2, 10, 2));
					}
					inMenu = false;
					pauseMenu = false;
				}

				if (helpSelected) //if help selected go into second tier menu and let user choose the next option
				{
					inT2Menu = true;
					controlsSelected = true;
					aboutSelected = false;
				}

				if (exitSelected) //if help selected exit the game
				{
					theOGLWnd.shutdown(); //Free any resources
					pgmWNDMgr->destroyWND(); //Destroy the program window

					return 0; //Return success
				}
			}

			if (theInputMgr->isKeyDown(VK_ESCAPE)) //if escape is pressed 
			{
				if (soundPlaying)
				theSoundMgr->getSnd("Shot")->playAudio(AL_TRUE); //play sound as long as we are allowed to

				if (inT2Menu) //back to first tier
				{
					inT2Menu = false;
					controlsSelected = false;
					aboutSelected = false;
				}
			}

			if (theInputMgr->isKeyDown(VK_NUMPAD6)) //if numpad 6 is pressed toggle the sound
			{
				if (soundPlaying)
				{
					theSoundMgr->getSnd("Theme")->stopAudio();
					soundPlaying = false;
				}
				else
				{
					theSoundMgr->getSnd("Theme")->playAudio(AL_LOOPING);
					soundPlaying = true;
				}
			}

			if (theInputMgr->isKeyDown(VK_UP)) //if the up key is pressed move to the menu option above the current one
			{
				if (soundPlaying)
					theSoundMgr->getSnd("Shot")->playAudio(AL_TRUE); // play sound as long as we are allowed to

				if (inT2Menu == false) // if we are in the first tier menu cycle through the selected options
				{
					if (playSelected)
					{
						exitSelected = true;
						playSelected = false;
					}

					else if (helpSelected)
					{
						helpSelected = false;
						playSelected = true;
					}

					else if (exitSelected)
					{
						exitSelected = false;
						helpSelected = true;
					}
				}
				else if (inT2Menu == true) // if we are in the second tier menu cycle through the selected options
				{
					if (controlsSelected)
					{
						aboutSelected = true;
						controlsSelected = false;
					}
					else if (aboutSelected)
					{
						aboutSelected = false;
						controlsSelected = true;
					}
				}


			}
			if (theInputMgr->isKeyDown(VK_DOWN)) //if the down key is pressed, move to the option below the current pressed one
			{
				if (soundPlaying)
				theSoundMgr->getSnd("Shot")->playAudio(AL_TRUE);// play the button sound as long as we are allowed

				if (inT2Menu == false)// if we are in the first tier menu cycle through the selected options
				{
					if (playSelected)
					{
						helpSelected = true;
						playSelected = false;
					}

					else if (helpSelected)
					{
						helpSelected = false;
						exitSelected = true;
					}

					else if (exitSelected)
					{
						exitSelected = false;
						playSelected = true;
					}
				}
				else if (inT2Menu == true) // if we are in the second tier menu cycle through the selected options
				{
					if (controlsSelected)
					{
						aboutSelected = true;
						controlsSelected = false;
					}
					else if (aboutSelected)
					{
						aboutSelected = false;
						controlsSelected = true;
					}
				}
			}

			tardisMdl.renderMdl(glm::vec3(0, 10, 0), 0, glm::vec3(1, 1, 1)); //render the tardis in the middle of the scene

			glPushMatrix(); //push the matrix so we can get ready to render in the 2d ortho window - for text
			theOGLWnd.setOrtho2D(windowWidth, windowHeight);

			if (pauseMenu) //ifd we arepaused, say paused instead of menu
			{
				theFontMgr->getFont("DrWhoLarge")->printText("Paused", FTPoint(10, 400, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
			}
			else
			{
				theFontMgr->getFont("DrWhoLarge")->printText("Menu", FTPoint(10, 400, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
			}

			if (playSelected == true) // if play is selected make it blue, else make it green
			{
				if (pauseMenu)//if we are paused, say resume not play
				{
					theFontMgr->getFont("DrWho")->printText("Resume", FTPoint(10, 500, 0.0f), colour3f(0.0f, 0.0f, 100.0f));
				}
				else
				{
					theFontMgr->getFont("DrWho")->printText("Play", FTPoint(10, 500, 0.0f), colour3f(0.0f, 0.0f, 100.0f));
				}
			}
			else
			{
				if (pauseMenu)
				{
					theFontMgr->getFont("DrWho")->printText("Resume", FTPoint(10, 500, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
				}
				else
				{
					theFontMgr->getFont("DrWho")->printText("Play", FTPoint(10, 500, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
				}
			}
			if (helpSelected == true) //if help is selected make it blue else make it green
			{
				theFontMgr->getFont("DrWho")->printText("Help", FTPoint(10, 550, 0.0f), colour3f(0.0f, 0.0f, 100.0f));
			}
			else
			{
				theFontMgr->getFont("DrWho")->printText("Help", FTPoint(10, 550, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
			}
			if (exitSelected == true) //if exit is selected make it blue else make it green
			{
				theFontMgr->getFont("DrWho")->printText("Exit", FTPoint(10, 600, 0.0f), colour3f(0.0f, 0.0f, 100.0f));
			}
			else
			{
				theFontMgr->getFont("DrWho")->printText("Exit", FTPoint(10, 600, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
			}
			if (inT2Menu == true) //show the right stuff for the second tier
			{

				if (controlsSelected == true) //if controls is selected show all of the controls info on screen
				{
					theFontMgr->getFont("DrWho")->printText("Controls", FTPoint(150, 525, 0.0f), colour3f(0.0f, 0.0f, 100.0f));
					theFontMgr->getFont("DrWho")->printText("Use the Arrow keys or WASD to move around", FTPoint(350, 400, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
					theFontMgr->getFont("DrWho")->printText("Use the Mouse to look!", FTPoint(350, 450, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
					theFontMgr->getFont("DrWho")->printText("NumPad 0 to toggle debug mode.", FTPoint(350, 500, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
					theFontMgr->getFont("DrWho")->printText("ESC triggers the pause menu", FTPoint(350, 550, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
					theFontMgr->getFont("DrWho")->printText("numpad 6 will toggle the audio", FTPoint(350, 600, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
					theFontMgr->getFont("DrWho")->printText("numpad 8 will toggle map in level 0", FTPoint(350, 650, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
					theFontMgr->getFont("DrWho")->printText("but the map can only be used after collecting the pickup in the main level", FTPoint(400, 700, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
					theFontMgr->getFont("DrWho")->printText("numpad 9 will put the mouse in the center of the screen, only for debug", FTPoint(350, 750, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
					theFontMgr->getFont("DrWho")->printText("numpad 7 will toggle the collision detection", FTPoint(350, 800, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
				}
				else //just show the controls option
				{
					theFontMgr->getFont("DrWho")->printText("Controls", FTPoint(150, 525, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
				}
				if (aboutSelected == true) //if about is selected show the about stuff
				{
					theFontMgr->getFont("DrWho")->printText("About", FTPoint(150, 575, 0.0f), colour3f(0.0f, 0.0f, 100.0f));

					theFontMgr->getFont("DrWho")->printText("You are trapped in a maze, find your way to the exit!", FTPoint(350, 400, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
					theFontMgr->getFont("DrWho")->printText("There is a short demo level before the main level", FTPoint(350, 450, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
					theFontMgr->getFont("DrWho")->printText("It is used to show collision detection working,", FTPoint(350, 500, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
					theFontMgr->getFont("DrWho")->printText("and to show the multiple level 'loading' method working ", FTPoint(350, 550, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
					theFontMgr->getFont("DrWho")->printText("Navigate to the white exit to enter the main level", FTPoint(350, 600, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
					theFontMgr->getFont("DrWho")->printText("but feel free to play around to see the collision working in the tutorial", FTPoint(350, 650, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
					theFontMgr->getFont("DrWho")->printText("as it does not work as well in the second level.", FTPoint(350, 700, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
				}
				else //just show about
				{
					theFontMgr->getFont("DrWho")->printText("About", FTPoint(150, 575, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
				}
			}

			if (endgame) //if the game was previously completed show well done message
			{
				theFontMgr->getFont("DrWho")->printText("Well Done, you complete both levels", FTPoint(150, 150, 0.0f), colour3f(0.0f, 255.0f, 0.0f));
			}
		}
		else //we are out of the menu and in one of the levels of the game
		{
			//get universal input that is used across all levels - some mght need to be disabled later
			if (theInputMgr->isKeyDown(VK_ESCAPE)) //if escape is pressed open the pause menu
			{
				inMenu = true;
				pauseMenu = true;

				if (soundPlaying)
				theSoundMgr->getSnd("Shot")->playAudio(AL_TRUE);
			}

			if (theInputMgr->isKeyDown(VK_NUMPAD9)) //if nupad 9 is pressed set the cursor to the middle of the screen
			{
				SetCursorPos(GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2);
			}

			if (theInputMgr->isKeyDown(VK_NUMPAD8)) //if numpad 8 is pressed switch camera views between map and normal
			{
				if (levelNumber == 0 || IsDebug) //on the demo level allow it whenever
				{
					inMap = !inMap;

					cout << "inMap:" << inMap << endl;
				}
				else if (mapUses > 0) //on the main level, only allow it when you have uses left
				{
					inMap = !inMap;
					if (!inMap)
					{
						mapUses--;
					}	
					cout << "inMap:" << inMap << endl;
					cout << "Map Uses:" << mapUses << endl;
				}

				//if in the main level, need to have picked up the map pickup to be able to switch, or if 
				//in debug mode, allow switching all the time

			}

			if (theInputMgr->isKeyDown(VK_NUMPAD7)) //if numpad 7 pressed toggle collision detection on and off - collision is a little funky anyway
			{
				CollisionOn = !CollisionOn;
			}

			if (theInputMgr->isKeyDown(VK_NUMPAD6)) //if numpad 6 is pressed, toggle the sound
			{
				if (soundPlaying)
				{
					theSoundMgr->getSnd("Theme")->stopAudio();
					soundPlaying = false;
				}
				else
				{
					theSoundMgr->getSnd("Theme")->playAudio(AL_LOOPING);
					soundPlaying = true;
				}
			}

			//now that all universal input is detected do the updates for each level
			if (levelNumber == 0)
			{
				//We get the time that passed since the last frame
				float elapsedTime = pgmWNDMgr->getElapsedSeconds();

				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				theOGLWnd.initOGL(windowWidth, windowHeight);


				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();

				//do the light and starfield stuff before we update the camera, the lights were here so that when i had torch moving, it would always be in the
				//right place, and not a frame behind, though it didnt work anyway
				theStarField.render(0.0f);
				sunMaterial.useMaterial();
				//turn all the lights on
				sunLight1.lightOn();
				sunLight2.lightOn();
				sunLight3.lightOn();
				sunLight4.lightOn();

				cLight torchLight(GL_LIGHT1, lightColour4(0, 0, 0, 1), lightColour4(1, 1, 1, 1), lightColour4(1, 1, 1, 1), glm::vec4(fpsCam.getPosition().x, fpsCam.getPosition().y, fpsCam.getPosition().z, 1),
					fpsCam.getDirection(), 90.0f, 90.0f, 1.0f, 0.0f, 0.0f);
				torchLight.lightOn();


				if (inMap) //if we are in the map, use the map camera, otherwise use the normal fps one
				{
					glLoadMatrixf((GLfloat*)&mapCam.getViewMatrix());
					mapCam.Update(tCount);
				}
				else
				{	//call the movement and updating of positionsfor the cameras in here as well, then check collision afterwards and move back if needed
					glLoadMatrixf((GLfloat*)&fpsCam.getViewMatrix());
					fpsCam.doMovement();
					thePlayer.setPosition(glm::vec3(fpsCam.getPosition().x + 0.5f, fpsCam.getPosition().y, fpsCam.getPosition().z - 0.5f));
				}

				//render the test wall
				playerModel.renderMdl(level0Wall.getPosition(), 0, level0Wall.getScale()); //this is a cube, as this player model is only for collision use

				//render the ground
				groundModel.renderMdl(glm::vec3(0, -2, 0), 0, glm::vec3(1, 1, 1));

				if (CollisionOn) //only check for collisions if the collision is actually on
				{
					if (exit.BoundingBoxCollision(thePlayer.getPosition(), playerModel.getModelDimensions())) //if we collide with the exit
					{
						if (soundPlaying)
							theSoundMgr->getSnd("success")->playAudio(AL_TRUE); //play sound if allowed

						exit.setPosition(glm::vec3(11, 0, 19));//set to the level 1 position and then increment to next level
						mapPickupGotten = false;

						levelNumber++;
					}

					if (level0Wall.BoundingBoxCollision(thePlayer.getPosition(), playerModel.getModelDimensions())) //if we collide with the wall, stop us and move us back
					{
						fpsCam.undoMovement();
						thePlayer.setPosition(glm::vec3(fpsCam.getPosition().x, fpsCam.getPosition().y, fpsCam.getPosition().z));
					}

					if (!mapPickupGotten) //only check collision with the piickup if we havent picked it up already
					{
						if (mapPickup.BoundingBoxCollision(thePlayer.getPosition(), playerModel.getModelDimensions())) //if we collide, stop it rendering, colliding and add the uses to the player
						{

							if (soundPlaying)
								theSoundMgr->getSnd("success")->playAudio(AL_TRUE); //and play sound if allowed

							mapPickupGotten = true;
							mapUses += 2;
							//hit the pickup -- stop rendering and asking for collision as well as activating the pickup
						}
					}

					if (Enemy.BoundingBoxCollision(thePlayer.getPosition(), playerModel.getModelDimensions())) //if we hit the enemy send a message to console and play sound if allowed - enemy doesnt move as its broken
					{
						if (soundPlaying)
							theSoundMgr->getSnd("fail")->playAudio(AL_TRUE);

						cout << "enemy touched" << endl;
						//we hit the enemy who is static and broken!
					}
					//check against single wall that is included in this
					//check againt any pickups
				}

				if (!mapPickupGotten) //only render if ewe havent picked it up yet
					mapPickupModel.renderMdl(mapPickup.getPosition(), 0 , mapPickup.getScale());

				//render all the models
				exitModel.renderMdl(exit.getPosition(), 0.0f, exit.getScale());
				tardisMdl.renderMdl(glm::vec3(fpsCam.getPosition().x, fpsCam.getPosition().y - 1.5, fpsCam.getPosition().z), 0, glm::vec3(0.1f, 0.1f, 0.1f));
				thePlayer.update(elapsedTime);
				fpsCam.Update(tCount);

				if (elapsedTime - previousElapsedTime >= 1) //move the enemy every second, doesnt work :(
				{
					//call the enemies update fucntion currently broken -- for some reason does not iterate through the positions properly
					Enemy.setPosition(theenemy.getNextPosition());
					theenemy.Update();

					previousElapsedTime = elapsedTime;
				}
				//render the enemy in its new position hopefully
				enemyModel.renderMdl(Enemy.getPosition(), 0, glm::vec3(1, 1, 1));

				//make the time since start of the game to a string
				outputMsg = to_string(floorf(tCount)); // convert float to string

				//push the matrix and get ready to do any relevant text
				glPushMatrix();
				theOGLWnd.setOrtho2D(windowWidth, windowHeight);
				theFontMgr->getFont("DrWho")->printText(outputMsg.c_str(), FTPoint(1600, 100, 0.0f), colour3f(255.0f, 255.0f, 0.0f)); // uses c_str to convert string to LPCSTR
				theFontMgr->getFont("DrWho")->printText("Level 0, tutorial/example level.", FTPoint(150, 100, 0.0f), colour3f(255.0f, 255.0f, 0.0f));

			}
			else //else we are in level 1
			{

				//We get the time that passed since the last frame
				float elapsedTime = pgmWNDMgr->getElapsedSeconds();

				// Lab code goes here

				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				theOGLWnd.initOGL(windowWidth, windowHeight);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				//same as level 0
				cLight torchLight(GL_LIGHT1, lightColour4(0, 0, 0, 1), lightColour4(1, 1, 1, 1), lightColour4(1, 1, 1, 1), glm::vec4(fpsCam.getPosition().x, fpsCam.getPosition().y, fpsCam.getPosition().z, 1),
					fpsCam.getDirection(), 90.0f, 180.0f, 1.0f, 0.0f, 0.0f);
				torchLight.lightOn();


				theStarField.render(0.0f);
				sunMaterial.useMaterial();
				sunLight1.lightOn();
				sunLight2.lightOn();
				sunLight3.lightOn();
				sunLight4.lightOn();

				if (inMap)
				{
					glLoadMatrixf((GLfloat*)&mapCam.getViewMatrix());
					mapCam.Update(tCount);
				}
				else
				{
					glLoadMatrixf((GLfloat*)&fpsCam.getViewMatrix());
					fpsCam.doMovement();
					thePlayer.setPosition(glm::vec3(fpsCam.getPosition().x + 0.5f, fpsCam.getPosition().y, fpsCam.getPosition().z - 0.5f));
				}
				//render the walls from the wall manager and render the ground
				theWallManager.renderWalls();
				groundModel.renderMdl(glm::vec3(0, -2, 0), 0, glm::vec3(1, 1, 1));

				if (CollisionOn)
				{
					//check all collision hereonly if its on
					if (theWallManager.CheckWallCollisions(thePlayer)) //check for collisions against the walls, each of them is called in turn inside the wall manager class
					{
						CollisionDetected = true;
						fpsCam.undoMovement();
						thePlayer.setPosition(glm::vec3(fpsCam.getPosition().x, fpsCam.getPosition().y, fpsCam.getPosition().z));
					}
					else
					{
						CollisionDetected = false;
					}

					if (!mapPickupGotten) //check if we are allowed to get the pickup and if we are, check for collision with it
					{
						if (mapPickup.BoundingBoxCollision(thePlayer.getPosition(), playerModel.getModelDimensions()))
						{
							if (soundPlaying)
								theSoundMgr->getSnd("success")->playAudio(AL_TRUE);

							mapPickupGotten = true;
							mapUses += 2;
							//hit the pickup -- stop rendering and asking for collision as well as activating the pickup
						}
					}
				}

				if (exit.BoundingBoxCollision(thePlayer.getPosition(), playerModel.getModelDimensions())) //check if we have hit the exit to complete the game
				{
					if (soundPlaying)
						theSoundMgr->getSnd("success")->playAudio(AL_TRUE);

					levelNumber += 1;
				}

				if (!mapPickupGotten) //render the pickup only if allowed
					mapPickupModel.renderMdl(mapPickup.getPosition(), 0, mapPickup.getScale());

				//render all of the models and then update the fps camera
				exitModel.renderMdl(exit.getPosition(), 0.0f, exit.getScale());
				tardisMdl.renderMdl(glm::vec3(fpsCam.getPosition().x, fpsCam.getPosition().y - 1.5, fpsCam.getPosition().z), 0, glm::vec3(0.1f, 0.1f, 0.1f));
				thePlayer.update(elapsedTime);
				fpsCam.Update(tCount);

				outputMsg = to_string(floorf(tCount)); // convert float to string
				string mapusesString = to_string(mapUses); //create the string of the amount of uses i have left in the maps

				glPushMatrix(); //push matrix and get ready to do text
				theOGLWnd.setOrtho2D(windowWidth, windowHeight);
				theFontMgr->getFont("DrWho")->printText(outputMsg.c_str(), FTPoint(1600, 100, 0.0f), colour3f(255.0f, 255.0f, 0.0f)); // uses c_str to convert string to LPCSTR
				theFontMgr->getFont("DrWho")->printText("Level 1, Main Level.", FTPoint(150, 100, 0.0f), colour3f(255.0f, 255.0f, 0.0f));
				theFontMgr->getFont("DrWho")->printText("Map Uses Left:", FTPoint(850, 100, 0.0f), colour3f(255.0f, 255.0f, 0.0f));
				theFontMgr->getFont("DrWho")->printText(mapusesString.c_str(), FTPoint(1200, 100, 0.0f), colour3f(255.0f, 255.0f, 0.0f)); //how many more times can the player use the map

			}
		}

		glPopMatrix();

		pgmWNDMgr->swapBuffers();

		tCount += elapsedTime;

		//Clear key buffers
		theInputMgr->clearBuffers(theInputMgr->KEYS_DOWN_BUFFER | theInputMgr->KEYS_PRESSED_BUFFER);

	}

	//game loop has been exited...
	theOGLWnd.shutdown(); //Free any resources
	pgmWNDMgr->destroyWND(); //Destroy the program window

    return 0; //Return success
}