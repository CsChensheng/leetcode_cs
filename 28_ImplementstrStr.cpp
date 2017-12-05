//采用kmp字符串匹配
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//计算kmp中next数组
void computNext(const string p, int next[]){
	int q; //字符串下标
	int maxK = 0; //最大前后缀长度
	
	next[0] = 0;
	for(q = 1; q < int(p.size()); q++){
		//从字符串第二位开始
		while(maxK > 0 && p[maxK] != p[q])
			maxK = next[maxK-1]; //重要 需要理解 笔记本上
		if(p[maxK] == p[q])
			maxK++;
		next[q] = maxK;
	}
}

//计算kmp中next数组
void computNext(const string p, vector<int> &next){
	int q; //字符串下标
	int maxK = 0; //最大前后缀长度
	if(int(next.size())==0)  next.push_back(0);
	//next[0] = 0;
	for(q = 1; q < int(p.size()); q++){
		//从字符串第二位开始
		while(maxK > 0 && p[maxK] != p[q])
			maxK = next[maxK-1]; //重要 需要理解 笔记本上
		if(p[maxK] == p[q])
			maxK++;
		next[q] = maxK;
		//next.push_back(maxK);
	}
}

int main(){
	/*string p = "ll";
	int strSize = p.size();
	//int next[strSize];
	vector<int> next(strSize);
	computNext(p, next);
	cout << next[1];
	return 0;*/
	
	string haystack = "mississippi";
	string needle = "sipp";
	int strSize = needle.size();
	//int next[strSize];
	vector<int> next(strSize);
	computNext(needle, next);
	int i, j;
	int result = -1;
	for(i = 0, j = 0; i < int(haystack.size()); ){
		while(haystack[i] == needle[j] && j < strSize){
			i++;
			j++;
		}
		if(j == strSize){
			result = i - j;
			break;
		}
		else{
			if(j == 0)	
				i++;
			else 
				i += (j-next[j-1]);
		} 
	}
	cout << result;
	return 0;
}
