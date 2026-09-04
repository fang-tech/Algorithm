#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#

# @lc code=start
class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        ans = []
        nums = sorted(nums)
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            j, k = i + 1, len(nums) - 1
            while j < k:
                s = nums[i] + nums[j] + nums[k]
                if s == 0:
                    ans.append([nums[i], nums[j], nums[k]])
                    j += 1
                    while j < k and nums[j] == nums[j-1]:
                        j += 1

                    k -= 1
                    while j < k and nums[k] == nums[k+1]:
                        k -= 1
                elif s > 0:
                    k -= 1
                else:
                    j += 1
        return ans
if __name__ == "__main__":
    i = [0, 0, 0]
    s = Solution()
    print(s.threeSum(i))

# @lc code=end
