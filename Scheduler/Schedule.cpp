#include "Schedule.h"



void Schedule::add_node(Task *t, int time)
{
	if (!root)
	{ 
		root = new Node(t, time);
		//root->print_node();
		return;
	}
	else
	{
		Node* new_node = new Node(t, time);
		Node* p = root;
		Node* parent = p;
		Node* left_child = nullptr;

		while (p)
		{
			parent = p; // ��� ������ p ��������� ��������

			if (new_node->time < p->time)
			{
				left_child = p; // ���� ����, ����� ������ �������� - �������� ������������ ��������
				p = p->left;
			}
			else
			{
				if (p->right_is_thread)
					break;
				else p = p->right;
			}
		}
		if (new_node->time < parent->time)
		{
			parent->left = new_node;
			//�������� ������ ��������, ������������ � ����� ���������
			new_node->right = parent;
			new_node->right_is_thread = true;
		}
		else
		{
			parent->right = new_node;
			parent->right_is_thread = false;
			if (left_child)
			{
				// �������� ��������, ������������ � ������ ���������
				// ��� �������, ��� ������ ������, ����������� ����� �� ��������
				new_node->right = left_child;
				new_node->right_is_thread = true;
			}
		}
		/*
		new_node->print_node();
		printf("Parent:\n");
		parent->print_node();
		if (new_node->right_is_thread)
		{
			printf("My thread: \n");
			new_node->right->print_node();
		}
		*/
	}
	

}
// ����� �����
void Schedule::show(Node *p) const
{
	//���������� �� ����� ���������� �� ���. ��������
	while (p->left)
	{
		p = p->left;
	}
	//������ �� ��������, ���� ��� �� ��������
	while (p)
	{
		p->print_node();
		if (p->right_is_thread)
		{
			p = p->right;
		}
		else break;

	}
	if (!p) return;
	if (p->right)
	{
		show(p->right);
	}
}

void Schedule::execute_task()
{
	Node* p = root;
	Node* parent = p;
	Node* u = nullptr, * s = nullptr;
	//����� ������������ ��������
	while (p->left)
	{
		parent = p;
		p = p->left;
	}
	if (p->right_is_thread)
	{
		parent->left = nullptr;
		delete p;
	}
	else
	{
		u = s = p->right;
		while (u->left)
			u->left;
		p->task = u->task;
		p->time = u->time;
		delete u;
    }

	
}
