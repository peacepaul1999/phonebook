#include <iostream>
#include <fstream>
using namespace std;

class phonebook
{
	struct ListNode
		{
			string number;
			string name;
			string printnumber;
			string printname;
			struct ListNode *next;
		};
	    ListNode *head;
		   
	    public:
	    	phonebook()
			{
				head = nullptr;
			}
	    	void input(string,string);  
	    	void print();
	    	void writefile();
	    	void makefile();
};

void phonebook::input(string num,string n)
{
	ListNode *newNode;
	ListNode *nodePtr;
	
	newNode = new ListNode;
	newNode->number = num;
	newNode->name = n;
	newNode->next = nullptr;
	if(!head)
	{
		head = newNode;
	}
	else 
	{
		nodePtr = head;
		while(nodePtr->next != nullptr)
		nodePtr = nodePtr->next;
		nodePtr->next = newNode;
		writefile();
	}
}

void phonebook::writefile()
{
	ListNode *nodePtr;
	nodePtr = head;
	fstream outFile("phonebook.txt",ios::out);
	while(nodePtr)
	{
		outFile<<nodePtr->number<<"  "<<nodePtr->name<<endl;
		nodePtr = nodePtr->next;
	}
	outFile.close();
}

void phonebook::makefile()
{
	ListNode *nodePtr;
	nodePtr = head;
	
	string line;
	string Num;
	string Name;
	
	fstream inFile("phonebook.txt",ios::in);
	while(inFile>>Num>>Name)
	{
		getline(inFile,line);
	    nodePtr->printnumber=Num;
	    nodePtr->printname=Name;
	    nodePtr = nodePtr->next;
	}
	inFile.close();
} 

void phonebook::print()
{
	ListNode *nodePtr;
	nodePtr = head;
	
	while(nodePtr)
	{
		cout<<nodePtr->number<<"  "<<nodePtr->name<<endl;
		nodePtr = nodePtr->next;
	}
	
}

int main() 
{
	int x;
	string num;
	string n;
	char c1,c2;

    phonebook pb;
    
	fist:
	system("cls");
	cout<<"---------------Program is phone book---------------"<<endl<<endl;
	cout<<"Record new phone number\n\n";
	cout<<"Enter your phone number :"; cin>>num;
	cout<<"Enter your name :"; cin>>n;
		        pb.input(num,n);
				cout<<endl;
				cout<<"i. To write data next \n"
				    <<"j. Show all phone number\n"
				    <<"k. Exit to program\n";
				cout<<"select choice : "; cin>>c1; cout<<endl;    
				switch(c1)
				{
					i:
					case 'i' : goto fist; break;
					case 'j' : goto f; break;
					case 'k' : goto Exit; break;
					default : goto i; break;
				} 
	cout<<"---------------------------------------------------\n";
	cout<<endl;
	f:    
    cout<<"Show all phone number of phone book\n\n";
		        pb.print();
				cout<<endl;
				cout<<"a. Rerum to fist manu\n"
				    <<"b. Makeup file\n"
					<<"c. Exit to program\n";
				cout<<"select choice : "; cin>>c2; cout<<endl;    
				switch(c2)
				{
					k:
					case 'a' : goto fist; break;
					case 'b' : 	pb.makefile(); cout<<"To write flie finish\n" 
					               <<"Good bye"<<endl;
					           break;
					case 'c' : goto Exit; break;
					default : goto k; break;
				} 	
	Exit:		
	return 0;
}
