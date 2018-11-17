#include <iostream>

using namespace std;

struct Edge //For defining the edges of the graphs containing the source destination and the weight of the edge
{
    int source, destination, weight;
};

struct Graph //For defining the graph along with the node labels and edges
{
    int nodes, E;
    struct Edge* edge;
};

struct Graph* createGraph(int nodes, int E) //For creating the graph with the node and edge.
{
    struct Graph* graph = new Graph;
    graph->nodes = nodes;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void print(int distance[], int n) //For printing the distance of each of the nodes from the source node
{
    cout << "\n\nNode   Distance from Source" << endl;
    for (int i = 0; i < n; ++i)
        cout << i << "\t\t" << distance[i] << endl;
}

void BellmanFord(struct Graph* graph, int source) //Implementation of the bellman Ford algorithm.
{
    int nodes = graph->nodes;
    int E = graph->E;
    int distance[nodes];

    for (int i = 0; i < nodes; i++)
        distance[i]   = 100000; //100000 is just a huge value taken instead of infinity
    distance[source] = 0;

    for (int i = 1; i <= nodes-1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            if (distance[u] != 100000 && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }

    for (int i = 0; i < E; i++) //This for loop catches the negative cycle nad returns the same statement t othe user.
    {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        if (distance[u] != 100000 && distance[u] + weight < distance[v])
        {
            cout << "\n\nThe graph contains a negative weight cycle\n" << endl;
            exit(1);
        }

    }

    print(distance, nodes);

    return;
}

void without_negative_cycle() //Displays minimum ditance of each of the nodes from source node without negative cycle.
// Refer figure 1 in the pdf attached.
{
    int nodes = 10;
    int E = 15;
    struct Graph* graph = createGraph(nodes, E);


    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;
    graph->edge[0].weight = 1;

    graph->edge[1].source = 0;
    graph->edge[1].destination = 2;
    graph->edge[1].weight = 2;

    graph->edge[2].source = 0;
    graph->edge[2].destination = 3;
    graph->edge[2].weight = 3;



    graph->edge[3].source = 1;
    graph->edge[3].destination = 2;
    graph->edge[3].weight = 4;

    graph->edge[4].source = 1;
    graph->edge[4].destination = 4;
    graph->edge[4].weight = -1;

    graph->edge[5].source = 1;
    graph->edge[5].destination = 5;
    graph->edge[5].weight = -2;

    graph->edge[6].source = 1;
    graph->edge[6].destination = 6;
    graph->edge[6].weight = -3;


    graph->edge[7].source = 2;
    graph->edge[7].destination = 3;
    graph->edge[7].weight = 5;


    graph->edge[8].source = 3;
    graph->edge[8].destination = 7;
    graph->edge[8].weight = 1;

    graph->edge[9].source = 3;
    graph->edge[9].destination = 8;
    graph->edge[9].weight = -2;

    graph->edge[10].source = 3;
    graph->edge[10].destination = 9;
    graph->edge[10].weight = 3;


    graph->edge[11].source = 4;
    graph->edge[11].destination = 5;
    graph->edge[11].weight = -5;


    graph->edge[12].source = 5;
    graph->edge[12].destination = 6;
    graph->edge[12].weight = -7;


    graph->edge[13].source = 7;
    graph->edge[13].destination = 8;
    graph->edge[13].weight = -4;


    graph->edge[14].source = 8;
    graph->edge[14].destination = 9;
    graph->edge[14].weight = 5;

    BellmanFord(graph, 0);
}

void with_negative_cycle() //Catches and displays that there is  a negatvie cycle in the graph. Refer figure 2 in the pdf.
{
    int nodes = 10;
    int E = 19;
    struct Graph* graph = createGraph(nodes, E);


    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;
    graph->edge[0].weight = 1;

    graph->edge[1].source = 0;
    graph->edge[1].destination = 2;
    graph->edge[1].weight = 2;

    graph->edge[2].source = 0;
    graph->edge[2].destination = 3;
    graph->edge[2].weight = 3;



    graph->edge[3].source = 1;
    graph->edge[3].destination = 2;
    graph->edge[3].weight = 4;

    graph->edge[4].source = 1;
    graph->edge[4].destination = 4;
    graph->edge[4].weight = -1;

    graph->edge[5].source = 1;
    graph->edge[5].destination = 5;
    graph->edge[5].weight = -2;

    graph->edge[6].source = 1;
    graph->edge[6].destination = 6;
    graph->edge[6].weight = -3;


    graph->edge[7].source = 2;
    graph->edge[7].destination = 3;
    graph->edge[7].weight = 5;


    graph->edge[8].source = 3;
    graph->edge[8].destination = 7;
    graph->edge[8].weight = 1;

    graph->edge[9].source = 3;
    graph->edge[9].destination = 8;
    graph->edge[9].weight = -2;

    graph->edge[10].source = 3;
    graph->edge[10].destination = 9;
    graph->edge[10].weight = 3;


    graph->edge[11].source = 4;
    graph->edge[11].destination = 5;
    graph->edge[11].weight = -5;


    graph->edge[12].source = 5;
    graph->edge[12].destination = 4;
    graph->edge[12].weight = -4;

    graph->edge[13].source = 5;
    graph->edge[13].destination = 6;
    graph->edge[13].weight = -7;


    graph->edge[14].source = 6;
    graph->edge[14].destination = 5;
    graph->edge[14].weight = -6;


    graph->edge[15].source = 7;
    graph->edge[15].destination = 8;
    graph->edge[15].weight = -4;



    graph->edge[16].source = 8;
    graph->edge[16].destination = 7;
    graph->edge[16].weight = -6;

    graph->edge[17].source = 8;
    graph->edge[17].destination = 9;
    graph->edge[17].weight = 5;



    graph->edge[18].source = 9;
    graph->edge[18].destination = 8;
    graph->edge[18].weight = 7;

    BellmanFord(graph, 0);
}

int main()
{

    int choice;
    cout << "++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "Hello!!! Let's work with Bellman-Ford algorithm which includes negative cycle" << endl;

    while(1)
    {
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Choose one of the option from below:" << endl;
        cout << "1. Showing minimum distances to each of the nodes from the source node without a negative cycle as shown in the figure." << endl;
        cout << "2. Catching the negative cycle in the graph shown in the figure" << endl;
        cout << "3. Exit program" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------\n" << endl;

        cin >> choice;

        switch(choice)
        {
        case 1:
            {
                without_negative_cycle();
                break;
            }
        case 2:
            {
                with_negative_cycle();
                break;
            }
        case 3:
            {
                exit(1);
            }
        default:
            {
                cout << "Please choose the correct option" << endl;
            }
        }

    }
    return 0;
}
