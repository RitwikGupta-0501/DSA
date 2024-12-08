#include <bits/stdc++.h>
using namespace std;

class Graph {
    private:
        int numNodes;
        vector< list<int> > adjList;
    
    public:
        Graph(int vertices) {
            numNodes = vertices;
            adjList.resize(vertices);
        }

        void addEdge(int u, int v, bool isDirected=false) {
            adjList[u].push_back(v);
            if (!isDirected) adjList[v].push_back(u);
        }

        void removeEdge(int u, int v, bool isDirected=false) {
            adjList[u].remove(v);
            if (!isDirected) adjList[v].remove(u);
        }

        bool isAdjacent(int u, int v){
            for (int neighbour : adjList[u]) {
                if (neighbour == v) return true;
            }
            return false;
        }

        void DFS(int src) {
            vector<bool> visited(numNodes, false);
            stack<int> stack;

            stack.push(src);
            visited[src] = true;

            while(!stack.empty()) {
                int current = stack.top(); stack.pop();
                cout << current << " ";

                for (int neighbor : adjList[current]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        stack.push(neighbor);
                    }
                }
            }
            cout << endl;
        }

        void BFS(int src) {
            vector<bool> seen(numNodes, false);
            queue<int> q;

            q.push(src);
            seen[src] = true;

            while(!q.empty()) {
                int current = q.front(); q.pop();
                cout << current << " ";

                for(int neighbour : adjList[current]) {
                    if (!seen[neighbour]) {
                        seen[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
            cout << endl;
        }

        bool hasPath(int src, int dst) {
            vector<bool> seen(numNodes, false);
            return hasPathDFS(src, dst, seen);
        }

    private:
        bool hasPathDFS(int src, int dst, vector<bool> &visited) {
            visited[src] = true;

            if (src == dst) return true;

            for (int neighbour : adjList[src]) {
                if (!visited[neighbour]) {
                    if (hasPathDFS(neighbour, dst, visited)) return true;
                }
            }

            return false;
        }
};