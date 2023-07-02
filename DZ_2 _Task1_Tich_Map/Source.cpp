#include<map>
#include<cstdint>
#include<vector>
#include<cstring>
#include<iostream>

class Person
{
private:
	const char* _fio = nullptr;
	uint16_t _age = -1;// Не валидное
public:
	Person(const char* fio, uint16_t age) : _age{ age }
	{
		_fio = new char[strlen(fio)];// Выделяем память по поле _fio
		_fio = fio; // Помещаем значение аргумента в поле
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
	~Person() 
	{ 
		delete[] _fio;
	}// Освобождаем выделеную память
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
	Flat(){ }

	Flat(Flat& flat)
	{
		this->_people = flat._people;// this это то, что вызывает функцию  Flat E(Person A);  this это  E
		// в this храниться объект, который вызвал функцию.
	}

	void AddPerson(Person* person)// Она принимает в себя объект класса Person
	{
		_people.push_back(person);// Кладем в себя Адрес ссылки &person . 
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
	std::map<uint16_t, Flat*>_flats;//Ключь uint16_t - номер квартиры будет Рандомным  
public:
	House(){}

	House(House& house)
	{
		this->_flats = house._flats;//_flats присваиваем значение поля _flats у аргумента конструктора(house)
	}

	//static void Foo(); - Статик используем тогда когда к функции можем обращаться не создавая объект класса House.Foo()/House::Foo();

	void AddFlat(Flat& flat)
	{
		// const_iterator пишем const так какон не будетменять значение в контейнере map (на который указывает)
		std::map<uint16_t, Flat*>::const_iterator it = _flats.begin();// Создаем итераторна map и присваиваем невалидное значение .end()

		uint16_t random_flats_number;

		while (it != _flats.end())
		{
			random_flats_number = 0 + std::rand() % 101; //Получаем случайный номер квартиры (Включительно  % 101)

			it = _flats.find(random_flats_number); // Проверяем есть ли в map данное значение random_flats_number 
		}

		_flats.insert(std::make_pair(random_flats_number, &flat));// std::make_pair(std::rand() - это рандомное добавление Номера квартиры
		// Квартире присваивается рандомный номер (Является ключем в map )
		//AddFlat(flat);	// Иначе вызываем рекурсию до тех пор пока не найдем уникальное значение!!
	}

	void ShouHouse()
	{
		//32 = jsenmgfesf rsgrdgrd
		//58 = segsrgrdgrdg
		//58 = segsrgrdgrdg
		//58 = segsrgrdgrdg
		//58 = segsrgrdgrdg
		//58 = segsrgrdgrdg
		//58 = segsrgrdgrdg
		//58 = segsrgrdgrdg
		
		//for(const auto flat = _flats.begin(); flat != _flats.end(); ++flat)
		//for range-based
		for (const auto& flat : _flats) //Бежим по значениям поля _flats (Нашего map)
		{
			std::cout << "Flat number " << flat.first << ": \n";// first это ключь для map - ромер квартиры
			flat.second->ShowPeople();// second это значение в map  Обращаемся к значению(квартира)  и вызываем метод ShowPeople()
		}
	}
};


int main()
{
	// Создали объекты класса Person  (людей)
	/*std::string name = "Ivanov";
	std::string name2 = "Sidorov";
	std::string name3 = "Petrov";*/
	Person person("Ivanov", 30);
	Person person2("Sidorov", 20);
	Person person3("Petrov", 40);
	// Создаем объект класса Flat (Квартиру)
	Flat flat;
	// Добавляем в квартиру  созданных людей 
	flat.AddPerson(&person);
	flat.AddPerson(&person2);
	flat.AddPerson(&person3);

	House house;
	house.AddFlat(flat);
	house.ShouHouse();

	//House::Foo();

	/*Person A("Ivanov", 45);		
	Flat E(Person A);
	Flat* H(new Flat);
	Flat C(*H);*/
	/*House C(Flat & E);
	House* house1{ new House };	
	House C(*house1);*/
	//H->ShowPeople();
	/*C.ShowPeople();*/

	////House* house1{new House};
	////House house2(*house1);
}