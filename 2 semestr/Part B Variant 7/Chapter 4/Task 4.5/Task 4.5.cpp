//  Используя объекты класса «Бинарное дерево»,
//  реализовать алгоритм своего варианта задания
//  2.7 «Учебной вычислительной практики».

#include <iostream>
#include "2.7.h"

using namespace std;

template <typename T>
void output_tree(BinaryTree<T>*);

int main()
{
	//make_task_2_7();

	// For check all methods and constructors
	//// Copy constructor
	//	BinaryTree<int> Tree1(5);
	//	cout << "Tree1:\n";
	//	output_tree(Tree1);

	//	BinaryTree<int> Tree2(Tree1);
	//	cout << "Tree2:\n";
	//	output_tree(Tree2);

	//	BinaryTree<int> Tree3 = Tree1;
	//	cout << "Tree3:\n";
	//	output_tree(Tree3);

	//	cout << "Tree1:\n";
	//	output_tree(Tree1);
	////
	//cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	//// Move constructor
	//	BinaryTree<int> Tree4(5);
	//	cout << "Tree4:\n";
	//	output_tree(Tree4);

	//	BinaryTree<int> Tree4_copy(Tree4);
	//	cout << "Tree4 copy:\n";
	//	output_tree(Tree4_copy);

	//	BinaryTree<int> Tree5(move(Tree4));
	//	cout << "Tree5:\n";
	//	output_tree(Tree5);

	//	BinaryTree<int> Tree6 = move(Tree4_copy);
	//	cout << "Tree6:\n";
	//	output_tree(Tree6);

	//	cout << "Tree4:\n";
	//	output_tree(Tree4);

	//	cout << "Tree4 copy:\n";
	//	output_tree(Tree4_copy);
	////
	//cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	//// Check methods
	//	// Удаление элементов
	//		BinaryTree<int> Tree7(10);
	//		cout << "Tree7:\n";
	//		output_tree(Tree7);
	//		
	//		Tree7.pop_element(1);
	//		cout << "Tree7 del 1:\n";
	//		output_tree(Tree7);

	//		Tree7.pop_element(11);
	//		cout << "Tree7 del 11:\n";
	//		output_tree(Tree7);

	//		Tree7.pop_element(5);
	//		cout << "Tree7 del 5:\n";
	//		output_tree(Tree7);

	//		Tree7.pop_all_elements(Tree7.get_root());
	//		cout << "Tree7 del all:\n";
	//		output_tree(Tree7);
	//	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	//	//Вставка
	//		BinaryTree<int> Tree8(5);
	//		cout << "Tree8:\n";
	//		output_tree(Tree8);
	//		
	//		Tree8.insert_element(13);
	//		cout << "Tree8 ins 17:\n";
	//		output_tree(Tree8);

	//		Tree8.insert_element(-5);
	//		cout << "Tree7 ins -5:\n";
	//		output_tree(Tree8);

	//		Tree8.insert_element(8);
	//		cout << "Tree8 ins 10:\n";
	//		output_tree(Tree8);
	//	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	//	// Поиск
	//		BinaryTree<int> Tree9(10);
	//		cout << "Tree9:\n";
	//		output_tree(Tree9);
	//		
	//		Tree9.search_element(5);
	//		Tree9.search_element(11);
	//		Tree9.search_element(8);
	return 0;
}

template <typename T>
void output_tree(BinaryTree<T>* Tree)
{
	Tree.output_elements_infix();
	Tree.output_elements_postfix();
	Tree.output_elements_prefix();
	cout << endl;
}