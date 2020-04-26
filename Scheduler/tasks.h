#pragma once
#include <string>
using std::string;
// задание с кратким сроком
class Task {
	string id; // строковый идентификатор задания
	string text; // текст задания
	int importance; // уровень важности
	int deadline; // крайний срок исполнения

public:
	// создание задания
	Task(const string& id, const string& text, int deadline, int importance)
	{
		this->id = id;
		this->text = text;
		this->importance = importance;
		this->deadline = deadline;
	}
	bool extend_deadline(int dt); // продление срока исполнения
	bool change_level(int lvl); //изменение уровня важности задания
	virtual void print() const; // печать информации о задании
	int get_deadline() const;
	int get_importance() const;
	virtual ~Task() {};
};
