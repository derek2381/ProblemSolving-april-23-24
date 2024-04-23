// problem link
// https://www.codechef.com/practice/course/stacks-and-queues/STAQUEF/problems/NEC

#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

int main() {
	// your code goes here

	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    vector<int> arr(n), res;

	    for(int i = 0;i < n;i++){
	        cin >> arr[i];
	    }

	    stack<int> stk;

	    for(int i = k-1;i >= 0;i--){
	        stk.push(arr[i]);
	    }

	    for(int i = n-1;i >= k;i--){
	        stk.push(arr[i]);
	    }

	    while(stk.size() > 0){
	        res.push_back(stk.top());
	        stk.pop();
	    }

	    for(int i : res){
	        cout << i << " ";
	    }
	    cout << endl;
	}

}
