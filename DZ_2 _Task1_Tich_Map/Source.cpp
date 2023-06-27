#include<map>
#include<cstdint>
#include<vector>
#include<string>
#include<iostream>

class Person
{
private:
	const char* _fio = nullptr;
	uint16_t _age = -1;// �� ��������
public:
	Person(const std::string& fio, uint16_t age) : _age{ age }
	{
		_fio = new char[fio.size()];// �������� ������ �� ���� _fio
		_fio = fio.c_str(); // �������� �������� ��������� � ����
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

	void AddPerson(Person& person)// ��� ��������� � ���� ������ ������ Person
	{
		_people.push_back(&person);// ������ � ���� ����� ������ &person . 
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
	std::map<uint16_t, Flat*>_flats;
public:
	House(){}
	House(House& house)
	{
		this->_flats = house._flats;//_flats ����������� �������� ���� _flats � ��������� ������������(house)
	}
	void AddFlat(Flat& flat)
	{
		this
		int random_flats_number = 0 + std::rand() % 100; //�������� ��������� ����� ��������

		auto it = _flats.find(random_flats_number); // ��������� ���� �� � map ������ �������� random_flats_number 

		if (it == _flats.end())// ���� �� ����� � map �������� � ������� random_flats_number �� ���������!! ����� 
		{
			_flats.insert(std::make_pair(std::rand() % 100, &flat));// std::make_pair(std::rand() - ��� ��������� ���������� ������ ��������
			// �������� ������������� ��������� ����� (�������� ������ � map 
			return;
		}

		AddFlat(flat);	// ����� �������� �������� �� ��� ��� ���� �� ������ ���������� ��������!!
	}


};


int main()
{
	House* house1{new House};
	House house2(*house1);
}