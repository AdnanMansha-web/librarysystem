#include <iostream>
#include <stdlib.h>

using namespace std;
template<class T>
class BSTNode
{	public:
    
    
        T name;
	T author_name;
	T type;
	T book_id;
	int no_of_copy;
	T price;
	int id;
     	
		BSTNode *left, *right;
        BSTNode(){ left = right = 0; }
		BSTNode(T na ,T a_n, T t, int no, T pr,int i,  BSTNode *lef = 0, BSTNode *ret = 0) 
 {	
     name=na;
	author_name=a_n;
	type=t;
	
	no_of_copy=no;
	price=pr;
	id=i;
	
		left = lef;
			right = ret;
		}	
};

