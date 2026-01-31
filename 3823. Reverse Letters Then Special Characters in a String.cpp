class Solution {
public:
    string reverseByType(string s) {
        int n = s.size();
        string letters, specials;
        
        
        for(char ch : s) {
            if(isalpha(ch)) letters += ch;
            else specials += ch;
        }
        
   
        reverse(letters.begin(), letters.end());
        reverse(specials.begin(), specials.end());
        
        string ans = "";
        int li = 0, si = 0;
        
       
        for(char ch : s) {
            if(isalpha(ch)) ans += letters[li++];
            else ans += specials[si++];
        }
        
        return ans;
    }
};
