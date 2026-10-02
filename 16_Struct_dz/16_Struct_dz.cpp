#include <iostream>
using namespace std;

// 1
struct WashingMachine
{
	char brand[20];
	char color[20];
	double width;
	double length;
	double height;
	int power;
	int spinSpeed;
	int heatTemperature;
};

// 2
struct Iron
{
	char brand[20];
	char model[20];
	char color[20];
	int minTemperature;
	int maxTemperature;
	bool steam;
	int power;
};

//3
struct Boiler
{
	char brand[20];
	char color[20];
	int power;
	int volume;
	int heatTemperature;
};

//4
union CarNumber
{
	int digits;
	char word[9];
};

struct Car
{
	char color[20];
	char model[20];
	bool isDigits;    
	CarNumber number;
};

void FillCar(Car& car)
{
	cout << "Color : "; cin >> car.color;
	cout << "Model : "; cin >> car.model;
	cout << "Number type (1 - digits, 2 - word) : ";
	int type;
	cin >> type;
	if (type == 1)
	{
		car.isDigits = true;
		cout << "Number (5 digits) : "; cin >> car.number.digits;
	}
	else
	{
		car.isDigits = false;
		cout << "Word (max 8 chars) : "; cin >> car.number.word;
	}
}

void ShowCar(Car& car)
{
	cout << car.color << ", " << car.model << ", ";
	if (car.isDigits)
		cout << car.number.digits << endl;
	else
		cout << car.number.word << endl;
}

bool SameWord(char a[], char b[])
{
	int i = 0;
	while (a[i] != '\0' && a[i] == b[i])
		i++;
	return a[i] == b[i];
}

int main()
{
	// 1
	WashingMachine machine = { "Samsung", "white", 60, 55, 85, 2100, 1200, 90 };
	cout << "---- Washing machine ----" << endl;
	cout << "Brand : " << machine.brand << endl;
	cout << "Color : " << machine.color << endl;
	cout << "Width : " << machine.width << endl;
	cout << "Length : " << machine.length << endl;
	cout << "Height : " << machine.height << endl;
	cout << "Power : " << machine.power << endl;
	cout << "Spin speed : " << machine.spinSpeed << endl;
	cout << "Heat temperature : " << machine.heatTemperature << endl << endl;

	// 2
	Iron iron = { "Philips", "GC4567", "blue", 60, 220, true, 2400 };
	cout << "---- Iron ----" << endl;
	cout << "Brand : " << iron.brand << endl;
	cout << "Model : " << iron.model << endl;
	cout << "Color : " << iron.color << endl;
	cout << "Min temperature : " << iron.minTemperature << endl;
	cout << "Max temperature : " << iron.maxTemperature << endl;
	cout << "Steam : " << iron.steam << endl;   
	cout << "Power : " << iron.power << endl << endl;


	Boiler boiler = { "Ariston", "grey", 1500, 80, 75 };
	cout << "---- Boiler ----" << endl;
	cout << "Brand : " << boiler.brand << endl;
	cout << "Color : " << boiler.color << endl;
	cout << "Power : " << boiler.power << endl;
	cout << "Volume : " << boiler.volume << endl;
	cout << "Heat temperature : " << boiler.heatTemperature << endl << endl;

	Car car;
	cout << "---- One car ----" << endl;
	FillCar(car);
	ShowCar(car);


	Car cars[10] = {
		{ "red",   "BMW",  true,  { 12345 } },
		{ "black", "Audi", true,  { 54321 } },
		{ "white", "Opel", true,  { 11111 } }
	};
	cars[3] = { "green", "Fiat", false };
	cars[3].number = { };
	cars[3].number.word[0] = 'K'; cars[3].number.word[1] = 'A';
	cars[3].number.word[2] = 'Z'; cars[3].number.word[3] = '\0';

	int count = 4; 

	cout << "\n---- Edit car ----" << endl;
	int index;
	cout << "Index (0-3) : "; cin >> index;
	FillCar(cars[index]);

	cout << "\n---- All cars ----" << endl;
	for (int i = 0; i < count; i++)
		ShowCar(cars[i]);

	cout << "\n---- Find car ----" << endl;
	cout << "Number type (1 - digits, 2 - word) : ";
	int type;
	cin >> type;
	if (type == 1)
	{
		int n;
		cout << "Enter number : "; cin >> n;
		for (int i = 0; i < count; i++)
			if (cars[i].isDigits && cars[i].number.digits == n)
				ShowCar(cars[i]);
	}
	else
	{
		char w[9];
		cout << "Enter word : "; cin >> w;
		for (int i = 0; i < count; i++)
			if (!cars[i].isDigits && SameWord(cars[i].number.word, w))
				ShowCar(cars[i]);
	}

}