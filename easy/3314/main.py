class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []

        for num in nums:
            ans.append(-1);
            for i in range(num):
                if ((i | i+1) == num):
                    ans.pop()
                    ans.append(i)
                    break

        return ans
        
