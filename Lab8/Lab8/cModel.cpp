#include "cModel.h"

cModel::cModel()
{
	m_mdlPosition = glm::vec3(0.0f, 0.0f, 0.0f);
	m_mdlRotation = 0.0f;
	m_mdlDirection = glm::vec3(0.0f, 0.0f, 0.0f);
	m_mdlSpeed = 0.0f;
	m_IsActive = false;
	m_mdlScale = glm::vec3(1.0f, 1.0f, 1.0f);
	m_Dimensions.s_mdldepth = 0.0f;
	m_Dimensions.s_mdlheight = 0.0f;
	m_Dimensions.s_mdlWidth = 0.0f;
	m_mdlRadius = m_Dimensions.s_mdldepth / 2;
	m_TextureID = 0;
}

// +++++++++++++++++++++++++++++++++++++++++++++
// Setters
// +++++++++++++++++++++++++++++++++++++++++++++

void cModel::setPosition(glm::vec3 mdlPosition)
{
	m_mdlPosition = mdlPosition;
}

void cModel::setRotation(GLfloat mdlRotation)
{
	m_mdlRotation = mdlRotation;
}

void cModel::setDirection(glm::vec3 mdlDirection)
{
	m_mdlDirection = mdlDirection;
}

void cModel::setSpeed(float mdlSpeed)
{
	m_mdlSpeed = mdlSpeed;
}

void cModel::setIsActive(bool mdlIsActive)
{
	m_IsActive = mdlIsActive;
}

void cModel::setMdlDimensions(mdlDimensions mdlDims)
{
	m_Dimensions = mdlDims;
	m_mdlRadius = m_Dimensions.s_mdldepth / 2;
}

void cModel::setMdlRadius(float mdlRadius)
{
	m_mdlRadius = mdlRadius;
}

void cModel::setScale(glm::vec3 mdlScale)
{
	m_mdlScale = mdlScale;

	m_Dimensions.s_mdldepth *= mdlScale.z;
	m_Dimensions.s_mdlheight *= mdlScale.y;
	m_Dimensions.s_mdlWidth *= mdlScale.x;
}

// +++++++++++++++++++++++++++++++++++++++++++++
// Getters
// +++++++++++++++++++++++++++++++++++++++++++++

glm::vec3 cModel::getPosition()
{
	return m_mdlPosition;
}

GLfloat cModel::getRotation()
{
	return m_mdlRotation;
}

glm::vec3 cModel::getDirection()
{
	return m_mdlDirection;
}

float cModel::getSpeed()
{
	return m_mdlSpeed;
}

bool cModel::isActive()
{
	return m_IsActive;
}

mdlDimensions cModel::getMdlDimensions()
{
	return m_Dimensions;
}

float cModel::getMdlRadius()
{
	return m_mdlRadius;
}

glm::vec3 cModel::getScale()
{
	return m_mdlScale;
}

void cModel::setTextureID(GLuint theTextureID)
{
	m_TextureID = theTextureID;
}

void cModel::initialise(glm::vec3 mdlPosition, GLfloat mdlRotation, glm::vec3 mdlScale, glm::vec3 mdlDirection, float mdlSpeed, bool mdlIsActive)
{
	setPosition(mdlPosition);
	setRotation(mdlRotation);
	setScale(mdlScale);
	setDirection(mdlDirection);
	setSpeed(mdlSpeed);
	setIsActive(mdlIsActive);
	m_Dimensions.s_mdldepth = 0.0f;
	m_Dimensions.s_mdlheight = 0.0f;
	m_Dimensions.s_mdlWidth = 0.0f;
	m_mdlRadius = m_Dimensions.s_mdldepth / 2;
	glm::vec3 mdlPos = getPosition();
	GLfloat mdlRot = getRotation();
	glRotatef(mdlRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(mdlPos.x,mdlPos.y,mdlPos.z);
}

bool cModel::SphereSphereCollision(glm::vec3 mdlPosition, float mdlRadius)
{
	const float distSq = lengthSQRD(m_mdlPosition - mdlPosition);

	const float sumRadius = (m_mdlRadius + mdlRadius);

	if (distSq < sumRadius * sumRadius)
	{
		return true; // Collision
	}
	return false; // No Collision
}

float cModel::lengthSQRD(glm::vec3 mdlLength)
{
	return (mdlLength.x * mdlLength.x) + (mdlLength.y * mdlLength.y) + (mdlLength.z * mdlLength.z);
}

bool cModel::BoundingBoxCollision(glm::vec3 inPosition, mdlDimensions inDimensions)
{
	//check for collisions in here
	mdlDimensions thisModelDimensions, otherModelDimensions;

	glm::vec3 thisModelPosition, otherModelPosition;

	thisModelDimensions = m_Dimensions;
	otherModelDimensions = inDimensions;

	thisModelPosition = m_mdlPosition;
	otherModelPosition = inPosition;

	//create the 2 bounding boxes using min and max for each axis per model.
	//this model
	float thisModelMinX = thisModelPosition.x; 									
	float thisModelMaxX = (thisModelPosition.x + thisModelDimensions.s_mdlWidth);	

	float thisModelMinY = thisModelPosition.y - 100;
	float thisModelMaxY = thisModelPosition.y + thisModelDimensions.s_mdlheight + 100;	

	float thisModelMinZ = thisModelPosition.z;
	float thisModelMaxZ = thisModelPosition.z + thisModelDimensions.s_mdldepth;

	//other model
	float otherModelMinX = otherModelPosition.x;
	float otherModelMaxX = otherModelPosition.x + otherModelDimensions.s_mdlWidth;

	float otherModelMinY = otherModelPosition.y - 100;
	float otherModelMaxY = otherModelPosition.y + otherModelDimensions.s_mdlheight + 100;

	float otherModelMinZ = otherModelPosition.z;
	float otherModelMaxZ = otherModelPosition.z + otherModelDimensions.s_mdldepth;

	//hopefully this has created the correct bounds...needs to be tested.

	if ((thisModelMaxX > otherModelMinX && thisModelMaxX < otherModelMaxX) || (thisModelMinX > otherModelMinX && thisModelMinX < otherModelMaxX))
	{
		//the x axes are aligned --> but we dont know if it has intersected on the z or y yet

		//now check the zplane.
		if ((thisModelMaxZ > otherModelMinZ && thisModelMaxZ < otherModelMaxZ) || (thisModelMinZ > otherModelMinZ && thisModelMinZ < otherModelMaxZ))
		{
			//it is positions both in the z and x axis, we now need to see if it is also the same for the y --> only then is there collision

			if ((thisModelMaxY > otherModelMinY && thisModelMaxY < otherModelMaxY) || (thisModelMinY > otherModelMinY && thisModelMinY < otherModelMaxY))
			{
				//they have aligned in some place on all axes, so a collision has occured
				//std::cout << "collision on x axis: this Models  minX:" << thisModelMinX << "maxX:" << thisModelMaxX << std::endl;
				//std::cout << "collision on x axis: other(player) Models  minX:" << otherModelMinX << "maxX:" << otherModelMaxX << std::endl;
				//std::cout << "collision on Z axis: this Models  minZ:" << thisModelMinZ << "maxZ:" << thisModelMaxZ << std::endl;
				//std::cout << "collision on Z axis: other(player) Models  minZ:" << otherModelMinZ << "maxZ:" << otherModelMaxZ << std::endl;
				//std::cout << "collision on y axis: this Models  minY:" << thisModelMinY << "maxY:" << thisModelMaxY << std::endl;
				//std::cout << "collision on y axis: other(player) Models  minY:" << otherModelMinY << "maxY:" << otherModelMaxY << std::endl;

				std::cout << "we found a collision here" << std::endl;
				return true;
			}
		}
	}

		return false;

}

cModel::~cModel()
{

}
