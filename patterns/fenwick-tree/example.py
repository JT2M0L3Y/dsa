class Fenwick:
    def __init__(self, nums):
        self.n = len(nums)
        self.bit = [0] * (self.n + 1)
        for i, value in enumerate(nums):
            self.add(i, value)

    def add(self, index, delta):
        index += 1
        while index <= self.n:
            self.bit[index] += delta
            index += index & -index

    def prefix_sum(self, index):
        index += 1
        result = 0
        while index > 0:
            result += self.bit[index]
            index -= index & -index
        return result

if __name__ == "__main__":
    fw = Fenwick([1, 2, 3, 4, 5])
    print(fw.prefix_sum(3))
    fw.add(2, 10)
    print(fw.prefix_sum(3))
