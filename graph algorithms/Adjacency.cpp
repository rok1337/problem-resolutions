#include <bits/stdc++.h>

using namespace std;

//arreglos de vectores
vector<int> adj[N];


//si el grafo no es dirigido, se almacena de forma similar, pero cada arista se agrega en ambas direcciones
//grafo ponderado se expresa asi
vector<pair<int,int>> adj[N];




int main(){
    //se puede almacenar de la sig forma
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(4);
    adj[4].push_back(1);



    adj[1].push_back({2,5});
    adj[2].push_back({3,7});
    adj[2].push_back({4,6});
    adj[3].push_back({4,5});
    adj[4].push_back({1,2});

    return 0;


}