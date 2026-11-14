import heapq

def top_k_largest(nums, k):
    return heapq.nlargest(k, nums)

if __name__ == "__main__":
    print(top_k_largest([3, 2, 1, 5, 4], 3))
