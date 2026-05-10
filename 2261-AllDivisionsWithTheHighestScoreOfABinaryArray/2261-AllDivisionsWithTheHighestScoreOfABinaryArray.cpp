// Last updated: 11/05/2026, 01:31:18
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
  
        int total_zeros=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0){total_zeros++;}
        }
        
        int maxx=n-total_zeros;
        
        vector<int>ans={0};
        
        int left_zeros=0;
    
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0){left_zeros++;}
            int right_ones=n-total_zeros-(i+1-left_zeros);
            int score=left_zeros+right_ones;
            
            if(score>maxx){maxx=score;ans.clear();ans.push_back(i+1);}
            else if(score==maxx){ans.push_back(i+1);}
            
        }
        return ans;
    }
};