#include <iostream>
#include <stdlib.h>

using namespace std;
template<class T, int size = 100>
class ArrayQueue {
	public:
		ArrayQueue() {  InRef = OutRef = -1;  }
	    	void enqueue(T);
	   	 T dequeue();
         	bool isFull() {   return OutRef == 0 && InRef == size-1 || 				OutRef == InRef + 1;  }
     	 bool isEmpty() {   return OutRef == -1;     }
	private:
		int InRef, OutRef;
		T storage[size];
};	   
 template<class T, int size >
 void ArrayQueue<T, size> :: enqueue(T el)
 {	if(!isFull())
		if(InRef == size-1 || InRef ==-1) {
			storage[0] = el;
			InRef = 0;
			if(OutRef == -1)
				OutRef = 0;
		}
		else	storage[++InRef] = el;
	else
		cout << "Full queue. \n";
}
 template<class T, int size >
T ArrayQueue<T, size> :: dequeue()
 {	T tmp;
	if(!isEmpty())
	{
		tmp = storage[OutRef];
		if(InRef == OutRef)
			InRef = OutRef =-1;
		else if (OutRef==size-1)
			OutRef = 0;
		else	OutRef++;
		return tmp;
	}
	else
		cout<<"queue is empty";
}



