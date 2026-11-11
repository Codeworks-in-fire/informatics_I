#include <iostream>
#include <vector>
using in = long;
using namespace std;

// int sum(const vector<int>& d);
void truncate(vector<in> &d,int &st,int &en,int &min);

in tmp = 0;

int main() {
    int n,a,b;
    cin >> n >> a >> b;
    vector<in> temp(n), stor(n) ;
    int p1 = 0, p2 = -1, lng;
    for (int i = 0; i < n; i++) {
        cin >> stor[i];
    }
    
    while (p2 < a - 1) {
        p2++;
        temp[p2] = stor[p2];
        tmp += stor[p2];
    }
    lng = tmp;
    for (int i = p2 + 1; i < n; i++) {
        if (temp[p1] < 0 ){
            truncate(temp,p1,p2,a);
            tmp += stor[i];
            p2++;
            temp[p2] = stor[i];
        }else if (stor[i] > temp[p1] && p2 - p1 + 1 == b) {
            tmp += stor[i] - temp[p1];
            temp[p1] =0;
            p1++;
            p2++;
            temp[p2] = stor[i];
            
        } else if (stor[i] >= 0 && p2-p1+1 < b) {
            p2++;
            temp[p2] = stor[i];
            tmp+= stor[i];
        } else if (p2-p1+1 == b) {
            if(lng < tmp) {
                lng = tmp;
            }
            p2++;
            tmp += stor[i] - temp[p1];
            temp[p1] = 0;
            p1++;
            temp[p2] = stor[i];
        } else {
            if(lng < tmp) {
                lng = tmp;
            }
            p2++;
            temp[p2] = stor[i];
            tmp += stor[i];
        }
    }
    if(lng < tmp) {
        lng = tmp;
    }
    cout << lng;
}
// int sum(const vector<int>& d){
//     int ans = 0;
//     for (int l : d) {
//         ans += l;
//     }
//     return ans;
// }

void truncate(vector<in> &d,int &st,int &en,int &min){
    while (en - st +1 >= min && d[st] < 0){
        tmp -= d[st];
        d[st] = 0;
        st ++;
        
    }
}