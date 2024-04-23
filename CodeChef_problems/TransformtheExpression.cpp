// problem link
// https://www.codechef.com/practice/course/stacks-and-queues/STAQUEF/problems/ONP

#include <iostream>
#include <stack>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--) {
	    string str, res = "";
	    cin >> str;
	    stack<char> stk;

	    for(char i : str){
	        if(i == '('){
	            stk.push(i);
	        }
	        else if(i == ')'){
	            while(stk.size() > 0 && stk.top() != '('){
	                res = res + stk.top();
	                stk.pop();
	            }

	            stk.pop();
	        }
	        else if(stk.size() > 0 && (stk.top() == '*' || stk.top() == '/' || stk.top() == '^') && (i == '+' || i == '-')){

	            while((stk.top() == '*' || stk.top() == '/' || stk.top() == '^') && (i == '+' || i == '-')){
	                res += stk.top();
	                stk.pop();
	            }

	            stk.push(i);
	        }
	        else if(i == '+' || i == '-' || i == '*' || i == '/' || i == '^'){
	            stk.push(i);
	        }else{
	            res += i;
	        }
	    }

	    while(stk.size() > 0){
	        res = res + stk.top();
	        stk.pop();
	    }

	    cout << res << endl;
	}
	return 0;
}
