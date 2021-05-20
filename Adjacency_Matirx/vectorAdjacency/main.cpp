#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>



using namespace std;

vector<bool> v;
vector<vector<int>> g;
//map<int, bool> visited;


// CPP program to convert Adjacency matrix
// representation to Adjacency List
// converts from adjacency matrix to adjacency list
vector<vector<int>> convert(vector<vector<int>> a)
{
    vector<vector<int>> adjList(a.size());
    for (int i = 0; i < a.size(); i++)
    {

        for (int j = 0; j < a[i].size(); j++)
        {
            if (a[i][j] == 1)
            {
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}
// Nodelerin giris ve cikis derecesi hesaplamasi
void calculator(vector<vector<int>> a, int node) {
    // node cikis counter
    int counterOut = 0;
    // node giris counter
    int counterIn = 0;
    for (int i = 0; i < a.size()-2; i++)
    {
        cout << i;

        for (int j = 0; j < a[i].size(); j++)
        {
            if (j == a[i].size() - 1)
            {
                cout << " -> " << a[i][j] << endl;
                if (node == i)
                {
                    counterOut++;

                }
                if (node == a[i][j])
                    counterIn++;

                break;
            }
            else {
                if (node == i)
                {
                    counterOut++;

                }
                if (node == a[i][j])
                    counterIn++;
                cout << " -> " << a[i][j];
            }
        }
    }
    cout << node <<". nodun cikis derecesi : " <<counterOut << "\n"<<node << ". nodun giris derecesi : " << counterIn;

}

void calculatorEdge(vector<vector<int>> a) {
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i].size();
    }
    cout <<" " <<sum ;

}
void AdjMatrixBFS(vector< vector<int> > adjMatrix, int start)
{
    cout << "\nDoing a BFS on an adjacency list.\n";

    int n = adjMatrix.size();
    // Create a "visited" array (true or false) to keep track of if we visited a vertex.
    bool visited[8] = { false };

    // Create a queue for the nodes we visit.
    queue<int> q;

    // Add the starting vertex to the queue and mark it as visited.
    q.push(start);
    visited[start] = true;

    // While the queue is not empty..
    while (q.empty() == false)
    {
        int vertex = q.front();
        q.pop();

        // Doing +1 in the cout because our graph is 1-based indexing, but our code is 0-based.
        cout << vertex + 1 << " ";

        // Loop through all of it's friends.
        for (int i = 0; i < adjMatrix[vertex].size(); i++)
        {

            // The neighbor is the column number, and the edge is the value in the matrix.
            int neighbor = i;
            int edge = adjMatrix[vertex][i];

            // If the edge is "0" it means this guy isn't a neighbor. Move on.
            if (edge == 0) { continue; }

            // If the friend hasn't been visited yet, add it to the queue and mark it as visited
            if (visited[neighbor] == false)
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl << endl;
    return;
}
/*
int color[];
int pred[];
int d[];
f[u];
*/

int G[10][10], visited[10], n;

void DFS(int i) {
    int j;
    cout << "\n" << i;
    visited[i] = 1;
    for ( j = 0; j < n; j++)
    {
        if (!visited[j] && G[i][j] == 1)
            DFS(j);
    }
};




int main()
{
    std::ifstream fin("Text.txt");

    vector<vector<int>> data;
    std::string line; int size=0;
    
    while (std::getline(fin,line))
    {
        vector<int> row;
        char ch;
        istringstream ss(line);
        while (ss >> ch)
            row.push_back(ch - '0');
        data.push_back(row);
        size++;

    }
   
    vector<vector<int>> AdjList = convert(data);
    vector<vector<int>> g = convert(data);
    

    int c;
    cout << "\nGiris ve cikislarini istediginiz node'un degerini giriniz : " << endl;
    cin >> c;

    calculator(AdjList,c);

    cout << "\nGraftaki toplam kenar sayisi : ";
    calculatorEdge(AdjList);

    AdjMatrixBFS(g, 0);

    cout << "\n\n";

    for (int i = 0; i < g.size(); i++)
    {
        visited[i] = 0;
    }
    DFS(0);
    
    
    
}

