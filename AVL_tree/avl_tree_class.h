//program to implement AVL Tree

#include<iostream>

using namespace std;

template <typename T>
class avl
{
private:
    //In AVL tree,  a node contain Two pointers, 
    //variable to store height of each node, 
    //variable for storing data, 
    // constructor for initializing values
    struct node
    {
        T data; node *left,*right; int height;
        node (const T &element, node *left_node, node *right_node, int height_of_node)//:data(element),left(left_node),right(right_node),height(height_of_node)
        {
              data = element; height = height_of_node;
              left = left_node; right = right_node;
        }
    };
    node *root;
    void print( node *& temp);                     // This function called by display function
    void insert(const T &element, node *&temp); // This function called by display function
    void remove(const T &element, node *&temp); //This function called by display function
    int  height(node *temp);
    int max(int a,int b);
    void single_rotate_left(node *& k2);    
    void single_rotate_right(node *& k2);
    void double_rotate_left(node *& k3);
    void double_rotate_right(node *& k3);
    void balance(node *& t);
    node *find_min(node *temp) const
    {
        if (temp == NULL)
            return NULL; 
        else if (temp -> left == NULL)
        {
            return temp;
        }
        else
            return find_min(temp->left);
    }

public:
    avl()
    {
        root = NULL;
    }
        void display();                             // This function called by user  
        void insert(const T &element);                // This function called by user
        void remove(const T &element);                // This function called by user
};
