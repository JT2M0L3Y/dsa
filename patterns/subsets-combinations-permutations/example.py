def subsets(nums):
    result = []
    def dfs(start, path):
        result.append(path.copy())
        for i in range(start, len(nums)):
            path.append(nums[i])
            dfs(i + 1, path)
            path.pop()
    dfs(0, [])
    return result

if __name__ == "__main__":
    print(subsets([1, 2, 3]))
