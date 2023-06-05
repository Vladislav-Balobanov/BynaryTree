// BynaryTree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "BinaryTree.h"

int main()
{
	BinaryTree bt, bt2;

	for (int i = 0; i < 10; i++)
	{
		bt.addNode(bt.getRoot(), i);
		bt2.addNode(bt2.getRoot(), rand() % 100);
	}

	std::cout << "Bynary Tree who named \"Bt\":\n";
	bt.printHorizontal();

	std::cout << "Bynary Tree who named \"Bt2\":\n";
	bt2.printHorizontal();
	bt = bt2;

	std::cout << "Bynary Tree who named \"Bt\":\n";
	bt.printHorizontal();

	std::cout << std::endl << std::endl << std::endl;

	bt.deleteNodeByKey(bt.getRoot(), 4);
	bt.printHorizontal();


	return 0;
}