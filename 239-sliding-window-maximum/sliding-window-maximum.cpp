class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        struct monotonedq{
            deque<int> dq;
          void insert(int x){
            while(!dq.empty() && dq.back()<x){
                dq.pop_back();}
            dq.push_back(x);
          }
          void remove(int x){
            if (!dq.empty() && dq.front()==x) dq.pop_front();
          }
          int give() {return dq.front();}
        };
        monotonedq d;
        vector<int> maxi;
        for(int i=0;i<nums.size();i++){
            d.insert(nums[i]);
            if(i-k>=0) d.remove(nums[i-k]);
            if(i-k>=-1){
                maxi.push_back(d.give());
            }
        }
        return maxi;
    }
};