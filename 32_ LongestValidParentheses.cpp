#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int longestValidParentheses(string s) {
	int strLen = s.size();
	stack<char> strS;
	int startStackSize = 0;
	int curStackSize = 0;
	int maxLen = 0;
	int curLen = 0;
	char curC;
	int i;
	//vector<int> everyValue;
	for(i = 0; i < strLen; i++){
		curC = s[i];
		if(!strS.empty()){
			if(strS.top() == '(' && curC == ')'){
				strS.pop();
				curLen += 2;
				curStackSize = strS.size();
				if(startStackSize >= curStackSize){
					maxLen += curLen;
					curLen = 0;
					startStackSize = curStackSize;
				}
				if(curLen > maxLen){
					if(i < strLen-1){
						if(s[i+1] != ')'){
							maxLen = curLen;
							startStackSize = curStackSize;
							curLen = 0;
						}
					}
				}
			}
			else{
				strS.push(curC);
			}	
		}
		else{
			strS.push(curC);		
		}
	}
	return maxLen;
}

int main(){
	string s = "(()";
	int result = longestValidParentheses(s);
	cout << result;
	return 0;
}
