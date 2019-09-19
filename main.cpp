#include <iostream>
#include <windows.h>
#include <corecrt_math_defines.h>
using namespace std;
#define _USE_MATH_DEFINES

int main(int argc, char** argv) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num;

	cout << "                              Задачі " << endl <<
		"1. Обчисліть периметр і площу прямокутного трикутника, якщо відома гіпотенуза і один із катетів." << endl <<
		"2. Обчисліть периметр трикутника, якщо задано координати(x, y) трьох його вершин." << endl <<
		"3. Відома діагональ квадрата.Обчислити його площу та периметр." << endl <<
		"4. Трикутник заданий величинами усіх своїх сторін.Визначити усі кути трикутника." << endl <<
		"5. У трикутнику відомі один з катетів і площа.Визначити гіпотенузу, інший катет та гострі кути." << endl <<
		"6. Відома площа квадрата.Обчислити сторону і діагональ квадрата, а також площу круга, описаного навколо квадрата. " << endl <<
		"7. Відома діагональ квадрата.Визначити довжину кола та площу круга, вписаного у заданий квадрат." << endl <<
		"8. Відомо значення периметра рівностороннього трикутника.Обчислити сторону трикутника та його площу, а також радіус кола, описаного навколо нього. " << endl <<
		"9. Тіло має форму паралелепіпеда з висотою h.Квадрат в основі має діагональ d.Визначити об’єм тіла і площу повної поверхні. " << endl <<
		"10. У рівнобедреному трикутнику відома основа і кут при ній.Визначити площу трикутника і величину бічної сторони. " << endl <<
		"Виберіть № задачі" << endl;
	cin >> num;

	switch (num) {

	case 1:
		float g, k, P;
		double S;
		float k2;
		cout << "Введіть дані" << endl;
		cout << "Гіпотенуза = " << endl;
		cin >> g;
		cout << "Катет = " << endl;
		cin >> k;
		k2 = sqrt(g * g - k * k);
		P = g + k + k2;
		S = 0.5 * k * k2;
		cout << "Периметр = " << P << " Площа =" << S << endl;

		break;

	case 2:
		double x1, x2, x3, y1, y2, y3;
		double a, b, c;

		cout << "Введіть дані" << endl;

		cout << "x1 =" << endl;
		cin >> x1;
		cout << "y1 =" << endl;
		cin >> y1;

		cout << "x2 =" << endl;
		cin >> x2;
		cout << "y2 =" << endl;
		cin >> y2;

		cout << "x3 =" << endl;
		cin >> x3;
		cout << "y3 =" << endl;
		cin >> y3;

		a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
		c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

		cout << "Периметр = " << a + b + c << endl;

		break;

	case 3:
		float d;
		cout << "Введіть дані" << endl;
		cout << "Діагональ =" << endl;
		cin >> d;
		cout << "Периметр = " << 2 * sqrt(2) * d << " Площа =" << 0.5 * d * d << endl;
		break;

	case 4:
		double c4a, c4b, c4c, c4x, c4y, c4z;

		cout << "Введіть дані" << endl;
		cout << "a =" << endl;
		cin >> c4a;
		cout << "b =" << endl;
		cin >> c4b;
		cout << "c =" << endl;
		cin >> c4c;

		c4x = acos(((c4b * c4b) + (c4c * c4c) - (c4a * c4a)) / (2 * c4b * c4c)) * (180.00 / M_PI);
		c4y = acos(((c4a * c4a) + (c4c * c4c) - (c4b * c4b)) / (2 * c4a * c4c)) * (180.00 / M_PI);
		c4z = 180 - c4x - c4y;

		cout << "кут а =" << c4x << " кут в =" << c4y << " кут с =" << c4z << endl;
		break;


	case 5:
		double case5_k, case5_S;

		double case5_k2, case5_g;
		cout << "Введіть дані" << endl;
		cout << "Площа = " << endl;
		cin >> case5_S;
		cout << "Відомий катет = " << endl;
		cin >> case5_k;

		case5_k2 = (2 * case5_S) / case5_k;
		case5_g = sqrt((case5_k * case5_k) + (case5_k2 * case5_k2));

		/*
		B
		|\
	  k2| \ g
		|  \
		|----C
		A  k

		*/
		cout << "Невідомий катет = " << case5_k2 << " Гіпотенуза =" << case5_g << endl;

		if (case5_k == case5_g / 2) {
			cout << "B - гострий кут, B = 30°, C = 60°" << endl;
		}
		else {
			cout << "c - гострий кут, C = 30°, B = 60° " << endl;
		}

		break;


	case 6:
		double case6_S;

		double case6_a, case6_d, case6_S1;

		cout << "Введіть дані" << endl;
		cout << "Площа = " << endl;
		cin >> case6_S;

		case6_a = sqrt(case6_S);
		case6_d = sqrt(case6_S * 2);
		case6_S1 = M_PI * (case6_d / 2) * (case6_d / 2);

		cout << "Сторона квадрата = " << case6_a << " Діагональ = " << case6_d << " Площа круга =" << case6_S1 << endl;


		break;

	case 7:
		double case7_d;

		double case7_r, case7_l, case7_s;
		cout << "Введіть дані" << endl;
		cout << "Діагональ =" << endl;
		cin >> case7_d;

		case7_r = (sqrt(2) / 4) * case7_d;
		case7_l = M_PI * case7_r * 2;
		case7_s = M_PI * case7_r * case7_r;

		cout << " Довжина кола = " << case7_l << " Площа круга =" << case7_s << endl;

		break;

	case 8:

		double case8_p;
		double case8_a, case8_S, case8_r;

		cout << "Введіть дані" << endl;
		cout << "Периметр =" << endl;
		cin >> case8_p;

		case8_a = case8_p / 3;
		case8_S = (case8_a * sqrt(3) * case8_a) / 4;
		case8_r = (case8_a * case8_a * case8_a) / (4 * case8_S);

		cout << " Довжина сторони = " << case8_a << " Площа  = " << case8_S << " Радіус кола = " << case8_r << endl;
		break;

	case 9:
		//"9. Тіло має форму паралелепіпеда з висотою h.Квадрат в основі має діагональ d.Визначити об’єм тіла і площу повної поверхні. "
		double case9_h, case9_d;
		double case9_V, case9_S, case9_a;
		cout << "Введіть дані" << endl;
		cout << "Висота = " << endl;
		cin >> case9_h;
		cout << "Діагональ = " << endl;
		cin >> case9_d;

		case9_a = sqrt(3) / case9_d;
		case9_V = case9_a * case9_a * case9_a;
		case9_S = case9_h * case9_a * case9_a;

		cout << "Площа  = " << case9_S << " Об'єм = " << case9_V << endl;
		break;


	case 10:
		//"10. У рівнобедреному трикутнику відома основа і кут при ній.Визначити площу трикутника і величину бічної сторони. "

		double case10_o, case10_oa;
		double case10_S, case10_a;

		cout << "Введіть дані" << endl;
		cout << "Довжина основи =" << endl;
		cin >> case10_o;
		cout << "Кут при основі =" << endl;
		cin >> case10_oa;
		case10_a = case10_o / (2 * (cos(case10_oa)));
		case10_S = 0.5 * case10_a * case10_o * sin(case10_oa);

		cout << " Довжина сторони = " << case10_a << " Площа  = " << case10_S << endl;

		break;


	default: cout << "Error" << endl;
		break;
	}
	return 0;
