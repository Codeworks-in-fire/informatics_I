#include <iostream> 
#include <algorithm> 
#include <vector>
using ll = long long;
using namespace std;


int main() {
    int N,M;
    cin >> N >> M;
    vector<pair<ll,ll>> store(N);
    vector<ll> lengths(2*N - 1);
    for (int i = 0; i < N; i ++ ) {
        cin >> store[i].first >> store[i].second;
    }
    lengths[0] =  store[0].second - store[0].first;    
    for (int i = 1; i < N; i ++ ) {
        lengths[2*i + 1] = store[i].second - store[i].first;
        lengths[2*i] = store[i].first - store[i-1].second;
    }
    
}