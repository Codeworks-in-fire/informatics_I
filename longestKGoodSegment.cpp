#include <stdio.h>
#include <vector>
#include <unordered_set>
using namespace std;

int push(int x,vector<int>y);

int main () {
    int n;
    int k;
    int p1 = 1,p2 = 1, x = -2;
    int curr, lng = 0, a = 1 , b = 1;
    unordered_set <int> current;
    scanf ("%d %d", &n ,&k);
    vector<int> keep(n);
    for (int i = 0; i < n ; i ++) {
        scanf("%d",&curr);
        keep[i] = curr;
    }
    for (int i = 0; i < n ; i ++) {
        curr = keep[i];
        if (current.size() > k) {
            if (lng < p2 - p1) {
                lng = p2 - p1;
                a = p1;
                b = p2 - 1;
            }
            x = curr;
            current.erase(keep[p1-1]);
            p1 = push(p1,keep);
        }
        if (curr == x + 1 || curr == x - 1 || x == -2) {
            x = curr;
            p2 ++;
            current.insert(x);
        } else {
            if (lng < p2 - p1) {
                lng = p2 - p1;
                a = p1;
                b = p2 -1;
            }
            x = curr;
            current.erase(keep[p1-1]);
            p1 = push(p1,keep);
        }
        
    }
    if (lng < p2 - p1) {
        lng = p2 - p1;
        a = p1;
        b = p2 - 1;
    }
    printf ("%d %d", a ,b);
    return 0;
}

int push(int x,vector<int>y) {
    while (true) {
        if (y[x-1] == y[x] ) {
            x ++;
        } else {
            break;
        }
    }
    return x;
}