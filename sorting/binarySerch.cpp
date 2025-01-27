#include <bits/stdc++.h>

using namespace std;


//es O(n) xq en el peor de los casos es necesario verificar todos los elementos del arreglo
int main(){
    for (int i = 0; i < n; i++)
    {
        if(array[i] == x){
            //x encontrado en el indice i
    }
    
    //esto es metodo 1
    int a = 0, b = n-1;
    while(a <= b){
        int k = (a+b)/2;
        if(array[k] == x){
            //x encontrado en el indice k
        }
        if(array[k] > x) b = k - 1;
        else a = k + 1;
    }

    //esto es metodo 2
    int k = 0;
    for(int b = n/2; b >= 1; b/=2){
        while(k+b < n && array[k+b] <= x) k += b;
    }
    if(array[k] == x){
        //x encontrado en el indice k
    }



}