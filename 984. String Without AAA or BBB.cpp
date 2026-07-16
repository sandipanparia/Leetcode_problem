class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s="";
        char ch='a';
        if(b>a){
            ch='b';
        }
        while(a>0||b>0){
            if(ch=='a'){
                if(a>b){
                    if((a-b)>1){
                        s.push_back('a');
                        s.push_back('a');
                        a-=2;
                    }
                    else{
                        s.push_back('a');
                        a--;
                    }
                }
                else{
                    s.push_back('a');
                    a--;
                }
                ch='b';
            }
            else{
                if(b>a){
                    if((b-a)>1){
                        s.push_back('b');
                        s.push_back('b');
                        b-=2;
                    }
                    else{
                        s.push_back('b');
                        b--;
                    }
                }
                else{
                    s.push_back('b');
                    b--;
                }
                ch='a';
            }
        }
        return s;
        
    }
};
