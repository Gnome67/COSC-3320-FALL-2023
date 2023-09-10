# Fails 6, 8, 9

def canDivide(nums, k):
    def helper(count):
        if not count:
            return True
        
        min_element = min(count)
        if min_element not in count:
            return False
        
        for i in range(min_element, min_element + k):
            if i not in count or count[i] <= 0:
                return False
            count[i] -= 1
            if count[i] == 0:
                del count[i]
        
        return helper(count)
    
    count = {}
    for num in nums:
        count[num] = count.get(num, 0) + 1
    
    return helper(count)

# Read input
nums = list(map(int, input().split()))
k = int(input())

# Check if it's possible to divide nums into sets of k consecutive numbers
result = canDivide(nums, k)
if result == True:
  print("true")
if result == False:
  print("false")
