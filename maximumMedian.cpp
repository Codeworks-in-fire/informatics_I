#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    unordered_map <int,int> store;
    vector<int> keep(n);
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        cin >> keep[i] ; 
    }
    sort(keep.begin(),keep.end());
    int l = n/2;
    int med = keep[l];
    for (int i = l; i < n; i++){
        if (store.find(keep[i]) == store.end()) {
            store.insert({keep[i],1});
            temp.push_back(keep[i]);
        } else {
            store[keep[i]]++;
        }
    }
    l = store[temp[0]];
    n = 0;
    while(n < temp.size()){
        if (n == temp.size()-1) {
            med += k/l;
            break;
        }
        if (k/l >= temp[n+1]-temp[n]) {
            med = temp[n+1];
            k -=  l*(temp[n+1]-temp[n]);
            n ++;
            
            l += store[temp[n]];
            

        } else {
            med += k/l;
            break;
        }
    }
    cout << med;
}