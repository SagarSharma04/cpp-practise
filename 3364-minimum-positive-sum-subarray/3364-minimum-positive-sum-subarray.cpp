class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                int len = j-i+1;
                if(len>= l && len<=r){
                    
                    for(int k=i;k<=j;k++){
                        sum+=nums[k];
                    }
                    if(sum>0){
                            flag = true;
                            ans = min(ans,sum);
                    }
                    
                }
            }
        }
        if(!flag){
                return -1;
        }
        return ans;
    }
};