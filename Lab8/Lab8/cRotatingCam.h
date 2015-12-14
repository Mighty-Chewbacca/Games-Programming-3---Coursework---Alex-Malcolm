#ifndef _CROTATINGCAMERA_H
#define _CROTATINGCAMERA_H

// OpenGL Headers
#include "GameConstants.h"

using namespace std;

class cRotatingCam
{
private:
	glm::vec3 m_CameraPos;
	glm::vec3 m_CameraTarget;
	glm::vec3 m_CameraDirection;
	glm::vec3 m_Up;
	glm::vec3 m_CameraRight;
	glm::vec3 m_CameraUp;
	glm::mat4 m_View;
	glm::vec3 m_CameraFront;

public:

	cRotatingCam();
	~cRotatingCam();

	glm::mat4 getViewMatrix();
	glm::vec3 getPosition();
	void Update(float elapsedtime);
};
#endif