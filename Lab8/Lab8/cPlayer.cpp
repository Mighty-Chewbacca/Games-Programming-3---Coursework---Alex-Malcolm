#include "cPlayer.h"

cPlayer::cPlayer() : cModel()
{
	
}

void cPlayer::attachInputMgr(cInputMgr* inputMgr)
{
	m_InputMgr = inputMgr;
}

void cPlayer::attachSoundMgr(cSoundMgr* soundMgr)
{
	m_SoundMgr = soundMgr;
}

void cPlayer::update(float elapsedTime)
{
	//if (m_InputMgr->isKeyDown(DKey))
	//{
	//	cModel::m_mdlPosition.x += 0.5f;
	//}
	//if (m_InputMgr->isKeyDown(AKey))
	//{
	//	cModel::m_mdlPosition.x -= 0.5f;
	//}
	//if (m_InputMgr->isKeyDown(WKey))
	//{
	//	cModel::m_mdlPosition.z -= 0.5f;
	//}
	//if (m_InputMgr->isKeyDown(SKey))
	//{
	//	cModel::m_mdlPosition.z += 0.5f;
	//}


	// Find out what direction we should be thrusting, using rotation.
	glm::vec3 mdlVelocityAdd;
	mdlVelocityAdd.x = -(float)glm::sin(cModel::m_mdlRotation);  // Remember to adjust for radians
	mdlVelocityAdd.y = 0.0f;
	mdlVelocityAdd.z = -(float)glm::cos(cModel::m_mdlRotation);

	cModel::m_mdlRotation -= rotationAngle;

	mdlVelocityAdd *= translationZ;
	cModel::m_mdlDirection += mdlVelocityAdd;

	cModel::m_mdlPosition += cModel::m_mdlDirection * cModel::m_mdlSpeed *elapsedTime;
	cModel::m_mdlDirection *= 0.95f;

	rotationAngle = 0;
	translationZ = 0;
}

cPlayer::~cPlayer()
{

}