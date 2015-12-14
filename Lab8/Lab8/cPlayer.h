#ifndef _CPLAYER_H
#define _CPLAYER_H

#include "GameConstants.h"
#include "cModel.h"
#include "cInputMgr.h"
#include "cCamera.h"
#include "cSoundMgr.h"

class cPlayer : public cModel
{
private:
	cInputMgr* m_InputMgr;
	cSoundMgr* m_SoundMgr;

public:
	cPlayer();
	void attachInputMgr(cInputMgr* inputMgr);
	void attachSoundMgr(cSoundMgr* soundMgr);
	virtual void update(float elapsedTime);

	~cPlayer();
};
#endif