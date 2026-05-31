#include<bits/stdc++.h>
using namespace std;
vector<int> RandomArray(int n,int v) {
    static mt19937 rng(time(0));
    uniform_int_distribution<int> dist(1,v);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = dist(rng);
    }
    return arr;
}
int right(const vector<int>& arr, int num) {
    for (int i = 0;i < arr.size(); ++i) {
        if (arr[i] >= num) return i;
    }
    return -1;
}
int FindLeft (const vector<int>& arr, int num){
    int l = 0,r = arr.size() - 1,m = 0;
    int ans = -1;
    while (l <= r){
        m = l + (r - l) / 2;
        if (arr[m] >= num){
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}
int main() {
    const int N = 100;
    const int V = 1000;
    const int testTime = 500000;

    mt19937 rng((unsigned)time(nullptr));
    uniform_int_distribution<int> distN(0,N - 1);
    uniform_int_distribution<int> distNum(0,V - 1);

    cout << "Begin" << endl;
    for (int i = 0; i < testTime; ++i) {
        int n = distN(rng);
        vector<int> arr = RandomArray(n,V);
        sort(arr.begin(),arr.end());
        int num = distNum(rng);
        if (right(arr,num) != FindLeft(arr,num)) {
            cout << "Wrong!" << endl;
            return 1;
        }
    } 
    cout << "END" << endl;
    return 0;
}