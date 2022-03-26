#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
	while(1){
    	long long ans = 0;
    	int N;
    	cin >> N;
    	if (N==0) break;	
	
    	long long arr[100002];	
    	for(int i = 1; i <= N; i++) 
    	    cin >> arr[i];
    
    	stack<int> height;	
    	height.push(0);
	
    	for(int i = 1; i <= N + 1; i++) {
    		while(!height.empty() && arr[height.top()] > arr[i]) {
	    		int h= height.top();
	    		height.pop();
    			ans = max(ans, (arr[h] * (i - height.top() - 1)));
    		}
    		height.push(i);
    	}	
    	cout << ans << '\n';    	
	}
}