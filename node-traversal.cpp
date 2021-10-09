#include <iostream>

using namespace std;

class Node {
private:
    int val;
    Node* left;
    Node* right;
    bool rightThread;
public:
    Node(int v): val(v), left(NULL), right(NULL), rightThread(true) {}
    friend class BinaryTree; 
};

class BinaryTree {
private:
    Node* root;
public:
    BinaryTree() {
        this->root = NULL;
    }
    void Insert(int);
    void In_Order_Traversal();
    void Pre_Order_Traversal();
};

void BinaryTree::Insert(int val) {
    if(this->root == NULL) {
        this->root = new Node(val);
    } else {
        Node* current = this->root;
        while(true) {
            cout << "\n1. Place Node on Left of " << current->val << "\n2. Place node on right of " << current->val << "\nEnter choice: ";
            int choice;
            cin >> choice;
            if(choice == 1) {
                if(current->left == NULL) {
                    Node* temp = new Node(val);
                    temp->right = current;
                    current->left = temp;
                    break;
                }
                current = current->left;
            }
            else if(choice == 2) {
                if(current->rightThread) {
                    Node* temp = new Node(val);
                    temp->right = current->right;
                    current->right = temp;
                    current->rightThread = false;
                    break;
                }
                current = current->right;
            }
        }
    }
}

//      1
//   2     5
// 3   4

void BinaryTree::In_Order_Traversal() {
    Node* current = this->root;
    while(current->left != NULL)
        current =current->left;
    while(current != NULL) {
        cout << current->val << " ";
        if(current->rightThread)
            current = current->right;
        else {
            current = current->right;
            while (current->left != NULL)
                current = current->left;
        }
    }
    cout << "\n";
}

void BinaryTree::Pre_Order_Traversal() {
    Node* current = this->root;
    while (current != NULL) {
        cout << current->val << " ";
        if (current-> left != NULL) 
            current = current->left;
        else if (!current->rightThread)
            current = current->right;
        else {
            while (current->right != NULL && current->rightThread) 
                current = current->right;

            if (current->right == NULL)
                break;
            else 
                current = current->right;
        }
    }
    cout << "\n";
}

int main() {
    BinaryTree tree;
    int choice;
    while(true) {
        cout << "MENU\n";
        cout << "1. Add Node\n";
        cout << "2. In Order Traversal\n";
        cout << "3. Pre Order Traversal\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1: {
                int val;
                cout << "Enter value to enter in node: ";
                cin >> val;
                tree.Insert(val);
                break;
            }
            case 2: {
                tree.In_Order_Traversal();
                break;
            }
            case 3: {
                tree.Pre_Order_Traversal();
            }
        }
    }
}
/**
 * Output:
 MENU
1. Add Node
2. In Order Traversal
3. Pre Order Traversal
Enter your choice: 1
Enter value to enter in node: 24
MENU
1. Add Node
2. In Order Traversal
3. Pre Order Traversal
Enter your choice: 1
Enter value to enter in node: 22

1. Place Node on Left of 24
2. Place node on right of 24
Enter choice: 1
MENU
1. Add Node
2. In Order Traversal
3. Pre Order Traversal
Enter your choice: 1
Enter value to enter in node: 43

1. Place Node on Left of 24
2. Place node on right of 24
Enter choice: 2
MENU
1. Add Node
2. In Order Traversal
3. Pre Order Traversal
Enter your choice: 1
Enter value to enter in node: 21

1. Place Node on Left of 24
2. Place node on right of 24
Enter choice: 1

1. Place Node on Left of 22
2. Place node on right of 22
Enter choice: 1
MENU
1. Add Node
2. In Order Traversal
3. Pre Order Traversal
Enter your choice: 1   
Enter value to enter in node: 21

1. Place Node on Left of 24
2. Place node on right of 24
Enter choice: 1

1. Place Node on Left of 22
2. Place node on right of 22
Enter choice: 2
MENU
1. Add Node
2. In Order Traversal
3. Pre Order Traversal
Enter your choice: 1
Enter value to enter in node: 41

1. Place Node on Left of 24
2. Place node on right of 24
Enter choice: 2

1. Place Node on Left of 43
2. Place node on right of 43
Enter choice: 2
MENU
1. Add Node
2. In Order Traversal
3. Pre Order Traversal
Enter your choice: 1
Enter value to enter in node: 54

1. Place Node on Left of 24
2. Place node on right of 24
Enter choice: 2

1. Place Node on Left of 43
2. Place node on right of 43
Enter choice: 2

1. Place Node on Left of 41
2. Place node on right of 41
Enter choice: 1
MENU
1. Add Node
2. In Order Traversal
3. Pre Order Traversal
Enter your choice: 1
Enter value to enter in node: 235

1. Place Node on Left of 24
2. Place node on right of 24
Enter choice: 1

1. Place Node on Left of 22
2. Place node on right of 22
Enter choice: 2

1. Place Node on Left of 21
2. Place node on right of 21
Enter choice: 1
MENU
1. Add Node
2. In Order Traversal
3. Pre Order Traversal
Enter your choice: 1
Enter value to enter in node: 49

1. Place Node on Left of 24
2. Place node on right of 24
Enter choice: 2

1. Place Node on Left of 43
2. Place node on right of 43
Enter choice: 2

1. Place Node on Left of 41
2. Place node on right of 41
Enter choice: 1

1. Place Node on Left of 54
2. Place node on right of 54
Enter choice: 2

MENU
1. Add Node
2. In Order Traversal
3. Pre Order Traversal
Enter your choice: 2
21 22 235 21 24 43 54 49 41 

MENU
1. Add Node
2. In Order Traversal
3. Pre Order Traversal
Enter your choice: 3
24 22 21 21 235 43 41 54 49 
 **/