void buildSegmentTree(int i, int l, int r, int segmentTree[], int arr[]) {
    if (l == r) {
        segmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
    segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
}

int* constructST(int arr[], int n) {
    int* segmentTree = new int[4 * n];
    buildSegmentTree(0, 0, n - 1, segmentTree, arr);
    return segmentTree;
}

int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[]) {
    if (l > end || r < start) {
        return INT_MIN;
    }

    if (l >= start && r <= end) {
        return segmentTree[i];
    }

    int mid = l + (r - l) / 2;
    return max(querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree),
               querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree));
}

int RMQ(int st[], int n, int a, int b) {
    return querySegmentTree(a, b, 0, 0, n - 1, st);
}
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n=s.size();
        int cnt=count(s.begin(),s.end(),'1');

        vector<int>blockStart;
        vector<int>blockEnd;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int str=i;
                while(i<n&&s[i]=='0')i++;
                blockStart.push_back(str);
                blockEnd.push_back(i-1);
            }
            else i++;
        }
        int m=blockStart.size();
        if(m<2){
            return vector<int>(queries.size(),cnt);
        }
        vector<int>blockSize(m);
        for(int i=0;i<m;i++){
            blockSize[i]=blockEnd[i]-blockStart[i]+1;
        }

        //PairSum: blockSize[i]=blocksz[i]+blocksz[i+1];
        vector<int>pairSum(m-1);
        for(int i=0;i<m-1;i++){
            pairSum[i]=blockSize[i]+blockSize[i+1];
        }
        int *st=constructST(pairSum.data(),m-1);

        vector<int>res;
        for(auto it:queries){
            int l=it[0];
            int r=it[1];

            int low=lower_bound(blockEnd.begin(),blockEnd.end(),l)-blockEnd.begin();
            int high=upper_bound(blockStart.begin(),blockStart.end(),r)-blockStart.begin()-1;
            int mxPairSum=0;

            if(low<high){
                int firstLen=blockEnd[low]-max(blockStart[low],l)+1;
                int lastLen=min(blockEnd[high],r)-blockStart[high]+1;

                if(high-low==1){
                    mxPairSum=firstLen+lastLen;
                }
                else{
                    int pair1=firstLen+blockSize[low+1];
                    int pair2=blockSize[high-1]+lastLen;
                    int RMQMaxPairSum=RMQ(st,m-1,low+1,high-2);
                    mxPairSum=max({pair1,pair2,RMQMaxPairSum});
                }
            }
            res.push_back(mxPairSum+cnt);
        }
        return res;
    }
};
