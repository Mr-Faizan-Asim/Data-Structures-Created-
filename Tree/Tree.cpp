#include<iostream>
#include<vector>
#include <queue>
using namespace std;

struct Node
{
    int key;
    vector<Node*> child;
};

// to create a new tree
Node *newNode(int key)
{
    Node*temp = new Node;
    temp->key = key;
    return temp;
}
// Print All Data
void printData(Node *root)
{
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        while(n > 0)
        {
            Node* p = q.front();
            q.pop();
            cout<<p->key<<", ";
            for(int i = 0 ; i < p->child.size(); i++)
                q.push(p->child[i]);
            n--;
        }
        cout<<endl;
    }
}

int main()
{
    Node* root = newNode(10);
    root->child.push_back(newNode(2));
    root->child.push_back(newNode(3));
    root->child.push_back(newNode(4));
    root->child.push_back(newNode(5));
    root->child[0]->child.push_back(newNode(21));
    root->child[0]->child.push_back(newNode(22));
    root->child[1]->child.push_back(newNode(31));
    root->child[3]->child.push_back(newNode(51));
    root->child[0]->child[1]->child.push_back(newNode(111));
    cout<<"RESULT IS "<<endl;
    printData(root);


}
