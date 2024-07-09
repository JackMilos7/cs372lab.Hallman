//File: KevinBacon.cpp
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include<iostream>
#include<fstream>
#include<sstream>
#include<list>
#include<iomanip>
#include "AdjMatrixGraph.h"

const std::string KEVIN = "KevinBacon", ME = "Jackson";
void visit(int aNode)
{
	std::cout << aNode << " ";
};

bool hasCycle(std::string path, AdjMatrixGraph<std::string> &graph)
{
	std::stringstream pathStream;
	pathStream.str(path);
	std::string source, dest;
	std::vector<std::string> visited;

	pathStream >> source >> dest;
	visited.push_back(source);
	visited.push_back(dest);
	
	if (!graph.adjacent(source, dest))
	{
		std::cout << "Invalid path.\n";
		return false;
	}
	else if (source == dest)
	{
		std::cout << "There is a cycle in the path: \"" << path << "\"\n";
		return false;
	}
	else
	{
		source = dest;
		while (pathStream >> dest)
		{	
			if (!graph.adjacent(source, dest))
			{
				std::cout << "Invalid path.\n";
				return false;
			}
			else
			{
				for (int x = 0; x < visited.size(); x++)
				{
					if (visited[x] == dest)
					{
						std::cout << "There is a cycle in the path: \"" << path << "\"\n";
						return true;		
					}
					else
					{
						visited.push_back(dest);
						source = dest;
					}
				}
			}
		}
		std::cout << "There is no cycle in the path: \"" << path << "\"\n";
		return false;
	}

}
bool baconConnection(std::string person)
{
	if (person == KEVIN)
	{
		return true;
	}
	else
		return false;
}

bool baconConnectionRef(std::string start, AdjMatrixGraph<std::string>& graph)
{
	std::list<std::string> path;
	std::vector<std::string> pathVector;
	bool returnVal = graph.baconFS(start, baconConnection,path);

	for (auto it = path.rbegin(); it != path.rend(); ++it)
	{
		pathVector = graph.neighbors(*it);
		
	}


	if (returnVal)
	{
		for (auto it = path.begin(); it != path.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	return returnVal;
}

int main()
{
	//Open File
	std::ifstream fileIn;
	fileIn.open("Bacon.txt");		
											

	if (!fileIn.is_open())
		return 1;


	//Variables
	std::string tempString;
	std::stringstream nodeEdgeLine;
	std::string source, dest;
	
	//GraphCreation
	AdjMatrixGraph<std::string> txtGraph;

	while (std::getline(fileIn, tempString))
	{
		nodeEdgeLine.str(tempString);
		nodeEdgeLine.clear();
		nodeEdgeLine >> source;
		txtGraph.addNode(source);			

		while (nodeEdgeLine >> dest)
		{
			txtGraph.addEdge(source, dest);		
		}
	}
	fileIn.close();
	baconConnectionRef("3", txtGraph);
	baconConnectionRef("14", txtGraph);
	baconConnectionRef(ME, txtGraph);
	baconConnectionRef("25", txtGraph);

	return 0;

}