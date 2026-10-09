#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

//структура книги яка має буть
struct Book
{
	char title[50];
	char author[50];
	char publisher[50];
	char genre[30];
	int year;
	double price;
};
//прийм.. копію, повертає заповнену
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
// пишем одну книгу
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
	for (int i = 0; i < size; i++)
	{
		cout << "\nКнига номер " << i + 1;
		ShowBook(books[i]);
	}
}
// редагувати книгу
void ChangeData(Book* books, int size)
{
	int number;
	cout << "Введіть номер книги (1-" << size << ") : "; cin >> number;
	if (number < 1 || number > size)
	{
		cout << "----------------Неправильний номер!!!!!---------------" << endl;
		return;
	}
	books[number - 1] = InputBook(books[number - 1]);
	cout << "---------------Книгу змінено!!!!!!-----------------" << endl;
}

void SearchByAuthor(Book* books, int size)
{
	char author[50];
	int count = 0;
	cout << "Введіть автора : "; cin >> author;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(books[i].author, author) == 0)
		{
			ShowBook(books[i]);
			count++;
		}
	}
	if (count == 0) cout << "------------ Нічого не знайдено!!!!!!!!!!------------ " << endl;
}

void SearchByTitle(Book* books, int size)
{
	char title[50];
	int count = 0;
	cout << "Введіть назву : "; cin >> title;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(books[i].title, title) == 0)
		{
			ShowBook(books[i]);
			count++;
		}
	}
	if (count == 0) cout << "------------ Нічого не знайдено!!!!!!!!------------ " << endl;
}

void SearchByPublisher(Book* books, int size)
{
	char publisher[50];
	int count = 0;
	cout << "Введіть видавництво : "; cin >> publisher;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(books[i].publisher, publisher) == 0)
		{
			ShowBook(books[i]);
			count++;
		}
	}
	if (count == 0) cout << "------------  Нічого не знайдено!!!!!! ------------ " << endl;
}

void SearchByGenre(Book* books, int size)
{
	char genre[30];
	int count = 0;
	cout << "Введіть жанр : "; cin >> genre;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(books[i].genre, genre) == 0)
		{
			ShowBook(books[i]);
			count++;
		}
	}
	if (count == 0) cout << "------------  Нічого не знайдено!!!!!!!!------------ " << endl;
}
// сменить ціну книги
void ChangePrice(Book* books, int size)
{
	int number;
	cout << "Введіть номер книги (1-" << size << ") : "; cin >> number;
	if (number < 1 || number > size)
	{
		cout << "Неправильний номер!" << endl;
		return;
	}
	cout << "Стара ціна : " << books[number - 1].price << endl;
	cout << "Введіть нову ціну : "; cin >> books[number - 1].price;
	cout << "------------  Ціну змінено!!!!!!!! ------------ " << endl;
}
// додат.  нову книгу 
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

Book* DeleteBook(Book* books, int& size)
{
	int number;
	cout << "Введіть номер книги (1-" << size << ") : "; cin >> number;
	if (number < 1 || number > size)
	{
		cout << " ------------ Неправильний номер!!!!!!! ------------" << endl;
		return books;
	}
	Book* newBooks = new Book[size - 1];
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != number - 1)
		{
			newBooks[k] = books[i];
			k++;
		}
	}
	delete[] books;
	size--;
	cout << " ------------ Книгу видалено!!!!!!! ------------" << endl;
	return newBooks;
}
int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// колір усього тексту 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

	int size = 10;
	Book* books = new Book[size];   // динамічний масив 

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
		cout << "\n------------ БІБЛІОТЕКА -------------------" << endl;
		cout << "1 - показати всі книги" << endl;
		cout << "2 - редагувати книгу" << endl;
		cout << "3 - пошук за автором" << endl;
		cout << "4 - пошук за назвою" << endl;
		cout << "5 - пошук за видавництвом" << endl;
		cout << "6 - пошук за жанром" << endl;
		cout << "7 - змінити ціну" << endl;
		cout << "8 - додатии нову книгу" << endl;
		cout << "9 - видалити книгу" << endl;
		cout << "0 - ехід" << endl;
		cout << "твій вибір : "; cin >> choice;

		switch (choice)
		{
		case 1: Show(books, size); break;
		case 2: ChangeData(books, size); break;
		case 3: SearchByAuthor(books, size); break;
		case 4: SearchByTitle(books, size); break;
		case 5: SearchByPublisher(books, size); break;
		case 6: SearchByGenre(books, size); break;
		case 7: ChangePrice(books, size); break;
		case 8: books = AddBook(books, size); break;
		case 9: books = DeleteBook(books, size); break;
		case 0: cout << "До побачення!" << endl; break;
		default: cout << "---------------------Неправильний вибір!!!!!---------------------" << endl;
		}
	} while (choice != 0);

	delete[] books;

}