
#include <iostream>
using namespace std; 

//
//zaimplementuj klasę reprezentującą liczbę zespoloną zawierającą: 
// - Konstruktor domyślny, kopiujący, parametryczny
// - Destruktor
// - Przeładowane operatory +,-,*,/,=
//Liczba zespolona to Z = a + bi
//Z - liczba zespolona
//a - część rzeczywista  RE(z)
//b - część urojona IM(z)
//i - jednostka urojona
//i*i = -1
// 
// z1 = 2 + 4i
// z2 = 3 + 6i 
// z3 = z1 + z2 
// 
// 


class CN
{
private:
	float RE;
	float IM;

public:

	CN() : CN(0.0f,0.0f) // konsturktor domyślny
	{
		cout << "Kontruktor domyslny" << endl;
	};

	CN(float a, float b) // konstruktor parametryczny
	{
		RE = a;
		IM = b;
		cout << "Kontruktor parametryczny" << endl;
	};

	CN(const CN& other) // konstruktor kopiujący
	{
		RE = other.RE;
		IM = other.IM;
		cout << "kontruktor kopiujacy" << endl;

	};

	~CN() //destruktor
	{
		cout << "Destruktor is on" << endl;
	};

	void PrintCN() const // funckcja do wydruku
	{
		if (RE == 0)
		{
			cout << IM << "i" << endl;
			return;
		}
		if (RE != 0 && IM > 0)
		{
			cout << RE << " + " << IM << "i" << endl;
			return;
		}
		if (RE != 0 && IM < 0)
		{
			cout << RE << " - " << -IM << "i" << endl;
			return;
		}
		if (RE != 0 && IM == 0)
		{
			cout << RE << endl;
			return;
		}
		
	};

	void Increment() // inkrementacja
	{
		++RE;
		++IM;
	};

	CN operator+(const CN& z1) // dodawanie
	{
		float new_RE = RE + z1.RE;
		float new_IM = IM + z1.IM;

		return CN(new_RE, new_IM);
	};

	CN operator-(const CN& z1) // odejmowanie
	{
		float new_RE = RE - z1.RE;
		float new_IM = IM - z1.IM;

		return CN(new_RE, new_IM);
	};

	CN operator*(const CN& z1) // mnożenie
	{
		float new_RE = (RE * z1.RE) - (IM * z1.IM);
		float new_IM = (RE * z1.IM) + (z1.RE * IM);

		return CN(new_RE, new_IM);
	};

	CN operator/(const CN& z1) // dzielenie
	{
		float mianownik = (z1.RE * z1.RE) + (z1.IM * z1.IM);
		float new_RE = ((RE * z1.RE) + (IM * z1.IM)) / mianownik;
		float new_IM = ((IM * z1.RE) - (RE * z1.IM)) / mianownik;

		return CN(new_RE, new_IM);
	};


	CN& operator=(const CN& z1)
	{
		RE = z1.RE;
		IM = z1.IM;

		return *this;
	}

};

int main()
{
	CN* z0 = new CN(5.0f,3.0f);
	CN* z2 = new CN;

	z0 -> PrintCN();
	z2 -> Increment();
	z2 -> PrintCN();
	CN z3 = *z0 + *z2;
	CN z4 = *z0 - *z2;
	CN z5 = *z0 * *z2;
	CN z6 = *z0 / *z2;
	CN z7 = *z2;
	

	z3.PrintCN();
	z4.PrintCN();
	z5.PrintCN();
	z6.PrintCN();
	z7.PrintCN();

	return 0;
}
