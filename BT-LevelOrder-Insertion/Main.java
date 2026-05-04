import java.util.Scanner;

class Node{
    int data;
    Node left;
    Node right;

    Node(int val){
        data = val;
        left = right = null;
    }
}

class BinaryTree{

    Node root;
    // int maxSize;

    // BinaryTree(int size){
    //     root = null;
    //     maxSize = size;
    // }

    BinaryTree(){
        root = null;
    }

    Node queue[] = new Node[100];
    int front =0,rear=0;

    void insert(int val){

        Node newNode = new Node(val);

        if(root == null){
            root = newNode;
            queue[rear++] = root;
            return;
        }

        Node temp = queue[front];

        if(temp.left == null){
            temp.left = newNode;
        }
        else{
            temp.right = newNode;
            front++;
        }
        queue[rear++]=newNode;
    }

    void inorder(Node root){
        if(root!=null){
            inorder(root.left);
            System.out.print(root.data+" ");
            inorder(root.right);
        }
    }

    void preorder(Node root){
        if(root!=null){
            System.out.print(root.data+" ");
            preorder(root.left);
            preorder(root.right);
        }

    }

    void postorder(Node root){
        if(root!=null){
            postorder(root.left);
            postorder(root.right);
            System.out.print(root.data+" ");
        }
    }
}

public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);

        // int size = sc.nextInt();
        // BinaryTree tree = new BinaryTree(size);

        BinaryTree tree = new BinaryTree();

        int val;

        do{
            val = sc.nextInt();
            if(val!=-1)
                tree.insert(val);
        }while(val!=-1);

        tree.inorder(tree.root);
        System.out.println();
        tree.preorder(tree.root);
        System.out.println();
        tree.postorder(tree.root);

        sc.close();
    }
}