#include <cstdio>
#include "tasks.h"

bool Task::extend_deadline(int dt) // продление срока исполнения
{
	if (dt > 0)
	{
		deadline += dt;
		return true;
	}
	else return false;

}

bool Task::change_level(int lvl) //изменение уровня важности задания
{
	if (lvl > 0)
	{
		importance = lvl;
		return true;
	}
	else
		return false;
}

void Task::print() const //печать информации о задании
{
	printf("------\n");
    printf("ID: %s\nText: %s\ndeadline - %ds, importance level - %d \n", id.c_str(), text.c_str(), deadline, importance);
	printf("------\n");
}

int Task::get_deadline() const
{
	return deadline;
}

int Task::get_importance() const 
{
	return importance;
}

bool Task::exec()
{
	this->print();
	printf("Executed.\n\n");
	this->state = true;
	return false;
}




