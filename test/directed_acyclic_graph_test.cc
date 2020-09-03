#include "test_suite.h"
#include "directed_acyclic_graph.h"

TEST(DirectedAcyclicGraphTest, GetShortestPathTest)
{
    DirectedAcyclicGraph dag;
    std::vector<int> path;

    //  1
    // 0->1
    dag.AppendVertex();
    dag.AddEdge(0, 1, 1);
    path = dag.GetShortestPath(0, 1);
    EXPECT_EQ(path.size(), 2U);
    EXPECT_EQ(path[0], 0);
    EXPECT_EQ(path[1], 1);

    /*
     *  1  0
     * 0->1->2
     *  \_0_/
     */
    dag.AppendVertex();
    dag.AddEdge(1, 2, 0);
    dag.AddEdge(0, 2, 0);
    path = dag.GetShortestPath(0, 2);
    EXPECT_EQ(path.size(), 2U);
    EXPECT_EQ(path[0], 0);
    EXPECT_EQ(path[1], 2);

    /*     __0_
     *  1 /0  1\
     * 0->1->2->3
     *  \_0_/   /
     *   \__0__/
     */
    dag.AppendVertex();
    dag.AddEdge(2, 3, 1);
    dag.AddEdge(1, 3, 0);
    dag.AddEdge(0, 3, 0);
    path = dag.GetShortestPath(0, 3);
    EXPECT_EQ(path.size(), 2U);
    EXPECT_EQ(path[0], 0);
    EXPECT_EQ(path[1], 3);

    /*      ___0__
     *     /_0_   \
     *  1 /0  1\ 1 \
     * 0->1->2->3->4
     *  \_0_/ \_/0_/
     *   \__0__/  /
     *    \___0__/
     */
    dag.AppendVertex();
    dag.AddEdge(3, 4, 1);
    dag.AddEdge(2, 4, 0);
    dag.AddEdge(1, 4, 0);
    dag.AddEdge(0, 4, 0);
    path = dag.GetShortestPath(0, 4);
    EXPECT_EQ(path.size(), 3U);
    EXPECT_EQ(path[0], 0);
    EXPECT_EQ(path[1], 2);
    EXPECT_EQ(path[2], 4);
}