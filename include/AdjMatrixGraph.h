//File: AdjMatrixGraph.h
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <vector>
#include<functional>
#include<stack>
#include<queue>
#include"Graph.hpp"

template <class N>
class AdjMatrixGraph : public Graph<N>
{
private:
	const static int MAXSIZE = 100;
	std::vector<N> nodeVector;					
	bool adjMatrix[MAXSIZE][MAXSIZE];
public:

	//Default
	AdjMatrixGraph() : Graph<N>()
	{
		for (int left = 0; left < MAXSIZE; left++)
		{
			for (int right = 0; right < MAXSIZE; right++)
			{
				adjMatrix[left][right] = 0;	
			}
		}
	}

	//Copy
	AdjMatrixGraph(const AdjMatrixGraph& other) : Graph<N>()
	{
		nodeVector = other.nodeVector;
		for (int left = 0; left < MAXSIZE; left++)
		{
			for (int right = 0; right < MAXSIZE; right++)
			{
				adjMatrix[left][right] = other.adjMatrix[left][right];
			}
		}
	}

	//Assignment Operator
	AdjMatrixGraph& operator= (const AdjMatrixGraph& source)
	{
		AdjMatrixGraph<N> tempGraph;
		tempGraph.nodeVector = source.nodeVector;
		this->nodeVector = source.nodeVector;
		for (int left = 0; left < MAXSIZE; left++)
		{
			for (int right = 0; right < MAXSIZE; right++)
			{
				this->adjMatrix[left][right] = source.adjMatrix[left][right];
				tempGraph.adjMatrix[left][right] = source.adjMatrix[left][right];
			}
		}
		return *this;
	}

	//Specified Constructor
	AdjMatrixGraph(std::vector<N> newNodes, bool newMatrix[][MAXSIZE]) : Graph<N>(newNodes, newMatrix) { }

	//Destructor
	~AdjMatrixGraph() {}

	
	virtual bool  adjacent(N x, N y)
	{

		int x_index = -1, y_index = -1; 

		for (int i = 0; i < nodeVector.size(); i++)
		{
			//Find nodes in nodeVector and record their indexes 
			if (nodeVector[i] == x)
				x_index = i;
			if (nodeVector[i] == y)
				y_index = i;
		}
		if (x_index < 0 || y_index < 0)
		{
			//Node isn't in vector - index is negative
			std::cout << "Node(s) not found.\n";
			return false;
		}
		else 
		{
			return adjMatrix[x_index][y_index];
		}
	}
	virtual std::vector<N> neighbors(N x)
	{
		std::vector<N> neighborVec;

		int x_index = -1; 

		for (int i = 0; i < nodeVector.size(); i++)
		{
			
			if (nodeVector[i] == x)
			{
				x_index = i;
				break;
			}
		}
		if (x_index < 0)
		{
			std::cout << "node not found\n";
		}
		else
		{
			for (int r = 0; r < nodeVector.size(); r++)
			{
				if (adjMatrix[x_index][r])
				{
					neighborVec.push_back(nodeVector[r]);
				}
			}
		}
		return neighborVec;
	}
	virtual void addNode(N node)
	{
		for (int i = 0; i < nodeVector.size(); i++)
		{
			
			if (nodeVector[i] == node)
			{
				return;
			}
		}
		nodeVector.push_back(node);
	}
	virtual void  addEdge(N source, N dest)
	{
		int x_index = -1;
		int y_index = -1;
		for (int i = 0; i < nodeVector.size(); i++)
		{
			
			if (nodeVector[i] == source)
			{
				x_index = i;
			}
			if (nodeVector[i] == dest)
			{
				y_index = i;
			}
		}
		if (x_index < 0)
		{
			std::cout << "Source node not found\n";
			return;
		}
		if (y_index < 0)
		{
			addNode(dest);
			y_index = nodeVector.size() - 1;
		}
		if (x_index != y_index)
		{
			adjMatrix[x_index][y_index] = 1;
			adjMatrix[y_index][x_index] = 1;
		}
		else
			std::cout << "Can not have an edge connecting node to itself.\n";
	}
	virtual void deleteEdge(N source, N dest)
	{
		int x_index = -1;	
		int y_index = -1;	
		bool found = true;
		for (int i = 0; i < nodeVector.size(); i++)
		{
			
			if (nodeVector[i] == source)
			{
				x_index = i;
			}
			if (nodeVector[i] == dest)
			{
				y_index = i;
			}
		}
		if (x_index < 0)
		{
			std::cout << "Source node not found\n";
			found = false;
		}
		if (y_index < 0)
		{
			std::cout << "Destination node not found\n";
			found = false;
		}
		if (!found)
		{
			std::cout << "No such node and edge exist.\n";
			return;
		}
		else
		{
			adjMatrix[x_index][y_index] = 0;
			adjMatrix[y_index][x_index] = 0;
		}
	}
	virtual void deleteNode(N node)
	{
		int x_index = -1;
		for (int i = 0; i < nodeVector.size(); i++)
		{
			
			if (nodeVector[i] == node)
			{
				x_index = i;
			}
		}
		if (x_index < 0)
		{
			std::cout << "Node node not found\n";
		}
		else
		{
			int x = x_index;
			while (x < nodeVector.size())
			{
				for (int i = 0; i < nodeVector.size(); ++i)
				{

					adjMatrix[i][x] = adjMatrix[i][x + 1];
				}
				for (int i = 0; i < nodeVector.size(); ++i)
				{
					adjMatrix[x][i] = adjMatrix[x + 1][i];
				}
				x++;
			}
			for (int i = x_index; i < nodeVector.size(); i++)
			{
				int iPlusOne = i + 1;
				if (iPlusOne >= nodeVector.size())
					continue;
				else
					nodeVector[i] = nodeVector[iPlusOne];
			}

			nodeVector.pop_back();
		}
	}

	void displayAdjacencyMatrix()
	{
		std::cout << "\n\n Adjacency Matrix:";

		for (int i = 0; i < nodeVector.size(); ++i) {
			std::cout << "\n";
			for (int j = 0; j < nodeVector.size(); ++j) {
				std::cout << " " << adjMatrix[i][j];
			}
		}
	}

	void dfs(N start, std::function<void(N)> visit)
	{
		std::vector<bool> visited(nodeVector.size(), false);
		std::stack<N> toVisit;
		toVisit.push(start);
		int x_index = -1;

		while (!toVisit.empty())
		{
			N current = toVisit.top();
			toVisit.pop();
			for (int i = 0; i < nodeVector.size(); i++)
			{
				 
				if (nodeVector[i] == current)
					x_index = i;
			}
			if (x_index < 0)
			{
				std::cout << "Error: Node not in graph.\n";
				return;
			}
			else if (!visited[x_index])
			{
				visit(current);
				visited[x_index] = true;

				for (auto& neighbor : neighbors(current))
				{
					for (int i = 0; i < nodeVector.size(); i++)
					{
						
						if (nodeVector[i] == neighbor)
							x_index = i;
					}

					if (!visited[x_index])
					{
						toVisit.push(neighbor);
					}
				}
			}
		}
	}
	void bfs(N startNode, std::function<void(N)> visit)
	{
		std::vector<bool> visited(nodeVector.size(), false);
		std::queue<N> toVisit;
		toVisit.push(startNode);
		int x_index = -1;

		while (!toVisit.empty())
		{
			N current = toVisit.front();
			toVisit.pop();
			for (int i = 0; i < nodeVector.size(); i++)
			{
				
				if (nodeVector[i] == current)
					x_index = i;
			}
			if (x_index < 0)
			{
				std::cout << "Error: Node not in graph.\n";
				return;
			}
			else if (!visited[x_index])
			{
				visit(current);
				visited[x_index] = true;

				for (auto& neighbor : neighbors(current))
				{
					for (int i = 0; i < nodeVector.size(); i++)
					{
						
						if (nodeVector[i] == neighbor)
							x_index = i;
					}

					if (!visited[x_index])
					{
						toVisit.push(neighbor);
					}
				}
			}
		}
	}

	bool baconFS(N startNode, std::function<bool(N)> bacon, std::list<N>& path)
	{
		std::vector<bool> visited(nodeVector.size(), false);
		std::queue<N> toVisit;
		toVisit.push(startNode);
		int x_index = -1, first = -1;
		bool found = false;


		for (int i = 0; i < nodeVector.size(); i++)
		{
			
			if (nodeVector[i] == startNode)
				first = i;
		}
		if (first < 0)
		{
			std::cout << "Error: Starting person not in graph.\n";
			return false;
		}
		while (!toVisit.empty())
		{
			N current = toVisit.front();
			toVisit.pop();
			for (int i = 0; i < nodeVector.size(); i++)
			{
				if (nodeVector[i] == current)
					x_index = i;
			}
			if (x_index < 0)
			{
				std::cout << "Error: Node not in graph.\n";
				return false;
			}
			else if (!visited[x_index])
			{
				if (bacon(current))
				{
					found = true;
					break;
				}
				visited[x_index] = true;
				path.push_back(current);
				for (auto& neighbor : neighbors(current))
				{
					for (int i = 0; i < nodeVector.size(); i++)
					{
						
						if (nodeVector[i] == neighbor)
							x_index = i;
					}

					if (!visited[x_index])
					{
						toVisit.push(neighbor);
					}
				}

			}
		}


		if (found)
			std::cout << nodeVector[first] << " is connected to Kevin Bacon.\n";
		else
			std::cout << nodeVector[first] << " has no connection to Kevin Bacon.\n";
		return found;

	}

};