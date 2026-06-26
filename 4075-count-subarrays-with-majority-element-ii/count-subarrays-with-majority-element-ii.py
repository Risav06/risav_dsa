class Solution:
    def countMajoritySubarrays(self, nums, target):
        n = len(nums)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i+1] = prefix[i] + (1 if nums[i] == target else -1)
        
        offset = n + 1
        size = 2 * n + 3
        BIT = [0] * (size + 1)
        
        def update(i, val):
            i += 1
            while i <= size:
                BIT[i] += val
                i += i & -i
        
        def query(i):
            i += 1
            res = 0
            while i > 0:
                res += BIT[i]
                i -= i & -i
            return res
        
        ans = 0
        update(offset, 1)
        
        for i in range(1, n + 1):
            ans += query(prefix[i] + offset - 1)
            update(prefix[i] + offset, 1)
        
        return ans