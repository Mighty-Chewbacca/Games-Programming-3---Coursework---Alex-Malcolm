#ifndef _AIENEMY_H
#define _AIENEMY_H

#include "GameConstants.h"
#include "cModel.h"
#include <time.h>

class AIEnemy
{
private:

	glm::vec2 destination;
	glm::vec2 current;
	glm::vec2 next;
	bool atDestination = false;
	std::list<glm::vec2> path;

public:
	AIEnemy();
	~AIEnemy();

	glm::vec2 ChooseNewDestination();
	std::list<glm::vec2> DepthFirstSearch();
	std::list<glm::vec2> DFS(std::list <glm::vec2> listIn, glm::vec2 targetPosition);
	void GoToNextWaypoint(glm::vec2 waypointIn);

	void Print2dArrays();

	bool CheckIfContains(std::list<glm::vec2> listIn, glm::vec2 comparison);
	glm::vec3 GetCoord(glm::vec2 arrayPos);

	glm::vec3 getNextPosition();
	glm::vec3 getFirstPosition();

	void Update();
};
#endif