class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        int i = 0, j = 0;
        multiset<int> window;
        int max_size = 0;
        while(j < n){
            window.insert(nums[j]);
            if((*window.rbegin() - *window.begin()) <= limit){
                cout<<*window.rbegin()<<" "<<*window.begin()<<" ";
                max_size = max(max_size, j - i + 1);
                cout<<max_size<<endl;
            }
            else{
                while((*window.rbegin() - *window.begin()) > limit){
                    // cout<<*window.begin()<<" "<<*window.end()<<endl;
                    window.erase(window.find(nums[i]));
                    i++;
                }
            }
            j++;
        }

        return max_size;
    }
};