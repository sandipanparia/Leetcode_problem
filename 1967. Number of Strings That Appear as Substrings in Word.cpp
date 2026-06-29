class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(auto it:patterns){
            if(word.find(it)!=string::npos)ans++; //substring ha ki nahi check karne k liye
        }
        return ans;
    }
};
