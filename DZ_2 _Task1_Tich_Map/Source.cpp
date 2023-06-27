#include<map>
#include<cstdint>
#include<vector>
#include<string>
#include<iostream>

class Person
{
private:
	const char* _fio = nullptr;
	uint16_t _age = -1;// Не валидное
public:
	Person(const std::string& fio, uint16_t age) : _age{ age }
	{
		_fio = new char[fio.size()];// Выделяем память по поле _fio
		_fio = fio.c_str(); // Помещаем значение аргумента в поле
	}

	Person(Person& person) // Принимает объект и копирует значения его полей в свои поля (Нужен если надо 2 объекта дублей)
	{
		_fio = person._fio;
		_age = person._age;
	}

	void Print()
	{
		std::cout << "FIO: " << _fio << '\n';
		std::cout << "Age: " << _age << '\n';
	}
	~Person() { delete[] _fio; }
};
//Person person1("Jake", 20);
//
//Person person2(person1._fio, person1._age);
//Person person2(person1);

class Flat
{
private:
	std::vector<Person*> _people;
public:

	Flat(Flat& flat)
	{
		this->_people = flat._people;
	}

	void AddPerson(Person& person)// Она принимает в себя объект класса Person
	{
		_people.push_back(&person);// Кладем в себя Адрес ссылки &person . 
		// Берем ячейку памяти и кладем в нашь вектор Так как  у нас вектор по указателю <Person*>. 
	}
	
	void ShowPeople()
	{
		for (const auto& person : _people)// В person храниться объект класса Person  и мы вызываем метод Print 
			person->Print();
	}
};

class House
{
private:
	std::map<uint16_t, Flat*>_flats;
public:
	House(){}
	House(House& house)
	{
		this->_flats = house._flats;//_flats присваиваем значение поля _flats у аргумента конструктора(house)
	}
	void AddFlat(Flat& flat)
	{
		this
		int random_flats_number = 0 + std::rand() % 100; //Получаем случайный номер квартиры

		auto it = _flats.find(random_flats_number); // Проверяем есть ли в map данное значение random_flats_number 

		if (it == _flats.end())// Если не нашли в map квартиру с номером random_flats_number то добавляем!! Иначе 
		{
			_flats.insert(std::make_pair(std::rand() % 100, &flat));// std::make_pair(std::rand() - это рандомное добавление Номера квартиры
			// Квартире присваивается рандомный номер (Является ключем в map 
			return;
		}

		AddFlat(flat);	// Иначе вызываем рекурсию до тех пор пока не найдем уникальное значение!!
	}


};


int main()
{
	House* house1{new House};
	House house2(*house1);
}