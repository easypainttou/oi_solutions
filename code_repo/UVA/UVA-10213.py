# 见紫薯例题10-23

S = int(input())
for _ in range(S):
    n = int(input())
    print(int((2 * n * n - 2 * n + n * (n - 1) * (n - 2) * (n - 3) // 6) // 4 + 1))