#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	//setlocale(LC_ALL, "Russian");
	int a, b;
	cout << "Введіть число: ";
	cin >> a >> b;
	cout << "Ваше число: "
		 << " ";
	if (a < 0)
	{
		cout << "Від'ємне число";
	}
	switch (a / 100)
	{
	case 1:
		cout << "Сто ";
		break;
	case 2:
		cout << "Двісті ";
		break;
	case 3:
		cout << "Триста ";
		break;
	case 4:
		cout << "Чотириста ";
		break;
	case 5:
		cout << "П'ятсот ";
		break;
	case 6:
		cout << "Шістсот ";
		break;
	case 7:
		cout << "Сімсот ";
		break;
	case 8:
		cout << "Вісімсот ";
		break;
	case 9:
		cout << "Девятсот ";
		break;
	}
	switch ((a % 100) / 10)
	{
	case 2:
		cout << "двадцять ";
		break;
	case 3:
		cout << "тридцять ";
		break;
	case 4:
		cout << "сорок ";
		break;
	case 5:
		cout << "пятдесят ";
		break;
	case 6:
		cout << "шістдесят ";
		break;
	case 7:
		cout << "сімдесят ";
		break;
	case 8:
		cout << "вісімдесят ";
		break;
	case 9:
		cout << "девяносто ";
		break;
	}
	if (a % 100 >= 10 & a % 100 < 20)
	{
		switch (a % 100)
		{
		case 10:
			cout << "десять гривень";
			break;
		case 11:
			cout << "одинадцять гривень";
			break;
		case 12:
			cout << "дванадцять гривень";
			break;
		case 13:
			cout << "тринадцять гривень";
			break;
		case 14:
			cout << "чотирнадцять гривень";
			break;
		case 15:
			cout << "пятнадцять гривень";
			break;
		case 16:
			cout << "шістнадцять гривень";
			break;
		case 17:
			cout << "сімнадяать гривень";
			break;
		case 18:
			cout << "вісімнадцять гривень";
			break;
		case 19:
			cout << "девятнадцять гривень";
			break;
		}
	}
	else
	{
		switch (a % 10)
		{
		case 0:
			cout << "";
			break;
		case 1:
			cout << "один гривні ";
			break;
		case 2:
			cout << "два гривні ";
			break;
		case 3:
			cout << "три гривні ";
			break;
		case 4:
			cout << "чотири гривні ";
			break;
		case 5:
			cout << "пять гривень ";
			break;
		case 6:
			cout << "шість гривень ";
			break;
		case 7:
			cout << "сім гривень ";
			break;
		case 8:
			cout << "вісім гривень ";
			break;
		case 9:
			cout << "девять гривень ";
			break;
		}
	}

	if (b == 0)
	{
		cout << " нуль копійок";
	}
	else if (b > 0 && b <= 99)
	{
		switch (b / 10)
		{
		case 2:
			cout << "двадцять ";
			break;
		case 3:
			cout << "тридцять ";
			break;
		case 4:
			cout << "сорок ";
			break;
		case 5:
			cout << "пятдесят ";
			break;
		case 6:
			cout << "шістдесят ";
			break;
		case 7:
			cout << "сімдесят ";
			break;
		case 8:
			cout << "вісімдесят ";
			break;
		case 9:
			cout << "девяносто ";
			break;
		}
		if (b >= 10 && b < 20)
		{
			switch (b)
			{
			case 10:
				cout << "десять";
				break;
			case 11:
				cout << "одинадцять";
				break;
			case 12:
				cout << "дванадцять";
				break;
			case 13:
				cout << "тринадцять";
				break;
			case 14:
				cout << "чотирнадцять";
				break;
			case 15:
				cout << "пятнадцять";
				break;
			case 16:
				cout << "шістнадцять";
				break;
			case 17:
				cout << "сімнадяать";
				break;
			case 18:
				cout << "вісімнадцять";
				break;
			case 19:
				cout << "девятнадцять";
				break;
			}
		}
		else
		{
			switch (b % 10)
			{
			case 0:
				cout << "";
				break;
			case 1:
				cout << "одна";
				break;
			case 2:
				cout << "дві";
				break;
			case 3:
				cout << "три";
				break;
			case 4:
				cout << "чотири";
				break;
			case 5:
				cout << "пять";
				break;
			case 6:
				cout << "шість";
				break;
			case 7:
				cout << "сім";
				break;
			case 8:
				cout << "вісім";
				break;
			case 9:
				cout << "девять";
				break;
			}
		}
	}
	if (b % 10 == 0 && b % 10 >= 5 && b % 10 <= 9)
	{
		cout << " копійок";
	}
	else if (b % 10 >= 1 && b % 10 <= 4)
	{
		cout << " копійки";
	}else if(b >= 10 && b <= 19){
			cout << " копійок";
	}

	_getch();
	return 0;
}
