// Copyright 2020 ding liang
#include "directed_acyclic_graph.h"
#include <limits>
#include <algorithm>
#include <cassert>

DirectedAcyclicGraph::DirectedAcyclicGraph()
{
    // root node
    AppendVertex();
    nodes_.back().cost = 0;
}
DirectedAcyclicGraph::~DirectedAcyclicGraph()
{
}
void DirectedAcyclicGraph::AppendVertex()
{
    Node node;
    node.pre = -1;
    node.cost = std::numeric_limits<int>::max();
    nodes_.push_back(node);
}

void DirectedAcyclicGraph::AddEdge(int start, int end, int weight)
{
    assert(start >= 0 && end > start);

    if (nodes_[end].cost > (weight + nodes_[start].cost)) {
        nodes_[end].cost = (weight + nodes_[start].cost);
        nodes_[end].pre = start;
    }
}

std::vector<int> DirectedAcyclicGraph::GetShortestPath(int start, int end)
{
    std::vector<int> path;
    int pre_node = end;
    while (pre_node != start) {
        path.push_back(pre_node);
        pre_node = nodes_[pre_node].pre;
    }
    assert(pre_node == start);
    path.push_back(pre_node);
    std::reverse(path.begin(), path.end());
    return path;
}
