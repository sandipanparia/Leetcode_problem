class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h=(hour%12+(double)minutes/60)*30;
        double m=minutes*6;
        double d=abs(h-m);
        double d1=360-d;
        double ans=min(d,d1);
        return ans;
        
    }
};
