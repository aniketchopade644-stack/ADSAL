#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

struct Node
{
    char data;
    Node *left, *right;
};

// Function to create new node
Node* createNode(char x)
{
    Node* temp = new Node;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

// Construct expression tree from prefix
Node* constructTree(char prefix[])
{
    stack<Node*> s;
    int len = strlen(prefix);

    for(int i = len - 1; i >= 0; i--)
    {
        Node* temp = createNode(prefix[i]);

        if(isalpha(prefix[i])) // operand
        {
            s.push(temp);
        }
        else // operator
        {
            temp->left = s.top(); s.pop();
            temp->right = s.top(); s.pop();
            s.push(temp);
        }
    }

    return s.top();
}

// Non-recursive postorder traversal
void postorder(Node* root)
{
    stack<Node*> s1, s2;

    s1.push(root);

    while(!s1.empty())
    {
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);

        if(temp->left)
            s1.push(temp->left);

        if(temp->right)
            s1.push(temp->right);
    }

    cout << "\nPostorder Traversal: ";

    while(!s2.empty())
    {
        cout << s2.top()->data;
        s2.pop();
    }
}

// Delete entire tree
void deleteTree(Node* root)
{
    if(root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    cout << "\nDeleting node: " << root->data;
    delete root;
}


int main()
{
    char prefix[20];

    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    Node* root = constructTree(prefix);

    postorder(root);

    cout << "\n\nDeleting Tree...";
    deleteTree(root);

    return 0;
}



