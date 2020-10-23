#include <iostream>
#include <iomanip>

using namespace std;

class MyString
{
private:
	char* str;
	int length;
public:
	MyString(const char* str = "") // конструктор класса
	{
		int length = strlen(str);
		this->length = length;
		this->str = new char[length + 1];

		strcpy_s(this->str, this->length + 1, str);
	}

	~MyString() // деструктор класса
	{
		delete[] str;
	}

	MyString(const MyString& other) // конструктор копирования
	{
		int newLength = strlen(other.str);
		this->length = newLength;
		this->str = new char[newLength + 1];

		strcpy_s(this->str, this->length + 1, other.str);
	}

	int operator >(const MyString& other); // перегрузка оператора >

	void enterStr(const char* str);  // ввод строки

	void print();  // вывод строки
};


int main()
{
	setlocale(LC_ALL, "rus");

	char ss[80];
	MyString str1;
	MyString str2;
	int deferance;

	cout << "Введите первую строку: ";
	cin.getline(ss, 80);
	str1.enterStr(ss);
	
	cout << "Введите вторую строку: ";
	cin.getline(ss, 80);
	str2.enterStr(ss);

	deferance = str1 > str2;
	cout << "Разница между первыми несовпадающими элементами строк: " << deferance << endl;

	system("pause");
}

int MyString::operator >(const MyString& other) // перегрузка оператора >
{
	int deferance = 0;

	if (this->length > other.length)
	{
		for (int i = 0; i < other.length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				deferance = this->str[i] - other.str[i];
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < this->length; i++)
		{
			if (this->str[i] != other.str[i])
			{
				deferance = this->str[i] - other.str[i];
				break;
			}
		}
	}

	return deferance;
}

void MyString::enterStr(const char* str)  // ввод строки
{
	if (this->str != nullptr)
	{
		delete[] this->str;
	}

	int length = strlen(str);
	this->length = length;
	this->str = new char[length + 1];

	strcpy_s(this->str, length + 1, str);
}

void MyString::print() // вывод строки
{
	for (int i = 0; i < this->length; i++) {
		cout << this->str[i];
	}

	cout << endl;
}