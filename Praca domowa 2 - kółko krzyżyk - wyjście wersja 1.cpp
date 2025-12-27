
#include <iostream>
using namespace std;

class Plansza;
int input_a, input_b = 0;
char currentPlayer = 'X';

void Initialize();
void GetInput();
void Update();
void Render();
void Wincon();
void Shutdown();
bool IsGameFinished = false;
bool Next = false;


int main()
{
	while (!Next)
	{
		Initialize();

		while (!IsGameFinished)
		{
			GetInput();
			Update();
			Render();
			Wincon();
		}

		Shutdown();
	}

	return 0;
}

static const int PDG_size = 3;
char PDG[PDG_size][PDG_size];

class Plansza
{

public:
	Plansza()
	{
		for (int a = 0; a < PDG_size; a++)
		{
			for (int b = 0; b < PDG_size; b++)
			{
				PDG[a][b] = '*';
			}
		}
	}
	void pokaz()
	{
		for (int a = 0; a < 3; a++)
		{
			for (int b = 0; b < 3; b++)
			{
				cout << PDG[a][b] << " ";
			}
			cout << endl;
		}
		
		};
			

	};


Plansza* pole = new Plansza();

void Initialize()
{
	cout << "Witam w grze, kolko krzyzyk" << endl;
	
	pole->pokaz();
	
};

void GetInput()
{
	if (currentPlayer == 'X')
	{
		cout << "Teraz tura gracza X" << endl;
	}
	else
	{
		cout << "Teraz tura gracza O" << endl;
	}

	cout << "Napisz w ktorym rzedzie chcesz postawic znak" << endl;
	cin >> input_a;
	cout << "Napisz w ktorej kolumnie chcesz postawic znak" << endl;
	cin >> input_b;
	input_a--;
	input_b--;



}

void Update()
{
	if (input_a < 0 || input_a >= PDG_size || input_b < 0 || input_b >= PDG_size)
	{
		cout << "To pole jest nieprawidlowe!" << endl;
		return;
	}

	if (PDG[input_a][input_b] == '*')
	{
		PDG[input_a][input_b] = currentPlayer;
		
	}
	else
	{
		cout << "To pole jest zajete! Wybierz inne pole" << endl;
	}
}

void Render()
{
	pole->pokaz();
}

void Wincon()
{
		char test = currentPlayer;

		if (PDG[input_a][0] == test && PDG[input_a][1] == test && PDG[input_a][2] == test)
		{
			cout << "Gracz " << test << " wygral!" << endl;
			IsGameFinished = true;
			return;
		}

		if (PDG[0][input_b] == test && PDG[1][input_b] == test && PDG[2][input_b] == test)
		{
			cout << "Gracz " << test << " wygral!" << endl;
			IsGameFinished = true;
			return;
		}

		if (input_a == input_b)
		{
			if (PDG[0][0] == test && PDG[1][1] == test && PDG[2][2] == test)
			{
				cout << "Gracz " << test << " wygral!" << endl;
				IsGameFinished = true;
				return;
			}
		}

		if (input_a + input_b == 2)
		{
			if (PDG[0][2] == test && PDG[1][1] == test && PDG[2][0] == test)
			{
				cout << "Gracz " << test << " wygral!" << endl;
				IsGameFinished = true;
				return;
			}
		}

		bool remis = true;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (PDG[i][j] == '*')
				{
					remis = false;
					break;
				}
			}
		}

		if (remis)
		{
			cout << "Remis!" << endl;
			IsGameFinished = true;
			return;
		}

		currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void Shutdown()
{
	string Z;
	delete pole;
	cout << "Czy chcesz zagrac jeszcze raz?" << endl;
	cout << "Napisz tak lub nie" << endl; 
	cin >> Z;

	if (Z == "tak")
	{
		IsGameFinished = false;
		currentPlayer = 'X';
		pole = new Plansza();

	}
	else
	{
		Next = true;
	}
	


}