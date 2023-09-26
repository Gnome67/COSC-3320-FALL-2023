# def countRotations(arr, n):
#     start = 0
#     end = len(arr)-1
#     while start<=end:
#         mid = start+(end-start)//2
#         prev = (mid-1 + len(arr)) % len(arr)
#         nex = (mid+1) % len(arr)
#         if arr[mid]<arr[prev] and arr[mid]<=arr[nex]: 
#           return mid
#         elif arr[mid]<arr[start]: end = mid-1
#         elif arr[mid]>arr[end]: start = mid+1
#         else: return 0

# def search(arr, n):
#         left, right = 0, len(arr) - 1
#         while left <= right:
#             mid = (left + right) // 2
#             if arr[mid] == n:
#                 return mid
#             if arr[left] <= arr[mid]:
#                 if arr[left] <= n < arr[mid]:
#                     right = mid - 1
#                 else:
#                     left = mid + 1
#             else:
#                 if arr[mid] < n <= arr[right]:
#                     left = mid + 1
#                 else:
#                     right = mid - 1
#         return -1

# input_str = input()
# n = int(input())
# input_arr = input_str.split()
# arr = [int(x) for x in input_arr]
# count = countRotations(arr, n)
# n = search(arr, n)
# print(count)
# print(n)
