//File: AdjMatGraph.h
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <vector>
#include <cstring> 

template <class N>
class AdjMatrixGraph : public Graph<N> {
private:
    const static int MaxSize = 100;
    std::vector<N> nodeVector;
    std::byte adjMatrix[MaxSize][MaxSize];
    unsigned int numNodes = 0;

    int getNodeIndex(N node) {
        auto it = std::find(nodeVector.begin(), nodeVector.end(), node);
        if (it != nodeVector.end()) {
            return std::distance(nodeVector.begin(), it);
        }
        return -1; 
    }

public:
    AdjMatrixGraph() : Graph<N>() {
        std::memset(adjMatrix, std::byte{0}, sizeof(adjMatrix));
    }

    AdjMatrixGraph(std::vector<N> newNodes, std::vector<std::pair<N, N>> newEdges) : Graph<N>(newNodes, newEdges) {
        nodeVector = newNodes;
        numNodes = newNodes.size();
        std::memset(adjMatrix, std::byte{0}, sizeof(adjMatrix));
        for (auto& edge : newEdges) {
            addEdge(edge.first, edge.second);
        }
    }

    ~AdjMatrixGraph() { }

    bool adjacent(N x, N y) override {
        int indexX = getNodeIndex(x);
        int indexY = getNodeIndex(y);
        if (indexX != -1 && indexY != -1) {
            return adjMatrix[indexX][indexY] == std::byte{1};
        }
        return false;
    }

    std::vector<N> neighbors(N x) override {
        std::vector<N> result;
        int index = getNodeIndex(x);
        if (index != -1) {
            for (unsigned int i = 0; i < numNodes; ++i) {
                if (adjMatrix[index][i] == std::byte{1}) {
                    result.push_back(nodeVector[i]);
                }
            }
        }
        return result;
    }

    void addNode(N node) override {
        nodeVector.push_back(node);
        ++numNodes;
    }

    void addEdge(N x, N y) override {
        int indexX = getNodeIndex(x);
        int indexY = getNodeIndex(y);
        if (indexX != -1 && indexY != -1) {
            adjMatrix[indexX][indexY] = std::byte{1};
        }
    }

    void deleteEdge(N x, N y) override {
        int indexX = getNodeIndex(x);
        int indexY = getNodeIndex(y);
        if (indexX != -1 && indexY != -1) {
            adjMatrix[indexX][indexY] = std::byte{0};
        }
    }
};