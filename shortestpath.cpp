#include<iostream>
#include<list>
#include<unordered_map>
#include<stack>
#include<limits.h>
#include<vector>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;
    void addEdge(int u,int v,int weight){
        adj[u].push_back({v,weight});
    }
    void printAdj(){
        for(auto i:adj){
            cout << i.first << "->" ;
            for(auto j:i.second){
                cout << "( "<< j.first << " " << j.second << " )";
            }cout << endl;
        }
    }
    void topologicalSort(stack<int> &st,unordered_map<int,bool> &visited,int node){
        visited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i.first]){
                topologicalSort(st,visited,i.first);
            }
        }
        st.push(node);
    }
    void getshortest(vector<int> &dist,stack<int> &st,int src){
        dist[src]=0;
        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(dist[top]!=INT_MAX){
                for(auto i:adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first]=dist[top] + i.second ;
                    }
                }
            }
        }
    }
};
int main (){
    Graph G;
    G.addEdge(0,1,5);
    G.addEdge(0,2,3);
    G.addEdge(1,2,2);
    G.addEdge(1,3,6);
    G.addEdge(2,3,7);
    G.addEdge(2,4,4);
    G.addEdge(2,5,2);
    G.addEdge(3,4,-1);
    G.addEdge(4,5,-2);
    G.printAdj();
    stack<int> st;
    unordered_map<int,bool> visited;
    int n=6;
    for(int i=0;i<n;i++){
        if(!visited[i])
            G.topologicalSort(st,visited,i);
    }
    int src=1;
    vector<int> dist(n);
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    G.getshortest(dist,st,src);
    for(auto i:dist){
        cout << i << " ";
    }
    return 0;
    
}