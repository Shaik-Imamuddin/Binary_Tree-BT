class Node:
    def __init__(self,val):
        self.data=val
        self.left=None
        self.right=None

class BinaryTree:
    def __init__(self):
        self.root=None
        self.queue=[]
        self.front=0
        self.rear=0

    def insert(self,val):
        newNode = Node(val)

        if self.root is None:
            self.root=newNode
            self.queue.append(self.root)
            self.rear+=1
            return
        
        temp = self.queue[self.front]

        if temp.left is None:
            temp.left=newNode
        else:
            temp.right=newNode
            self.front+=1
        
        self.queue.append(newNode)

    def inorder(self,root):
        if root is not None:
            self.inorder(root.left)
            print(root.data,end=" ")
            self.inorder(root.right)

    def preorder(self,root):
        if root is not None:
            print(root.data,end=" ")
            self.preorder(root.left)
            self.preorder(root.right)

    def postorder(self,root):
        if root is not None:
            self.postorder(root.left)
            self.postorder(root.right) 
            print(root.data,end=" ")
    

bt = BinaryTree()

while True:
    val=int(input())
    if(val==-1):
        break
    bt.insert(val)

bt.inorder(bt.root)
print()
bt.preorder(bt.root)
print()
bt.postorder(bt.root)