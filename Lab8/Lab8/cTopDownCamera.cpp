#include "cTopDownCamera.h"

//same constructor as other custom cams, sets initial values
cTopDownCamera::cTopDownCamera()
{
	m_CameraPos = glm::vec3(13.0f, 10.0f, 13.0f);

	m_CameraTarget = glm::vec3(13.0f, 0.0f, 13.0f);
	m_CameraDirection = glm::normalize(m_CameraPos - m_CameraTarget);

	m_Up = glm::vec3(0.0f, 0.0f, 1.0f);
	m_CameraRight = glm::normalize(glm::cross(m_Up, m_CameraDirection));

	m_CameraUp = glm::cross(m_CameraDirection, m_CameraRight);
	m_View = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));
}

cTopDownCamera::~cTopDownCamera()
{

}

//returns the view matrix for gl useage
glm::mat4 cTopDownCamera::getViewMatrix()
{
	return m_View;
}
//returns the position incase i need it
glm::vec3 cTopDownCamera::getPosition()
{
	return m_CameraPos;
}
//no real need for the update, but i wasnt sure if it would render properly without, so i left it in
void cTopDownCamera::Update(float elapsedtime)
{
	//doesnt change the view matrix, just reapplies it
	m_View = glm::lookAt(glm::vec3(13.0f, 50.0f, 13.0f), glm::vec3(13.0f, 0.0f, 13.0f), glm::vec3(0.0, 0.0, 1.0));
}
