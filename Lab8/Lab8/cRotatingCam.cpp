#include "cRotatingCam.h"

//contstructor define sinitial values
cRotatingCam::cRotatingCam()
{
	m_CameraPos = glm::vec3(13.0f, 10.0f, 13.0f); //cams location

	m_CameraTarget = glm::vec3(13.0f, 0.0f, 13.0f); //what it is looking at
	m_CameraDirection = glm::normalize(m_CameraPos - m_CameraTarget); //the direction vector

	m_Up = glm::vec3(0.0f, 0.0f, 1.0f); //upvec
	m_CameraRight = glm::normalize(glm::cross(m_Up, m_CameraDirection)); //the cameras right

	m_CameraUp = glm::cross(m_CameraDirection, m_CameraRight); //cameras up
	m_View = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), //initial view matrix
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));
}

cRotatingCam::~cRotatingCam()
{

}

//returns the view matri=x so that we can use the camerea to render
glm::mat4 cRotatingCam::getViewMatrix()
{
	return m_View;
}

//returns the cams position incase i need it
glm::vec3 cRotatingCam::getPosition()
{
	return m_CameraPos;
}

//simple rotates the camera around its target lookat using the radius and the elapsed time to tell where it should be
//should smoothly circulate the taget
void cRotatingCam::Update(float elapsedtime)
{
	float radius = 40.0f;
	float camX = (sin(elapsedtime) * radius) /2;
	float camZ = (cos(elapsedtime) * radius) /2;
	glm::mat4 view;
	m_View = glm::lookAt(glm::vec3(camX, 20.0, camZ), glm::vec3(0.0, 10.0, 0.0), glm::vec3(0.0, 10.0, 0.0));
}
