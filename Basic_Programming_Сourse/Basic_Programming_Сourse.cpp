#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include <Windows.h>
#include <cmath>
#include"List.h"
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;
void littleprint(TRAIN* tmp) {
	if (tmp)
		std::cout << std::setw(25) << tmp->destination << std::setw(15) << tmp->number << std::setw(15) << tmp->time << std::endl;
}
int inputint()
{
	int x; int i = 0;
	std::cin >> x;
	while (std::cin.fail() || std::cin.get() != '\n')
	{
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << "Повторите ввод: ";
		std::cin >> x;
	}
	return x;
}
bool namecheck(std::string name)
{
	if (name.size() == 0) {
		return false;
	}
	int check = 0;
	for (size_t i = 0; i < name.length(); i++)
	{
		if (int('a') <= int(name[i]) && int(name[i]) <= int('z') ||
			int('A') <= int(name[i]) && int(name[i]) <= int('Z') ||
			int('А') <= int(name[i]) && int(name[i]) <= int('Я') ||
			int('а') <= int(name[i]) && int(name[i]) <= int('я') ||
			int(name[i]) == int(' ') ||
			int(name[i]) == int('ё') ||
			int(name[i]) == int('Ё') ||
			int(name[i]) == int('-'))
		{

		}
		else {
			std::cout << name[i] << " - недопустимый символ символ!" <<
				std::endl;
			return false;
		}
	}
	return true;
}
bool number_check(string number)
{
	if (number.length() != 4)
		return false;
	for (size_t i = 0; i < number.length(); i++) {
		if (!iswdigit(number[i]))
			return false;
	}
	return true;
}
bool numbersamecheck(ListTRAIN*& list, string number)
{
	if (list)
	{
		TRAIN* tmp = list->head;
		int count = 0;
		for (int i = 0; i < list->size; i++) {
			if (number == tmp->number)
				count++;
			tmp = tmp->next;
		}
		if (count < 1)
			return true;
		else
			return false;
	}
}
bool timecheck(string time)
{
	if (time.size() == 0) {
		return false;
	}
	if (time.size() != 5)
	{
		return false;
	}
	if ((int('0') <= int(time[0]) && int(time[0]) <= int('1')) && (int('0') <= int(time[1]) && int(time[1]) <= int('9')) || 
		(int(time[0]) == int('2')  && int('0') <= int(time[1])) && (int(time[1]) <= int('3')) &&
		int(':') == int(time[2]) &&
		int('0') <= int(time[3]) && int(time[3]) <= int('5') &&
		int('0') <= int(time[4]) && int(time[4]) <= int('9'))
	{
		return true;
	}
	else
	{
		return false;
	}
	return true;
}
std::string inputstring(int flag)
{
	std::string str;
	std::getline(std::cin, str);
	if (flag == 1)
		while (!namecheck(str))
		{
			std::cout << "Некорректный ввод. Пожалуйста, попробуйте снова: " <<
				std::endl;
			std::getline(std::cin, str);
		}
	if (flag == 2)
		while (!number_check(str))
		{
			std::cout << "Некорректный ввод. Пожалуйста, попробуйте снова: " <<
				std::endl;
			std::getline(std::cin, str);
		}
	if (flag == 3)
	{
		while (!timecheck(str))
		{
			cout << "Некорректный ввод. Пожалуйста, попробуйте снова: " << endl;
			getline(cin, str);
		}
	}
	int i = str.size();
	while (str[i - 1] == ' ')
	{
		str[i - 1] = '\0';
		i--;
	}
	for (int j = 0; j < i; ++j)
	{
		while (str[j] == ' ' && str[j + 1] == ' ')
		{
			for (int k = j; k < str.size() - 1; ++k)
				str[k] = str[k + 1];
			i--;
		}
	}
	if (str[0] == ' ')
	{
		for (int k = 0; k < str.size() - 1; ++k)
			str[k] = str[k + 1];
		i--;
	}
	str.resize(i);
	return str;
}
bool ultimatecheck(TRAIN*& tmp, ListTRAIN*& list)
{
	if (!namecheck(tmp->destination) || !number_check(tmp->number) || !timecheck(tmp->time)) {
		std::cout << "Провертье файл. Возможно где-то ошибка" <<
			std::endl;
		return false;
	}
	if (!numbersamecheck(list, tmp->number)) {
		std::cout << "Номера поездов повторяются" << std::endl;
		return false;
	}
	return true;
}
void dobavlenie_elementa_v_spisok(ListTRAIN*& list)
{
	TRAIN* newya4eeka = new TRAIN;
	std::cout << "Введите название пункта назначения:" << std::endl;
	std::string destination = inputstring(1);
	newya4eeka->destination = destination;
	std::cout << "Введите уникальный номер поезда (4-х значное положительное число)" << std::endl;
	std::string number = inputstring(2);
	while (!numbersamecheck(list, number))
	{
		std::cout << "Такой номер поезда уже существует: " << std::endl;
		number = inputstring(2);
	}
	newya4eeka->number = number;
	std::cout << "Введите время отправления поезда" << endl;
	string time = inputstring(3);
	newya4eeka->time = time;
	AddList(list, newya4eeka);
	std::cout << "Добавлено в список" << std::endl;
}
int nalichie_imen_v_spiske(ListTRAIN*& list, std::string destination)
{
	int count = 0;
	TRAIN* tmp = list->head;
	for (int i = 0; i < list->size; i++) {
		if (tmp->destination == destination)
			count++;
		tmp = tmp->next;
	}
	return count;
}
int nalichie_nomera_v_spiske(ListTRAIN*& list, std::string number)
{
	TRAIN* tmp = list->head;
	for (int i = 0; i < list->size; i++) {
		if (tmp->number == number)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}
int nalichie_time_v_spiske(ListTRAIN*& list, std::string time)
{
	int count = 0;
	TRAIN* tmp = list->head;
	for (int i = 0; i < list->size; i++) {
		if (tmp->time == time)
			count++;
		tmp = tmp->next;
	}
	return count;
}
void redactirovanie_elementa_v_spisoek(ListTRAIN*& list)
{
	std::cout << "Введите название пункта назначения или номер поезда \n : ";
	std::string NameOrTrain;
	std::string Name = "";
	std::string Train = "";
	TRAIN* tmp = new TRAIN;
	std::getline(std::cin, NameOrTrain);
	std::cout << "Проверяю название ли это?" << std::endl;
	while (!namecheck(NameOrTrain))
	{
		std::cout << "Проверяю номер ли это?" << std::endl;
		if (number_check(NameOrTrain)) {
			std::cout << "Это номер! Ищу в базе: " << std::endl;
			Train = NameOrTrain;
			break;
		}
		std::cout << "Некорректный ввод. Повторите: " << std::endl;
		std::getline(std::cin, NameOrTrain);
	}
	if (Train == "") 
	{
		Name = NameOrTrain;
		std::cout << "Это имя! Ищу в базе: " << std::endl;
		if (nalichie_imen_v_spiske(list, Name) < 1)
		{
			std::cout << "Не найдено: " << std::endl;
			return;
		}
		else {
			if (nalichie_imen_v_spiske(list, Name) == 1)
			{
				tmp = SbD(list, Name);
				littleprint(tmp);
			}
			else {
				std::cout << "Найдено несколько поездов \n";
				TRAIN* tmp = list->head;
				int q = 0;
				while (tmp) {
					if (tmp->destination == Name) {
						std::cout << q << ' ';
						littleprint(tmp);
						q++;
					}
					tmp = tmp->next;
				}
				std::cout << "Введите номер поезда \n";
				std::getline(std::cin, Train);
				while (!number_check(Train) || !SbN(list, Train))
				{
					std::cout << "Некорректный ввод. Повторите: " <<
						std::endl;
					std::getline(std::cin, Train);
				}
			}
		}
	}
	if (Train != "") 
	{
		if (!nalichie_nomera_v_spiske(list, Train)) {
			std::cout << "Не найдено: " << std::endl;
			return;
		}
		else {
			tmp = SbN(list, Train);
			std::cout << "Найдено " << std::endl;
			littleprint(tmp);
		}
	}
	std::cout << " ___________________________________ " << std::endl;
	std::cout << " | Введите номер команды: |" << std::endl;
	std::cout << " | 1 Редактирования название пункта назначения |" << std::endl;
	std::cout << " | 2 Редактирование номера поезда |" << std::endl;
	std::cout << " | 3 Редактирование времени отправления |" << std::endl;
	std::cout << " | 0 Отмена редактирования |" << std::endl;
	std::cout << " |___________________________________|" << std::endl;
	std::cout << " :";
	int menu = inputint();
	switch (menu)
	{
	case 0:
		break;
	case 1:
	{
		std::cout << "Введите название пункта назначения: " << std::endl;
		std::string nam2 = inputstring(1);
		while (!namecheck(nam2))
		{
			std::cout << "Некорректный ввод. Повторите: " << std::endl;
			std::string nam2 = inputstring(1);
		}
		tmp->destination = nam2;
		std::cout << "Отредактированно" << std::endl;
		break;
	}
	case 2:
	{
		std::cout << "Введите номер поезда " << std::endl;
		std::string pho2 = inputstring(2);
		while (!numbersamecheck(list, pho2))
		{
			std::cout << "Этот номер уже существует. Повторите: " << std::endl;
			pho2 = inputstring(2);
		}
		tmp->number = pho2;
		std::cout << "Отредактированно" << std::endl;
		break;
	}
	case 3:
	{
		std::cout << "Введите время отправления. Формат 00:00 до 23:59" << std::endl;
		std::string tm = inputstring(3);
		while (!timecheck(tm))
		{
			std::cout << "Некорректный ввод. Повторите: " << std::endl;
			tm = inputstring(3);
		}
		tmp->time = tm;
		std::cout << "Отредактированно" << std::endl;
	}
	}
}
void notedelete(ListTRAIN*& list)
{
	std::cout << "Введите название пункта назначения или номер поезда " << std::endl;
	std::string NameOrTrain;
	std::string Train;
	std::string name;
	std::getline(std::cin, NameOrTrain);
	while (!namecheck(NameOrTrain))
	{
		std::cout << "Проверяю номер поезда ли это?" << std::endl;
		if (number_check(NameOrTrain)) {
			std::cout << "Это номер поезда! Ищу в базе: " << std::endl;
			Train = NameOrTrain;
			TRAIN* tmp = SbN(list, Train);
			if (tmp)
				Delete(list, tmp);
			return;
		}
		std::getline(std::cin, NameOrTrain);
	}
	name = NameOrTrain;
	if (nalichie_imen_v_spiske(list, name) > 0)
	{
		if (nalichie_imen_v_spiske(list, name) > 1)
		{
			std::cout << "В этот пункт направляются несколько поездов. Введите уникальный номер поезда : " << std::endl;
			Search_by_ALL(list, name);
			std::string Phone;
			std::getline(std::cin, Train);
			while (!number_check(Train))
			{
				std::cout << "Некорректный ввод. Повторите: " << std::endl;
				std::getline(std::cin, Train);
			}
			Delete(list, SbN(list, Train));
			return;
		}
		else {
			Delete(list, SbD(list, name));
			return;
		}
	}
	else
	{
		std::cout << "Таких маршрутов нет." << std::endl;
	}
}
void fileout(ListTRAIN*& list)
{
	std::ofstream fout("C:\\SUAI\\basicProgramming.txt");
	TRAIN* tmp = list->head;
	while (tmp)
	{
		fout << ' ' << tmp->destination;
		fout << ' ' << tmp->number;
		fout << ' ' << tmp->time;
		fout << '\n';
		tmp = tmp->next;
	}
	fout.close();
}
void filein(ListTRAIN*& list)
{
	std::ifstream fin("C:\\SUAI\\basicProgramming.txt");
	if (!fin.is_open()) {
		std::cout << "Не удалось открыть файл(возможно файла не существует)." <<
			std::endl;
	}
	else
	{
		bool flag = true;
		if (list)
			list = NULL;
		while (!fin.eof())
		{
			TRAIN* tmp = new TRAIN;
			fin >> tmp->destination >> tmp->number >> tmp->time;
			if (!ultimatecheck(tmp, list) || tmp->destination == "")
			{
				std::cout << "Файл не коректен." << std::endl;
				list = NULL;
				flag = false; break;
			}
			AddList(list, tmp);
		}
		if (flag)
		{
			std::cout << "Загрузка завершена!" << std::endl;
		}
		fin.close();
	}
}
int comp_name(TRAIN* num1, TRAIN* num2)
{
	if (num1->destination < num2->destination)
		return true;
	else
		return false;
}
ListTRAIN* data_sort_name(ListTRAIN*& list)
{
	std::cout << "Сортирую" << std::endl;
	TRAIN* tmp = list->head;
	TRAIN* newtmp = list->head;
	ListTRAIN* newlist = NULL;
	std::vector<TRAIN*> v;
	while (tmp) {
		v.push_back(tmp);
		tmp = tmp->next;
	}
	std::sort(v.rbegin(), v.rend(), comp_name);
	std::reverse(std::begin(v), std::end(v));
	for (int i = 0; i < v.size(); i++) {
		littleprint(v[i]);
	}
	std::cout << "_______________!" << std::endl;
	std::cout << "Сортировка окончена!" << std::endl;
	std::cout << "Сохранить отсортированный вид?" << std::endl;
	std::cout << "1 - да сохранить || другие числе - не сохранять " << std::endl;
	int x = inputint();
	if (x == 1) {
		for (int i = 0; i < v.size(); i++) {
			v[i]->next = NULL;
			AddList(newlist, v[i]);
		}
		Show(newlist);
		return newlist;
	}
	else {
		return list;
	}
}
int comp_train(TRAIN* num1, TRAIN* num2)
{
	if (num1->number > num2->number)
		return true;
	else
		return false;
}
ListTRAIN* data_sort_train(ListTRAIN*& list)
{
	std::cout << "Сортирую по убыванию1" << std::endl;
	TRAIN* tmp = list->head;
	TRAIN* newtmp = list->head;
	ListTRAIN* newlist = NULL;
	std::vector<TRAIN*> v;
	while (tmp) {
		v.push_back(tmp);
		tmp = tmp->next;
	}
	std::sort(v.rbegin(), v.rend(), comp_train);
	std::reverse(std::begin(v), std::end(v));
	for (int i = 0; i < v.size(); i++) {
		littleprint(v[i]);
	}
	std::cout << "_______________!" << std::endl;
	std::cout << "Сортировка окончена!" << std::endl;
	std::cout << "Сохранить отсортированный вид?" << std::endl;
	std::cout << "1 - да || другое - нет " << std::endl;
	int x = inputint();
	if (x == 1) {
		for (int i = 0; i < v.size(); i++) {
			AddList(newlist, v[i]);
		}
		return newlist;
	}
	else {
		return list;
	}
}
int comp_time(TRAIN* num1, TRAIN* num2)
{
	if (num1->time > num2->time)
		return true;
	else
		return false;
}
ListTRAIN* data_sort_time(ListTRAIN*& list)
{
	std::cout << "Сортирую от начала суток до конца суток" << std::endl;
	TRAIN* tmp = list->head;
	TRAIN* newtmp = list->head;
	ListTRAIN* newlist = NULL;
	std::vector<TRAIN*> v;
	while (tmp) {
		v.push_back(tmp);
		tmp = tmp->next;
	}
	std::sort(v.rbegin(), v.rend(), comp_time);
	for (int i = 0; i < v.size(); i++) {
		littleprint(v[i]);
	}
	std::cout << "_______________!" << std::endl;
	std::cout << "Сортировка окончена!" << std::endl;
	std::cout << "Сохранить отсортированный вид?" << std::endl;
	std::cout << "1 - да || другое - нет " << std::endl;
	int x = inputint();
	if (x == 1) {
		for (int i = 0; i < v.size(); i++) {
			AddList(newlist, v[i]);
		}
		return newlist;
	}
	else {
		return list;
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "rus");
	system("color 08");
	ListTRAIN* list = NULL;
	int menu;
	menu = 1;
	while (menu)
	{
		if (list == NULL) {
			std::cout << std::endl;
			std::cout << " ___________________________________ " << std::endl;
			std::cout << " | Введите номер команды: |\n";
			std::cout << " | 1 добавить новый элемент в список |\n";
			std::cout << " | 8 загрузить из файла |\n";
			std::cout << " | 0 выход. |\n";
			std::cout << " |___________________________________| " << std::endl;
			std::cout << " : ";
		}
		else
		{
			system("pause");
			system("cls");
			std::cout << " ___________________________________ " << std::endl;
			std::cout << " | Введите номер команды: |\n";
			std::cout << " | 1 добавить новый элемент в список |\n";
			std::cout << " | 2 редактировать |\n";
			std::cout << " | 3 удалить элемент из списка |\n";
			std::cout << " | 4 сортировать |\n";
			std::cout << " | 5 поиск |\n";
			std::cout << " | 6 вывод на экран |\n";
			std::cout << " | 7 сохранить; |\n";
			std::cout << " | 8 загрузить из файла |\n";
			std::cout << " | 0 выход. |\n";
			std::cout << " |___________________________________| " << std::endl;
			std::cout << " : ";
		}
		menu = inputint();
		if (menu == 0)
			break;
		else if (menu == 1)
			dobavlenie_elementa_v_spisok(list);
		else if (menu == 2 && list) {
			Show(list);
			redactirovanie_elementa_v_spisoek(list);
		}
		else if (menu == 3 && list) {
			if (list) {
				Show(list);
				std::cout << " _______________________________ " << std::endl;
				std::cout << "|Введите номер команды: |" <<
					std::endl;
				std::cout << "| 1.Удалить по номеру в списке |" << std::endl;
				std::cout << "| 2.Удалить по данным (по номеру поезда или по названию пункта) |" << std::endl;
				std::cout << "| 0.Отмена удаления |" << std::endl;
				std::cout << "|_______________________________|" << std::endl;
				int choice = inputint();
				if (choice == 1)
				{
					std::cout << "введите номер в списке" << std::endl;
					int num = 0;
					while (num == 0 || num > list->size) {
						num = inputint();
					}
					TRAIN* tmp = list->head;
					while (tmp->num != num) {
						tmp = tmp->next;
					}
					Delete(list, tmp);
				}
				else if (choice == 2)
				{
					notedelete(list);
				}
			}
		}
		else if (menu == 4 && list)
		{
			std::cout << "Сортировка:" << std::endl;
			std::cout << " ______________________ " << std::endl;
			std::cout << "|Введите номер команды:|" << std::endl;
			std::cout << "| 1.по названию |" << std::endl;
			std::cout << "| 2.по номеру поезда:|" << std::endl;
			std::cout << "| 3.по времени:|" << std::endl;
			std::cout << "| 0.отмена сортировки |" << std::endl;
			std::cout << "|______________________|" << std::endl;
			int choice = inputint();
			if (choice == 1)
			{
				Show(list);
				list = data_sort_name(list);
			}
			else if (choice == 2)
			{
				Show(list);
				list = data_sort_train(list);
			}
			else if (choice == 3)
			{
				Show(list);
				list = data_sort_time(list);
			}
		}
		else if (menu == 5 && list)
		{
			Show(list);
			std::cout << "Поиск:" << std::endl;
			std::cout << " ______________________ " << std::endl;
			std::cout << "|Введите номер команды:|" << std::endl;
			std::cout << "| 1.по номеру поезда |" << std::endl;
			std::cout << "| 2.по названию |" << std::endl;
			std::cout << "| 3.по времени |" << std::endl;
			std::cout << "| 0.отмена поиска |" << std::endl;
			std::cout << "|______________________|" << std::endl;
			int choice = inputint();
			if (choice == 1) {
				std::cout << "(для отмены поиска введите 0)" << std::endl;
				std::cout << "Введите номер поезда: \n";
				std::string Train;
				std::getline(std::cin, Train);
				while (!number_check(Train) || numbersamecheck(list, Train))
				{
					if (Train == "0")
						break;
					std::cout << "Номер поезда не найден или некорректен! Проверьте правильность ввода!" << std::endl;
					std::cout << "(для выхода введите 0)" << std::endl;
					std::getline(std::cin, Train);
				}
				if (Train != "0") {
					TRAIN* tmp = SbN(list, Train);
					littleprint(tmp);
				}
			}
			else if (choice == 2) {
				std::cout << "Введите название пункта назначения: " << std::endl;
				std::string name;
				std::getline(std::cin, name);
				while (!namecheck(name))
				{
					std::cout << "Некорректный ввод. Повторите: " <<
						std::endl;
					std::getline(std::cin, name);
				}
				if (nalichie_imen_v_spiske(list, name) == 1)
				{
					littleprint(SbD(list, name));
				}
				else {
					std::cout << "Найдено несколько поездов \n";
					TRAIN* tmp = list->head;
					int q = 1;
					while (tmp) {
						if (tmp->destination == name) {
							std::cout << q << ' ';
							littleprint(tmp);
							q++;
						}
						tmp = tmp->next;
					}
					std::cout << "Введите номер поезда \n";
					std::string Train;
					std::getline(std::cin, Train);
					while (!number_check(Train))
					{
						std::getline(std::cin, Train);
						std::cout << "Некорректный ввод. Повторите: " <<
							std::endl;
					}
					tmp = SbN(list, Train);
					littleprint(tmp);
				}
			}
			else if (choice == 3) {
				std::cout << "Введите время отправления: " << std::endl;
				std::string time;
				std::getline(std::cin, time);
				while (!timecheck(time))
				{
					std::cout << "Некорректный ввод. Повторите: " <<
						std::endl;
					std::getline(std::cin, time);
				}
				if (nalichie_time_v_spiske(list, time) == 1)
				{
					littleprint(SbT(list, time));
				}
				else {
					std::cout << "Найдено несколько поездов \n";
					TRAIN* tmp = list->head;
					int q = 1;
					while (tmp) {
						if (tmp->time == time) {
							std::cout << q << ' ';
							littleprint(tmp);
							q++;
						}
						tmp = tmp->next;
					}
					std::cout << "Введите номер поезда \n";
					std::string Train;
					std::getline(std::cin, Train);
					while (!number_check(Train))
					{
						std::getline(std::cin, Train);
						std::cout << "Некорректный ввод. Повторите: " <<
							std::endl;
					}
					tmp = SbN(list, Train);
					littleprint(tmp);
				}
			}
		}
		else if (menu == 6 && list)
			Show(list);
		else if (menu == 7 && list)
		{
			if (list)
				fileout(list);
			std::cout << "Сохранено!" << std::endl;
		}
		else if (menu == 8) {
			int choice = 1;
			if (list) {
				std::cout << "Это удалит старую базу! Вы уверены?" <<
					std::endl;
				std::cout << "1 - да | 2 - нет\n";
				choice = inputint();
			}
			if (choice == 1)
			{
				filein(list);
			}
			else if (choice == 2) {
				std::cout << "_";
			}
		}
		else
			std::cout << " | Такого пункта нет в меню |" << std::endl;
	}
	system("pause");
	return 0;
}