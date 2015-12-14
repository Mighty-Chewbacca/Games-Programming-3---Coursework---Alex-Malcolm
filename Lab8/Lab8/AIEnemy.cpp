#include "AIEnemy.h"

//create the map for the AI -- a 2d array of 1's or 0's - to represent walls and spaces
int map[14][14] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
	{ 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1 },
	{ 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1 },
	{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1 },
	{ 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};


//create the corresponding coords for the AI -- this will be a 2d array of vec3's which the ai will be using as world positions to move to when in a specific location
glm::vec3 mapCoords[14][14] =
{
	{ glm::vec3(0, 0, 26), glm::vec3(2, 0, 26), glm::vec3(4, 0, 26), glm::vec3(6, 0, 26), glm::vec3(8, 0, 26), glm::vec3(10, 0, 26), glm::vec3(12, 0, 26), glm::vec3(14, 0, 26), glm::vec3(16, 0, 26), glm::vec3(18, 0, 26), glm::vec3(20, 0, 26), glm::vec3(22, 0, 26), glm::vec3(24, 0, 26), glm::vec3(26, 0, 26) },
	{ glm::vec3(0, 0, 24), glm::vec3(2, 0, 24), glm::vec3(4, 0, 24), glm::vec3(6, 0, 24), glm::vec3(8, 0, 24), glm::vec3(10, 0, 24), glm::vec3(12, 0, 24), glm::vec3(14, 0, 24), glm::vec3(16, 0, 24), glm::vec3(18, 0, 24), glm::vec3(20, 0, 24), glm::vec3(22, 0, 24), glm::vec3(24, 0, 24), glm::vec3(26, 0, 24) },
	{ glm::vec3(0, 0, 22), glm::vec3(2, 0, 22), glm::vec3(4, 0, 22), glm::vec3(6, 0, 22), glm::vec3(8, 0, 22), glm::vec3(10, 0, 22), glm::vec3(12, 0, 22), glm::vec3(14, 0, 22), glm::vec3(16, 0, 22), glm::vec3(18, 0, 22), glm::vec3(20, 0, 22), glm::vec3(22, 0, 22), glm::vec3(24, 0, 22), glm::vec3(26, 0, 22) },
	{ glm::vec3(0, 0, 20), glm::vec3(2, 0, 22), glm::vec3(4, 0, 22), glm::vec3(6, 0, 22), glm::vec3(8, 0, 22), glm::vec3(10, 0, 20), glm::vec3(12, 0, 20), glm::vec3(14, 0, 20), glm::vec3(16, 0, 20), glm::vec3(18, 0, 20), glm::vec3(20, 0, 20), glm::vec3(22, 0, 20), glm::vec3(24, 0, 20), glm::vec3(26, 0, 20) },
	{ glm::vec3(0, 0, 18), glm::vec3(2, 0, 20), glm::vec3(4, 0, 20), glm::vec3(6, 0, 20), glm::vec3(8, 0, 20), glm::vec3(10, 0, 18), glm::vec3(12, 0, 18), glm::vec3(14, 0, 18), glm::vec3(16, 0, 20), glm::vec3(18, 0, 18), glm::vec3(20, 0, 18), glm::vec3(22, 0, 18), glm::vec3(24, 0, 18), glm::vec3(26, 0, 18) },
	{ glm::vec3(0, 0, 16), glm::vec3(2, 0, 18), glm::vec3(4, 0, 18), glm::vec3(6, 0, 18), glm::vec3(8, 0, 18), glm::vec3(10, 0, 16), glm::vec3(12, 0, 16), glm::vec3(14, 0, 16), glm::vec3(16, 0, 18), glm::vec3(18, 0, 16), glm::vec3(20, 0, 16), glm::vec3(22, 0, 16), glm::vec3(24, 0, 16), glm::vec3(26, 0, 16) },
	{ glm::vec3(0, 0, 14), glm::vec3(2, 0, 14), glm::vec3(4, 0, 14), glm::vec3(6, 0, 14), glm::vec3(8, 0, 14), glm::vec3(10, 0, 14), glm::vec3(12, 0, 14), glm::vec3(14, 0, 14), glm::vec3(16, 0, 14), glm::vec3(18, 0, 14), glm::vec3(20, 0, 14), glm::vec3(22, 0, 14), glm::vec3(24, 0, 14), glm::vec3(26, 0, 14) },
	{ glm::vec3(0, 0, 12), glm::vec3(2, 0, 12), glm::vec3(4, 0, 12), glm::vec3(6, 0, 12), glm::vec3(8, 0, 12), glm::vec3(10, 0, 12), glm::vec3(12, 0, 12), glm::vec3(14, 0, 12), glm::vec3(16, 0, 12), glm::vec3(18, 0, 12), glm::vec3(20, 0, 12), glm::vec3(22, 0, 12), glm::vec3(24, 0, 12), glm::vec3(26, 0, 12) },
	{ glm::vec3(0, 0, 10), glm::vec3(2, 0, 10), glm::vec3(4, 0, 10), glm::vec3(6, 0, 10), glm::vec3(8, 0, 10), glm::vec3(10, 0, 10), glm::vec3(12, 0, 10), glm::vec3(14, 0, 10), glm::vec3(16, 0, 10), glm::vec3(18, 0, 10), glm::vec3(20, 0, 10), glm::vec3(22, 0, 10), glm::vec3(24, 0, 10), glm::vec3(26, 0, 10) },
	{ glm::vec3(0, 0, 8), glm::vec3(2, 0, 8), glm::vec3(4, 0, 8), glm::vec3(6, 0, 8), glm::vec3(8, 0, 8), glm::vec3(10, 0, 8), glm::vec3(12, 0, 8), glm::vec3(14, 0, 8), glm::vec3(16, 0, 8), glm::vec3(18, 0, 8), glm::vec3(20, 0, 8), glm::vec3(22, 0, 8), glm::vec3(24, 0, 8), glm::vec3(26, 0, 8) },
	{ glm::vec3(0, 0, 6), glm::vec3(2, 0, 6), glm::vec3(4, 0, 6), glm::vec3(6, 0, 6), glm::vec3(8, 0, 6), glm::vec3(10, 0, 6), glm::vec3(12, 0, 6), glm::vec3(14, 0, 6), glm::vec3(16, 0, 6), glm::vec3(18, 0, 6), glm::vec3(20, 0, 6), glm::vec3(22, 0, 6), glm::vec3(24, 0, 6), glm::vec3(26, 0, 6) },
	{ glm::vec3(0, 0, 4), glm::vec3(2, 0, 4), glm::vec3(4, 0, 4), glm::vec3(6, 0, 4), glm::vec3(8, 0, 4), glm::vec3(10, 0, 4), glm::vec3(12, 0, 4), glm::vec3(14, 0, 4), glm::vec3(16, 0, 4), glm::vec3(18, 0, 4), glm::vec3(20, 0, 4), glm::vec3(22, 0, 4), glm::vec3(24, 0, 4), glm::vec3(26, 0, 4) },
	{ glm::vec3(0, 0, 2), glm::vec3(2, 0, 2), glm::vec3(4, 0, 2), glm::vec3(6, 0, 2), glm::vec3(8, 0, 2), glm::vec3(10, 0, 2), glm::vec3(12, 0, 2), glm::vec3(14, 0, 2), glm::vec3(16, 0, 2), glm::vec3(18, 0, 2), glm::vec3(20, 0, 2), glm::vec3(22, 0, 2), glm::vec3(24, 0, 2), glm::vec3(26, 0, 2) },
	{ glm::vec3(0, 0, 0), glm::vec3(2, 0, 0), glm::vec3(4, 0, 0), glm::vec3(6, 0, 0), glm::vec3(8, 0, 0), glm::vec3(10, 0, 0), glm::vec3(12, 0, 0), glm::vec3(14, 0, 0), glm::vec3(16, 0, 0), glm::vec3(18, 0, 0), glm::vec3(20, 0, 0), glm::vec3(22, 0, 0), glm::vec3(24, 0, 0), glm::vec3(26, 0, 0) }
};

//constructor
AIEnemy::AIEnemy()
{
	Print2dArrays(); //print both arrays to console to ensure they were initialised properly
	current = glm::vec2(8, 9); //set starting position
	GoToNextWaypoint(current); //let the ai go to current as its the first and needs to be here
	destination = ChooseNewDestination(); //use rng to choose new non wall destination
	path = DepthFirstSearch(); //find a path from starting point to end point
}

AIEnemy::~AIEnemy()
{

}

//mathod for choosing a new destination from the map array
glm::vec2 AIEnemy::ChooseNewDestination()
{
	int randX = 0;
	int randY = 0;

	while (map[randY][randX] == 1) //while there is a 1 in the chosen place, keep looping through this as that is a wall
	{
		srand(time(NULL));  //seed in the time as the seed - this sometimes ;eaves me looking for a rand for > 5 seconds which is baaaad
		//choose a random position that is NOT a wall. --  a wall is a 1 in the map array
		randX = rand() % 14+1;
		randY = rand() % 14+1;
		randX -= 1;
		randY -= 1;
		//need the rand to be between 0 and 13, but removing the plus 1 gave me bad results.

		std::cout << "randX: " << glm::to_string(randX);
		std::cout << "randY: " << glm::to_string(randY) << std::endl; //print the cords it has chosen as destination, if it gets past here, its a safe pos
	}
	glm::vec2 returnWaypoint(randX, randY); //create the vec2 to return	
	atDestination = false;

	std::cout << "New Destination Chosen: " << glm::to_string(returnWaypoint) << std::endl;
	std::cout << "Destination Value: " << glm::to_string(map[randY][randX]) << std::endl; //print the coord and value of destination

	int tempX = current.x;
	int tempY = current.y;
	std::cout << "Current Position: " << glm::to_string(current) << std::endl;
	std::cout << "Current Position Value: " << glm::to_string(map[tempY][tempX]) << std::endl; //print the coord and value of the current location
	Print2dArrays(); //reprint arrays so that we can manually check coords if needed

	return returnWaypoint;
}

// the depth first search method which will kick off the recursive searching, will look around the starting node for a path and then check in each direction
//again the vectors are messed around, but that was my initialising of the 2d array.
std::list<glm::vec2> AIEnemy::DepthFirstSearch()
{
	std::list<glm::vec2> up;
	std::list<glm::vec2> down;
	std::list<glm::vec2> left;
	std::list<glm::vec2> right; //create the 4 lists which will hold the paths found

	std::cout << "currentPos " << glm::to_string(current) << std::endl; //print current location
	int currX = current.x;
	int currY = current.y; //grab current location into 2 seperate ints for ease later
	std::cout << "looking at X " << currX;
	std::cout << "looking at Y " << currY << std::endl;

	if (map[currY - 1][currX] == 0) //up checker if it looks up, and sees a 0 we can go there and it adds to the up list
	{
		//add current and next to list
		up.push_back(current); //current place
		up.push_back(glm::vec2(currX, currY - 1)); //next up one
		std::cout << "looking up at " << glm::to_string(glm::vec2(currX, currY - 1)) << std::endl; //print the coord that we have found is a 0
		std::cout << "Value: " << glm::to_string(map[currY - 1][currX]) << std::endl; //print its value just to be sure
	}

	if (map[currY + 1][currX] == 0) //down checker if it looks up, and sees a 0 we can go there and it adds to the down list
	{
		//add current and next to list
		down.push_back(current);
		down.push_back(glm::vec2(currX, currY + 1));
		std::cout << "looking down at " << glm::to_string(glm::vec2(currX, currY + 1)) << std::endl;
		std::cout << "Value: " << glm::to_string(map[currY + 1][currX]) << std::endl;
	}

	if (map[currY][currX + 1] == 0) //right checker if it looks up, and sees a 0 we can go there and it adds to the right list
	{
		//add current and next to list
		right.push_back(current);
		right.push_back(glm::vec2(currX + 1, currY));
		std::cout << "looking right at " << glm::to_string(glm::vec2(currX + 1, currY)) << std::endl;
		std::cout << "Value: " << glm::to_string(map[currY][currX + 1]) << std::endl;
	}

	if (map[currY][currX - 1] == 0) //left checker if it looks up, and sees a 0 we can go there and it adds to the left list
	{
		//add current and next to list
		left.push_back(current);
		left.push_back(glm::vec2(currX - 1, currY));
		std::cout << "looking left at " << glm::to_string(glm::vec2(currX - 1, currY)) << std::endl;
		std::cout << "Value: " << glm::to_string(map[currY][currX - 1]) << std::endl;
	}

	//now that we have looked immediatly around the starting location
	//if there was anything in any of these lists it means there was a space to walk on in that direction
	//so we want to now go through each list, and call the DFS method to search fully for a path
	if (up.size() > 0) 
	{
		//search up :)
		std::list<glm::vec2> result = DFS(up, destination); //this method will only return a list WITH elements if the destination is found
		if (result.size() > 0)
		{
			return result;
		}
		
	}
		else if (down.size() > 0)
		{
			//search down
			std::list<glm::vec2> result = DFS(down, destination);//this method will only return a list WITH elements if the destination is found
			if (result.size() > 0)
			{
				return result;
			}
		}

			else if (left.size() > 0)
			{
				//search left
				std::list<glm::vec2> result = DFS(left, destination);//this method will only return a list WITH elements if the destination is found
				if (result.size() > 0)
				{
					return result;
				}
			}

				else if (right.size() > 0)
				{
					//search right
					std::list<glm::vec2> result = DFS(right, destination);//this method will only return a list WITH elements if the destination is found
					if (result.size() > 0)
					{
						return result;
					}
				}
}

//this is the main recursive search method, it is able to #call itself and will return a list of vec2's ONLY if the destination is found, otherwise it returns an empyy list
std::list<glm::vec2> AIEnemy::DFS(std::list <glm::vec2> listIn, glm::vec2 targetPosition)
{
	//std::for_each(listIn.begin, listIn.end, GoToNextWaypoint); //example of a foreach incase i need it later

	//create an empty list that we can return incase nothing is found
	std::list<glm::vec2> emptyList;
	emptyList.clear(); //ensure its empty even though ive not put anything in it -- funny bug earlier

	int listSize = listIn.size();

	glm::vec2 currentPos = listIn.back(); //grab the final element in the array, as it is the furthest advanced into the path
	int currX = currentPos.x;
	int currY = currentPos.y;
	std::cout << "DFS enterd for: " << glm::to_string(currentPos) << std::endl; //print this so we can seethe path progressing as it searched

	//as if we are at the goal here at the top, and if we are, return the list else continue on
	if (currentPos == targetPosition)
	{
		std::cout << "Should have found the goal " << glm::to_string(destination) << std::endl;
		return listIn; //only returns this when it has found the goal here
	}

	//it clearly hasnt found the goal, so check around this current waypoint
	//these next statements are nearly identical to the above method all 4 do the same thing as well so only the first is commented
	if (map[currY - 1][currX] == 0) //if we find a space in this direction enter here
	{
		std::list<glm::vec2> forwardingList = listIn; //create a list that we can pass into the recursive method
		glm::vec2 nextPos(currX, currY - 1); //create a vector which represents the location we just found to be a 0
		std::cout << "found a space up its coord is " << glm::to_string(nextPos) << std::endl; //print it for debugging
		if (CheckIfContains(forwardingList, nextPos) == false) //now if the found waypoint is NOT already in the list search again using it as the staritng point
		{
			forwardingList.push_back(nextPos); //push it onto the back of the list as dfs always runs from the back
			std::cout << "this waypoint is not already in the path " << glm::to_string(nextPos) << std::endl;
			std::list<glm::vec2> result = DFS(forwardingList, targetPosition); //recursion :) calls this method and passes in the new list, agian this will only ever return a list if the destination is found
			if (result.size() > 0)
			{
				return result; //the destination must have been found if the list is populated, return the path to it!
			}
		}
	}

	if (map[currY + 1][currX] == 0) //down
	{
		std::list<glm::vec2> forwardingList = listIn;
		glm::vec2 nextPos(currX, currY + 1);
		std::cout << "found a space down its coord is " << glm::to_string(nextPos) << std::endl;
		if (CheckIfContains(forwardingList, nextPos) == false)
		{
			forwardingList.push_back(nextPos);
			std::cout << "this waypoint is not already in the path " << glm::to_string(nextPos) << std::endl;
			std::list<glm::vec2> result = DFS(forwardingList, targetPosition);
			if (result.size() > 0)
			{
				return result;
			}
		}
	}

	if (map[currY][currX - 1] == 0) //left
	{
		std::list<glm::vec2> forwardingList = listIn;
		glm::vec2 nextPos(currX - 1, currY);
		std::cout << "found a space left its coord is " << glm::to_string(nextPos) << std::endl;
		if (CheckIfContains(forwardingList, nextPos) == false)
		{
			forwardingList.push_back(nextPos);
			std::cout << "this waypoint is not already in the path " << glm::to_string(nextPos) << std::endl;
			std::list<glm::vec2> result = DFS(forwardingList, targetPosition);
			if (result.size() > 0)
			{
				return result;
			}
		}
	}

	if (map[currY][currX + 1] == 0) //right
	{
		std::list<glm::vec2> forwardingList = listIn;
		
		glm::vec2 nextPos(currX + 1, currY);
		std::cout << "found a space right its coord is " << glm::to_string(nextPos) << std::endl;
		if (CheckIfContains(forwardingList, nextPos) == false)
		{
			forwardingList.push_back(nextPos);
			std::cout << "this waypoint is not already in the path " << glm::to_string(nextPos) << std::endl;
			std::list<glm::vec2> result = DFS(forwardingList, targetPosition);
			if (result.size() > 0)
			{
				return result;
			}
		}
	}


	//only returns this if not path found
	return emptyList;
}

//simple method that is meant to move the ai to the next waypoint, but never worked so just prints to the console the next waypoints location in space
void AIEnemy::GoToNextWaypoint(glm::vec2 waypointIn)
{
	std::cout << "Moved To: " << glm::to_string(waypointIn) << std::endl; //use this to print out that the ai has moved into the path, as i couldnt
																		  //get the model actually moving for some reason
}

//returns the next position in the path
glm::vec3 AIEnemy::getNextPosition()
{
	std::list<glm::vec2> tempList = path; //we have to mess around as i am doing lists, you cannot access specific elements from what i found

	if (tempList.size() < 1) //as long as there is something in the list -- dont want to iterate an empty list!
	{
		tempList.pop_front(); //take the front off, as this is the current location
		next = tempList.front(); //set the next coord to the new front
		GoToNextWaypoint(next); //call the wee goto method
		current = next; //now set current to next as we have "moved there"
		path = tempList; //and now we alter the path as it now has a new front value

		return GetCoord(next); //while there is something in the list, return the positon just moved to
	}

	return GetCoord(current); //if there is nothing in the list anymore, just return the current location, no need to move.
}

//simple method tat is done when enemy ai is initialised, return the first coord publicly so that the model can grab it
glm::vec3 AIEnemy::getFirstPosition()
{
	return GetCoord(current);
}

//returns the vec3 coord which relates to the vec2 coord passed into it
glm::vec3 AIEnemy::GetCoord(glm::vec2 arrayPos)
{
	int tempX = arrayPos.x;
	int tempY = arrayPos.y;

	glm::vec3 returnCoords = mapCoords[tempY][tempX]; //have to switch the x and y, as the way i defined the arrays i accidentaly used rows as columns and vice versa

	return returnCoords;
}

//simple update method, was meant to reselect a new path as soon as it hit the destination, and it works, however as we are not mving to the destination i
//disabled it so that it does not spam the console when you are trying to debug
void AIEnemy::Update()
{
	if (current == destination) //if the current is the same as the destination, we are here!
	{
		atDestination = true;
	}

	if (atDestination) //if we are at the destionatiom, choose a new one and find the path for it.
	{
		//destination = ChooseNewDestination();
		//path = DepthFirstSearch();
		std::cout << "Reached Destintion" << std::endl;
	}
}

//simple method to check through a list and find out of the input vec2 is in there anywhere, we dont want to add the node to the list if its already there!
bool AIEnemy::CheckIfContains(std::list<glm::vec2> listIn, glm::vec2 comparison)
{
	if (std::find(listIn.begin(), listIn.end(), comparison) != listIn.end() ) // iterate through the list, from beginning to end looking for "comparison"
	{
		return true;
	}
	//else return false :)
	return false;
}

//simple method to console display all of the 2d arrays
void AIEnemy::Print2dArrays()
{
	std::cout << "Map Array" << std::endl;
	for (int i = 0; i < 14; ++i) //iterate through the first dimension
	{
		for (int j = 0; j < 14; ++j) //iterate through the second dimension
		{
			std::cout << map[i][j] << ' ';
		}
		std::cout << std::endl; //only end the line once we have hit the end of a row
	}
	std::cout << "" << std::endl; //then once all the rows are printed, end the printing

	//std::cout << "Map Array" << std::endl;
	//for (int i = 0; i < 14; ++i)
	//{
	//	for (int j = 0; j < 14; ++j)
	//	{
	//		std::cout << map[i][j] << ' ';
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << "" << std::endl;

	//std::cout << "Coord Array" << std::endl;
	//for (int i = 0; i < 14; ++i)
	//{
	//	for (int j = 0; j < 14; ++j)
	//	{
	//		std::cout << glm::to_string(mapCoords[i][j]) << ' ';
	//	}
	//	std::cout << std::endl;
	//}
	std::cout << "" << std::endl;
}
