#include<bits/stdc++.h> 
using namespace std;

class Graph{
    public:
    vector<int> graph[10005];
    int N;

    Graph(int n){
        this->N = n;
    }

    void addEdges(int source,int destination){
         for(auto edges: graph[source]){
            if(destination==edges){
                cout<<"This node is already present"<<endl;
                return ;
            }
        }
        graph[source].push_back(destination);
        graph[destination].push_back(source);
    }

    void printAdjList(){
        for(int i = 0;i<N;i++){
            cout<<"Nodes connected to "<<i<<" are : ";
            for(auto j : graph[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    void dfs_travesral(int node){
        cout<<"DFS Recurssive traversal is "<<endl;
        int par = -1,flag = 0;
        vector<bool>visited(N+1,0);
        dfs(node,par,visited,flag);
        if(flag) cout<<"Cycle is detected"<<endl;

        cout<<"\nDFS iterative traversal is "<<endl;
        dfsi(node);
    }

    void dfs(int node ,int par, vector<bool>& visited,int& flag){
        visited[node] = 1;
        cout<<node<<" -> ";
        for(auto child : graph[node]){
            if(par == child) continue;
            if(visited[child] == 0){
                visited[child] = 1;
                dfs(child,node,visited,flag);
            }
            else flag  = 1;
        }
    }

    void dfsi(int node){
        vector<bool>visited(N+1,0);
        stack<int>s;
        s.push(node);
        visited[node]= 1;

        while(!s.empty()){
            int temp = s.top();
            s.pop();
            cout<<temp<<" -> ";
            for(auto child : graph[temp]){
                if(visited[child] == 0){
                    visited[child] = 1;
                    s.push(child);
                }
            }
        }
    }

    void bfs_traversal(int node){
        cout<<"\nBFS recurssive travesral is"<<endl;
        queue<int>q;
        vector<bool>visited(N+1,0);
        visited[node] = 1;
        q.push(node);
        bfsr(q,visited);

        cout<<"\nBFS iterative traversal is "<<endl;
        bfs(node);
    }

    void bfs(int node){
        queue<pair<int,int>>qt;
        vector<bool>visited(N+1,0);
        visited[node] = 1;
        qt.push({node,-1});
        int flag = 0;
        while(!qt.empty()){
            pair<int,int>temp = qt.front();
            qt.pop();
            cout<<temp.first<<" -> ";
            int par = temp.second;
            for(auto child : graph[temp.first]){
                if(child == par) continue;
                else if(visited[child] == 0){
                    visited[child] = 1;
                    qt.push({child,temp.first});
                }
                else flag = 1;
            }
        }
        if(flag == 1) cout<<"Cycle is detected"<<endl;
    }

    void bfsr(queue<int>& q,vector<bool>& visited){
        if(q.empty()) return;
        int temp= q.front();
        cout<<temp<<" -> ";
        q.pop();
        for(auto child : graph[temp]){
            if(visited[child] == 0){
                visited[child] = 1;
                q.push(child);
            }
        }
        bfsr(q,visited);
    }
};

int main(){
    Graph obj(5);
    obj.addEdges(1,2);
    obj.addEdges(1,3);
    obj.addEdges(2,4);
    obj.addEdges(3,5);
    // obj.addEdges(4,6);
    // obj.addEdges(4,7);
    // obj.addEdges(5,7);
    obj.printAdjList();
    obj.dfs_travesral(1);
    obj.bfs_traversal(1);
}