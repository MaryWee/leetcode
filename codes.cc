#include<iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int t=m^n,sum=0,cur=0;
        while(t){
            cur|=(1<<(sum++));
			t>>=1;
        }
        return (m|n)&(~cur);
    }
};

int main() {
	Solution s1;
	cout<<s1.rangeBitwiseAnd(5,7);
	return 0;
}
