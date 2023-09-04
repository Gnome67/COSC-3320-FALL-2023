class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert(root, val):
    if root is None:
        return TreeNode(val)
    if val < root.val:
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    return root

def find_lca(root, node1, node2):
    while root:
        if root.val > node1 and root.val > node2:
            root = root.left
        elif root.val < node1 and root.val < node2:
            root = root.right
        else:
            return root

def find_depth(root, target):
    depth = 0
    while root:
        if root.val == target:
            return depth
        elif target < root.val:
            root = root.left
        else:
            root = root.right
        depth += 1
    return -1  # If target is not found

def shortest_path_distance(root, node1, node2):
    lca = find_lca(root, node1, node2)
    depth1 = find_depth(lca, node1)
    depth2 = find_depth(lca, node2)
    if depth1 == -1 or depth2 == -1:
        return -1  # One of the nodes is not in the tree
    return depth1 + depth2

values = list(map(int, input().split()))
root = None
for val in values:
    root = insert(root, val)

node1, node2 = map(int, input().split())
distance = shortest_path_distance(root, node1, node2)
print(distance)
