#include<iostream>
using namespace std;
#include "avl_tree.cpp"

int main()
{
    avl<int>a;
    
    printf("Inserting elements\n");
    for (int i = 0; i < 10000000; i++)
    {
           a.insert(i);

    }
    
    a.display();
/*
    printf("removing element 30\n");
    a.remove(30);

    printf("removing element 24\n");
    a.remove(24);

    printf("Display after removing\n");
    a.display();

*/
    return 0;
}
    
