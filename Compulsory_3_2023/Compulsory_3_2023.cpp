// Compulsory_3_2023.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> iPair;
#define INF 0x3f3f3f3f

class Node
{
	public:

	int data;
    Node* parent;
    vector<Node*> child;
    
};

Node* CreateNode(int data, Node* Parentnode)
{
    Node* newnode = new Node();
    newnode->data = data;
    newnode->parent = Parentnode;
    if (Parentnode != nullptr)
    {
        Parentnode->child.push_back(newnode);
        
    }
    return newnode;
}
void TreeTraversal(Node* root)
{
    if (root == nullptr)
        return ;

    queue<Node*> Tree;
    Tree.push(root);
    while (!Tree.empty())
    {
        int i = Tree.size();
       
        while (i > 0)
        {
                Node* k = Tree.front();
        		cout << "parent is " << k->parent << "\n";
                cout << "weight is " << k->data << "\n";

                Tree.pop();
                for (int o = 0; o < k->child.size(); o++)
                {
                    Tree.push(k->child[o]);
                    

                }
                cout << endl;
                i--;

        }
       
    }
   


}
int Treesize(Node* tree)
{
    if (tree == nullptr || tree->child.size() < 1)
        return 0;

    int size = 1;
    if (!tree->child.empty()) {
        for (Node* Tree : tree->child)
        {
            size += Treesize(Tree);
        }
    }
     return size;
     
}
int TreeDepth(Node* root)
{
    if (root == nullptr)
        return 0;

    int Depth;
    root->parent;
    Depth = 1;
        while(root->parent != nullptr)
        {
            root = root->parent;
            Depth++;

        }
        return Depth;

}
bool IsLeaf(Node* node)
{
    return node->child.empty();

}
void CheckifLeaf(Node* tree)
{
    if (tree == nullptr)
        return;
    if(IsLeaf(tree))
    {
        cout << "the node" << " "<<tree << " "<< "is a leaf\n";
    }
    for(Node* Tree : tree->child)
    {

        CheckifLeaf(Tree);
    }

}
Node* GetRoot(Node* tree)
{
	while(tree->parent != nullptr)
	{
        tree = tree->parent;

	}
    return tree;
}
void CheckifRoot(Node*tree)
{
     if (tree->parent != nullptr)
     {
         cout << "Node is not Root\n";
         return;
     }
		 cout << "Node is Root\n";
         
        

}
void Isempty(Node* tree)
{
    if (tree == nullptr)
        return;


}
Node* GetParent(Node* tree)
{
    if (tree->parent != nullptr) {

    	tree->parent;
        
    }
	return tree->parent;
   

}
void DeleteNode(Node* tree)
{
    if (tree == nullptr)
        return;
    if (tree->parent != nullptr)
    {
        tree->parent->child.clear();
    }
    for(Node*Tree : tree->child)
    {
        DeleteNode(Tree);
    }
    delete tree;
   
}

class Graph
{
public:
   list<int>* Adjlist;
    int size;
    int data;
    Graph(int size)
    {
        this->size = size;
        Adjlist = new list<int>[size];
    }

void AddEdge(int a, int b)
{
    Adjlist[a].push_back(b);
   

}
void print() {
    for (int i = 0; i < size; i++) {
        cout << i << " is connected to-->";
        for (auto it : Adjlist[i]) {
            cout << it  << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void DepthRecursive(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int neighbor : Adjlist[v]) {
        if (!visited[neighbor]) {
            DepthRecursive(neighbor, visited);
        }
    }
}

// Function to start the depth-first traversal from all unvisited vertices
void Depth() {
    vector<bool> visited(size, false);

    for (int v = 0; v < size; ++v) {
        if (!visited[v]) {
            cout << "Connected Component: ";
            DepthRecursive(v, visited);
            cout << endl;
        }
    }
}
};

	




int main()
{
    Graph Test(5);
    Test.AddEdge(0, 1);
    Test.AddEdge(1, 2);
    Test.AddEdge(2, 3);
    Test.AddEdge(3, 4);
    Test.AddEdge(4, 0);
    Test.print();
    Test.Depth();
  

 //   Node* Root = CreateNode(3, nullptr);
 //   Node* child1 = CreateNode(5, Root);
 //   Node* child2 = CreateNode(6, child1);
 //   Node* child3 = CreateNode(1, child1);
 //   //
 //   CheckifRoot(Root);
 //   //
	////DeleteNode(child1);
 //   //
	//Node* parent =  GetParent(Root);
	//cout << "Parent of node is " << parent << "\n";
 //   //
 //   int size = Treesize(Root);
 //   cout << "tree size is->" << size << "\n";
 //   //
 //   int depth = TreeDepth(Root);
 //   cout << "Tree depth is ->" << depth << "\n";
 //   //
 //   CheckifLeaf(Root);
 //   //
 //   Node* TreeRoot = GetRoot(Root);
 //   cout << "the node" << " " << TreeRoot << " " << "is Root\n";
 //  //
	//TreeTraversal(Root);
    
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
