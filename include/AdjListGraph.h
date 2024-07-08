//File: AdjListGraph.h
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <vector>
#include <list>
#include <algorithm> 

template <class N>
class AdjListGraph : public Graph<N> {
private:
    using Edge = std::pair<N, N>;
    using Edges = std::list<Edge>;
    std::vector<N> nodeVector;
    std::vector<Edges> edgesVector;

    int getNodeIndex(N node) {
        auto it = std::find(nodeVector.begin(), nodeVector.end(), node);
        if (it != nodeVector.end()) {
            return std::distance(nodeVector.begin(), it);
        }
        return -1; 
    }

public:
    AdjListGraph() : Graph<N>() { }

    AdjListGraph(std::vector<N> newNodes, std::vector<Edge> newEdges) : Graph<N>(newNodes, newEdges) {
        nodeVector = newNodes;
        edgesVector.resize(newNodes.size());
        for (auto& edge : newEdges) {
            addEdge(edge.first, edge.second);
        }
    }

    ~AdjListGraph() { }

    bool adjacent(N x, N y) override {
        int index = getNodeIndex(x);
        if (index != -1) {
            for (auto& edge : edgesVector[index]) {
                if (edge.second == y) {
                    return true;
                }
            }
        }
        return false;
    }

    std::vector<N> neighbors(N x) override {
        std::vector<N> result;
        int index = getNodeIndex(x);
        if (index != -1) {
            for (auto& edge : edgesVector[index]) {
                result.push_back(edge.second);
            }
        }
        return result;
    }

    void addNode(N node) override {
        nodeVector.push_back(node);
        edgesVector.resize(nodeVector.size());
    }

    void addEdge(N x, N y) override {
        int index = getNodeIndex(x);
        if (index != -1) {
            edgesVector[index].push_back({x, y});
        }
    }

    void deleteEdge(N x, N y) override {
        int index = getNodeIndex(x);
        if (index != -1) {
            edgesVector[index].remove_if([&](const Edge& edge) { return edge.second == y; });
        }
    }
};
