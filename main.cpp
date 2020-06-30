#include <iostream>
#include <stdlib.h>
#include "binarysearchtree.h"
#include <fstream>
#include <string>
#include <ctime>

//#include "Queue.h"
using namespace std;

int main()
{ 
    BST<string> obj;
    	system("color 1b");
  		time_t a;  //create variable of time_t
	time(&a); //pass va  
      char op,ch,choice,pas,by,c;
    string b_name,a_name,b_t,aa,bn,bt,q,gh;
       ofstream outfile;
    ifstream infile; 
     
    outfile.open("yashir&ahsan.txt");  
    static int iD; iD=1;
    int n;
   string pri;
   
    char pass[20];
    do{
    cout<<"ENTER THE PASSWORD  :"; 
    cin>>pass; 
    if(strcmp(pass,"ahsan")==0)
    {
    cout<<"                  ||=================================||"<<endl;
    cout<<"                  ||=================================||"<<endl; 
    cout<<"                  || W E L L C O M E   I N   M E N U ||"<<endl;
    cout<<"                  ||=================================||"<<endl;
    cout<<"                  ||=================================||"<<endl;
    cout<<"======================"<<endl;
    cout <<"||"<<ctime(&a)<<"||";
    cout<<"======================"<<endl;
    do{
        cout<<"                                                     "<<endl;
    cout<<"  =================================================="<<endl;
    cout<<"  1- press I for inserting a new book in the system"<<endl;
    cout<<"  2- press S for searching a book"<<endl;
    cout<<"  3- press D for displaying a book"<<endl;
    cout<<"  4- press F for saving data"<<endl;
    cout<<"  5- press L for loading data"<<endl;
    cout<<"  6- press B for buy a book"<<endl;
    cout<<"  7- press Q for printing queue of a book"<<endl;
    cout<<"  8- press R for reading a batch  of a book"<<endl;
    cout<<"  9- press E for exit"<<endl;
    cout<<" ====================================================="<<endl;
    cout<<"please  enter any option=";
    cin>>op;
    
    switch(op)
    { case 'I':
        
        cout<<"book id="<<iD<<endl;
        getline(cin,q);
        cout<<"please enter book name=";
        getline(cin,b_name);
        cout<<endl;
        cout<<"please enter author name=";
        getline(cin,a_name);
        cout<<endl;
        cout<<"please enter book type=";
        getline(cin,b_t);
        cout<<endl;
        cout<<"please enter number of copies=";
        cin>>n;
		cin.clear();
		cin.ignore();
        cout<<endl;
        cout<<"please enter price=";
        getline(cin,pri);
        cout<<endl;
        
    
    obj.Insert(b_name,a_name,b_t,n,pri,iD);
    iD++;
    break;
    case 'L':
    cout<<"READ FROM FILE"<<endl; 
    obj.breadthFirst2();
   /*getline(infile,b_name);
   cout<<b_name<<endl;
   getline(infile,a_name);
   cout<<a_name<<endl;
   getline(infile,b_t);
   cout<<b_t<<endl;
  // getline(infile,n);
   cout<<n<<endl;
   getline(infile,pri);
   cout<<pri<<endl;*/
   break;

case 'F':
  /*cout<<"YOUR FILE HAS BEEN SAVE"<<endl;
  outfile<<b_name<<endl;          
  outfile<<a_name<<endl;
  outfile<<b_t<<endl;
  outfile<<n<<endl;
  outfile<<pri<<endl;
outfile<<"********************************"<<endl;*/
obj.breadthFirst();
cout<<"file saved successfully"<<endl;
break;
    
    case 'S':
        
        cout<<"           Searching options            "<<endl;
        cout<<"||====================================||"<<endl;
        cout<<"||====================================||"<<endl;
        cout<<"|| press 1 for search by author name  ||"<<endl;
        cout<<"|| press 2 for search by book name    ||"<<endl;
        cout<<"|| press 3 for search by book type    ||"<<endl;
        cout<<"||====================================||"<<endl;
        cout<<"select any choice=";
        cin>>choice;
        
        if(choice=='1')
            {  
                getline(cin,q);
                cout<<"enter author name=";
                
                getline(cin,aa);
                cout<<endl;
               obj.searchbya_n(aa); 
           }    
            else if(choice=='2')
               { cout<<"enter book name=";
               getline(cin,q);
                getline(cin,bn);
                obj.searchbyna(bn);
            }    
            else if(choice=='3')
             {   cout<<"enter book type=";
             getline(cin,q);
                getline(cin,bt);
                obj.searchbyt(bt);
            }    
            else
            {cout<<"sorry u enter a wrong choice"<<endl;}
            
        
    
        
        
        break;
        
    case 'D':
        
        obj.display();
    break;
    case 'B':
        cout<<"              buying options            "<<endl;
        cout<<"||====================================||"<<endl;
        cout<<"||====================================||"<<endl;
        cout<<"|| press 1 for buy by author name     ||"<<endl;
        cout<<"|| press 2 for buy by book name       ||"<<endl;
        cout<<"|| press 3 for buy by book type       ||"<<endl;
        cout<<"||====================================||"<<endl;
        cout<<"select any choice=";
        cin>>by;
        if(by=='1')
        {  
                getline(cin,q);
                cout<<"enter author name=";
                cout<<endl;
                getline(cin,aa);
               obj.buybya_n(aa); 
           }    
            else if(by=='2')
               { cout<<"enter book name=";
               getline(cin,q);
                getline(cin,bn);
                obj.buybyna(bn);
            }    
            else if(by=='3')
             {   cout<<"enter book type=";
             getline(cin,q);
                getline(cin,bt);
                obj.buybyt(bt);
            }    
            else
            {cout<<"sorry u enter a wrong choice"<<endl;}
            
        
    
        
        
        break;
       case 'Q':
            cout<<"||=========================||"<<endl;
            cout<<"||         Menu            ||"<<endl;
            cout<<"||=========================||"<<endl;
            cout<<"  press 1 for display all queue of books"<<endl;
            cout<<"  press 2 for display only specific book queue"<<endl;
            cout<<"=================================================="<<endl;
            cout<<"enter choice="<<endl;
            cin>>choice;
            if(choice=='1')
            {
                obj.allqueue();
            
        }
        /*else if(choice=='2')
        {   cout<<endl<<"enter book name=";
        getline(cin,q);
        getline(cin,gh);
            q.dequeuebyb_n(gh);
        } */       
            break;
        case 'E':
            exit (0);
            
        }
cout<<"DO U WANT TO CONTINUE? (y/n)=";
cin>>ch;
}while(ch=='y');
}
else 
 cout<<"Incorect Password"<<endl;  

cout<< "do u want to try again?(y/n)=";
cin>>pas;
}
while(pas=='y');
 
    system("PAUSE");	
  return EXIT_SUCCESS;
}
