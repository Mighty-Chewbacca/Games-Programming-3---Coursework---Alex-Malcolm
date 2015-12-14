/*
==========================================================================
cCamera.h
==========================================================================
*/

#ifndef _CAMERA_H
#define _CAMERA_H

// OpenGL Headers
#include "GameConstants.h"

using namespace std;

class cCamera
{
private:

	//--------------------------------------------------------------------------------------
	// Added for the creation of a camera
	//--------------------------------------------------------------------------------------
	glm::vec3 m_cameraLookAt;		// Where the camera is looking
	glm::vec3 m_cameraUpVector;		// Cameras up vector
	//missing nearclip?
	//missing farclip?
	//missing fov?
	GLfloat m_AspectRatio;
	glm::mat4 m_camViewMatrix;		// Cameras view
	glm::mat4 m_ProjectionMatrix;	// Projection Matrix
	float m_yaw;						//missing yaw?
	float m_pitch;					//missing pitch?
	glm::vec3 m_cameraDirection;	// direction it is pointing at
	glm::vec3 m_cameraStrafe;		// Strafe - move on X -- right vector...
	glm::vec3 m_cameraPos;			// Position of Camera in world
	glm::vec3 m_rotation;
	

	//dunno if i need these
	glm::mat4 m_camRotationMatrix;	// Rotation Matrix for camera to reflect movement around Y Axis
	glm::vec3 m_camTransform;		// Used for repositioning the camer after it has been rotated
	glm::vec4 m_viewPort;


public:

	cCamera();
	cCamera(int screenWidth, int screenHeight);
	~cCamera();

	void setTheViewPort(int x, int y, int width, int height);
	const glm::vec4 getTheViewPort();

	void setCamViewMatrix();
	glm::mat4 getCamViewMatrix();

	void setTheCameraPos(glm::vec3 camPos);
	glm::vec3 getTheCameraPos();

	void setTheCameraUpVector(glm::vec3 camPosUpVec);
	glm::vec3 getTheCameraUpVector();

	void setTheCameraLookAt(glm::vec3 camLookAt);
	glm::vec3 getTheCameraLookAt();

	void setTheCameraDirection();
	glm::vec3 getTheCameraDirection();

	void setTheCameraStrafe();
	glm::vec3 getTheCameraStrafe();

	void setTheCameraAspectRatio(GLfloat width, GLfloat height);
	GLfloat getTheCameraAspectRatio();

	void setTheProjectionMatrix(float fov, float aspectRatio, float nearCP, float farCP);
	glm::mat4 getTheProjectionMatrix();
	glm::mat4 getTheViewMatrix();

	//yaw pitch stuff
	float getYaw();
	float getPitch();
	void setYaw(float yaw);
	void setPitch(float pitch);

	//rotation stuff
	glm::vec3 getRotation();
	void setRotation(glm::vec3 rot);

	void update();
};
#endif