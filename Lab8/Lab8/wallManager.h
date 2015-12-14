#ifndef _WALLMANAGER_H
#define _WALLMANAGER_H

#include "GameConstants.h"
#include "cModelLoader.h"
#include "cModel.h"
#include "cWall.h"
#include "cPlayer.h"

class wallManager
{
private:

public:
	wallManager();

	void renderWalls();
	void createWalls();
	void setPositions();
	void setScales();
	void setModelDimensions();
	bool CheckWallCollisions(cPlayer playerIn);
	~wallManager();
};
#endif