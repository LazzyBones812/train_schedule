#include <iostream>
#include <string>
#include <iomanip>
#include "List.h"
using namespace std;

void ClearList(ListTRAIN*& list)
{
	if (list->head) {
		while (list->size > 0) //Пока размерность списка не станет нулевой
		{
			TRAIN* temp = list->head;
			if (list->head->next) {
				temp = list->head->next;
			}
			delete list->head; //Освобождаем память от активного элемента
			list->head = temp; //Смена адреса начала на адрес следующего элемента
			list->size--; //Один элемент освобожден. корректируем число элементов
		}
	}
	list->head = NULL;
}
void AddList(ListTRAIN*& list, TRAIN*& yacheeka)
{
	if (yacheeka != NULL) {
		TRAIN* newelem = yacheeka; //Выделение памяти для нового элемента списка
		if (!list) {
			list = new ListTRAIN;
			list->head = newelem;
			list->end = newelem;
			list->head->next = NULL;
			list->size = 1; //При каждом добавлении элемента увеличиваем число	элементов в списке
			return;
		}
		TRAIN* temp = list->head; //Выделение памяти для нового элемента списка
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = newelem;
		list->end = newelem;
		list->end->next = NULL;
		list->size++; //При каждом добавлении элемента увеличиваем число элементов	в списке
	}
}
void numbering(ListTRAIN*& list) {
	TRAIN* tmp = list->head; //Указываем на голову
	int i = 1;
	while (tmp) //Пока не выполнен признак прохода по всему списку
	{
		tmp->num = i;
		i++;
		tmp = tmp->next; //Указываем, что нужен следующий элемент
	}
}
void Show(ListTRAIN* list)
{
	if (list->size < 1) {
		std::cout << "Массив пуст" << std::endl;
		return;
	}
	numbering(list);
	TRAIN* tempHead = list->head; //Указываем на голову
	while (tempHead) //Пока не выполнен признак прохода по всему списку
	{
		std::cout << tempHead->num<<" "<<tempHead->destination << " " << tempHead->number << " " <<//std::setw(15) <<
			tempHead->time << std::endl;
		tempHead = tempHead->next; //Указываем, что нужен следующий элемент
	}
	std::cout << "\n";
}
void Delete(ListTRAIN*& list, int num) {
	if (num > list->size || num < 1 || list->size <= 0) {
		std::cout << "Ошибка(списка ещё нет)" << std::endl;
		return;
	}
	int q = 0;
	TRAIN* tmp = list->head;
	while (q < num - 1)
	{
		tmp = tmp->next; //Указываем, что нужен следующий элемент
		q++;
	}
	std::cout << "Удаляю " << tmp->destination << " \n"; //выводим удаляемый элемент списка на экран
	tmp->next = tmp->next->next;
	list->size--;
	cout << "Удалено" << endl;
}
void Delete(ListTRAIN*& list, TRAIN* yacheeka) {
	if (yacheeka != NULL) {
		TRAIN* tmp = list->head;
		if (yacheeka == list->head) {
			list->head = list->head->next;
			list->size--;
			return;
		}
		while (tmp->next != yacheeka)
		{
			tmp = tmp->next; //Указываем, что нужен следующий элемент
		}
		tmp->next = tmp->next->next;
		list->size--;
		cout << "Удалено" << endl;
	}
}
TRAIN* SbN(ListTRAIN*& list, std::string number) {
	TRAIN* tmp = list->head; //Указываем на голову
	while (tmp) //Пока не выполнен признак прохода по всему списку
	{
		if (tmp->number == number) {
			return tmp;
		}
		tmp = tmp->next; //Указываем, что нужен следующий элемент
	}
	std::cout << " не найдено " << std::endl;
	return NULL;
}
TRAIN* SbD(ListTRAIN*& list, std::string destination) {
	TRAIN* tmp = list->head; //Указываем на голову
	while (tmp) //Пока не выполнен признак прохода по всему списку
	{
		if (tmp->destination == destination) {
			return tmp;
		}
		tmp = tmp->next; //Указываем, что нужен следующий элемент
	}
	std::cout << " не найдено " << std::endl;
	return NULL;
}
TRAIN* SbT(ListTRAIN*& list, std::string time)
{
	TRAIN* tmp = list->head; //Указываем на голову
	while (tmp) //Пока не выполнен признак прохода по всему списку
	{
		if (tmp->time == time) {
			return tmp;
		}
		tmp = tmp->next; //Указываем, что нужен следующий элемент
	}
	std::cout << " не найдено " << std::endl;
	return NULL;
}
void Search_by_ALL(ListTRAIN*& list, string number) {
	TRAIN* tmp = list->head; //Указываем на голову
	while (tmp) //Пока не выполнен признак прохода по всему списку
	{
		if (tmp->number == number) {
			std::cout << std::setw(25) << tmp->destination << std::setw(15) << tmp->number<<setw(25) <<tmp->time << std::endl;
		}
		tmp = tmp->next; //Указываем, что нужен следующий элемент
	}
}