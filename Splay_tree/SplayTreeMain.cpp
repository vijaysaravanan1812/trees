#include<iostream>
#include "SplayTreeDefinitions.cpp"

using namespace std;

int main()
{
    Splay<int> a;

	a.insert(4);
	a.insert(36);
	a.insert(63);
	a.insert(68);
	a.display();
    return 0;
}
    
 

