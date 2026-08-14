class Solution {
public:
    int minPartitions(string n) {
        char ch=*max_element(begin(n),end(n));
        return ch-'0';
    }
};
