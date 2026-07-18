class Solution {
public:
    int m=1e9 + 7;
    long long merge(vector<int>& a, int l, int mid, int r) {
        vector<int> temp;
        int i = l, j = mid + 1;
        long long inv = 0;

        while (i <= mid && j <= r) {
            if (a[i] <= a[j]) {
                temp.push_back(a[i++]);
            } else {
                temp.push_back(a[j++]);
                inv += (mid - i + 1);
            }
        }

        while (i <= mid) temp.push_back(a[i++]);
        while (j <= r) temp.push_back(a[j++]);

        for (int k = l; k <= r; k++)
            a[k] = temp[k - l];

        return inv%m;
    }

    long long mergeSort(vector<int>& a, int l, int r) {
        if (l >= r) return 0;

        int mid = (l + r) / 2;

        long long inv = 0;
        inv += (mergeSort(a, l, mid))%m;
        inv += (mergeSort(a, mid + 1, r))%m;
        inv += merge(a, l, mid, r)%m;

        return inv;
    }
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        vector<int> grp;

        for(int x: nums){
            if(x<a) grp.push_back(0);
            else if(x<=b) grp.push_back(1);
            else grp.push_back(2);
        }
        return (mergeSort(grp, 0, grp.size() - 1))%m;
        
    }
};
