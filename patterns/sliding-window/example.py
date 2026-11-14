def max_sum_subarray(nums, k):
    if len(nums) < k:
        return 0
    window_sum = sum(nums[:k])
    best = window_sum
    for i in range(k, len(nums)):
        window_sum += nums[i] - nums[i - k]
        best = max(best, window_sum)
    return best

if __name__ == "__main__":
    nums = [1, 3, 2, 6, 4, 5]
    print(max_sum_subarray(nums, 3))
