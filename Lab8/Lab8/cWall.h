#ifndef _CWALL_H
#define _CWALL_H

#include "GameConstants.h"
#include "cModel.h"

class cWall : public cModel
{
private:

public:
	cWall();

	virtual void update(float elapsedTime);

	~cWall();
};
#endif