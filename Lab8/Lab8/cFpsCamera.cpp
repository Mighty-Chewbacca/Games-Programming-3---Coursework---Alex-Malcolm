#include "cFpsCamera.h"

//constructor for the fps cam which will take the users input, sets all the initial variables as usual
cFpsCamera::cFpsCamera()
{
	m_CameraPos = glm::vec3(2.0f, 10.0f, 2.0f);
	m_CameraTarget = glm::vec3(2.0f, 10.0f, 12.0f);
	m_CameraDirection = glm::normalize(m_CameraPos - m_CameraTarget);
	m_Up = glm::vec3(0.0f, 1.0f, 0.0f);
	m_CameraRight = glm::normalize(glm::cross(m_Up, m_CameraDirection));
	m_CameraUp = glm::cross(m_CameraDirection, m_CameraRight);
	m_CameraFront = glm::vec3(0.0f, 0.0f, -1.0f);

	m_View = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));

	//need these coords sets the first ever usage of the camera to the centre of the screen or else we would rotate in funny ways and run out of screen easily
	lastX = GetSystemMetrics(SM_CXSCREEN) / 2;
	lastY = GetSystemMetrics(SM_CYSCREEN) / 2;

	yaw = -90.0f;	// Yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right (due to how Eular angles work) so we initially rotate a bit to the left.
	pitch = 0.0f;
}

//attach the input manager instance 
void cFpsCamera::attachInputMgr(cInputMgr* inputMgr)
{
	m_InputMgr = inputMgr;
}

cFpsCamera::~cFpsCamera()
{

}

//rturn the view matrix for rendering
glm::mat4 cFpsCamera::getViewMatrix()
{
	return m_View;
}

//return position, allows me to set player models position to follow this camera
glm::vec3 cFpsCamera::getPosition()
{
	return m_CameraPos;
}
//set the camera back to the previous location if a collision was detected this is called
void cFpsCamera::undoMovement()
{
	m_CameraPos = previousPosition;
}

//returns the direction vector, was using this so that i could make the torch follow the cameras look, but did not work
glm::vec3 cFpsCamera::getDirection()
{
	return m_CameraDirection;
}

//this is the method that does the movement as opposed to update, defines a speed for the camera and then queries all arrow keys and wasd to see if they are pressed
//intended to create an array of sorts which would hold pressed buttons to allow for pressing moer than one at once., howevr i was unable to get it working
//so for time restraints i removed that
void cFpsCamera::doMovement()
{
	float m_Speed = 0.5f;

	previousPosition = m_CameraPos;

	if (m_InputMgr->isKeyDown(DKey) || m_InputMgr->isKeyDown(VK_RIGHT)) //D key or right arrow
	{
		m_CameraPos += glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * m_Speed;
	}
	if (m_InputMgr->isKeyDown(AKey) || m_InputMgr->isKeyDown(VK_LEFT)) //a key or left arrow
	{
		m_CameraPos -= glm::normalize(glm::cross(m_CameraFront, m_CameraUp)) * m_Speed;
	}
	if (m_InputMgr->isKeyDown(WKey) || m_InputMgr->isKeyDown(VK_UP)) //w key or up arrow
	{
		m_CameraPos += m_Speed * m_CameraFront;
	}
	if (m_InputMgr->isKeyDown(SKey) || m_InputMgr->isKeyDown(VK_DOWN)) //s key or down arrow
	{
		m_CameraPos -= m_Speed * m_CameraFront;
	}
	//we move by multiplying the entire position against the front vector of the camera and the speed, this allows us to move on more than one axis if we are not
	//looking directly aligned with an axis

	if (m_InputMgr->isKeyDown(VK_NUMPAD0)) //if 0 is pressed, we toggle debug mode
	{
		IsDebug = !IsDebug;

		std::cout << "isdebug:" << IsDebug <<std::endl;
	}

	if (m_InputMgr->isKeyDown(VK_SPACE)) //if space is pressed we go up
	{
		m_CameraPos.y += m_Speed;
	}
	 
	if (m_InputMgr->isKeyDown(VK_CONTROL)) //if control is pressed we go down
	{
		m_CameraPos.y -= m_Speed;
	}
}

//update method updates the lookat and stuff
void cFpsCamera::Update(float elapsedtime)
{
	m_View = glm::lookAt(m_CameraPos, m_CameraPos + m_CameraFront, m_CameraUp);

	if (!IsDebug)
	{
		m_CameraPos.y = 2.0; //if we are not in debug mode make sure that we stay at the eye level height
	}

	int xPos = m_InputMgr->getMouseXPos();
	int yPos = m_InputMgr->getMouseYPos(); //get the x and y positions of the mouse

	float xoffset = xPos - lastX;
	float yoffset = lastY - yPos; // checks the current mouse locations against the last frame

	if (xoffset != 0 || yoffset != 0)
	{
		float sensitivity = 0.5;	// if it hasny moved then it wont change the pitch or yaw, if it has then it will adjust them
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		yaw += xoffset;
		pitch += yoffset;

		// Make sure that when pitch is out of bounds, screen doesn't get flipped around the wrong way when moving the mouse, keep it unable to roll over itself
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		//now update the front vector and normalize it to allow it to be used
		glm::vec3 front;
		front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		front.y = sin(glm::radians(pitch));
		front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		m_CameraFront = glm::normalize(front);

		//update the stored mouse positions
		lastX = xPos;
		lastY = yPos;
	}
}
