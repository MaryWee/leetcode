/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string. 
*/
class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        for(int i=1;i<n;i++) {
            string temp=std::move(res);
            res="";
            int count=1;
            char cur=temp[0];
            for(int j=1;j<temp.size();j++) {
                if(temp[j]==cur)
                    count++;
                else {
                    res.push_back(count+'0');
                    res.push_back(cur);
                    count=1;
                    cur=temp[j];
                }
            }
            res.push_back(count+'0');
            res.push_back(cur);
        }
        return res;
    }
};
