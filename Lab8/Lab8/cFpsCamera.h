#ifndef _CFPSCAMERA_H
#define _CFPSCAMERA_H

// OpenGL Headers
#include "GameConstants.h"
#include "cInputMgr.h"
#include "wallManager.h"

using namespace std;

class cFpsCamera
{
private:
	cInputMgr* m_InputMgr;

	glm::vec3 m_CameraPos;
	glm::vec3 m_CameraTarget;
	glm::vec3 m_CameraDirection;
	glm::vec3 m_Up;
	glm::vec3 m_CameraRight;
	glm::vec3 m_CameraUp;
	glm::mat4 m_View;
	glm::vec3 m_CameraFront;
	glm::vec3 previousPosition;
	float lastX;
	float lastY;
	float yaw;
	float pitch;

public:

	cFpsCamera();
	~cFpsCamera();

	void attachInputMgr(cInputMgr* inputMgr);
	glm::mat4 getViewMatrix();
	glm::vec3 getPosition();
	void doMovement();
	void undoMovement();
	glm::vec3 getDirection();

	void Update(float elapsedtime);
};
#endif