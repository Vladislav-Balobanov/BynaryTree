#pragma once
// Подключение внешних зависимостей
#include <vector>
#include <iostream>
/// <summary>
/// Узел дерева
/// </summary>
struct Node
{
	/// <summary>
	/// Конструктор
	/// </summary>
	/// <param name="key"></param>
	/// <param name="leftChild"></param>
	/// <param name="rightChild"></param>
	/// <param name="parrent"></param>
	Node
	(
		const int key = 13,
		Node* leftChild = nullptr,
		Node* rightChild = nullptr,
		Node* parent = nullptr
	) : m_key(key),
		m_leftChild(leftChild),
		m_rightChild(rightChild),
		m_parent(parent)
	{}

	/// <summary>
	/// Ключ
	/// </summary>
	int m_key;

	/// <summary>
	/// Левый потомок
	/// </summary>
	Node* m_leftChild;

	/// <summary>
	/// Правый потомок
	/// </summary>
	Node* m_rightChild;

	/// <summary>
	/// Предок
	/// </summary>
	Node* m_parent;
};

class BinaryTree
{
protected:
	/// <summary>
	/// Корень дерева
	/// </summary>
	Node* m_root = nullptr;

	/// <summary>
	/// Размер
	/// </summary>
	size_t m_size;

	/// <summary>
	/// Удаление узлов включая родителя
	/// </summary>
	bool deleteNodeByKeyWithParrent(Node* root, const int key, Node* parent);

public:
	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	BinaryTree();

	/// <summary>
	/// Конструктор с параметром
	/// </summary>
	BinaryTree(int key);

	/// <summary>
	/// Десруктор
	/// </summary>
	~BinaryTree();

	/// <summary>
	/// Получить корень
	/// </summary>
	Node* getRoot();

	/// <summary>
	/// Добавить узел в дерево
	/// <param name="subTreeRoot"></param>
	/// <param name="key"></param>
	/// </summary>
	Node* addNode(Node* subTreeRoot, const int key);

	/// <summary>
	/// Удаление всех узлов дерва
	/// </summary>
	/// <param name="root"></param>
	void deleteTree(Node* root);

	/// <summary>
	/// Проверка на пустоту дерева
	/// </summary>
	bool isEmpty();

	/// <summary>
	/// Получить высоту
	/// </summary>
	/// <param name="root"></param>
	int getHeight(Node* root);

	/// <summary>
	/// Получить количество узлов
	/// </summary>
	/// <param name="root"></param>
	int getCount();

	/// <summary>
	/// Копирование деревьев
	/// </summary>
	/// <param name="toRoot"></param>
	/// <param name="fromRoot"></param>
	/// <param name="flag"></param>
	void Copy(Node* toRoot, Node* fromRoot, bool flag);

	/// <summary>
	/// Удалить узел по ключу
	/// </summary>
	/// <param name="root"></param>
	/// <param name="key"></param>
	bool deleteNodeByKey(Node* root, const int key);

	/// <summary>
	/// Получить родителя по ключу
	/// </summary>
	/// <param name="root"></param>
	/// <param name="key"></param>
	Node* getParentByKey(Node* root, const int key);

	/// <summary>
	/// Получение дерева по ключу
	/// </summary>
	/// <param name="root"></param>
	/// <param name="key"></param>
	Node* getTreeByKey(Node* tree, const int key);

	/// <summary>
	/// Перегрузка оператора присваивания
	/// </summary>
	/// <param name="tree"></param>
	BinaryTree& operator=(const BinaryTree& tree);

	/// <summary>
	/// Получить массив ключей
	/// </summary>
	/// <param name="root"></param>
	std::vector<int> getVectorKeys(Node* root);

	/// <summary>
	/// Вспомогательный метод получения ключей
	/// </summary>
	/// <param name="root"></param>
	/// <param name="vector"></param>
	void getKeys(Node* root, std::vector<int>& vector);

	// вывод в консоль дерева по уровням (через вызовы предыдущего метода)
	void printHorizontal();
	void printHorizontal(const int high);

	// вывод в консоль уровня дерева 
	void printLevel(const int level);
	void printLevel(Node* subTreeRoot, const int level, const int currentLevel = 0);
};