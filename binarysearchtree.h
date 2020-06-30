#include <iostream>
#include <stdlib.h>
#include "BST.h"
#include "queue.h"
#include "Que.h"
using namespace std;
int n;
string a;

template<class T>
class BST
{	public:
    queue<T> q;
           BST() {  root = 0;
            f=0;
         l=0;
         c=0; }
		~BST() { clear();}
		void clear()
       {clear(root);} //Delete all nodes of a tree
		bool isEmpty( ) const { return root == 0; }	//checks tree is empty or not
		void preorder() { preorder(root); }	//preorder traversal of tree
		void inorder( ) { inorder(root); } 		//inorder traversal of tree
		void postorder( ) { postorder(root); }	//postorder traveral of tree
		BSTNode<T> * searchbya_n(T a_n) { return searchbya_n(root, a_n); }
        BSTNode<T> * searchbyna(T na) { return searchbyna(root, na); }
        BSTNode<T> * searchbyt(T t) { return searchbyt(root, t); }	//search an 						element in tree
	//	void Insert( T na,T a_n, T t,T no, T pr);				//Insert an  element in BST
        void breadthFirst();
         void breadthFirst2();	//delete an element 
       void display();	
        int  no_of_nodes();	 
   BSTNode<T> * buybya_n( T a_n) {return buybya_n(root, a_n);}
   BSTNode<T> * buybyna( T na) {return buybyna(root, na);}
   BSTNode<T> * buybyt( T t) {return buybyt(root, t);}
   void Insert( T na,T a_n, T t,int no, T pr,int i);
   void allqueue();
   					//from BST by copying
	private:
	    
		BSTNode<T> *root;
		void clear(BSTNode<T> *);
		BSTNode<T> * searchbya_n(BSTNode<T> *, T);
		BSTNode<T> * searchbyna(BSTNode<T> *, T);
        BSTNode<T> * searchbyt(BSTNode<T> *, T);
        BSTNode<T> * buybya_n(BSTNode<T> *, T);
        BSTNode<T> * buybyna(BSTNode<T> *, T);
        BSTNode<T> * buybyt(BSTNode<T> *, T);
		void preorder(BSTNode<T> *); 
		void inorder(BSTNode<T> *);
		void postorder(BSTNode<T> *);
		 int  no_of_nodes(BSTNode<T>* );
  
  
int c,l,f;
};   
template<class T>
void  BST<T>:: clear(BSTNode<T>* p)
{
   
    if(p!=0)
    {
   	clear(p->left);
    clear(p->right);
   delete p;
}
else
   cout<<"tree is empty"<<endl;
}   
template<class T>
BSTNode<T>*  BST<T>::searchbya_n(BSTNode<T> *p, T a_n)
{	while(p != 0)
    {
		if(a_n == p->author_name)
		{ cout<<"search successfully"<<endl;
		cout<<endl;
		cout<<"id="<<p->id<<endl;
	    cout<<"book name is="<<p->name<<endl;
		cout<<"author name is="<<p->author_name<<endl;
        cout<<"book type is="<<p->type<<endl;
        cout<<"no of copies of this book are="<<p->no_of_copy<<endl;
        cout<<"price of this book is="<<p->price<<endl;
        cout<<endl;
			return p;
			}			
		else if(a_n < p->author_name)
			p = p->left;
		else
			p = p->right;
    }
    cout<<"not found"<<endl;		
	return 0;
}
template<class T>
BSTNode<T>*  BST<T>::searchbyna(BSTNode<T> *p, T na)
{	while(p != 0)
    {
		if(na == p->name)
		{ cout<<"search successfully"<<endl;
		cout<<endl;
			cout<<"id="<<p->id<<endl;
	    cout<<"book name is="<<p->name<<endl;
		cout<<"author name is="<<p->author_name<<endl;
        cout<<"book type is="<<p->type<<endl;
        cout<<"no of copies of this book are="<<p->no_of_copy<<endl;
        cout<<"price of this book is="<<p->price<<endl;
        cout<<endl;
			return p;
			}			
		else if(na < p->name)
			p = p->left;
		else
			p = p->right;
    }
    cout<<"not found"<<endl;		
	return 0;
}
template<class T>
BSTNode<T>*  BST<T>::searchbyt(BSTNode<T> *p, T t)
{	while(p != 0)
    {
		if(t == p->type)
		{ cout<<"search successfully"<<endl;
		cout<<endl;
			cout<<"id="<<p->id<<endl;
	    cout<<"book name is="<<p->name<<endl;
		cout<<"author name is="<<p->author_name<<endl;
        cout<<"book type is="<<p->type<<endl;
        cout<<"no of copies of this book are="<<p->no_of_copy<<endl;
        cout<<"price of this book is="<<p->price<<endl;
        cout<<endl;
			return p;
			}			
		else if(t < p->type)
			p = p->left;
		else
			p = p->right;
    }
    cout<<"not found"<<endl;		
	return 0;
}



 
template<class T>
void BST<T>::Insert( T na,T a_n, T t,int no, T pr, int i)
{	BSTNode<T> *p = root, *prev = 0;
	while(p != 0) //Find a place for inserting new node
	{	prev = p;
		if(p -> name < na)	p = p->right;
		else	p = p->left;
	}
	if(root == 0)	//tree is empty
		{
      root = new BSTNode<T>(na,a_n,t,no,pr,i);
		
}		// || prev->author_name <a_n || prev->type <t || prev->no_of_copy <no || prev->price <pr
	else if (prev -> name < na)	
 {
     prev->right = new BSTNode<T>(na,a_n,t,no,pr,i);
     
 }    
	else		{
     prev->left = new BSTNode<T>(na,a_n,t,no,pr,i);
     
 }    
}
template<class T>
void BST<T>::preorder(BSTNode<T> *p)
{
	if(p != 0)
	{ 
		cout<<"id="<<p->id<<endl;
	    cout<<"book name is="<<p->name<<endl;
		cout<<"author name is="<<p->author_name<<endl;
        cout<<"book type is="<<p->type<<endl;
        cout<<"no of copies of this book are="<<p->no_of_copy<<endl;
        cout<<"price of this book is="<<p->price<<endl;
        cout<<endl;
           
         
		preorder(p->left);
		preorder(p->right);
}}
template<class T>
void BST<T>::inorder(BSTNode<T> *p)
{
	if(p != 0)
	{
		inorder(p->left);
		cout<<"id="<<p->id<<endl;
	    cout<<"book name is="<<p->name<<endl;
		cout<<"author name is="<<p->author_name<<endl;
        cout<<"book type is="<<p->type<<endl;
        cout<<"no of copies of this book are="<<p->no_of_copy<<endl;
        cout<<"price of this book is="<<p->price<<endl;
           
         
		inorder(p->right);
	}
}
template<class T>
void BST<T>::postorder(BSTNode<T> *p)
{
	if(p != 0)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<"id="<<p->id<<endl;
	    cout<<"book name is="<<p->name<<endl;
		cout<<"author name is="<<p->author_name<<endl;
        cout<<"book type is="<<p->type<<endl;
        cout<<"no of copies of this book are="<<p->no_of_copy<<endl;
        cout<<"price of this book is="<<p->price<<endl;
           
         
	}
}
template<class T> 
void BST<T> :: breadthFirst()
{ ArrayQueue<BSTNode<T>*> q;
    ofstream outfile("D:\\boks.txt");
	BSTNode<T> *p = root;
	if(p != 0)
	{	q.enqueue(p);
		while(!q.isEmpty())
		{	//count++
            p = q.dequeue();
            outfile<<p->id<<" "<<p->no_of_copy<<endl;
             outfile<<p->name<<endl;
               outfile<<p->author_name<<endl;
                   outfile<<p->type<<endl;
                   
                   outfile<<p->price<<endl;
	           
         
			if(p-> left != 0)		q.enqueue(p->left);
			if(p-> right != 0)		q.enqueue(p->right);
		}
	}
}

template<class T> 
void BST<T> :: breadthFirst2()
{ 
    ifstream infile("D:\\boks.txt");
	int no,i;
	string na,a_n,t,pr;
	infile>>i>>no;
	 infile.ignore();
	 infile>>na;         
	 infile>>a_n;
	 infile>>t;
	 infile>>pr; 
	while(!infile.eof())
	 {
		 
		//add in tree
		BSTNode<T> *p = root, *prev = 0;
		while(p != 0) //Find a place for inserting new node
		{	prev = p;
			if(p -> name < na)	p = p->right;
			else	p = p->left;
		}
		if(root == 0)	//tree is empty
		{
		  root = new BSTNode<T>(na,a_n,t,no,pr,i);	
		}		
		else if (prev -> name < na)	
		 {
			 prev->right = new BSTNode<T>(na,a_n,t,no,pr,i);
		     
		 }    
		else
		{
		 prev->left = new BSTNode<T>(na,a_n,t,no,pr,i);    
		}

		//read next record
	 infile>>i>>no;
	 infile.ignore();
	 infile>>na;         
	 infile>>a_n;
	 infile>>t;
	 infile>>pr; 
	 }//end of while
}

template<class T>
void BST<T>::display()
{
    preorder();
}

  template<class T>     
  int BST<T>:: no_of_nodes()
  {
  return  no_of_nodes(root);
  } 
   template<class T>
   int  BST<T>::no_of_nodes(BSTNode<T>* p)
   {
   if(p!=0)
   {
   c++;
   if(p->left!=0)
   no_of_nodes(p->left);
   if(p->right!=0)
   no_of_nodes(p->right);
  }
  cout<<"no of nodes are in tree="<<c<<endl;
  return c;
  }
template<class T> 
BSTNode<T> * BST<T> :: buybya_n(BSTNode<T> *p, T a_n)
{
 while(p != 0)
    {
    if(a_n == p->author_name)
		{
      if(p->no_of_copy!=0) 
      {
          p->no_of_copy=p->no_of_copy-1;
		cout<<"your remaining no of copies of this book are=";
		cout<<p->no_of_copy<<endl;
			return p;
        }
    else
    { 
    cout<<"there is no more no of copies of this book"<<endl;
    cout<<"enter the name of coustomer"<<endl;
    getline(cin,a);
    
    q.addToTail(p->name,a);
}    
}    
     else if(a_n < p->author_name)
		{	p = p->left;
}		
		else
			p = p->right;
    }
 
    cout<<"not found"<<endl;		
	return 0;	
}


  template<class T> 
BSTNode<T> * BST<T> :: buybyna(BSTNode<T> *p, T na)
{
 while(p != 0)
    {
		if(na == p->name)
		{
      if(p->no_of_copy!=0) 
      {
          p->no_of_copy=p->no_of_copy-1;
		cout<<"your remaining no of copies of this book are=";
		cout<<p->no_of_copy<<endl;
			return p;
        }
    else
    { 
    cout<<"there is no more no of copies of this book"<<endl;
    cout<<"enter the name of coustomer"<<endl;
    getline(cin,a);
    
    q.addToTail(p->name,a);
}    
}    
     else if(na < p->name)
			p = p->left;
		else
			p = p->right;
    }
    
    cout<<"not found"<<endl;		
	return 0;	
}

template<class T> 
BSTNode<T> * BST<T> :: buybyt(BSTNode<T> *p, T t)
{
 while(p != 0)
    {
		if(t == p->type)
		{;
      if(p->no_of_copy!=0) 
      {p->no_of_copy=(p->no_of_copy)-1;
		cout<<"your remaining no of copies of this book are=";
		cout<<p->no_of_copy<<endl;
			return p;
}			
	else
	{cout<<"there is no more book of this type"<<endl;
    cout<<"enter the name of coutomer"<<endl;
    getline(cin,a);
    
    q.addToTail(p->name,a);
    }
}       
						
		else if(t < p->type)
			p = p->left;
		else
			p = p->right;
    }
    
    cout<<"not found"<<endl;		
	return 0;	
}
template<class T> 
void BST<T> :: allqueue()
{  
    while(!isEmpty())
    {
    q.deleteFromHead();
    /*cout<<"id="<<p->id<<endl;
	    cout<<"book name is="<<p->name<<endl;
		cout<<"author name is="<<p->author_name<<endl;
        cout<<"book type is="<<p->type<<endl;
        cout<<"no of copies of this book are="<<p->no_of_copy<<endl;
        cout<<"price of this book is="<<p->price<<endl;
        cout<<"======================"<<endl;
        cout<<"the name of persons for this book are=";
        cout<<a<<endl;
        cout<<endl;
      */     
       }
   }        
                                                  
