class Solution {
public:
    // void bruete(vector<int> &nums){
    //     int n = nums.size();
    //     int minEle = 1;
    //     int maxEle = *max_element(nums.begin(), nums.end());

    //     unordered_map<int, int> mp;
    //     for(int i = 0; i < n; i++){
    //         mp[nums[i]]++;
    //     }

    //     bool flag = false;
    //     int missingNumber;
    //     for(int i = 1; i <= n; i++){
    //         if(mp.find(i) == mp.end()){
    //             flag = true;
    //             cout<<flag<<endl;
    //             missingNumber = i;
    //             break;
    //         }
    //     }

    //     cout<<flag<<endl;
    //     if(flag == false){
    //         maxEle = max(0, maxEle);
    //         missingNumber = maxEle + 1;
    //     }

    //     return missingNumber;  
    // }
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // where ever i the 1 .... n there we have to use n as index
        bool contain1 = false;
        // first pass
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                contain1 = true;
            }
            else if(nums[i] > n){
                nums[i] = 1;
            }
            else if(nums[i] <= 0){
                nums[i] = 1;
            }
        }

        // 2nd pass

        if(!contain1) return 1;
        for(int i = 0; i < n; i++){
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0){
                continue;
            }
            nums[index] *= -1;
        }

        int missNum;
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                missNum = i + 1;
                flag = true;
                break;
            }
        }
        
        if(!flag) return n + 1;

        return missNum;

    }
};