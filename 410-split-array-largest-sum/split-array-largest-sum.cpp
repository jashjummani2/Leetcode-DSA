class Solution {
public:

    int check(int mid, vector<int>& nums,int k){
        int n = nums.size();
        int remK=0;
        int numInclude =0;
        for (int i=0;i<n;i++){
            if(numInclude>=nums[i]){
                numInclude -= nums[i];
            }
            else{
                remK++;
                numInclude = mid-nums[i];
            }
            if (remK>k)return 0;
        }
        if (remK>k) return 0;
        else return 1;
    }

    int splitArray(vector<int>& nums, int k) {
        
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans =0;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if (check(mid,nums,k)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;

    }
};