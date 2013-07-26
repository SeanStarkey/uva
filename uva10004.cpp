/*
 * UVa Online Judge - Problem 10004
 */

#include <iostream>
#include <vector>

struct Node
{
    int number;
    int color;

    Node(int x) : number(x), color(0) {};
};

struct Edge
{
    int x;
    int y;
    bool processed;

    Edge(int x_in, int y_in) : x(x_in), y(y_in), processed(false) {};
};

int main()
{
    while (true)
    {
        std::vector<Node> nodes;
        std::vector<Edge> edges;

        int numberNodes;
        std::cin >> numberNodes;
        if (numberNodes == 0)
            return 0;

        for (int cnt=0; cnt<numberNodes; cnt++)
        {
            Node n(cnt);
            nodes.push_back(n);
        }

        int numberEdges;
        std::cin >> numberEdges;

        for (int cnt=0; cnt<numberEdges; cnt++)
        {
            int x;
            int y;
            std::cin >> x;
            std::cin >> y;
            Edge e(x,y);
            edges.push_back(e);
        }

        nodes[edges[0].x].color = 1;
        nodes[edges[0].y].color = 2;
        edges[0].processed = true;

        bool bicolored = true;
        bool allProcessed = false;
        while (!allProcessed)
        {
            allProcessed = true;
            for (int cnt=1; cnt<numberEdges; cnt++)
            {
                if (!edges[cnt].processed)
                {
                    allProcessed = false;

                    edges[cnt].processed = true;
                    switch (nodes[edges[cnt].x].color)
                    {
                    case 0:
                        switch (nodes[edges[cnt].y].color)
                        {
                        case 0:
                            edges[cnt].processed = false;
                            break;
                        case 1:
                            nodes[edges[cnt].x].color = 2;
                            break;
                        case 2:
                            nodes[edges[cnt].x].color = 1;
                            break;
                        }
                        break;
                    case 1:
                        switch (nodes[edges[cnt].y].color)
                        {
                        case 0:
                            nodes[edges[cnt].y].color = 2;
                            break;
                        case 1:
                            bicolored = false;
                            break;
                        case 2:
                            break;
                        }
                        break;
                    case 2:
                        switch (nodes[edges[cnt].y].color)
                        {
                        case 0:
                            nodes[edges[cnt].y].color = 1;
                            break;
                        case 1:
                            break;
                        case 2:
                            bicolored = false;
                            break;
                        }
                        break;
                    }
                }

                if (!bicolored)
                    break;
            }
            if (!bicolored)
                break;
        }

        if (!bicolored)
            std::cout << "NOT BICOLORABLE.\n";
        else
            std::cout << "BICOLORABLE.\n";
    }

    return 0;
}
