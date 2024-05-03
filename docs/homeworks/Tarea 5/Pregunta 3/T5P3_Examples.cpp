
//Ejemplo de la implementación de una clase tipo lista

/Folder.h
#pragma once
#include <string>
using namespace std;

class Node;
class Folder
{
private:
	Node *root;

public:

	Folder();
	~Folder();//Destructor
	void addNode (string&,int&,int&,double&);
	void traverseList();
};


//Ejemplo de la implementación de una clase tipo lista


//Folder.cpp
#include "Folder.h"
#include "Node.h"

Folder::Folder()
{
//allocate memory for root
	root = new Node();
	root = NULL;
}

Folder::~Folder()
{
//free memory once Folder class has gone out of scope
	delete root;
}

void Folder::addNode(string&name,int&age,int&ID,double&GPA)
{

	Node*new_student = new Node (name,age,ID,GPA);//create a new node

	if(root == NULL)//empty link list
	{
		
		root = new_student;
		return;
	}
	else{
		Node*temp_node=root;//declares a Node data type to start at root
node
		while(temp_node->next!= NULL)//traverses to the end of the link list
		{
			temp_node=temp_node->next;
		}
			temp_node->next=new_student;
	}
}

void Folder::traverseList()
{
	Node*temp_node=root;
	while(temp_node!= NULL)
	{
		cout<<temp_node->name<<endl;
		temp_node=temp_node->next;
	}
}


//Ejemplo de la implementación de una clase tipo lista

//main.cpp
#include<iostream>
//must include header files
#include "Folder.h"
#include "Node.h"


using namespace std;


int main()
{
//declare variables
	Folder rec;
	string name;
	int age,ID;
	double GPA;


	while (true)
	{
		//input name,age, ID, and GPA and then send these variables to the addNode function
		cout<<"Enter name (or quit to exit)"<<endl;
		cin>>name;
		if (name == "quit") break;
		cout<<"Enter age"<<endl;
		cin>>age;
		cout<<"Enter ID number"<<endl;
		cin>>ID;
		cout<<"Enter GPA"<<endl;
		cin>>GPA;
		rec.addNode(name,age,ID,GPA);
}
	rec.traverseList();//Print out the linked list members

return 0;
}


