class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def insert(root, value):
    if root is None:
        return Node(value)
    if value < root.value:
        root.left = insert(root.left, value)
    else:
        root.right = insert(root.right, value)
    return root

def findLCA(root, value1, value2):
    if root is None:
        return None
    if root.value > value1 and root.value > value2:
        return findLCA(root.left, value1, value2)
    if root.value < value1 and root.value < value2:
        return findLCA(root.right, value1, value2)
    return root

def findDistance(root, value):
    if root is None or root.value == value:
        return 0
    if value < root.value:
        return 1 + findDistance(root.left, value)
    return 1 + findDistance(root.right, value)

def shortestPathDistance(root, value1, value2):
    lca = findLCA(root, value1, value2)
    if lca is None:
        return -1
    distance1 = findDistance(root, value1)
    distance2 = findDistance(root, value2)
    distanceLCA = findDistance(root, lca.value)
    return distance1 + distance2 - 2 * distanceLCA

values = list(map(int, input().split()))
root = None
for val in values:
    root = insert(root, val)

node1, node2 = map(int, input().split())
distance = shortestPathDistance(root, node1, node2)
print(distance)
