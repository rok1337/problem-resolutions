#include <bits/stdc++.h>

using namespace std;
//declaracion matrix adj
int adj[N][N];

//declaracion de lista de aristas
vector<pair<int,int>> edges;

//cadal elemento de esta lista (a, b, w), E 1 arista dsd nodo a hasta nodo b con peso w
vector<tuple<int,int,int>> edges;



int main(){
    //se puede almacenar de la sig forma, son las aristas del grafo
    edges.push_back({1,2});
    edges.push_back({2,3});
    edges.push_back({2,4});
    edges.push_back({3,4});
    edges.push_back({4,1});

    //es del ejemplo de (a,b,w)
    edges.push_back({1,2,5});// {1,2}   peso 5
    edges.push_back({2,3,7});// {2,3}   peso 7
    edges.push_back({2,4,6});// {2,4}   peso 6
    edges.push_back({3,4,5});// {3,4}   peso 5  
    edges.push_back({4,1,2});// {4,1}   peso 2

}