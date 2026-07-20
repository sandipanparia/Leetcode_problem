class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=INT_MIN;
        int i=0;int j=n-1;
        while(i<j){
            int w=j-i;
            int h=min(height[i],height[j]);
            int ar=w*h;
            ans=max(ans,ar);
            if(height[i]==h)i++;
            else j--;
        }
        return ans;
    }
};
