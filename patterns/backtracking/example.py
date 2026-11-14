def subset_sum(nums, target):
    result = []
    def dfs(start, path, remaining):
        if remaining == 0:
            result.append(path.copy())
            return
        for i in range(start, len(nums)):
            if nums[i] > remaining:
                break
            path.append(nums[i])
            dfs(i + 1, path, remaining - nums[i])
            path.pop()
    dfs(0, [], target)
    return result

if __name__ == "__main__":
    print(subset_sum([1, 2, 3, 4], 5))
