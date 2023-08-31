# def getMaxDiff(a):
#     if len(a) < 2:
#         return 0
#     max_diff = 0
#     min_val = a[0]
#     for i in range(1, len(a)):
#         if a[i] < min_val:
#             min_val = a[i]
#         max_diff = max(max_diff, a[i] - min_val)
#     return 0 if max_diff < 0 else max_diff

def getMaxDiff(arr, low, high):
    if low == high:
        return 0
    if high == low + 1:
        return max(0, arr[high] - arr[low])

    mid = (low + high) // 2

    maxDiffLeft = getMaxDiff(arr, low, mid)
    maxDiffRight = getMaxDiff(arr, mid + 1, high)

    minLeft = min(arr[low:mid + 1])
    maxRight = max(arr[mid + 1:high + 1])
    maxCrossDiff = maxRight - minLeft

    return max(maxDiffLeft, maxDiffRight, maxCrossDiff)

n = int(input())
arr = list(map(int, input().split()))

print(getMaxDiff(arr, 0, n-1))
