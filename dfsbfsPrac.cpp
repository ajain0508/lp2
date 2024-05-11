#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int N;
    vector<int>graph[10005];

    Graph(int n){
        N = n;
    }

    void addEdges(int source , int destination){
        for (auto node : graph[source]){
            if (node == destination){
                cout<<"This path already exists"<<endl;
                return;
            }
        }
        graph[source].push_back(destination);
        graph[destination].push_back(source);
    }

    void printAdjList(){
        for (int i = 1;i<=N;i++){
            cout<<"Nodes connected to "<<i<<" are : ";
            for (auto edge : graph[i]){
                cout<<edge<<" ";
            }
            cout<<endl;
        }
        
    }

    void dfs_traversal(int startNode){
        vector<bool> visited(N+1,0);
        // dfs recursive
        cout<<"DFS Recurssive is "<<endl;
        int flag = 0;
        dfsr(startNode,visited,-1,flag);
        if(flag == 1) cout<<"Cycle is detected"<<endl;
        // dfs non recurssive
        vector<bool> visited2(N+1,0);
        cout<<"\nDFS non recurssive is "<<endl;
        dfsnr(startNode,visited2);
    }

    void dfsr(int startNode,vector<bool>&visited,int par,int& flag){
        visited[startNode] = 1;
        cout<<startNode<<" -> ";
        for (auto i : graph[startNode]){
            if(i == par) continue;
            if(visited[i]==0){
                dfsr(i,visited,startNode,flag);
            }
            else flag = 1;
        }
    }

    void dfsnr(int startNode,vector<bool> visited){
       stack<int>s;
       visited[startNode] = 1;
       s.push(startNode);
       while(!s.empty()){
        int temp = s.top();
        s.pop();
        cout<<temp<<" -> ";
        for (auto node : graph[temp]){
            if(visited[node] == 0){
                s.push(node);
                visited[node]  = 1;
            }
        }
       }
       cout<<endl;
    }

    void bfsTraversal(int startNode){
       vector<bool> vis(N+1,0);
       cout<<"BFS normal traversal is : "<<endl;
       bfs(startNode,vis);
       cout<<endl;
       cout<<"BFS recurssive normal traversal is : "<<endl;
       vector<bool> vis2(N+1,0);
       queue<int>q;
       q.push(startNode);
       vis2[startNode] = 1;
       bfsr(q,vis2);
    }

    void bfs(int startNode,vector<bool> vis){
        queue<pair<int,int>> q;
        q.push({startNode,-1});
        vis[startNode] = 1;
        bool flag = 0;
        while(!q.empty()){
            pair<int,int> temp = q.front();
            q.pop();
            cout<<temp.first<<" -> ";
            for (auto node : graph[temp.first]){
                if(temp.second == node) continue;
                if(vis[node] == 0){
                    vis[node] = 1;
                    q.push({node,temp.first});
                }
                else flag = 1;
            }
        }
        if(flag == 1) cout<<"Cycle is detected"<<endl;
    }

    void bfsr(queue<int>&q,vector<bool>& vis2){
        if(q.empty()) return;
        int temp = q.front();
        q.pop();
        cout<<temp<<" -> ";
        for (auto node : graph[temp]){
            if(vis2[node] == 0){
                vis2[node] = 1;
                q.push(node);
            }
        }
        
        bfsr(q,vis2);
    }
};

int main(){
    Graph obj(5);
    obj.addEdges(1,2);
    obj.addEdges(1,3);
    obj.addEdges(2,4);
    obj.addEdges(3,5);
    obj.addEdges(4,5);
    obj.printAdjList();
    obj.dfs_traversal(1);
    obj.bfsTraversal(1);
}