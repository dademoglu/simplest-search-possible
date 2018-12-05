#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std; 
#include <iostream>

template<class Object>
class Node   //createing a Node
{
public:
	Object info;
	Node *next;

};

//************Node class ends here*****************//

template<class Object>
class LinkedList
{
public:
	Node<Object> *createNode(Object value)   //Create a node
	{
		Node<Object> *temp;
		temp = new Node<Object>; 
		if (temp == NULL)
		{
			return 0;
		}
		else
		{
			temp->info = value;
			temp->next = NULL;     
			return temp;
		}
	}

	//inserts given value to header position
	void insertBegin(const Object & value){  //Insert a value at the beginning
		Node<Object> *temp, *p;
		temp = createNode(value);
		if (header == NULL)
		{
			header = temp;
			header->next = NULL;          
		} 
		else
		{
			p = header;
			header = temp;
			header->next = p;
		}
		//cout<<"Element Inserted at beginning"<<endl;
	}

	//Insert a value at the given position
	Object returnPos(int pos){ 
		int counter = 0; 
		Node<Object> *s, *ptr;
		int i;
		s = header;
		while (s != NULL)
		{
			s = s->next;
			counter++;
		}
		if (pos == 1)
		{
			return header->info;
		}
		else if (pos > 1  && pos <= counter)
		{
			s = header;
			for (i = 1; i < pos; i++)
			{
				ptr = s;
				s = s->next;
			}
			return s->info;
		}
		else
		{
			//cout<<"Positon out of range"<<endl;
		
		}
			Object null;
			return null;
	}

	 //Insert a value at the last position
	void insertLast(const Object &value, LinkedList<Object>& list){ 

		Node<Object> *temp, *s;
		temp = createNode(value);
		s = list.header;
		if(list.header == NULL){
			list.insertBegin(value);
		}
		else
		{
		while(s->next != NULL)
		{         
			s = s->next;        
		}
		temp->next = NULL;
		s->next = temp;
		////cout<<"Element Inserted at last"<<endl; 
		} 
	} 

	//returns the length of the given list
	int listLength(LinkedList<Object>& list){

		int count = 1;
		Node<Object> *s;
		s = list.header;
	if(list.header != NULL){
		while(s->next != NULL)
		{         
			s = s->next;
			count++;
		}
	}
		return count;  
	} 

	// sort the Node<Object> of linked list
	void sort(){
		Node<Object> *ptr, *s;
		Object value;
		if (header == NULL)
		{
			//cout<<"The List is empty"<<endl;
			return;
		}
		ptr = header;
		while (ptr != NULL)
		{
			for (s = ptr->next;s !=NULL;s = s->next)
			{
				if (ptr->info > s->info)
				{
					value = ptr->info;
					ptr->info = s->info;
					s->info = value;
				}
			}
			ptr = ptr->next;
		}
	}

	//returns true if given object is found
	bool search(Object value){  //search an object 
		int pos = 0;
		bool flag = false;
		if (header == NULL)
		{
			return false;
		}
		Node<Object> *s;
		s = header;
		while (s != NULL)
		{
			pos++;
			if (s->info == value)
			{
				return true;
			}
			s = s->next;
		}
		return false;
	}

	//returns the node given objects --> used to find and update objects in main.cpp
	Object searchItem(const Object & value){  //search an object 
		int pos = 0;
		Object dump;
		bool flag = false;
		if (header == NULL)
		{
			return dump;
		}
		Node<Object> *s;
		s = header;
		while (s != NULL)
		{
			pos++;
			if (s->info == value)
			{
				return s->info;
			}
			s = s->next;
		}
		return dump;
	}

	//prints the list
	void display()
	{
		Node<Object> *temp;
		if (header == NULL)
		{
			//cout<<"No results found."<<endl;
			return;
		}
		temp = header;

		while (temp != NULL)
		{
			cout<<temp->info<<" ";
			temp = temp->next;
		}
		
	}

	//construct
	LinkedList() 
	{
		header = NULL;
	} //initiate

void deleteList(LinkedList<Object>& list) 
{ 
   Node<Object> *current = list.header; 
   Node<Object> *temp;
   while (current != NULL)  
   { 
       temp = current->next; 
       free(current); 
       current = temp; 
   } 
    
   list.header = NULL;
} 


	Node<Object> *header;
};


//************LinkedList ends here*****************//








#endif