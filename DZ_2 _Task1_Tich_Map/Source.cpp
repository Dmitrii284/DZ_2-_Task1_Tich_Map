#include<map>
#include<cstdint>
#include<vector>
#include<cstring>
#include<iostream>

class Person
{
private:
	const char* _fio = nullptr;
	uint16_t _age = -1;// �� ��������
public:
	Person(const char* fio, uint16_t age) : _age{ age }
	{
		_fio = new char[strlen(fio)];// �������� ������ �� ���� _fio
		_fio = fio; // �������� �������� ��������� � ����
	}

	Person(Person& person) // ��������� ������ � �������� �������� ��� ����� � ���� ���� (����� ���� ���� 2 ������� ������)
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
	}// ����������� ��������� ������
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
		this->_people = flat._people;// this ��� ��, ��� �������� �������  Flat E(Person A);  this ���  E
		// � this ��������� ������, ������� ������ �������.
	}

	void AddPerson(Person* person)// ��� ��������� � ���� ������ ������ Person
	{
		_people.push_back(person);// ������ � ���� ����� ������ &person . 
		// ����� ������ ������ � ������ � ���� ������ ��� ���  � ��� ������ �� ��������� <Person*>. 
	}
	
	void ShowPeople()
	{
		for (const auto& person : _people)// � person ��������� ������ ������ Person  � �� �������� ����� Print 
			person->Print();
	}
};

class House
{
private:
	std::map<uint16_t, Flat*>_flats;//����� uint16_t - ����� �������� ����� ���������  
public:
	House(){}

	House(House& house)
	{
		this->_flats = house._flats;//_flats ����������� �������� ���� _flats � ��������� ������������(house)
	}

	//static void Foo(); - ������ ���������� ����� ����� � ������� ����� ���������� �� �������� ������ ������ House.Foo()/House::Foo();

	void AddFlat(Flat& flat)
	{
		// const_iterator ����� const ��� ����� �� ����������� �������� � ���������� map (�� ������� ���������)
		std::map<uint16_t, Flat*>::const_iterator it = _flats.begin();// ������� ���������� map � ����������� ���������� �������� .end()

		uint16_t random_flats_number;

		while (it != _flats.end())
		{
			random_flats_number = 0 + std::rand() % 101; //�������� ��������� ����� �������� (������������  % 101)

			it = _flats.find(random_flats_number); // ��������� ���� �� � map ������ �������� random_flats_number 
		}

		_flats.insert(std::make_pair(random_flats_number, &flat));// std::make_pair(std::rand() - ��� ��������� ���������� ������ ��������
		// �������� ������������� ��������� ����� (�������� ������ � map )
		//AddFlat(flat);	// ����� �������� �������� �� ��� ��� ���� �� ������ ���������� ��������!!
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
		for (const auto& flat : _flats) //����� �� ��������� ���� _flats (������ map)
		{
			std::cout << "Flat number " << flat.first << ": \n";// first ��� ����� ��� map - ����� ��������
			flat.second->ShowPeople();// second ��� �������� � map  ���������� � ��������(��������)  � �������� ����� ShowPeople()
		}
	}
};


int main()
{
	// ������� ������� ������ Person  (�����)
	/*std::string name = "Ivanov";
	std::string name2 = "Sidorov";
	std::string name3 = "Petrov";*/
	Person person("Ivanov", 30);
	Person person2("Sidorov", 20);
	Person person3("Petrov", 40);
	// ������� ������ ������ Flat (��������)
	Flat flat;
	// ��������� � ��������  ��������� ����� 
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