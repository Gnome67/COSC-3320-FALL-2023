def lastRemaining(n):
        if n == 1:
            return 1
        return 2 * (n // 2 - lastRemaining(n // 2) + 1)

k = int(input())
ans = lastRemaining(k)
print(ans)
