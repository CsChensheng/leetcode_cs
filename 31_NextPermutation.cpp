#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int numsLen = nums.size();
    if(numsLen == 1)    return;
    int i;
    int exchangeNum;
    for(i = numsLen - 1; i > 0; i--){
        int tempI = i - 1;
        if(nums[tempI] < nums[i]){
            exchangeNum = tempI;
            break;
        }
        if(tempI == 0){
            reverse(nums.begin(), nums.end());
            return;
        }
    }
    int needExchange = nums[exchangeNum];
    vector<int>::iterator tempNum = max_element(nums.begin(), nums.end());
    int maxBack = *tempNum;
    int exchangeNum2;
    for(i = exchangeNum; i < numsLen; i++){
        if(nums[i] > needExchange && nums[i] <= maxBack){
            maxBack = nums[i];
            exchangeNum2 = i;
        }
    }
    swap(nums[exchangeNum], nums[exchangeNum2]);
    reverse(nums.begin()+exchangeNum+1, nums.end());
    //return nums;
}

int main(){
    vector<int> v = {3,2,1};
    nextPermutation(v);
    int i;
    for(i = 0;i < int(v.size()); i++)
        cout << v[i];
    return 0;
}
