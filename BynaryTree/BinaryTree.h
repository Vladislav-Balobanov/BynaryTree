#pragma once
// ����������� ������� ������������
#include <vector>
#include <iostream>
/// <summary>
/// ���� ������
/// </summary>
struct Node
{
	/// <summary>
	/// �����������
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
	/// ����
	/// </summary>
	int m_key;

	/// <summary>
	/// ����� �������
	/// </summary>
	Node* m_leftChild;

	/// <summary>
	/// ������ �������
	/// </summary>
	Node* m_rightChild;

	/// <summary>
	/// ������
	/// </summary>
	Node* m_parent;
};

class BinaryTree
{
protected:
	/// <summary>
	/// ������ ������
	/// </summary>
	Node* m_root = nullptr;

	/// <summary>
	/// ������
	/// </summary>
	size_t m_size;

	/// <summary>
	/// �������� ����� ������� ��������
	/// </summary>
	bool deleteNodeByKeyWithParrent(Node* root, const int key, Node* parent);

public:
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	BinaryTree();

	/// <summary>
	/// ����������� � ����������
	/// </summary>
	BinaryTree(int key);

	/// <summary>
	/// ���������
	/// </summary>
	~BinaryTree();

	/// <summary>
	/// �������� ������
	/// </summary>
	Node* getRoot();

	/// <summary>
	/// �������� ���� � ������
	/// <param name="subTreeRoot"></param>
	/// <param name="key"></param>
	/// </summary>
	Node* addNode(Node* subTreeRoot, const int key);

	/// <summary>
	/// �������� ���� ����� �����
	/// </summary>
	/// <param name="root"></param>
	void deleteTree(Node* root);

	/// <summary>
	/// �������� �� ������� ������
	/// </summary>
	bool isEmpty();

	/// <summary>
	/// �������� ������
	/// </summary>
	/// <param name="root"></param>
	int getHeight(Node* root);

	/// <summary>
	/// �������� ���������� �����
	/// </summary>
	/// <param name="root"></param>
	int getCount();

	/// <summary>
	/// ����������� ��������
	/// </summary>
	/// <param name="toRoot"></param>
	/// <param name="fromRoot"></param>
	/// <param name="flag"></param>
	void Copy(Node* toRoot, Node* fromRoot, bool flag);

	/// <summary>
	/// ������� ���� �� �����
	/// </summary>
	/// <param name="root"></param>
	/// <param name="key"></param>
	bool deleteNodeByKey(Node* root, const int key);

	/// <summary>
	/// �������� �������� �� �����
	/// </summary>
	/// <param name="root"></param>
	/// <param name="key"></param>
	Node* getParentByKey(Node* root, const int key);

	/// <summary>
	/// ��������� ������ �� �����
	/// </summary>
	/// <param name="root"></param>
	/// <param name="key"></param>
	Node* getTreeByKey(Node* tree, const int key);

	/// <summary>
	/// ���������� ��������� ������������
	/// </summary>
	/// <param name="tree"></param>
	BinaryTree& operator=(const BinaryTree& tree);

	/// <summary>
	/// �������� ������ ������
	/// </summary>
	/// <param name="root"></param>
	std::vector<int> getVectorKeys(Node* root);

	/// <summary>
	/// ��������������� ����� ��������� ������
	/// </summary>
	/// <param name="root"></param>
	/// <param name="vector"></param>
	void getKeys(Node* root, std::vector<int>& vector);

	// ����� � ������� ������ �� ������� (����� ������ ����������� ������)
	void printHorizontal();
	void printHorizontal(const int high);

	// ����� � ������� ������ ������ 
	void printLevel(const int level);
	void printLevel(Node* subTreeRoot, const int level, const int currentLevel = 0);
};