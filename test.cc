#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<unordered_set>
using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int rows=matrix.size(),cols=matrix[0].size(),ret=0;
        vector<int> h(cols+1);
        for(int i=0;i<rows;i++) {
            stack<int> lowi;
            matrix[i].push_back('0');
            for(int j=0;j<=cols;j++) {
                h[j]=((matrix[i][j]=='1')?h[j]+1:0);
		h[cols]=-2;
                if(!lowi.empty() && h[j]<h[lowi.top()]){
                    int height=h[lowi.top()];
                    lowi.pop();
                    int lefti=(lowi.empty()?-1:lowi.top());
                    ret=max((j-lefti-1)*height,ret);
                }
                lowi.push(j);
            }
        }
        return ret;     
    }
};

int main() {
	Solution s1;
	vector<vector<char>> vc{{'1','0','1','0','0'},{'1','0','1','1','1'},
							{'1','1','1','1','1'},{'1','0','0','1','0'}};
	auto res=s1.maximalRectangle(vc);
	cout<<res<<endl;
	return 0;
}
