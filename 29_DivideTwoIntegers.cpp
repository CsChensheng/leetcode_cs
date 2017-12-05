#include <iostream>
#include <cmath>

using namespace std;

int divide(int dividend, int divisor){
    bool flag = false;
    if(dividend > 0 && divisor < 0){
        flag = true;
    }
    if(dividend < 0 && divisor > 0){
        flag = true;
    }

    long long unDividend = abs(dividend);
    if(dividend == -2147483648) unDividend = 2147483648;
    long long unDivisor = abs(divisor);
    if(divisor == -2147483648) unDivisor = 2147483648;
    long long sum = 0;
    if(unDivisor == 0)    return 0;
    long long result = 0;
    long long addX = 0 ;
    while(unDivisor < unDividend){
        addX = 1;
        sum = unDivisor;
        while((sum<<=1) < unDividend){
            addX<<=1;
        }
        unDividend -= (sum>>=1);
        result += addX;
    }
    if(unDivisor == unDividend)
        result++;
   result = flag ? (0-result) : result;
   if(result > 2147483647 || result < -2147483648)   return 2147483647;
   return result;

}

int main(){
    int result = divide(-1010369383,-2147483648);
    //long long result = 2147483648;
    cout << result;
    return 0;
}
