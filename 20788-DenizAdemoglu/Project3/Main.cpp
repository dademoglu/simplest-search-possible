#include "LinkedList.h"
#include <string>
#include <iostream>
#include <fstream>
#include <utility> 
#include <sstream>
#include <stdio.h>
#include <ctype.h>
using namespace std;


class Data
{
public:

	Data dumbData(string key){  //this dumb data is created to find if the keyword exist in other elements of lis<Data>
		Data data;
		data.keyword = key;
		return data;
	}

	Data addNewData(string key, int article){  //creating new data for the list
		Data newData;	
		newData.keyword = key;
		newData.pages.insertBegin(article);

		return newData;
	}

	void addNewPage(int & article){         //since pages is a different list, it's existence checked and if it doesn't exist it's added to the list

		if(!pages.search(article))
			pages.insertBegin(article);
	}


	bool operator==( const Data & rhs ) const {  //== is overloaded because I just want to see that if keyword of both data are equal
		if( this->keyword == rhs.keyword)
		{
			return true;
		}
		return false;
	}

	bool  operator!=( const Data & rhs ){ //!= is overloaded because I just want to see that if keyword of both data are not equal
		if( this->keyword != rhs.keyword )
		{
			return true;
		}
		return false;
	}

	bool  operator<( const Data & rhs ){ //!= is overloaded because I just want to see that if keyword of both data are not equal
		if( this->keyword < rhs.keyword )
		{
			return true;
		}
		return false;
	}
	bool  operator>( const Data & rhs ){ //!= is overloaded because I just want to see that if keyword of both data are not equal
		if( this->keyword > rhs.keyword )
		{
			return true;
		}
		return false;
	}

	string returnWord(){
		return keyword;
	}
	LinkedList<int> & returnPages(Data  &data){
		return data.pages;
	}

	string keyword;
	LinkedList<int> pages;

};
//*****************// CLASS IMPLENTATION ENDS HERE

//'kind' of overload for header returnPos, overloaded for int
int returnPosition(int pos, LinkedList<int> & check){ //Insert a value at the given position
	int counter = 0; 
	Node<int> *s, *ptr;
	int i;
	s = check.header;
	while (s != NULL)
	{
		s = s->next;
		counter++;
	}
	if (pos == 1)
	{
		return check.header->info;
	}
	else if (pos > 1  && pos <= counter)
	{
		s = check.header;
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
	return NULL;
}
//in order to compare find exact string, lowercased every database item and input values
string lowercase(string temp){

	char * str = new char [temp.length()+1];
	strcpy_s (str, temp.length()+1, temp.c_str());

	int i=0;
	char c;
	while (str[i])
	{
		c = str[i];
		str[i] = tolower(c);
		i++;
	}
	string value(str);
	return value;
}
//finds all the intersections
void intersection(LinkedList<Data> dataset, LinkedList<int>  &intersect){  ///ONE DIFFERENT ITEM IS A PROBLEM
	
	int searchnum, count = 0;
	bool flag = true; //added flag to keep taking inputs  1/5
	Node<int> *pagetemp, *pagetemp2;
	Data tempData, dumbdata;
	LinkedList<int> pageList, intersectlist;
	LinkedList<string> wordlist;
	string num, word;
	while(flag){   //created a loop with the flag 2/5
		cin >> searchnum;
		if(searchnum == 0){
			flag = false;
		}
		else{
			for(int i = 1; i <= searchnum; i++){
				cin >> word;
				wordlist.insertLast(word, wordlist);
				word = lowercase(word); 
				pageList = dataset.searchItem(dumbdata.dumbData(word)).pages;
				pagetemp = pageList.header;
				while (pagetemp != NULL)
				{
					intersect.insertBegin(pagetemp->info);
					pagetemp = pagetemp->next;
				}
			}
			intersect.sort();
			for(int j = 1; j <= intersect.listLength(intersect); j++)
			{
				count = 0;
				pagetemp2 = intersect.header;
				while (pagetemp2 != NULL)
				{
					if(returnPosition(j, intersect) == pagetemp2->info){
						count++;

					}	
					pagetemp2 = pagetemp2->next;
				}
				if(count-- == searchnum){
					if(!intersectlist.search(returnPosition(j, intersect)))
						intersectlist.insertLast(returnPosition(j, intersect), intersectlist);
				}
			}
			intersectlist.sort();	

			int lengthList = intersectlist.listLength(intersectlist);
			if(intersectlist.header == NULL)
			{
				wordlist.display();
				cout << "0" << endl;
			}
			else{
			wordlist.display();
			cout << lengthList;        //added count of articles found 3/5
			cout << " ";
			intersectlist.display();
			}
		}
		cout << endl;
		wordlist.deleteList(wordlist);
		intersectlist.deleteList(intersectlist);	// cleared all lists 4/5
		intersect.deleteList(intersect);
		pageList.deleteList(pageList);
	}

}

//debug check, used for printing database with class data
/*void printList( const LinkedList<Data> & theList )  // Prints database list
{
Node<Data> *temp;
Node<int> *pagetemp;
Data tempData;
LinkedList<int> pageList;
if (theList.header == NULL)
{
cout<<"The List is Empty"<<endl;
return;
}
temp = theList.header;
cout<<"Elements of list are: "<<endl;
while (temp != NULL)
{
tempData = temp->info;
cout<< tempData.returnWord() << endl;
pageList = tempData.returnPages(tempData);
pagetemp = pageList.header;
while (pagetemp != NULL)
{
cout<< pagetemp->info << endl;
pagetemp = pagetemp->next;
}
temp = temp->next;
}
}*/

//database construction function
void addtoList(string key, int articlenum,LinkedList<Data> &trialdata){
	Data tempdata, newdata;
	tempdata = tempdata.dumbData(key);
	if(!trialdata.search(tempdata)){ //if data doesn't exist in database, directly add it
		trialdata.insertBegin(tempdata.addNewData(key, articlenum));
	}
	else if(trialdata.search(tempdata)){
		if(!trialdata.searchItem(tempdata).pages.search(articlenum)){
			trialdata.searchItem(tempdata).pages.insertLast(articlenum,trialdata.searchItem(tempdata).pages);
		}
	}
}

//sorting algorithm for data list
void sortList(LinkedList<Data> list){
	for(int k=1;k < list.listLength(list); k++)
	{


	}
	for(int i=1;i < list.listLength(list); i++)
	{
		Data data = list.returnPos(i);
		data.pages.sort();
	}
}

int main( )
{
	LinkedList<int>  intersect;
	LinkedList<Data> trialdata;
	ifstream input;  
	string s,k, searchset;
	int count = 0;

	string filename = "docdb.txt"; 
	input.open(filename.c_str());

	if (input.fail() )
	{   cout << "could not open file " << filename << endl;
	return 0;
	}

	while(input >> s){
		input >> k;
		s = lowercase(s); //lower database elements
		addtoList(s, stoi(k), trialdata);
	}
	cout << "What are you looking for?" << endl;

	//printList(trialdata);  //debug check
	sortList(trialdata);
	intersection(trialdata, intersect);


	cout << endl;
	return 0;
}

