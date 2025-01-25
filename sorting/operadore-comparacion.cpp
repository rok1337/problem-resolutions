#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<pair<int, int>> v1;
    v1.push_back({1, 5});
    v1.push_back({2, 3});
    v1.push_back({1, 2});
    sort(v1.begin(), v1.end());

    vector<tuple<int, int, int>> v2;
    v2.push_back({2, 1, 4});
    v2.push_back({1, 5, 3});
    v2.push_back({2, 1, 3});
    sort(v2.begin(), v2.end());

    struct P {
        int x, y;
        bool operator<(const P &p) {
            if (x != p.x) return x < p.x;
            else return y < p.y;
        }
    };

    bool comp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
    }

}
