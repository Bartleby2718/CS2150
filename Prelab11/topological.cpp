// code taken from fileio2.cpp
#include <fstream>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct Vertex
{
    string name;
    int topologicalNum;
    int indegree;

    explicit Vertex(string name) : name(move(name)), topologicalNum(0), indegree(0)
    {
    }
};

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    ifstream file(argv[1], ifstream::binary);
    if (!file.is_open())
    {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    vector<Vertex*> vertices;
    map<string, vector<Vertex*>> adjacencyList;
    string s1, s2;
    while (file >> s1 >> s2, s1 != "0" && s2 != "0")
    {
        // add to vertices if a vertex with the same name does not exist
        bool hasS1 = false, hasS2 = false;
        auto v1 = new Vertex(s1), v2 = new Vertex(s2);
        for (Vertex* v: vertices)
        {
            if (!hasS1 && v->name == s1)
            {
                hasS1 = true;
            }
            if (!hasS2 && v->name == s2)
            {
                hasS2 = true;
                v2 = v;
            }
        }
        if (!hasS1)
        {
            vertices.push_back(v1);
            adjacencyList[s1] = vector<Vertex*>();
        }
        if (!hasS2)
        {
            vertices.push_back(v2);
            adjacencyList[s2] = vector<Vertex*>();
        }
        // add an edge (from, to)
        adjacencyList[s1].push_back(v2);
        // increment to.indegree
        (v2->indegree)++;
    }
    file.close();

    /** topological sort */
    queue<Vertex*> q;
    // for each vertex of indegree 0, add to the queue
    for (Vertex* v: vertices)
    {
        if (v->indegree == 0)
        {
            q.push(v);
        }
    }
    // while the queue is nonempty
    bool isFirst = true;
    while (!q.empty())
    {
        // get a vertex
        Vertex* v = q.front();
        q.pop();
        if (isFirst)
        {
            isFirst = false;
        }
        else
        {
            cout << ' ';
        }
        cout << v->name;
        vector<Vertex*> adjacentVertices = adjacencyList[v->name];
        // for each vertex adjacent to it
        for (Vertex* adjacentVertex: adjacentVertices)
        {
            // decrement indegree
            // if its indegree is 0, add to the queue
            if (--adjacentVertex->indegree == 0)
            {
                q.push(adjacentVertex);
            }
        }
    }
}
