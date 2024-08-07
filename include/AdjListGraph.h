//File: AdjListGraph.h
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <vector>
#include<list>
#include<stack>
#include<queue>
#include<functional>
#include"Graph.h"

template <class N>
class AdjListGraph : public Graph<N>
{
private:
	using Edges = std::list<std::pair<int, int>>;
	std::vector<N> nodeVector;					
	std::vector<Edges> edgesVector;					
public:

	//Default
	AdjListGraph() : Graph<N>() {};

	//Copy
	AdjListGraph(const AdjListGraph& other) : Graph<N>()
	{
		nodeVector = other.nodeVector;
		edgesVector = other.edgesVector;
	}

	//Assignment Operator
	AdjListGraph& operator= (const AdjListGraph& source)
	{
		AdjListGraph<N> tempGraph = source;
		this->nodeVector = source.nodeVector;
		this->edgesVector = source.edgesVector;
		return tempGraph;
	}

	//Specified Constructor
	AdjListGraph(std::vector<N> newNodes, std::vector<std::pair<N, N>> newEdges) : Graph<N>(newNodes, newEdges) { }

	//Destructor
	~AdjListGraph() {}



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
			for (auto edge : edgesVector[x_index]) 
			{
				if (edge.second == y_index) 
				{
					return true;	
				}
			}
			return false;	
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
			for (auto edge : edgesVector[x_index])
			{
				neighborVec.push_back(nodeVector[edge.second]);
			}
		}
		return neighborVec;
	}
	virtual void addNode(N node)

	{
		//Prevent duplicates
		for (int i = 0; i < nodeVector.size(); i++)
		{
			if (nodeVector[i] == node)
			{
				return;
			}
		}
		nodeVector.push_back(node);
		Edges temp;
		edgesVector.push_back(temp);
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
		std::pair<int, int> newPair;
		newPair.first = x_index;
		newPair.second = y_index;
		edgesVector[x_index].push_back(newPair);
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
			std::cout << "Destination node not foudn\n;";
			found = false;
		}
		if (!found)
		{
			std::cout << "No such node and edge exist.\n";
			return;
		}
		else
		{
			std::pair<int, int> edgeRemoval;
			edgeRemoval.first = x_index;
			edgeRemoval.second = y_index;
			edgesVector[x_index].remove(edgeRemoval);
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
			for (int first = 0; first < nodeVector.size(); first++)
			{
				if (first == x_index)
					edgesVector[first].clear();
				else
				{
					//Remove all edges from first to node at x_index
					deleteEdge(nodeVector[first], nodeVector[x_index]);
				}
			}

			for (int i = x_index; i < edgesVector.size(); i++)
			{
				edgesVector[i].clear();

				int iPlusOne = i + 1;
				if (iPlusOne >= edgesVector.size())		
					continue;
				for (auto edge : edgesVector[iPlusOne])
				{
					if (!edgesVector[iPlusOne].empty())
					{
						edge.first -= 1;
						if (edge.second > x_index)	
							edge.second -= 1;		
						edgesVector[i].push_back(edge);
					}
				}
				nodeVector[i] = nodeVector[iPlusOne];
			}
			//Once nodes are shifted, pop the back
			edgesVector.pop_back();
			nodeVector.pop_back();
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
};