// Copyright 2020 ding liang
#ifndef _DIRECTED_ACYCLIC_GRAPH_H_
#define _DIRECTED_ACYCLIC_GRAPH_H_

#include <vector>

class DirectedAcyclicGraph {
    struct Node {
        int pre;
        int cost;
        std::vector<int> froms;
    };
 public:
    DirectedAcyclicGraph();
    ~DirectedAcyclicGraph();
 public:
    void AppendVertex();
    void AddEdge(int start, int end, int weight);
    std::vector<int> GetShortestPath(int start, int end);
    std::vector<std::vector<int>> GetShortestPaths(int start, int end);
 private:
    std::vector<Node> nodes_;
};
#endif  // _DIRECTED_ACYCLIC_GRAPH_H_
