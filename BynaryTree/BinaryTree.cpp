#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	m_root = new Node();
	m_size = 1;
}

BinaryTree::BinaryTree(int key)
{
	m_root = new Node(key);
	m_size = 1;
}

void BinaryTree::deleteTree(Node* root)
{
	if (root != nullptr)
	{
		deleteTree(root->m_leftChild);
		deleteTree(root->m_rightChild);
		delete root;
	}
}

bool BinaryTree::isEmpty() // возвращает true, если дерево пусто
{
	if (m_root == nullptr)
	{
		return true;
	}
	return false;
}

BinaryTree::~BinaryTree() // деструктор
{
	deleteTree(m_root);
}

Node* BinaryTree::getRoot() // получение корня дерева
{
	return m_root;
}

int BinaryTree::getHeight(Node* root) // поиск высоты дерева 
{
	int height = 0;
	if (root)
	{
		int left, right;
		left = getHeight(root->m_leftChild); // поиск по левой ветви
		right = getHeight(root->m_rightChild); // поиск по правой ветви 

		height = ((left > right) ? left : right) + 1;
	}

	return height; // возвращаем значение высоты
}

int BinaryTree::getCount() // получение количества узлов дерева
{
	return m_size;
}

Node* BinaryTree::addNode(Node* subTreeRoot, const int key) // добавление узла в дерево
{
	if (subTreeRoot == nullptr) // проверка что дерево не пустое
	{ 
		if (m_root == nullptr) 
		{
			m_root = new Node(key); // создаем корень
			subTreeRoot->m_parent = m_root;
			m_size = 1;
			return m_root;
		}
		else 
		{
			return nullptr;
		}
	}

	if (subTreeRoot->m_leftChild == nullptr) // если левая ветвь пустая, то создаем ее
	{ 
		subTreeRoot->m_leftChild = new Node(key);
		subTreeRoot->m_leftChild->m_parent = subTreeRoot->m_leftChild;
		m_size++;
		return subTreeRoot->m_leftChild;
	}
	else if (subTreeRoot->m_rightChild == nullptr) // если правая ветвь пустая, то создаем ее 
	{ 
		subTreeRoot->m_rightChild = new Node(key);
		subTreeRoot->m_rightChild->m_parent = subTreeRoot->m_leftChild;
		m_size++;
		return subTreeRoot->m_rightChild;
	}
	else 
	{
		if (rand() % 2)  // если rand четное, то добавляем левую ветвь, если нечетное, то правую
		{
			return addNode(subTreeRoot->m_leftChild, key);
		}
		else 
		{
			return addNode(subTreeRoot->m_rightChild, key);
		}
	}
}

// вывод в консоль дерева по уровням (через вызовы предыдущего метода)
void BinaryTree::printHorizontal()
{
	int high = this->getHeight(this->getRoot());
	for (int i = 0; i < high; i++)
	{
		printLevel(i);
		std::cout << std::endl;
	}
}

void BinaryTree::printHorizontal(const int high) // вывод в консоль дерева в горизонтальном виде
{
	for (int i = 0; i < high; i++)
	{
		printLevel(i);
		std::cout << std::endl;
	}
}

void BinaryTree::printLevel(const int level) //вывод в консоль уровня дерева
{
	printLevel(m_root, level);
}

// вывод в консоль дерева по уровням (через вызовы предыдущего метода)
void BinaryTree::printLevel(Node* subTreeRoot, const int level, const int currentLevel)
{
	if (subTreeRoot == nullptr)
	{
		if (subTreeRoot == m_root)
		{
			std::cout << "Tree is empty" << std::endl;
			return;
		}
	}

	if (currentLevel == level)
	{
		if (subTreeRoot)
		{
			std::cout << subTreeRoot->m_key << "   ";
		}
		else
		{
			std::cout << "x    ";
		}

	}
	else if (currentLevel < level)
	{
		if (subTreeRoot)
		{
			printLevel(subTreeRoot->m_leftChild, level, currentLevel + 1);
			printLevel(subTreeRoot->m_rightChild, level, currentLevel + 1);
		}
		else
		{
			printLevel(nullptr, level, currentLevel + 1);
			printLevel(nullptr, level, currentLevel + 1);
		}
	}
}

void BinaryTree::Copy(Node* toNode, Node* fromNode, bool flag)
{
	// Нет смысла копировать что-либо из пустого дерева
	if (fromNode == nullptr)
		return;

	// Заведем буффер для сохранения текущего узла
	Node* bufferNode = new Node(fromNode->m_key);

	// Соответсвенно прсвоим новое значение корню в который копируем
	bufferNode->m_parent = toNode;

	// Если флаг в значении true копируем левого потомка
	if (flag)
		toNode->m_leftChild = bufferNode;
	// Иначе копируем правого потомка
	else
		toNode->m_rightChild = bufferNode;

	// Повторяем рекурсивно процедуру для всех осатльных 
	Copy(bufferNode, fromNode->m_leftChild, true);
	Copy(bufferNode, fromNode->m_rightChild, false);
}

Node* BinaryTree::getTreeByKey(Node* tree, const int key)
{
	if (tree)
	{
		if (tree->m_leftChild && tree->m_leftChild->m_key == key)
		{
			return tree->m_leftChild;
		}
		if (tree->m_rightChild && tree->m_rightChild->m_key == key)
		{
			return tree->m_rightChild;
		}
	}

	return tree;
}

BinaryTree& BinaryTree::operator=(const BinaryTree& tree)
{
	if (this == &tree) // если деревья равны , то выход
		return *this;

	this->deleteTree(m_root); // удаляем всё кроме корня в исходном дереве

	if (tree.m_root == nullptr)
		m_root = nullptr; // проверка на "пустоту" дерева
	else
	{
		m_root = new Node(tree.m_root->m_key); // создаём новый корень , копирую корень дерева b
		Copy(m_root, tree.m_root->m_leftChild, true); // копируем левую ветвь дерева b
		Copy(m_root, tree.m_root->m_rightChild, false); // копируем правую ветвь дерева b
	}
	return *this;
}

Node* BinaryTree::getParentByKey(Node* tree, int key)
{
	if (tree)
	{
		if (tree->m_leftChild || tree->m_rightChild)
		{
			if ((tree->m_leftChild && tree->m_leftChild->m_key == key) ||
				(tree->m_rightChild && tree->m_rightChild->m_key == key))
			{
				return tree;
			}

			Node* parent = getParentByKey(tree->m_leftChild, key);

			if (parent == nullptr)
			{
				return getParentByKey(tree->m_rightChild, key);
			}
			else
			{
				return parent;
			}
		}
	}

	return nullptr;
}

// удаление узла из дерева по ключу (возвращает true, если узел был удалён)
bool BinaryTree::deleteNodeByKey(Node* root, const int key)
{
	if (root == nullptr)
	{
		return false;
	}

	Node* parent = nullptr;
	if (root->m_key != key)
	{
		parent = getParentByKey(root, key);
		root = getTreeByKey(parent, key);
	}


	if (root && root->m_leftChild == nullptr && root->m_rightChild == nullptr)
	{
		if (parent)
		{
			if (parent->m_leftChild == root)
			{
				parent->m_leftChild = nullptr;
			}

			else if (parent->m_rightChild == root)
			{
				parent->m_rightChild = nullptr;
			}

			m_size--;
			delete root;
			return true;
		}
		else
		{
			m_size--;
			delete root;
			m_root = nullptr;
			return true;
		}
	}

	if (root && root->m_leftChild == nullptr && root->m_rightChild != nullptr)
	{
		if (parent)
		{
			if (parent->m_leftChild == root)
			{
				parent->m_leftChild = root->m_rightChild;
			}

			else if (parent->m_rightChild == root)
			{
				parent->m_rightChild = root->m_rightChild;
			}

			m_size--;
			delete root;
			return true;
		}
		else
		{
			Node* rightDescendant = root->m_rightChild;
			m_size--;
			delete root;

			m_root = rightDescendant;

			return true;
		}


	}

	if (root && root->m_leftChild != nullptr && root->m_rightChild == nullptr)
	{
		if (parent)
		{
			if (parent->m_leftChild == root)
			{
				parent->m_leftChild = root->m_leftChild;
			}

			else if (parent->m_rightChild == root)
			{
				parent->m_rightChild = root->m_leftChild;
			}

			m_size--;
			delete root;
			return true;
		}
		else
		{
			Node* leftDescendant = root->m_leftChild;
			m_size--;
			delete root;

			m_root = leftDescendant;

			return true;
		}
	}

	if (root && root->m_leftChild && root->m_rightChild)
	{
		if (parent)
		{
			if (parent->m_leftChild == root)
			{
				Node* rightDescendant = root->m_rightChild;
				Node* leftDescendant = root->m_leftChild;
				m_size--;
				delete root;

				parent->m_leftChild = leftDescendant;
				Node* parentOfLeaf = leftDescendant;
				while (parentOfLeaf->m_leftChild != nullptr)
					parentOfLeaf = parentOfLeaf->m_leftChild;
				parentOfLeaf->m_leftChild = rightDescendant;

				return true;
			}
			else if (parent->m_rightChild == root)
			{
				Node* rightDescendant = root->m_rightChild;
				Node* leftDescendant = root->m_leftChild;
				m_size--;
				delete root;

				parent->m_rightChild = leftDescendant;
				Node* parentOfLeaf = leftDescendant;
				while (parentOfLeaf->m_leftChild != nullptr)
					parentOfLeaf = parentOfLeaf->m_leftChild;
				parentOfLeaf->m_leftChild = rightDescendant;

				return true;
			}
		}
		else
		{
			Node* rightDescendant = root->m_rightChild;
			Node* leftDescendant = root->m_leftChild;
			m_size--;
			delete root;

			m_root = leftDescendant;
			Node* parentOfLeaf = m_root;
			while (parentOfLeaf->m_leftChild != nullptr)
				parentOfLeaf = parentOfLeaf->m_leftChild;
			parentOfLeaf->m_leftChild = rightDescendant;

			return true;
		}
	}

	return false;
}

bool BinaryTree::deleteNodeByKeyWithParrent(Node* root, const int key, Node* parent)
{
	if (root == nullptr)
	{
		return false;
	}

	if (root && root->m_leftChild == nullptr && root->m_rightChild == nullptr)
	{
		if (parent)
		{
			if (parent->m_leftChild == root)
			{
				parent->m_leftChild = nullptr;
			}

			else if (parent->m_rightChild == root)
			{
				parent->m_rightChild = nullptr;
			}

			m_size--;
			delete root;
			return true;
		}
		else
		{
			m_size--;
			delete root;
			m_root = nullptr;
			return true;
		}
	}

	if (root && root->m_leftChild == nullptr && root->m_rightChild != nullptr)
	{
		if (parent)
		{
			if (parent->m_leftChild == root)
			{
				parent->m_leftChild = root->m_rightChild;
			}

			else if (parent->m_rightChild == root)
			{
				parent->m_rightChild = root->m_rightChild;
			}

			m_size--;
			delete root;
			return true;
		}
		else
		{
			Node* rightDescendant = root->m_rightChild;
			m_size--;
			delete root;

			m_root = rightDescendant;

			return true;
		}


	}

	if (root && root->m_leftChild != nullptr && root->m_rightChild == nullptr)
	{
		if (parent)
		{
			if (parent->m_leftChild == root)
			{
				parent->m_leftChild = root->m_leftChild;
			}

			else if (parent->m_rightChild == root)
			{
				parent->m_rightChild = root->m_leftChild;
			}

			m_size--;
			delete root;
			return true;
		}
		else
		{
			Node* leftDescendant = root->m_leftChild;
			m_size--;
			delete root;

			m_root = leftDescendant;

			return true;
		}
	}

	if (root && root->m_leftChild && root->m_rightChild)
	{
		if (parent)
		{
			if (parent->m_leftChild == root)
			{
				Node* rightDescendant = root->m_rightChild;
				Node* leftDescendant = root->m_leftChild;
				m_size--;
				delete root;

				parent->m_leftChild = leftDescendant;
				Node* parentOfLeaf = leftDescendant;
				while (parentOfLeaf->m_leftChild != nullptr)
					parentOfLeaf = parentOfLeaf->m_leftChild;
				parentOfLeaf->m_leftChild = rightDescendant;

				return true;
			}
			else if (parent->m_rightChild == root)
			{
				Node* rightDescendant = root->m_rightChild;
				Node* leftDescendant = root->m_leftChild;
				m_size--;
				delete root;

				parent->m_rightChild = leftDescendant;
				Node* parentOfLeaf = leftDescendant;
				while (parentOfLeaf->m_leftChild != nullptr)
					parentOfLeaf = parentOfLeaf->m_leftChild;
				parentOfLeaf->m_leftChild = rightDescendant;

				return true;
			}
		}
		else
		{
			Node* rightDescendant = root->m_rightChild;
			Node* leftDescendant = root->m_leftChild;
			m_size--;
			delete root;

			m_root = leftDescendant;
			Node* parentOfLeaf = m_root;
			while (parentOfLeaf->m_leftChild != nullptr)
				parentOfLeaf = parentOfLeaf->m_leftChild;
			parentOfLeaf->m_leftChild = rightDescendant;

			return true;
		}
	}

	return false;
}

void BinaryTree::getKeys(Node* tree, std::vector<int>& vector)
{
	if (tree == nullptr)
	{
		return;
	}

	getKeys(tree->m_leftChild, vector);
	getKeys(tree->m_rightChild, vector);

	vector.push_back(tree->m_key);
}

std::vector<int> BinaryTree::getVectorKeys(Node* tree)
{
	std::vector<int> vector;

	getKeys(tree, vector);

	return vector;
}