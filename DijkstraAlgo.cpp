//Author: Dinesh Reddy Kommera
//Date: 09/12/2021
//Purpose: C++ program to find the shortest path - Dijkstra Algorithm 

#include<iostream>
#include<vector>
using namespace std ;

int source;
int cost[100][100],n ; 

//Function to get minimum path of the visited nodes
int getMin(int dist[],bool visited[]){
    int key=0; 
    int min = INT_MAX; 
    for(int i=0;i < n;i++){
        if(!visited[i] && dist[i]<min){
            min = dist[i]; 
            key = i; 
        }
    }
    return key; 
}

int main(void){ 
    //Input number of nodes and the cost matrix
    cout<<"Enter number of nodes: "; 
    cin>>n; 
    cout<<"Enter cost matrix : \n"; 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>cost[i][j]; 
    }

    //Input source node
    cout<<"\nEnter source node : "; 
    cin>>source;
    int par[100],dist[100]; 
    bool visited[100]={0}; 
    fill(dist,dist+n,INT_MAX); 

    dist[source]=0; 
    par[source]=-1;
    
    //Checking if the nodes are visited and summing the weights
    for(int g=0; g<n-1; g++){
        int u = getMin(dist,visited); 
        visited[u] = true ;
        cout<< " min = " << u <<endl; 
        for(int v=0;v<n;v++){
            if(!visited[v] && (dist[u]+cost[u][v]) <  dist[v] && cost[u][v]!=9999)
            {
                par[v] = u ; 
                dist[v] = dist[u] + cost[u][v]; 
            }
        } 
    }
    //Display shortest path
    for(int i =0 ;i < n ;i++){
       int temp = par[i] ; 
       cout<<i << " <- " ;
       while(temp!=-1)
       {
           cout<< temp << " <- ";
           temp = par[temp]; 
       }
       cout<<endl; 
       cout<<"::::Distance = " << dist[i]; 
       cout<<endl; 
   } 
    
}
