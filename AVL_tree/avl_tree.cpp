//program to define the functions that are declare in class

#include<iostream>
using namespace std;
#include"avl_tree_class.h"


template <typename T>
int avl<T>::height(node *temp)
{
    return (temp == NULL)?-1:temp->height;
}

template <typename T>
void avl<T>::insert(const T &element)
{
    insert(element, root);
}

template<typename T>
void avl<T>::insert(const T &element, node *&temp)
{
    if (temp == NULL)
    {
       // cout<<"New node created element "<<element<<"\n";        
        temp = new node(element ,NULL,NULL,-1);
    }
    else if (element < temp->data)
    {
        insert(element , temp->left);
        if (height(temp->left) - height(temp->right) == 2 )
        {
            if (element < temp->left->data)
            {
         //       printf("straight pattern left\n");
                single_rotate_left(temp);
            }
            else 
            {
           //       printf("Dog leg pattern left\n");
                double_rotate_left(temp);
            }
        }
        
    }
    else if (element > temp ->data)
    {
        insert(element , temp->right);
        if ((height(temp -> right) - height(temp ->left)) == 2)
        {
            if (element > temp->right->data)
            {
             //    printf("straight pattern left\n");
                single_rotate_right(temp);
            }
            else
            {
             //   printf("Dog leg pattern right\n");
                double_rotate_right(temp);
            }
        }
        
    }
    temp->height = max(height(temp->left), height(temp->right)) + 1;
}

template <typename T>
void avl<T>::display()
{
    print(root);
    printf("\n");
    
}

template <typename T>
void avl<T>::print(node *& temp)
{
    if(temp != NULL)
    {
        cout<<temp->data<<"\t";
        print(temp->left);
        print(temp->right);
    }
}

template <typename T> 
void avl<T>::single_rotate_left(node *& k2)
{
    node *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left),k2->height) + 1;
    //cout<<"k2 "<<k2->data<<"\t"<<"k1 "<<k1->data<<"\n"<<"K2 height "<<k2->height<<"\n"<<"k1 height "<<k1->height<<"\n"; 
    k2 = k1; 
    //cout<<"k2 "<<k2->data<<"\t"<<"k1 "<<k1->data<<"\n"<<"K2 height "<<k2->height<<"\n"<<"k1 height "<<k1->height<<"\n";
}

template <typename T>
void avl<T>::single_rotate_right(node *& k2)
{
    node *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left),k2->height) + 1; 
    //cout<<"k2 "<<k2->data<<"\t"<<"k1 "<<k1->data<<"\n"<<"K2 height "<<k2->height<<"\n"<<"k1 height "<<k1->height<<"\n"; 
    k2 = k1; 
    //cout<<"k2 "<<k2->data<<"\t"<<"k1 "<<k1->data<<"\n"<<"K2 height "<<k2->height<<"\n"<<"k1 height "<<k1->height<<"\n";
}

template <typename T>
void avl<T>::double_rotate_left(node *& k3)
{
    single_rotate_right(k3->left);
    single_rotate_left(k3);
}

template <typename T>
void avl<T>::double_rotate_right(node *& k3)
{
  
    single_rotate_left(k3->right);
    single_rotate_right(k3);
}

template <typename T>
int avl<T>::max(int a, int b)
{
    if(a>=b)
        return a;
    else 
        return b;
}

template <typename T>
void avl<T>::remove(const T &element)
{
    remove(element,root);
}

template <typename T>
void avl<T>::remove(const T &element, node *&temp)
{
    if (temp == NULL)
    {
        printf("No element found\n");
        return ;
    }
    if(element < temp->data)
    {
        remove(element ,temp->left);
    }
    else if (element > temp->data)
    {
        remove(element , temp->right);
    }
    else  if (temp -> right == NULL && temp -> left != NULL)
    {
        temp -> data = find_min(temp -> right)->data;
        remove(temp -> data, temp->right);
    }
    else
    {
        node *oldNode = temp;
        temp = ( temp->left != NULL ) ? temp->left : temp->right;
        delete oldNode;
    }
    
    balance(temp);
    
}

template <typename T>
void avl<T>::balance( node *& t )
{
    if(t == NULL )
        return;
    if( height( t->left ) - height( t->right ) ==2 )
            if( height( t->left->left ) >= height( t->left->right ) )
                	single_rotate_left( t );
           	else
               	    double_rotate_left( t );
    else if( height( t->right ) - height( t->left ) ==2 )
            if( height( t->right->right ) >= height( t->right->left ) )
    				single_rotate_right( t );
            else
                	double_rotate_right( t );
                
   	t->height = max( height( t->left ), height( t->right ) ) + 1;
}