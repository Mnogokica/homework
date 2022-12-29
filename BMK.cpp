#include <cstdlib>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* CreateNode()
{
    Node* newNode;
    newNode = new Node;
    cout << "\nAdd node: ";
    cin >> newNode->data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void AddNode(Node* root)
{
    Node* newNode, * temp;
    temp = root;
    newNode = CreateNode();
    while ((temp->data >= newNode->data && temp->left != NULL) || (temp->data < newNode->data && temp->right != NULL))
    {
        while (temp->data >= newNode->data && temp->left != NULL)
        {
            temp = temp->left;
        }

        while (temp->data < newNode->data && temp->right != NULL)
        {
            temp = temp->right;
        }
    }

    if (temp->data >= newNode->data && temp->left == NULL)
    {
        temp->left = newNode;
    }

    if (temp->data < newNode->data && temp->right == NULL)
    {
        temp->right = newNode;
    }
}

Node* FindNode(Node* root, int x)
{
    Node* temp = root;
    if (temp->data == x)
    {
        return temp;
    }
    else
    {
        while ((temp->data >= x && temp->left != NULL) || (temp->data < x && temp->right != NULL))
        {
            while (temp->data >= x && temp->left != NULL)
            {
                temp = temp->left;
            }

            while (temp->data < x && temp->right != NULL)
            {
                temp = temp->right;
            }
        }
        return temp;
    }
}

Node* FindNodeParent(Node* root, int x)
{
    Node* temp = root, * parent = root;

    while ((temp->data >= x && temp->left != NULL) || (temp->data < x && temp->right != NULL))
    {
        while (temp->data >= x && temp->left != NULL)
        {
            parent = temp;
            temp = temp->left;
        }

        while (temp->data < x && temp->right != NULL)
        {
            parent = temp;
            temp = temp->right;
        }
    }
    return parent;
}

void CountNodes(Node* root, int& count)
{
    if (root)
    {
        CountNodes(root->left, count);
        count++;
        CountNodes(root->right, count);
    }
}

void PrintTreeInorder(Node* cur) // LVR
{
    if (!cur)
        return;
    PrintTreeInorder(cur->left);
    cout << cur->data << " ";
    PrintTreeInorder(cur->right);
}

void PrintTreePreorder(Node* cur) // VLR
{
    if (!cur)
        return;
    cout << cur->data << " ";
    PrintTreePreorder(cur->left);
    PrintTreePreorder(cur->right);
}

void PrintTreePostorder(Node* cur) // LRV
{
    if (!cur)
        return;
    PrintTreePostorder(cur->left);
    PrintTreePostorder(cur->right);
    cout << cur->data << " ";
}

void ReverseTree(Node* cur)
{
    if (cur)
    {
        ReverseTree(cur->left);
        ReverseTree(cur->right);
        Node* temp;
        temp = cur->left;
        cur->left = cur->right;
        cur->right = temp;
    }
}

Node* DeleteNode(Node* root, int x)
{
    Node* prev = root, * cur = root, * temp;
    while (cur->data != x/* && (cur->left != NULL && cur->right != NULL)*/)
    {
        if (cur->data > x  && cur->left != NULL)
        {
            prev = cur;
            cur = cur->left;
        }
        else if (cur->data < x && cur->right != NULL)
        {
            prev = cur;
            cur = cur->right;
        }
    }
    if (cur == NULL || cur->data != x)
    {
      cout<<"\ncur = "<<cur->data;
        cout << "\nSuch node does not exist!";
        return root;
    }
    cout<<"\ncytuur = "<<cur->data;
    // 1 bērns
    if ((cur->left == NULL) && (cur->right != NULL) || (cur->left != NULL) && (cur->right == NULL))
    {
        if ((cur->left != NULL) && (root == cur))
            root = cur->left;

        else if ((cur->right != NULL) && (root == cur))
            root = cur->right;

        else if ((cur->left != NULL) && (prev->left == cur))
            prev->left = cur->left;

        else if ((cur->left != NULL) && (prev->right == cur))
            prev->right = cur->left;

        else if ((cur->right != NULL) && (prev->left == cur))
            prev->left = cur->right;

        else if ((cur->right != NULL) && (prev->right == cur))
            prev->right = cur->right;

        delete cur;
        cout << "\nThe node was deleted!";
        return root;
    }

    // 2 bērni
    else if ((cur->left != NULL) && (cur->right != NULL))
    {
        temp = cur;

        if (cur == prev->left)
            prev->left = cur->right;

        else if (cur == prev->right)
            prev->right = cur->right;

        cur = cur->right;
        while (cur->left != NULL)
            cur = cur->left;

        cur->left = temp->left;
        if (temp == root)
            root = cur;

        delete temp;
        cout << "\nThe node was deleted!";

        return root;
    }
    // 0 bērnu
    else
    {
        if (cur == root)
        {
            delete cur;
            return NULL;
        }

        else if (prev->left == cur)
            prev->left = NULL;

        else if (prev->right == cur)
            prev->right = NULL;

        delete cur;
        cout << "\nThe node is deleted!";
        return root;
    }
}

int main()
{

    int x, count;
    Node* root = NULL, * cur, * find, * find1;
    string action = "";

    do
    {
        system("cls");
        cout << "Binary Tree by Alisa Suhoveiko\n";
        cout << "\nChoose action: ";
        cout << "\n0. Create root";
        cout << "\n1. Print tree";
        cout << "\n2. Add node";
        cout << "\n3. Find node";
        cout << "\n4. Find parent";
        cout << "\n5. Count nodes";
        cout << "\n6. Print tree (inorder, preorder, postorder)";
        cout << "\n7. Reverse tree";
        cout << "\n8. Delete node";
        cout << "\n100. Stop program";
        cout << "\nAction: ";
        cin >> action;

        if (action == "100")
        {
            cout << "\nEnd of the program!";
            system("pause>>nul");
        }

        else if (action == "0")
        {
            if (!root)
                root = CreateNode();

            else
                cout << "\nRoot already exists!";
            system("pause>>nul");
        }

        else if (action == "1")
        {
            if (!root)
                cout << "\nRoot does not exist!";

            else
                PrintTreeInorder(root);
            system("pause>>nul");
        }

        else if (action == "2")
        {
            if (!root)
                root = CreateNode();

            else
                AddNode(root);
        }

        else if (action == "3")
        {
            if (root)
            {
                {
                    cout << "\nFind node: ";
                    cin >> x;
                    cur = FindNode(root, x);
                    if (cur->data == x)
                        cout << "\nNode exists!";
                    else
                        cout << "\nNode doesn't exist!";
                }
            }
            else
                cout << "\nThe tree is empty!";
            system("pause>>nul");
        }

        else if (action == "4")
        {
            if (root)
            {
                {
                    cout << "\nFind parent of: ";
                    cin >> x;
                    if (root->data != x) {
                        find1 = FindNode(root, x);
                        if (find1->data == x)
                        {
                            find = FindNodeParent(root, x);
                            if (find->left->data == x || find->right->data == x)
                                cout << "\nParent: " << find->data;
                            else
                                cout << "\nParent doesn't exist!";
                        }
                        else
                            cout << "\nParent doesn't exist!";
                    }
                    else
                        cout << "\nParent doesn't exist!";
                }
            }
            else
                cout << "\nThe tree is empty!";
            system("pause>>nul");
        }

        else if (action == "5")
        {
            count = 0;
            CountNodes(root, count);
            cout << "\nCount of nodes: " << count;
            system("pause>>nul");
        }

        else if (action == "6")
        {
            if (!root)
                cout << "\nRoot does not exist!";

            else
            {
                cout << "\nInorder: "; // LVR
                PrintTreeInorder(root);
                cout << "\n\nPreorder: "; // VLR
                PrintTreePreorder(root);
                cout << "\n\nPostorder: "; // LRV
                PrintTreePostorder(root);
            }
            system("pause>>nul");
        }

        else if (action == "7")
        {
            if (!root)
                cout << "\nThe tree is empty!";
            else
            {
                ReverseTree(root);
                cout << "\nThe tree is reversed!";
            }
            system("pause>>nul");
        }

        else if (action == "8")
        {
            if (!root)
                cout << "\nThe tree is empty!";
            else
            {
                cout << "\nWhat node to delete: ";
                cin >> x;
                root = DeleteNode(root, x);
            }
            system("pause>>nul");
        }

        else
        {
            cout << "\nWrong action!";
             system("pause>>0");
        }
    } while (action != "100");

     system("pause>null");
    return 0;
}
