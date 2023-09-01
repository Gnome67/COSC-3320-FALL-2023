class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def insert(root, val):
    if not root:
        return TreeNode(val)
    if val < root.val:
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    return root

def findPath(root, val, path=[]):
    if not root:
        return None
    if root.val == val:
        return path + [val]
    leftPath = findPath(root.left, val, path + [root.val])
    if leftPath:
        return leftPath
    return findPath(root.right, val, path + [root.val])

def calculateDistance(root, start, end):
    path1 = findPath(root, start)
    path2 = findPath(root, end)
    
    i = 0
    while i < len(path1) and i < len(path2) and path1[i] == path2[i]:
        i += 1
    return len(path1[i:]) + len(path2[i:])
            

tree = list(map(int, input().split()))
start, end = list(map(int, input().split()))
root = None
for val in tree:
    root = insert(root, val)

print(calculateDistance(root, start, end))
