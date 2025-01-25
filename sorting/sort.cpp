#include <bits/stdc++.h>

using namespace std;

vector<int> v = {4,2,5,3,5,8,3};

int main(){

    sort(v.begin(),v.end());
    //esta es otra forma, Un arreglo ordinario se puede ordenar de la siguiente manera
    int n = 7;
    int a[] = {4,2,5,3,5,8,3};
    sort(a, a+n);

    //El siguiente código ordena la cadena s:
    string s = "monkey";
    sort(s.begin(), s.end());

    return 0;
}