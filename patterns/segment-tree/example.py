class SegmentTree:
    def __init__(self, nums):
        self.n = len(nums)
        self.tree = [0] * (2 * self.n)
        for i, value in enumerate(nums):
            self.tree[self.n + i] = value
        for i in range(self.n - 1, 0, -1):
            self.tree[i] = self.tree[i * 2] + self.tree[i * 2 + 1]

    def update(self, index, value):
        pos = self.n + index
        self.tree[pos] = value
        pos //= 2
        while pos:
            self.tree[pos] = self.tree[pos * 2] + self.tree[pos * 2 + 1]
            pos //= 2

    def query(self, left, right):
        left += self.n
        right += self.n
        result = 0
        while left <= right:
            if left % 2 == 1:
                result += self.tree[left]
                left += 1
            if right % 2 == 0:
                result += self.tree[right]
                right -= 1
            left //= 2
            right //= 2
        return result

if __name__ == "__main__":
    st = SegmentTree([1, 2, 3, 4, 5])
    print(st.query(1, 3))
    st.update(2, 10)
    print(st.query(1, 3))
