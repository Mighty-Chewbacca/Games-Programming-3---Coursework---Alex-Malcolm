#ifndef _CTOPDOWNCAMERA_H
#define CTOPDOWNCAMERA

// OpenGL Headers
#include "GameConstants.h"

using namespace std;

class cTopDownCamera
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

	cTopDownCamera();
	~cTopDownCamera();

	glm::mat4 getViewMatrix();
	glm::vec3 getPosition();

	void Update(float elapsedtime);
};
#endif