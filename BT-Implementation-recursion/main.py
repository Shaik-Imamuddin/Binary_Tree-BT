class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


def insert():
    val = int(input())

    if val == -1:
        return None

    node = Node(val)

    node.left=insert()
    node.right=insert()

    return node


def inorder(root):
    if root is None:
        return
    inorder(root.left)
    print(root.data,end=" ")
    inorder(root.right)

def preorder(root):
    if root is None:
        return
    print(root.data,end=" ")
    preorder(root.left)
    preorder(root.right)

def postorder(root):
    if root is None:
        return
    postorder(root.left)
    postorder(root.right)
    print(root.data,end=" ")


root = insert()
inorder(root)
print()
preorder(root)
print()
postorder(root)