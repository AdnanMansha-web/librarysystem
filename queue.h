#include <iostream>
#include <stdlib.h>
using namespace std;
template<class T>
class Node {
public:
	T C_name;
	T book_name;
	Node *next;
	Node() {
		next = 0;
	}
	Node(T cn,T bn, Node *n = 0) {
		C_name=cn;
		book_name=bn;
		next = n;
	}
};

template<class T>
class queue{
    private:
        Node<T> *head;
        Node<T> *tail;
    
    public:
        
        queue()
    {head=tail=0;}
    	bool isEmpty() {
	if (head == 0)		//list is empty
		return true;
}		
void addToTail(T bn,T cn)
{	Node<T> *n = new Node<T>(cn,bn, 0);	
if(isEmpty())
head = tail = n;
else			//Insert node at the end of a list
{
tail->next = n;
tail = n;
cout<<"you are adding from tail"<<endl;
   }
}
 

void deleteFromHead()
{	
if(head!=0)	//Non empty list
{
Node<T>* n =head;
if(head==tail)
head=tail=0;
else
head=head->next;
             delete n;
             cout<<"you are deleting from head"<<endl;
}
else cout<<"there is no node"<<endl;
}

};
