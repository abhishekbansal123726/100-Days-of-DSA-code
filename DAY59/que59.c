class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def build(inorder, postorder):
    if not inorder:
        return None
    root_val = postorder.pop()
    root = Node(root_val)
    idx = inorder.index(root_val)
    root.right = build(inorder[idx+1:], postorder)
    root.left = build(inorder[:idx], postorder)
    return root

def preorder(root):
    if root:
        print(root.val, end=" ")
        preorder(root.left)
        preorder(root.right)

n = int(input())
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))

root = build(inorder, postorder)
preorder(root)
