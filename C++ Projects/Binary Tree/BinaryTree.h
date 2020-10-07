#pragma once
#include<iostream>
#include<string>

using namespace std;

/** --------------------------------------------------------
* @file    BinaryTree.h
* @author  Noah Funderburgh
* @version 1.0
*
* CS162-01 - Assignment Binary Tree Pt 1
	* Generates Binary Tree of pokemon and prints it inorder
*
* ------------------------------------------------------------ */



struct Node {
	string data;
	Node *left;
	Node* right;
	Node* parent;
	Node* root;
};

class binaryTrees {
public:



	binaryTrees() { Node* root = nullptr; }
	
	void insertPub(string data);
	void delete_dataPub(string data, char letter);
	void inorderPub(int level, char letter);
	void preorderPub(int level,char letter);
	void postorderPub(int level,char letter);
	void copyTreePub();
	//void runEachElement(void(*func)(char, int));

private:
	bool child2Ran = false;
	Node* root;
	Node* copyRoot = NULL;
	/**
	*	Insert a string into the binary Tree
	*
	*   @param root - The root of the binary tree
	* 	@param data - The given string to be inserted in the binary tree
	*   @return Node - returning the root of the tree, set "root = insert Function"
	*/
	Node* insert(Node* root, string data);
	/**
	*	delete_data to delete a specific string in the tree
	*
	*   @param root - the character to be checked
	*   @return true if letter is a vowel (a,e,i,o,u),
	*		 false otherwise
	*/
	Node* delete_data(Node* root, string data);
	/**
*	Prints the binary tree inorder which prints the left child then parent then the right child
*
*   @param root - the root Node of the binary tree
*   @param level - used to tell the level of each node when printed
*/
	void inorder(Node* root, int level);
	/**
*	Prints the binary tree in pre order which prints parent first then
*   its children
*
*   @param root - the root Node of the binary tree
*   @param level - used to tell the level of each node when printed
*/
	void preorder(Node* root, int level);
	/**
*	Prints the binary tree in postorder the left then right children and lastly prints the parent
*
*   @param root - the root Node of the binary tree
*   @param level - used to tell the level of each node when printed
*/
	void postorder(Node* root, int level);
	/**
*	Checks if the binary tree is empty
*
*   @param root - the root Node of the binary tree
*   @return true - if the tree is empty
*		 false otherwise
*/
	bool empty(Node* root);
	/**
*	Creates a new Node then returns that node
*
*   @param data - a string in which a new node is created
*   @return Node - returns the new node that is created
*/
	Node* getNewNode(string data);
	/**
*	Checks to find the mininium value in the tree
*
*   @param Node - insert the root node of the tree
*   @return Node - func returns the lowest Node found in the tree or the minimum
*/
	Node* FindMin(Node* root);
	/**
*	Copys Root to create a deep copy of the binary tree
*
*   @param Node - insert the root node of the tree
*   @return Node - returns a temp node which is stored in CopyRoot
*/
	Node* copyTree(Node* Root);
};

//----------------------------------------------------------
Node* binaryTrees::insert(Node* root, string data) {
	bool done = false;
	Node* newNode = new Node;

	if (empty(root)) {
		root = getNewNode(data);
		return root;
	}

	else if (data <= root->data) {
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}
	return root;
}
//----------------------------------------------------------
void binaryTrees::insertPub(string data) {
	root = insert(root, data);
}
//----------------------------------------------------------
struct Node* binaryTrees::delete_data(Node* root, string data) {

	if (root == NULL) {
		return root;
	}
	else if (data < root->data) {
		root->left = delete_data(root->left, data);
	}
	else if (data > root->data) {
		root->right = delete_data(root->right, data);
	}
	else {
		// Case 1: No Child;
		if (root->left == NULL && root->right == NULL) {
			if (child2Ran == false)
				cout << endl << "Deleting " << root->data << endl << endl;
			delete root;
			root = NULL;
			return root;
		}
		// Case 2: One Child;
		else if (root->left == NULL) {
			struct Node *temp = root;
			if (child2Ran == false)
				cout << endl << "Deleting " << temp->data << endl << endl;
			root = root->right;

			delete temp;
		}
		else if (root->right == NULL) {
			struct Node *temp = root;
			cout << endl << "Deleting " << temp->data << endl << endl;
			root = root->left;

			delete temp;
		}
		// Case 3: 2 child
		else {
			child2Ran = true;
			cout << endl << "Deleting " << root->data << endl << endl;
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = delete_data(root->right, temp->data);
		}
	}
	return root;
}
//----------------------------------------------------------
void binaryTrees::delete_dataPub(string data, char letter) {
	if (letter == 'r')
		root = delete_data(root, data);
	else if (letter == 'c')
		copyRoot = delete_data(copyRoot,data);
	else {
		cout << endl << "Invalid letter for delete_dataPub function Please pick r for root and c for copyRoot" << endl;
	}
}
//----------------------------------------------------------
void binaryTrees::inorder(Node* root, int level) {
	
	if (root == NULL) {
		return;
	}

	inorder(root->left, level + 1);
	cout << root->data << " (" << level << ") ";

	inorder(root->right, level + 1);

}
//----------------------------------------------------------
void binaryTrees::inorderPub(int level, char letter) {
	if (letter == 'r') {
		inorder(root, level);
	}
	else if (letter == 'c')
		inorder(copyRoot, level);
	else {
		cout << endl << "Invalid letter for inorderPub function Please pick r for root and c for copyRoot" << endl;
	}
	cout << endl;
}
//----------------------------------------------------------
void binaryTrees::preorder(Node* root, int level) {

	if (root == NULL) {
		return;
	}
	cout << root->data << " (" << level << ") ";
	preorder(root->left, level + 1);
	preorder(root->right, level + 1);
}
//----------------------------------------------------------
void binaryTrees::preorderPub(int level, char letter) {
	if (letter == 'r') {
		preorder(root, level);
	}
	else if (letter == 'c')
		preorder(copyRoot, level);
	else {
		cout << endl << "Invalid letter for preorderPub function Please pick r for root and c for copyRoot" << endl;
	}
	cout << endl;
}
//----------------------------------------------------------
void binaryTrees::postorder(Node* root, int level) {

	if (root == NULL) {
		return;
	}

	postorder(root->left, level + 1);
	postorder(root->right, level + 1);
	cout << root->data << " (" << level << ") ";
}
//----------------------------------------------------------
void binaryTrees::postorderPub(int level,char letter) {
	if (letter == 'r') {
		postorder(root, level);
	}
	else if (letter == 'c')
		postorder(copyRoot, level);
	else {
		cout << endl << "Invalid letter for inorderPub function Please pick r for root and c for copyRoot" << endl;
	}
	cout << endl;
}
//----------------------------------------------------------
bool binaryTrees::empty(Node* root) {
	if (root == NULL) {
		return true;
	}
	else
		return false;
}
//----------------------------------------------------------
Node* binaryTrees::getNewNode(string data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
//----------------------------------------------------------
Node* binaryTrees::FindMin(Node* root)
{
	while (root->left != NULL) root = root->left;
	return root;
}
//----------------------------------------------------------
Node* binaryTrees::copyTree(Node* Root) {
	if (Root == NULL) {
		return Root;
	}
	Node* temp = new Node();
	temp->data = Root->data;
	temp->left = copyTree(Root->left);
	temp->right = copyTree(Root->right);
	return temp;
}
//----------------------------------------------------------
void binaryTrees::copyTreePub() {
	copyRoot = copyTree(root);
}
