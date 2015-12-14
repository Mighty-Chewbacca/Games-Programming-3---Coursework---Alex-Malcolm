#include "wallManager.h"

cModelLoader yellowWall, blueWall, pinkWall, greenyBlueWall; //only need to load each model once

cWall leftWall1, leftWall2, leftWall3, leftWall4, leftWall5, leftWall6, leftWall7, leftWall8,
leftWall9, leftWall10, leftWall11, leftWall12, leftWall13, leftWall14;

cWall rightWall1, rightWall2, rightWall3, rightWall4, rightWall5, rightWall6, rightWall7, rightWall8,
rightWall9, rightWall10, rightWall11, rightWall12, rightWall13, rightWall14;

cWall topWall1, topWall2, topWall3, topWall4, topWall5, topWall6, topWall7, topWall8,
topWall9, topWall10, topWall11, topWall12, topWall13, topWall14;

cWall bottomWall1, bottomWall2, bottomWall3, bottomWall4, bottomWall5, bottomWall6, bottomWall7, bottomWall8,
bottomWall9, bottomWall10, bottomWall11, bottomWall12, bottomWall13, bottomWall14;

cWall centreWall1, centreWall2, centreWall3, centreWall4, centreWall5, centreWall6, centreWall7, centreWall8,
centreWall9, centreWall10, centreWall11, centreWall12, centreWall13, centreWall14, centreWall15, centreWall16,
centreWall17, centreWall18, centreWall19, centreWall20, centreWall21, centreWall22, centreWall23, centreWall24, centreWall25,
centreWall26, centreWall27, centreWall28, centreWall29, centreWall30, centreWall31, centreWall32, centreWall33,
centreWall34, centreWall35, centreWall36, centreWall37, centreWall38, centreWall39, centreWall40, centreWall41,
centreWall42, centreWall43, centreWall44, centreWall45, centreWall46, centreWall47, centreWall48, centreWall49,
centreWall50, centreWall51, centreWall52, centreWall53, centreWall54, centreWall55, centreWall56, centreWall57, centreWall58,
centreWall59, centreWall60, centreWall61, centreWall62, centreWall63, centreWall64, centreWall65;
//all of the above walls are the ones tha tmake up the maze, need a seperate object for each which only stores position and dimensions, 
//the same models are rendered in each of these positions 

//constructor
wallManager::wallManager()
{
	createWalls(); //create the walls 
	setPositions(); //set their positions
	setModelDimensions(); //set all of their dimensions
	setScales(); //set all of their scales 
}

//sets the positions to to needed locations for all of the walls
void wallManager::setPositions()
{
	//goes through each and every wall, giving it its correct position
	leftWall1.setPosition(glm::vec3(0, 0, 0));
	leftWall2.setPosition(glm::vec3(0, 0, 2));
	leftWall3.setPosition(glm::vec3(0, 0, 4));
	leftWall4.setPosition(glm::vec3(0, 0, 6));
	leftWall5.setPosition(glm::vec3(0, 0, 8));
	leftWall6.setPosition(glm::vec3(0, 0, 10));
	leftWall7.setPosition(glm::vec3(0, 0, 12));
	leftWall8.setPosition(glm::vec3(0, 0, 14));
	leftWall9.setPosition(glm::vec3(0, 0, 16));
	leftWall10.setPosition(glm::vec3(0, 0, 18));
	leftWall11.setPosition(glm::vec3(0, 0, 20));
	leftWall12.setPosition(glm::vec3(0, 0, 22));
	leftWall13.setPosition(glm::vec3(0, 0, 24));
	leftWall14.setPosition(glm::vec3(0, 0, 26));

	rightWall1.setPosition(glm::vec3(26, 0, 0));
	rightWall2.setPosition(glm::vec3(26, 0, 2));
	rightWall3.setPosition(glm::vec3(26, 0, 4));
	rightWall4.setPosition(glm::vec3(26, 0, 6));
	rightWall5.setPosition(glm::vec3(26, 0, 8));
	rightWall6.setPosition(glm::vec3(26, 0, 10));
	rightWall7.setPosition(glm::vec3(26, 0, 12));
	rightWall8.setPosition(glm::vec3(26, 0, 14));
	rightWall9.setPosition(glm::vec3(26, 0, 16));
	rightWall10.setPosition(glm::vec3(26, 0, 18));
	rightWall11.setPosition(glm::vec3(26, 0, 20));
	rightWall12.setPosition(glm::vec3(26, 0, 22));
	rightWall13.setPosition(glm::vec3(26, 0, 24));
	rightWall14.setPosition(glm::vec3(26, 0, 26));

	topWall1.setPosition(glm::vec3(0, 0, 26));
	topWall2.setPosition(glm::vec3(2, 0, 26));
	topWall3.setPosition(glm::vec3(4, 0, 26));
	topWall4.setPosition(glm::vec3(6, 0, 26));
	topWall5.setPosition(glm::vec3(8, 0, 26));
	topWall6.setPosition(glm::vec3(10, 0, 26));
	topWall7.setPosition(glm::vec3(12, 0, 26));
	topWall8.setPosition(glm::vec3(14, 0, 26));
	topWall9.setPosition(glm::vec3(16, 0, 26));
	topWall10.setPosition(glm::vec3(18, 0, 26));
	topWall11.setPosition(glm::vec3(20, 0, 26));
	topWall12.setPosition(glm::vec3(22, 0, 26));
	topWall13.setPosition(glm::vec3(24, 0, 26));
	topWall14.setPosition(glm::vec3(26, 0, 26));

	bottomWall1.setPosition(glm::vec3(0, 0, 0));
	bottomWall2.setPosition(glm::vec3(2, 0, 0));
	bottomWall3.setPosition(glm::vec3(4, 0, 0));
	bottomWall4.setPosition(glm::vec3(6, 0, 0));
	bottomWall5.setPosition(glm::vec3(8, 0, 0));
	bottomWall6.setPosition(glm::vec3(10, 0, 0));
	bottomWall7.setPosition(glm::vec3(12, 0, 0));
	bottomWall8.setPosition(glm::vec3(14, 0, 0));
	bottomWall9.setPosition(glm::vec3(16, 0, 0));
	bottomWall10.setPosition(glm::vec3(18, 0, 0));
	bottomWall11.setPosition(glm::vec3(20, 0, 0));
	bottomWall12.setPosition(glm::vec3(22, 0, 0));
	bottomWall13.setPosition(glm::vec3(24, 0, 0));
	bottomWall14.setPosition(glm::vec3(26, 0, 0));

	//the centre walls that will make up the maze -- rows start from bottom and work up
	centreWall1.setPosition(glm::vec3(2, 0, 16)); //first row

	centreWall2.setPosition(glm::vec3(4, 0, 4)); //second row
	centreWall3.setPosition(glm::vec3(4, 0, 6));
	centreWall4.setPosition(glm::vec3(4, 0, 8));
	centreWall5.setPosition(glm::vec3(4, 0, 12));
	centreWall6.setPosition(glm::vec3(4, 0, 20));
	centreWall7.setPosition(glm::vec3(4, 0, 22));
	centreWall8.setPosition(glm::vec3(4, 0, 24));

	centreWall9.setPosition(glm::vec3(6, 0, 4)); //third row
	centreWall10.setPosition(glm::vec3(6, 0, 6));
	centreWall11.setPosition(glm::vec3(6, 0, 8));
	centreWall12.setPosition(glm::vec3(6, 0, 12));
	centreWall13.setPosition(glm::vec3(6, 0, 14));
	centreWall14.setPosition(glm::vec3(6, 0, 16));
	centreWall15.setPosition(glm::vec3(6, 0, 18));
	centreWall16.setPosition(glm::vec3(6, 0, 20));
	centreWall17.setPosition(glm::vec3(6, 0, 24));

	centreWall18.setPosition(glm::vec3(8, 0, 12)); // fourth row

	centreWall19.setPosition(glm::vec3(10, 0, 4)); //fifth row
	centreWall20.setPosition(glm::vec3(10, 0, 6));
	centreWall21.setPosition(glm::vec3(10, 0, 8));
	centreWall22.setPosition(glm::vec3(10, 0, 12));
	centreWall23.setPosition(glm::vec3(10, 0, 16));
	centreWall24.setPosition(glm::vec3(10, 0, 18));
	centreWall25.setPosition(glm::vec3(10, 0, 20));

	centreWall26.setPosition(glm::vec3(12, 0, 4)); //sixth row
	centreWall27.setPosition(glm::vec3(12, 0, 16));
	centreWall28.setPosition(glm::vec3(12, 0, 20));
	centreWall29.setPosition(glm::vec3(12, 0, 24));

	centreWall30.setPosition(glm::vec3(14, 0, 2)); //seventh row
	centreWall31.setPosition(glm::vec3(14, 0, 4));
	centreWall32.setPosition(glm::vec3(14, 0, 6));
	centreWall33.setPosition(glm::vec3(14, 0, 8));
	centreWall34.setPosition(glm::vec3(14, 0, 10));
	centreWall35.setPosition(glm::vec3(14, 0, 12));
	centreWall36.setPosition(glm::vec3(14, 0, 14));
	centreWall37.setPosition(glm::vec3(14, 0, 16));
	centreWall38.setPosition(glm::vec3(14, 0, 20));

	centreWall39.setPosition(glm::vec3(16, 0, 2)); //eighth row
	centreWall40.setPosition(glm::vec3(16, 0, 10));
	centreWall41.setPosition(glm::vec3(16, 0, 12));
	centreWall42.setPosition(glm::vec3(16, 0, 20));
	centreWall43.setPosition(glm::vec3(16, 0, 22));

	centreWall44.setPosition(glm::vec3(18, 0, 2)); //ninth row
	centreWall45.setPosition(glm::vec3(18, 0, 6));
	centreWall46.setPosition(glm::vec3(18, 0, 8));
	centreWall47.setPosition(glm::vec3(18, 0, 16));
	centreWall48.setPosition(glm::vec3(18, 0, 18));
	centreWall49.setPosition(glm::vec3(18, 0, 20));
	centreWall50.setPosition(glm::vec3(18, 0, 22));

	centreWall51.setPosition(glm::vec3(20, 0, 2));//tenth row
	centreWall52.setPosition(glm::vec3(20, 0, 6));
	centreWall53.setPosition(glm::vec3(20, 0, 8));
	centreWall54.setPosition(glm::vec3(20, 0, 12));
	centreWall55.setPosition(glm::vec3(20, 0, 14));
	centreWall56.setPosition(glm::vec3(20, 0, 18));

	centreWall57.setPosition(glm::vec3(22, 0, 2)); //eleventh row
	centreWall58.setPosition(glm::vec3(22, 0, 8));
	centreWall59.setPosition(glm::vec3(22, 0, 12));
	centreWall60.setPosition(glm::vec3(22, 0, 14));
	centreWall61.setPosition(glm::vec3(22, 0, 18));
	centreWall62.setPosition(glm::vec3(22, 0, 20));
	centreWall63.setPosition(glm::vec3(22, 0, 22));

	centreWall64.setPosition(glm::vec3(24, 0, 2)); //twelfth row
	centreWall65.setPosition(glm::vec3(24, 0, 4));
}

//sets the scales for each wall as well
void wallManager::setScales()
{
	//goes through each wall setting the scale
	leftWall1.setScale(glm::vec3(1, 1, 1));
	leftWall2.setScale(glm::vec3(1, 1, 1));
	leftWall3.setScale(glm::vec3(1, 1, 1));
	leftWall4.setScale(glm::vec3(1, 1, 1));
	leftWall5.setScale(glm::vec3(1, 1, 1));
	leftWall6.setScale(glm::vec3(1, 1, 1));
	leftWall7.setScale(glm::vec3(1, 1, 1));
	leftWall8.setScale(glm::vec3(1, 1, 1));
	leftWall9.setScale(glm::vec3(1, 1, 1));
	leftWall10.setScale(glm::vec3(1, 1, 1));
	leftWall11.setScale(glm::vec3(1, 1, 1));
	leftWall12.setScale(glm::vec3(1, 1, 1));
	leftWall13.setScale(glm::vec3(1, 1, 1));
	leftWall14.setScale(glm::vec3(1, 1, 1));

	rightWall1.setScale(glm::vec3(1, 1, 1));
	rightWall2.setScale(glm::vec3(1, 1, 1));
	rightWall3.setScale(glm::vec3(1, 1, 1));
	rightWall4.setScale(glm::vec3(1, 1, 1));
	rightWall5.setScale(glm::vec3(1, 1, 1));
	rightWall6.setScale(glm::vec3(1, 1, 1));
	rightWall7.setScale(glm::vec3(1, 1, 1));
	rightWall8.setScale(glm::vec3(1, 1, 1));
	rightWall9.setScale(glm::vec3(1, 1, 1));
	rightWall10.setScale(glm::vec3(1, 1, 1));
	rightWall11.setScale(glm::vec3(1, 1, 1));
	rightWall12.setScale(glm::vec3(1, 1, 1));
	rightWall13.setScale(glm::vec3(1, 1, 1));
	rightWall14.setScale(glm::vec3(1, 1, 1));

	topWall1.setScale(glm::vec3(1, 1, 1));
	topWall2.setScale(glm::vec3(1, 1, 1));
	topWall3.setScale(glm::vec3(1, 1, 1));
	topWall4.setScale(glm::vec3(1, 1, 1));
	topWall5.setScale(glm::vec3(1, 1, 1));
	topWall6.setScale(glm::vec3(1, 1, 1));
	topWall7.setScale(glm::vec3(1, 1, 1));
	topWall8.setScale(glm::vec3(1, 1, 1));
	topWall9.setScale(glm::vec3(1, 1, 1));
	topWall10.setScale(glm::vec3(1, 1, 1));
	topWall11.setScale(glm::vec3(1, 1, 1));
	topWall12.setScale(glm::vec3(1, 1, 1));
	topWall13.setScale(glm::vec3(1, 1, 1));
	topWall14.setScale(glm::vec3(1, 1, 1));

	bottomWall1.setScale(glm::vec3(1, 1, 1));
	bottomWall2.setScale(glm::vec3(1, 1, 1));
	bottomWall3.setScale(glm::vec3(1, 1, 1));
	bottomWall4.setScale(glm::vec3(1, 1, 1));
	bottomWall5.setScale(glm::vec3(1, 1, 1));
	bottomWall6.setScale(glm::vec3(1, 1, 1));
	bottomWall7.setScale(glm::vec3(1, 1, 1));
	bottomWall8.setScale(glm::vec3(1, 1, 1));
	bottomWall9.setScale(glm::vec3(1, 1, 1));
	bottomWall10.setScale(glm::vec3(1, 1, 1));
	bottomWall11.setScale(glm::vec3(1, 1, 1));
	bottomWall12.setScale(glm::vec3(1, 1, 1));
	bottomWall13.setScale(glm::vec3(1, 1, 1));
	bottomWall14.setScale(glm::vec3(1, 1, 1));

	//the centre walls that will make up the maze -- rows start from bottom and work up
	centreWall1.setScale(glm::vec3(1, 1, 1)); //first row

	centreWall2.setScale(glm::vec3(1, 1, 1)); //second row
	centreWall3.setScale(glm::vec3(1, 1, 1));
	centreWall4.setScale(glm::vec3(1, 1, 1));
	centreWall5.setScale(glm::vec3(1, 1, 1));
	centreWall6.setScale(glm::vec3(1, 1, 1));
	centreWall7.setScale(glm::vec3(1, 1, 1));
	centreWall8.setScale(glm::vec3(1, 1, 1));

	centreWall9.setScale(glm::vec3(1, 1, 1)); //third row
	centreWall10.setScale(glm::vec3(1, 1, 1));
	centreWall11.setScale(glm::vec3(1, 1, 1));
	centreWall12.setScale(glm::vec3(1, 1, 1));
	centreWall13.setScale(glm::vec3(1, 1, 1));
	centreWall14.setScale(glm::vec3(1, 1, 1));
	centreWall15.setScale(glm::vec3(1, 1, 1));
	centreWall16.setScale(glm::vec3(1, 1, 1));
	centreWall17.setScale(glm::vec3(1, 1, 1));

	centreWall18.setScale(glm::vec3(1, 1, 1)); // fourth row

	centreWall19.setScale(glm::vec3(1, 1, 1)); //fifth row
	centreWall20.setScale(glm::vec3(1, 1, 1));
	centreWall21.setScale(glm::vec3(1, 1, 1));
	centreWall22.setScale(glm::vec3(1, 1, 1));
	centreWall23.setScale(glm::vec3(1, 1, 1));
	centreWall24.setScale(glm::vec3(1, 1, 1));
	centreWall25.setScale(glm::vec3(1, 1, 1));

	centreWall26.setScale(glm::vec3(1, 1, 1)); //sixth row
	centreWall27.setScale(glm::vec3(1, 1, 1));
	centreWall28.setScale(glm::vec3(1, 1, 1));
	centreWall29.setScale(glm::vec3(1, 1, 1));

	centreWall30.setScale(glm::vec3(1, 1, 1));  //seventh row
	centreWall31.setScale(glm::vec3(1, 1, 1));
	centreWall32.setScale(glm::vec3(1, 1, 1));
	centreWall33.setScale(glm::vec3(1, 1, 1));
	centreWall34.setScale(glm::vec3(1, 1, 1));
	centreWall35.setScale(glm::vec3(1, 1, 1));
	centreWall36.setScale(glm::vec3(1, 1, 1));
	centreWall37.setScale(glm::vec3(1, 1, 1));
	centreWall38.setScale(glm::vec3(1, 1, 1));

	centreWall39.setScale(glm::vec3(1, 1, 1)); //eighth row
	centreWall40.setScale(glm::vec3(1, 1, 1));
	centreWall41.setScale(glm::vec3(1, 1, 1));
	centreWall42.setScale(glm::vec3(1, 1, 1));
	centreWall43.setScale(glm::vec3(1, 1, 1));

	centreWall44.setScale(glm::vec3(1, 1, 1)); //ninth row
	centreWall45.setScale(glm::vec3(1, 1, 1));
	centreWall46.setScale(glm::vec3(1, 1, 1));
	centreWall47.setScale(glm::vec3(1, 1, 1));
	centreWall48.setScale(glm::vec3(1, 1, 1));
	centreWall49.setScale(glm::vec3(1, 1, 1));
	centreWall50.setScale(glm::vec3(1, 1, 1));

	centreWall51.setScale(glm::vec3(1, 1, 1)); //tenth row
	centreWall52.setScale(glm::vec3(1, 1, 1));
	centreWall53.setScale(glm::vec3(1, 1, 1));
	centreWall54.setScale(glm::vec3(1, 1, 1));
	centreWall55.setScale(glm::vec3(1, 1, 1));
	centreWall56.setScale(glm::vec3(1, 1, 1));

	centreWall57.setScale(glm::vec3(1, 1, 1)); //eleventh row
	centreWall58.setScale(glm::vec3(1, 1, 1));
	centreWall59.setScale(glm::vec3(1, 1, 1));
	centreWall60.setScale(glm::vec3(1, 1, 1));
	centreWall61.setScale(glm::vec3(1, 1, 1));
	centreWall62.setScale(glm::vec3(1, 1, 1));
	centreWall63.setScale(glm::vec3(1, 1, 1));

	centreWall64.setScale(glm::vec3(1, 1, 1)); //twelfth row
	centreWall65.setScale(glm::vec3(1, 1, 1));
}

//sets the model dimensions for each wall
void wallManager::setModelDimensions()
{
	//again goes through each wall singly setting the dimensions
	leftWall1.setMdlDimensions(yellowWall.getModelDimensions());
	leftWall2.setMdlDimensions(yellowWall.getModelDimensions());
	leftWall3.setMdlDimensions(yellowWall.getModelDimensions());
	leftWall4.setMdlDimensions(yellowWall.getModelDimensions());
	leftWall5.setMdlDimensions(yellowWall.getModelDimensions());
	leftWall6.setMdlDimensions(yellowWall.getModelDimensions());
	leftWall7.setMdlDimensions(yellowWall.getModelDimensions());
	leftWall8.setMdlDimensions(yellowWall.getModelDimensions());
	leftWall9.setMdlDimensions(yellowWall.getModelDimensions());
	leftWall10.setMdlDimensions(yellowWall.getModelDimensions());
	leftWall11.setMdlDimensions(yellowWall.getModelDimensions());
	leftWall12.setMdlDimensions(yellowWall.getModelDimensions());
	leftWall13.setMdlDimensions(yellowWall.getModelDimensions());
	leftWall14.setMdlDimensions(yellowWall.getModelDimensions());

	rightWall1.setMdlDimensions(yellowWall.getModelDimensions());
	rightWall2.setMdlDimensions(yellowWall.getModelDimensions());
	rightWall3.setMdlDimensions(yellowWall.getModelDimensions());
	rightWall4.setMdlDimensions(yellowWall.getModelDimensions());
	rightWall5.setMdlDimensions(yellowWall.getModelDimensions());
	rightWall6.setMdlDimensions(yellowWall.getModelDimensions());
	rightWall7.setMdlDimensions(yellowWall.getModelDimensions());
	rightWall8.setMdlDimensions(yellowWall.getModelDimensions());
	rightWall9.setMdlDimensions(yellowWall.getModelDimensions());
	rightWall10.setMdlDimensions(yellowWall.getModelDimensions());
	rightWall11.setMdlDimensions(yellowWall.getModelDimensions());
	rightWall12.setMdlDimensions(yellowWall.getModelDimensions());
	rightWall13.setMdlDimensions(yellowWall.getModelDimensions());
	rightWall14.setMdlDimensions(yellowWall.getModelDimensions());

	topWall1.setMdlDimensions(yellowWall.getModelDimensions());
	topWall2.setMdlDimensions(yellowWall.getModelDimensions());
	topWall3.setMdlDimensions(yellowWall.getModelDimensions());
	topWall4.setMdlDimensions(yellowWall.getModelDimensions());
	topWall5.setMdlDimensions(yellowWall.getModelDimensions());
	topWall6.setMdlDimensions(yellowWall.getModelDimensions());
	topWall7.setMdlDimensions(yellowWall.getModelDimensions());
	topWall8.setMdlDimensions(yellowWall.getModelDimensions());
	topWall9.setMdlDimensions(yellowWall.getModelDimensions());
	topWall10.setMdlDimensions(yellowWall.getModelDimensions());
	topWall11.setMdlDimensions(yellowWall.getModelDimensions());
	topWall12.setMdlDimensions(yellowWall.getModelDimensions());
	topWall13.setMdlDimensions(yellowWall.getModelDimensions());
	topWall14.setMdlDimensions(yellowWall.getModelDimensions());

	bottomWall1.setMdlDimensions(yellowWall.getModelDimensions());
	bottomWall2.setMdlDimensions(yellowWall.getModelDimensions());
	bottomWall3.setMdlDimensions(yellowWall.getModelDimensions());
	bottomWall4.setMdlDimensions(yellowWall.getModelDimensions());
	bottomWall5.setMdlDimensions(yellowWall.getModelDimensions());
	bottomWall6.setMdlDimensions(yellowWall.getModelDimensions());
	bottomWall7.setMdlDimensions(yellowWall.getModelDimensions());
	bottomWall8.setMdlDimensions(yellowWall.getModelDimensions());
	bottomWall9.setMdlDimensions(yellowWall.getModelDimensions());
	bottomWall10.setMdlDimensions(yellowWall.getModelDimensions());
	bottomWall11.setMdlDimensions(yellowWall.getModelDimensions());
	bottomWall12.setMdlDimensions(yellowWall.getModelDimensions());
	bottomWall13.setMdlDimensions(yellowWall.getModelDimensions());
	bottomWall14.setMdlDimensions(yellowWall.getModelDimensions());

	//the centre walls that will make up the maze -- rows start from bottom and work up
	centreWall1.setMdlDimensions(yellowWall.getModelDimensions()); //first row

	centreWall2.setMdlDimensions(yellowWall.getModelDimensions()); //second row
	centreWall3.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall4.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall5.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall6.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall7.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall8.setMdlDimensions(yellowWall.getModelDimensions());

	centreWall9.setMdlDimensions(yellowWall.getModelDimensions()); //third row
	centreWall10.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall11.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall12.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall13.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall14.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall15.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall16.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall17.setMdlDimensions(yellowWall.getModelDimensions());

	centreWall18.setMdlDimensions(yellowWall.getModelDimensions()); // fourth row

	centreWall19.setMdlDimensions(yellowWall.getModelDimensions()); //fifth row
	centreWall20.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall21.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall22.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall23.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall24.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall25.setMdlDimensions(yellowWall.getModelDimensions());

	centreWall26.setMdlDimensions(yellowWall.getModelDimensions()); //sixth row
	centreWall27.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall28.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall29.setMdlDimensions(yellowWall.getModelDimensions());

	centreWall30.setMdlDimensions(yellowWall.getModelDimensions());  //seventh row
	centreWall31.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall32.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall33.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall34.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall35.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall36.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall37.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall38.setMdlDimensions(yellowWall.getModelDimensions());

	centreWall39.setMdlDimensions(yellowWall.getModelDimensions()); //eighth row
	centreWall40.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall41.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall42.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall43.setMdlDimensions(yellowWall.getModelDimensions());

	centreWall44.setMdlDimensions(yellowWall.getModelDimensions()); //ninth row
	centreWall45.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall46.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall47.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall48.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall49.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall50.setMdlDimensions(yellowWall.getModelDimensions());

	centreWall51.setMdlDimensions(yellowWall.getModelDimensions()); //tenth row
	centreWall52.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall53.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall54.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall55.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall56.setMdlDimensions(yellowWall.getModelDimensions());

	centreWall57.setMdlDimensions(yellowWall.getModelDimensions()); //eleventh row
	centreWall58.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall59.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall60.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall61.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall62.setMdlDimensions(yellowWall.getModelDimensions());
	centreWall63.setMdlDimensions(yellowWall.getModelDimensions());

	centreWall64.setMdlDimensions(yellowWall.getModelDimensions()); //twelfth row
	centreWall65.setMdlDimensions(yellowWall.getModelDimensions());
}

//create walls creates the textures and loads in the model with the correspodnign texture for each wall type
void wallManager::createWalls()
{
	// Create Texture map
	cTexture tardisTexture, blueTexture, yellowTexture, pinkTexture;
	tardisTexture.createTexture("Models/GreenyBlue.jpg");
	blueTexture.createTexture("Models/Blue.jpg");
	yellowTexture.createTexture("Models/Yellow.jpg");
	pinkTexture.createTexture("Models/Pink.jpg");

	//load the wall and assign the texture -- only need to keep one of each colour in memory, can simply render it in loads of places
	yellowWall.loadModel("Models/WallCube.obj", yellowTexture);
	blueWall.loadModel("Models/WallCube.obj", blueTexture);
	pinkWall.loadModel("Models/WallCube.obj", pinkTexture);
	greenyBlueWall.loadModel("Models/WallCube.obj", tardisTexture);
}

//render each of the walls with a position rotation and scale
void wallManager::renderWalls()
{
	//goes through each one and renders them
	yellowWall.renderMdl(glm::vec3(0, 0, 0), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(0, 0, 2), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(0, 0, 4), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(0, 0, 6), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(0, 0, 8), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(0, 0, 10), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(0, 0, 12), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(0, 0, 14), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(0, 0, 16), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(0, 0, 18), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(0, 0, 20), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(0, 0, 22), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(0, 0, 24), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(0, 0, 26), 0.0f, glm::vec3(1, 1, 1));

	blueWall.renderMdl(glm::vec3(26, 0, 0), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(26, 0, 2), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(26, 0, 4), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(26, 0, 6), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(26, 0, 8), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(26, 0, 10), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(26, 0, 12), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(26, 0, 14), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(26, 0, 16), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(26, 0, 18), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(26, 0, 20), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(26, 0, 22), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(26, 0, 24), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(26, 0, 26), 0.0f, glm::vec3(1, 1, 1));

	greenyBlueWall.renderMdl(glm::vec3(0, 0, 26), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(2, 0, 26), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(4, 0, 26), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(6, 0, 26), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(8, 0, 26), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(10, 0, 26), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(12, 0, 26), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(14, 0, 26), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(16, 0, 26), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(18, 0, 26), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(20, 0, 26), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(22, 0, 26), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(24, 0, 26), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(26, 0, 26), 0.0f, glm::vec3(1, 1, 1));

	greenyBlueWall.renderMdl(glm::vec3(0, 0, 0), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(2, 0, 0), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(4, 0, 0), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(6, 0, 0), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(8, 0, 0), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(10, 0, 0), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(12, 0, 0), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(14, 0, 0), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(16, 0, 0), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(18, 0, 0), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(20, 0, 0), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(22, 0, 0), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(24, 0, 0), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(26, 0, 0), 0.0f, glm::vec3(1, 1, 1));

	//the centre walls that will make up the maze -- rows start from bottom and work up
	yellowWall.renderMdl(glm::vec3(2, 0, 16), 0.0f, glm::vec3(1, 1, 1)); //first row

	yellowWall.renderMdl(glm::vec3(4, 0, 4), 0.0f, glm::vec3(1, 1, 1)); //second row
	greenyBlueWall.renderMdl(glm::vec3(4, 0, 6), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(4, 0, 8), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(4, 0, 12), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(4, 0, 20), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(4, 0, 22), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(4, 0, 24), 0.0f, glm::vec3(1, 1, 1));

	yellowWall.renderMdl(glm::vec3(6, 0, 4), 0.0f, glm::vec3(1, 1, 1)); //third row
	blueWall.renderMdl(glm::vec3(6, 0, 6), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(6, 0, 8), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(6, 0, 12), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(6, 0, 14), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(6, 0, 16), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(6, 0, 18), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(6, 0, 20), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(6, 0, 24), 0.0f, glm::vec3(1, 1, 1));
	
	yellowWall.renderMdl(glm::vec3(8, 0, 12), 0.0f, glm::vec3(1, 1, 1)); // fourth row

	greenyBlueWall.renderMdl(glm::vec3(10, 0, 4), 0.0f, glm::vec3(1, 1, 1)); //fifth row
	yellowWall.renderMdl(glm::vec3(10, 0, 6), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(10, 0, 8), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(10, 0, 12), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(10, 0, 16), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(10, 0, 18), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(10, 0, 20), 0.0f, glm::vec3(1, 1, 1));

	pinkWall.renderMdl(glm::vec3(12, 0, 4), 0.0f, glm::vec3(1, 1, 1)); //sixth row
	yellowWall.renderMdl(glm::vec3(12, 0, 16), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(12, 0, 20), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(12, 0, 24), 0.0f, glm::vec3(1, 1, 1));

	greenyBlueWall.renderMdl(glm::vec3(14, 0, 2), 0.0f, glm::vec3(1, 1, 1)); //seventh row
	yellowWall.renderMdl(glm::vec3(14, 0, 4), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(14, 0, 6), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(14, 0, 8), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(14, 0, 10), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(14, 0, 12), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(14, 0, 14), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(14, 0, 16), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(14, 0, 20), 0.0f, glm::vec3(1, 1, 1));

	yellowWall.renderMdl(glm::vec3(16, 0, 2), 0.0f, glm::vec3(1, 1, 1)); //eighth row
	yellowWall.renderMdl(glm::vec3(16, 0, 10), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(16, 0, 12), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(16, 0, 20), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(16, 0, 22), 0.0f, glm::vec3(1, 1, 1));

	yellowWall.renderMdl(glm::vec3(18, 0, 2), 0.0f, glm::vec3(1, 1, 1)); //ninth row
	blueWall.renderMdl(glm::vec3(18, 0, 6), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(18, 0, 8), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(18, 0, 16), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(18, 0, 18), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(18, 0, 20), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(18, 0, 22), 0.0f, glm::vec3(1, 1, 1));

	blueWall.renderMdl(glm::vec3(20, 0, 2), 0.0f, glm::vec3(1, 1, 1));//tenth row
	yellowWall.renderMdl(glm::vec3(20, 0, 6), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(20, 0, 8), 0.0f, glm::vec3(1, 1, 1));
	pinkWall.renderMdl(glm::vec3(20, 0, 12), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(20, 0, 14), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(20, 0, 18), 0.0f, glm::vec3(1, 1, 1));

	pinkWall.renderMdl(glm::vec3(22, 0, 2), 0.0f, glm::vec3(1, 1, 1)); //eleventh row
	yellowWall.renderMdl(glm::vec3(22, 0, 8), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(22, 0, 12), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(22, 0, 14), 0.0f, glm::vec3(1, 1, 1));
	yellowWall.renderMdl(glm::vec3(22, 0, 18), 0.0f, glm::vec3(1, 1, 1));
	blueWall.renderMdl(glm::vec3(22, 0, 20), 0.0f, glm::vec3(1, 1, 1));
	greenyBlueWall.renderMdl(glm::vec3(22, 0, 22), 0.0f, glm::vec3(1, 1, 1));

	yellowWall.renderMdl(glm::vec3(24, 0, 2), 0.0f, glm::vec3(1, 1, 1)); //twelfth row
	blueWall.renderMdl(glm::vec3(24, 0, 4), 0.0f, glm::vec3(1, 1, 1));
}

//goes through every single wall and checks for collision, this should have added all walls to a vector or some kind of list and iterated through instead
//that would have been quicker for me to type and for the game to run
bool wallManager::CheckWallCollisions(cPlayer playerIn)
{
	//goes through each and every wall and asks if it has collided with the input players location, if it has return true else false
#pragma region topwalls
	if (topWall1.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (topWall2.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (topWall3.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (topWall4.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (topWall5.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (topWall6.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (topWall7.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (topWall8.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (topWall9.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (topWall10.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (topWall11.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (topWall12.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (topWall13.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (topWall14.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
#pragma endregion

#pragma region bottomwalls
	//bottom walls
	if (bottomWall1.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (bottomWall2.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (bottomWall3.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (bottomWall4.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (bottomWall5.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (bottomWall6.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (bottomWall7.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (bottomWall8.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (bottomWall9.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (bottomWall10.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (bottomWall11.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (bottomWall12.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (bottomWall13.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (bottomWall14.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
#pragma endregion

#pragma region rightwalls
	//right walls
	if (rightWall1.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (rightWall2.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (rightWall3.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (rightWall4.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (rightWall5.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (rightWall6.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (rightWall7.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (rightWall8.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (rightWall9.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (rightWall10.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (rightWall11.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (rightWall12.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (rightWall13.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (rightWall14.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
#pragma endregion

#pragma region leftwalls
	//left walls
	if (leftWall1.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (leftWall2.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (leftWall3.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (leftWall4.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (leftWall5.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (leftWall6.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (leftWall7.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (leftWall8.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (leftWall9.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (leftWall10.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (leftWall11.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (leftWall12.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (leftWall13.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (leftWall14.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
#pragma endregion

	//centre walls
	if (centreWall1.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected "<< std::endl;
		return true;
	}
	if (centreWall2.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall3.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall4.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall5.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall6.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall7.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall8.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall9.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall10.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall11.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall12.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall13.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall14.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall15.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall16.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall17.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall18.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall19.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall20.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall21.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall22.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall23.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall24.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall25.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall26.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall27.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall28.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall29.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall30.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall31.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall32.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall33.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall34.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall35.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall36.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall37.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall38.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall39.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall40.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall41.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall42.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall43.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall44.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall45.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall46.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall47.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall48.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall49.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall50.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall51.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall52.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall53.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall54.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall55.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall56.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall57.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall58.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall59.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall60.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall61.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall62.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall63.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall64.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}
	if (centreWall65.BoundingBoxCollision(playerIn.getPosition(), playerIn.getMdlDimensions()))
	{
		std::cout << "collision detected" << std::endl;
		return true;
	}

	return false;
}

wallManager::~wallManager()
{

}