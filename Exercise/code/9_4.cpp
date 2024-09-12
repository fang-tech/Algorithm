#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int static maximumGap(vector<int>& nums) {
        // 当数组的长度小于2的时候
        if (nums.size() < 2){
            return 0;
        }
        int bkt_max=nums[0], bkt_min=nums[0];
        
        // 获取最大最小值, 以创建桶
        for (int x : nums){
            if (bkt_max < x){
                bkt_max = x;
            }
            else if (bkt_min > x){
                bkt_min = x;
            }
        }

        // 创建桶
        int bucket_size = nums.size() - 1;
        int bucket_step = (bkt_max - bkt_min) / bucket_size + 1;
        vector<vector<int>> buckets(bucket_size + 1);

        // 将元素传入桶
        for (int val : nums){
            int bucket_index = (val - bkt_min) / bucket_step; // 计算桶的索引
            buckets[bucket_index].push_back(val);
        } 

        // 得到每个桶的最大值和最小值
        vector<int> bucket_max;
        vector<int> bucket_min;
        for (const auto& bucket : buckets){
            if (bucket.size() > 0 && !bucket.empty()){
                auto max_it = max_element(bucket.begin(), bucket.end());
                auto min_it = min_element(bucket.begin(), bucket.end());
                bucket_max.push_back(*max_it);
                bucket_min.push_back(*min_it);
            }
        }

        cout << (bucket_max.size() == bucket_min.size());
        // 计算桶之间的差值
        int ret = 0;
        if (bucket_max.size() == 1){
            ret = bucket_max[0] - bucket_min[0];
        }
        else{
            for (int i = 0; i < bucket_max.size() - 1; i++){
                int diff = bucket_min[i+1] - bucket_max[i];
                if (diff > ret){
                    ret = diff;
                }
            }
        }
        return ret;
    }
};

int main(){
    vector<int> in;
    int n;
    while (cin >> n){
        in.push_back(n);
    }
    for (int val : in){
        cout << " " << val;
    }
    cout << endl;

    int ret = Solution().maximumGap(in);
    cout << "ret : " << ret;
    return 0;
}