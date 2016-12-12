#include <iostream>
#include <string>
#include <list>
#include <iostream>
#include <fstream>
using namespace std;


class node

{
public:
	string key_value;
	node * left;
	node * right;
};

class btree

{

public:

	node * root;
	btree()
	{
		root = NULL;
	}
	~btree()
	{
		destroy_tree();
	}

private:
    
	void destroy_tree()
	{
		destroy_tree(root);
	}
	void destroy_tree(node *leaf)
	{
		if (leaf != NULL)
		{
			destroy_tree(leaf->left);
			destroy_tree(leaf->right);
			delete leaf;
		}
	}
	
	
	//void insert(string key, node *leaf)
	//{
	//	if (key < leaf->key_value)
	//	{
	//		if (leaf->left != NULL)
	//			insert(key, leaf->left);
	//		else
	//		{
	//			leaf->left = new node;
	//			leaf->left->key_value = key;
	//			leaf->left->left = NULL;    //Sets the left child of the child node to null
	//			leaf->left->right = NULL;   //Sets the right child of the child node to null
	//		}
	//	}
	//	else if (key >= leaf->key_value)
	//	{
	//		if (leaf->right != NULL)
	//			insert(key, leaf->right);
	//		else
	//		{
	//			leaf->right = new node;
	//			leaf->right->key_value = key;
	//			leaf->right->left = NULL;  //Sets the left child of the child node to null
	//			leaf->right->right = NULL; //Sets the right child of the child node to null
	//		}
	//	}
	//}



};







string getItem(int index, list<string> l)
{
	list<string> ::iterator it;
	int i = 0;
	for (it = l.begin();it != l.end();it++)
	{
		if(index==i)
		{
			return *it ;
		}
		else i++;
		
	}
	return " ";
}



void error(string s) {
	cout << "Error in " + s << endl;
}

void match(string t, list<string> tokens)
{
	if (tokens.front() == t)
	{
		tokens.pop_front;
	}
	else error("In match fn");
	
}

//
//btree stmt_seqence()
//{
//	statement();
//	while (token == ";")
//	{
//		 
//
//	}
//
//}
//btree statement()
//{}

bool isDigit(string x)
{
	char num[10] = {'0','1','2','3','4','5','6','7','8','9'};
	for (int i = 0;i < 10;i++)
	{
		if (num[i] == x[0])
			return true;
		else
			return false;

	}
}

btree factor(list<string> tokens)
{
	btree temp;
	if ( tokens.front() == "(")
	{

		match("(", tokens);
		temp = exp();
		match(")",tokens);
	}
	else if (isDigit(tokens.front()))
	{
		temp.root->key_value = tokens.front();
	}
	else
	{
		error("in factor fn");
	}
	return temp;

}

btree exp() { btree e;return e; }




void main()
{
	list<string> tokenValue;
	list<string> tokenType;

	string line;
	ifstream myfile("input.txt");
	int flag = 0;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if(line=="type")
			{
				flag = 1;
			}
			if(flag == 0)
			{
				tokenValue.push_back(line);
			
			}
			else if(flag == 1 && line != "type")
			{
				tokenType.push_back(line);
			}
		}
		myfile.close();
	}
	else cout << "Unable to open file"<<endl;

	

	for (int i = 0;i < tokenType.size()-1;i++)
		{
			cout << getItem(i, tokenValue) << "-------------> " << getItem(i, tokenType)<<endl;
		}

	btree t1 ;
	//t1.root->left->key_value = "hye";
	

	






	system("pause");

}