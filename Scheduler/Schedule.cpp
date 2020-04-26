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
			parent = p; // при сдвиге p сохраняем родителя

			if (new_node->time < p->time)
			{
				left_child = p; // ищем узел, левый предок которого - родитель вставляемого элемента
				p = p->left;
			}
			else if (new_node->time > p->time)
			{
				if (p->right_is_thread)
					break;
				else p = p->right;
			}
			
			else
			{
				dynamic_cast<PeriodicTask *>(t)->skip_task();
				delete new_node;
				add_node(t, t->get_deadline());
				return;
			}
		}
		if (new_node->time < parent->time)
		{
			parent->left = new_node;
			//прошивка вправо элемента, вставленного в левое поддерево
			new_node->right = parent;
			new_node->right_is_thread = true;
		}
		else
		{
			parent->right = new_node;
			parent->right_is_thread = false;
			if (left_child)
			{
				// прошивка элемента, вставленного в правое поддерево
				// при условии, что найден предок, указывающий слева на родителя
				new_node->right = left_child;
				new_node->right_is_thread = true;
			}
		}
		
		new_node->print_node();
		printf("Parent:\n");
		parent->print_node();
		if (new_node->right_is_thread)
		{
			printf("My thread: \n");
			new_node->right->print_node();
		}
		
	}
	

}
// вывод плана
void Schedule::show(Node *p) const
{
	//спускаемся по левым указателям до мин. элемента
	while (p->left)
	{
		p = p->left;
	}
	//проход по прошивке, пока она не кончится
	while (p)
	{
		p->print_node();
		if (p->right_is_thread)
		{
			p = p->right;
		}
		else break;

	}
	if (!p)
	{
		return;
	}
	if (p->right)
	{
		show(p->right);
	}
}

//выполнение задания - не готова
void Schedule::execute_task()
{
	Node* p = root;
	Node* parent = p, *u = nullptr;
	//ищем элемент с наименьшим ключом
	while (p->left)
	{
		parent = p;
		p = p->left;
	}
	// выполняем задание
	// если вернулось true, значит задание периодическое --> должно быть добавлено в дерево повторно
	//с ключом, увеличенным на период
	if (p->task->exec())
	{
		//printf("%i\n\n", p->task->get_deadline());
		add_node(p->task, p->task->get_deadline());
	}
	if (p->right_is_thread)
	{

		parent->left = nullptr;
		delete p;
	}
	else if (p == root)
	{
		root = p->right;
		delete p;
	}
	else
	{
		parent->left = p->right;
		delete p;
	}

	
}
