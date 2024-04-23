// problem link
// https://codeforces.com/problemset/problem/1343/A

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;

        for(int i = 2;i < n;i++){
            int val = (1 << i) - 1;

            if(n%val == 0){
                cout << n/val << endl;
                break;
            }
        }
    }
}
