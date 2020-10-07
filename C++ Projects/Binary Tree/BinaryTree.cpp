#include"BinaryTree.h"



int main() {

	cout << "CS260, A5 - Binary Trees" << endl;
	cout << "Author : Noah Funderburgh" << endl << endl;

	binaryTrees T;
	

	Node* root = NULL;
	Node* cloneRoot = NULL;
	
	

	T.insertPub( "Jynx");
	T.insertPub( "Charmander");
	T.insertPub( "Snorlax");
	T.insertPub( "Diglett");
	T.insertPub( "Kakuna");
	T.insertPub( "Meowth");
	T.insertPub( "Pikachu");
	T.insertPub( "Blastoise");
	T.insertPub( "Squirtle");
	T.insertPub( "Ivysaur");
	T.insertPub( "Bulbasaur");
	T.insertPub( "Abra");

	T.copyTreePub();
	T.inorderPub(0, 'c');
	T.delete_dataPub("Squirtle", 'c');
	T.inorderPub(0, 'c');


	T.inorderPub(0, 'r');
	T.delete_dataPub( "Squirtle", 'r');
	T.inorderPub(0 , 'r');
	T.delete_dataPub("Meowth", 'r');
	T.inorderPub(0, 'r');
	T.delete_dataPub( "Blastoise", 'r');
	T.inorderPub(0,'r');
	T.delete_dataPub( "Jynx", 'r');
	T.inorderPub( 0, 'r');

}