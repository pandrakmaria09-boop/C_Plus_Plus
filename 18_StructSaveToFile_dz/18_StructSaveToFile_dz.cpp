#include <iostream>
#include <fstream>
#include <cstdlib>
#include <windows.h>
using namespace std;

const char* textFile = "text.txt";
const char* booksFile = "books.txt";


struct Book
{
	char title[50];      
	char author[50];     
	char publisher[50];  
	char genre[30];      
	int year;           
	double price;        
};

// перевірити чи існує файл
bool FileExists(const char* fileName)
{
	ifstream in(fileName, ios_base::in);
	bool result = in.is_open();
	in.close();
	return result;
}

// 1

void WriteText()
{
	const int count = 5;
	char line[250];

	if (FileExists(textFile))
		cout << "Файл " << textFile << " існує, його вміст буде перезаписано!" << endl;
	else
		cout << "Файл " << textFile << " не існує, він буде створений!" << endl;

	ofstream out(textFile, ios_base::out);
	if (out.is_open())
	{
		cout << "Введіть " << count << " рядків тексту:" << endl;
		for (int i = 0; i < count; i++)
		{
			cout << "Рядок " << i + 1 << " : ";
			cin.getline(line, 250);
			out << line << endl;
		}
		cout << "Збережено у файл!!!" << endl;
	}
	else
	{
		cout << "Не вдалося відкрити файл!" << endl;
	}
	out.close();
}

//2
// чит всього файлу text.txt
void ReadText()
{
	char buff[250];

	if (!FileExists(textFile))
	{
		cout << "Файл " << textFile << " не існує!" << endl;
		return;
	}
	ifstream in(textFile, ios_base::in);
	if (in.is_open())
	{
		cout << "\n------------ Вміст файлу -------------------" << endl;
		while (in.getline(buff, 250))   // читаємо до кінця файлу
		{
			cout << buff << endl;
		}
		cout << "------------ Кінець файлу -------------------" << endl;
	}
	else
	{
		cout << "Не вдалося відкрити файл!" << endl;
	}
	in.close();
}


Book InputBook(Book book)
{
	cout << "Введіть назву (одне слово) : "; cin >> book.title;
	cout << "Введіть автора (одне слово) : "; cin >> book.author;
	cout << "Введіть видавництво  : "; cin >> book.publisher;
	cout << "Введіть жанр (одне слово) : "; cin >> book.genre;
	cout << "Введіть рік видання : "; cin >> book.year;
	cout << "Введіть ціну : "; cin >> book.price;
	return book;
}
void ShowBook(Book& book)
{
	cout << "\nНазва : " << book.title << endl;
	cout << "Автор : " << book.author << endl;
	cout << "Видавництво : " << book.publisher << endl;
	cout << "Жанр : " << book.genre << endl;
	cout << "Рік видання : " << book.year << endl;
	cout << "Ціна : " << book.price << endl;
}
void Show(Book* books, int size)
{
	cout << "\n------------ Усі книги -------------------" << endl;
	if (size == 0)
	{
		cout << "--------------------Колекція порожня!!!!!!!!!!--------------------" << endl;
		return;
	}
	for (int i = 0; i < size; i++)
	{
		cout << "\nКнига номер " << i + 1;
		ShowBook(books[i]);
	}
}
Book* AddBook(Book* books, int& size)
{
	Book* newBooks = new Book[size + 1];
	for (int i = 0; i < size; i++)
	{
		newBooks[i] = books[i];
	}
	newBooks[size] = InputBook(newBooks[size]);
	delete[] books;
	size++;
	cout << "Книгу додано!" << endl;
	return newBooks;
}

// 3
// Запис колекції книг у файл (1 книга = 1 рядок)
void SaveBooksToFile(Book* books, int size)
{
	ofstream out(booksFile, ios_base::out);
	if (out.is_open())
	{
		for (int i = 0; i < size; i++)
		{
			out << books[i].title << ":";
			out << books[i].author << ":";
			out << books[i].publisher << ":";
			out << books[i].genre << ":";
			out << books[i].year << ":";
			out << books[i].price << endl;
		}
		cout << "Колекцію з " << size << " книг збережено у файл " << booksFile << endl;
	}
	else
	{
		cout << "Не вдалося відкрити файл!" << endl;
	}
	out.close();
}

// 4 завданя
// зчитування колекції книг з файлу
void ReadBooksFromFile(Book*& books, int& size)
{
	if (!FileExists(booksFile))
	{
		cout << "Файл " << booksFile << " не існує! Спочатку збережіть колекцію (пункт 5)." << endl;
		return;
	}
	ifstream in(booksFile, ios_base::in);
	if (!in.is_open())
	{
		cout << "Не вдалося відкрити файл!" << endl;
		return;
	}
	Book* newBooks = nullptr;
	int newSize = 0;
	char byear[50], bprice[50];
	Book readBook;
	while (in.getline(readBook.title, 50, ':'))   // до кінця файлу
	{
		in.getline(readBook.author, 50, ':');
		in.getline(readBook.publisher, 50, ':');
		in.getline(readBook.genre, 30, ':');
		in.getline(byear, 50, ':');
		in.getline(bprice, 50);
		readBook.year = atoi(byear);
		readBook.price = atof(bprice);

		Book* temp = new Book[newSize + 1];
		for (int i = 0; i < newSize; i++)
		{
			temp[i] = newBooks[i];
		}
		temp[newSize] = readBook;
		delete[] newBooks;
		newBooks = temp;
		newSize++;
	}
	in.close();

	delete[] books;     // замінюємо стару колекцію новой
	books = newBooks;
	size = newSize;
	cout << "З файлу зчитано " << size << " книг!" << endl;
}

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

	int size = 10;
	Book* books = new Book[size];   // динам. масив 

	books[0] = { "Кобзар","Шевченко","Ранок","Поезія",2018,250 };
	books[1] = { "Захар_Беркут","Франко","Фоліо","Роман",2016,180 };
	books[2] = { "Лісова_пісня","Українка","Ранок","Драма",2019,150 };
	books[3] = { "Тіні_забутих_предків","Коцюбинський","Фоліо","Повість",2015,170 };
	books[4] = { "Кайдашева_сім'я","Нечуй-Левицький","Основи","Повість",2017,120 };
	books[5] = { "Гаррі_Поттер","Роулінг","АБАБАГАЛАМАГА","Фентезі",2014,400 };
	books[6] = { "Гобіт","Толкін","Астролябія","Фентезі",2012,350 };
	books[7] = { "Дюна","Герберт","КМ-Букс","Фантастика",2010,420 };
	books[8] = { "Шерлок_Холмс","Дойл","Фоліо","Детектив",2013,300 };
	books[9] = { "Катерина","Шевченко","Ранок","Поезія",2020,90 };

	int choice;
	do
	{
		cout << "\n------------ ФАЙЛИ -------------------" << endl;
		cout << "1 - Записати 5 рядків у text.txt" << endl;
		cout << "2 - Прочитати text.txt" << endl;
		cout << "3 - Показати колекцію книг" << endl;
		cout << "4 - Додати нову книгу" << endl;
		cout << "5 - Записати колекцію книг у файл" << endl;
		cout << "6 - Зчитати колекцію книг з файлу" << endl;
		cout << "0 - Вихід" << endl;
		cout << "Ваш вибір : "; cin >> choice;
		cin.ignore();   // прибираємо enter після вибору

		switch (choice)
		{
		case 1: WriteText(); break;
		case 2: ReadText(); break;
		case 3: Show(books, size); break;
		case 4: books = AddBook(books, size); break;
		case 5: SaveBooksToFile(books, size); break;
		case 6: ReadBooksFromFile(books, size); break;
		case 0: cout << "До побачення!" << endl; break;
		default: cout << "Неправильний вибір!" << endl;
		}
	} while (choice != 0);

	delete[] books;   

}