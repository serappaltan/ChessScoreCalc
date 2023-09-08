#include "CalculateClass.h"
#include "SingletonClass.cpp"
#include <iostream>
using namespace std;


CalculateClass::CalculateClass()
{

}

void PawnBlackMove(int i, int j) {  // siyah piyonlarý kontrol eder
	//Yukarýdan aþaðý iniyor -> Sað çapraz kontrolü
	if (i < 7 && j < 7 && Singleton::getInstance()->chessboard[i + 1][j + 1].value[1] == 'b')
		Singleton::getInstance()->chessboard[i + 1][j + 1].inDanger = true;

	//Yukarýdan aþaðý iniyor -> Sol çapraz kontrolü
	if (i < 7 && 0 < j && Singleton::getInstance()->chessboard[i + 1][j - 1].value[1] == 'b') 
		Singleton::getInstance()->chessboard[i + 1][j - 1].inDanger = true;
}
void PawnWhiteMove(int i, int j) { // beyaz piyonlarý kontrol eder

	//Aþaðýdan yukarý çýkýyor -> Sað çapraz kontrolü
	if (0 < i && j < 7 && Singleton::getInstance()->chessboard[i - 1][j + 1].value[1] == 's')
		Singleton::getInstance()->chessboard[i - 1][j + 1].inDanger = true;

	//Aþaðýdan yukarý çýkýyor -> Sol çapraz kontrolü
	if (0 < i && 0 < j && Singleton::getInstance()->chessboard[i - 1][j - 1].value[1] == 's')
		Singleton::getInstance()->chessboard[i - 1][j - 1].inDanger = true;
}

void KnightMove(int i, int j, char targetColour) { // siyah ve beyaz atlarý kontrol eder
	//At Yukarý-Sol Kontrolü
	if (1 < i && 0 < j && Singleton::getInstance()->chessboard[i - 2][j - 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i - 2][j - 1].inDanger = true;

	//At Yukarý-Sað Kontrolü
	if (1 < i && j < 7 && Singleton::getInstance()->chessboard[i - 2][j + 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i - 2][j + 1].inDanger = true;

	//At Alt-Sol Kontrolü
	if (i < 6 && 0 < j && Singleton::getInstance()->chessboard[i + 2][j - 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i + 2][j - 1].inDanger = true;
	
	//At Alt-Sað Kontrolü
	if (i < 6 && j < 7 && Singleton::getInstance()->chessboard[i + 2][j + 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i + 2][j + 1].inDanger = true;

	//At Sað-Yukarý Kontrolü
	if (0 < i && j < 6 && Singleton::getInstance()->chessboard[i - 1][j + 2].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i - 1][j + 2].inDanger = true;

	//At Sað-Alt Kontrolü
	if (i < 7 && j < 6 && Singleton::getInstance()->chessboard[i + 1][j + 2].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i + 1][j + 2].inDanger = true;

	//At Sol-Yukarý Kontrolü
	if (0 < i && 1 < j && Singleton::getInstance()->chessboard[i - 1][j - 2].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i - 1][j - 2].inDanger = true;

	//At Sol-Alt Kontrolü
	if (i < 7 && 1 < j && Singleton::getInstance()->chessboard[i + 1][j - 2].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i + 1][j - 2].inDanger = true;
}

void BishopMove(int i, int j, char targetColour) { // siyah ve beyaz filleri kontrol eder
	char blok;
	if (targetColour == 'b') blok = 's'; else blok = 'b'; // önümüze çýkan taþ ile ayný renk isek ilerlemeyi bitirecek

	//Yukarý Sol Taraf kontrolü
	for (int k = 1; k < 8; k++)
	{
		if (-1 < i - k && -1 < j - k && Singleton::getInstance()->chessboard[i - k][j - k].value[1] == blok) break; // önündeki taþ kendi renginde ise yemiyor ve ilerlemeyi bitiriyor

		if (-1 < i - k && -1 < j - k && Singleton::getInstance()->chessboard[i - k][j - k].value[1] == targetColour) // önündeki taþ hedef renkte ise o taþ tehdit altýnda sayýlýp durumu true yapýlýyor
		{
			Singleton::getInstance()->chessboard[i - k][j - k].inDanger = true;
			break;
		}
	}

	//Yukarý Sað Taraf kontrolü
	for (int k = 1; k < 8; k++)
	{
		if (-1 < i - k && 8 > j + k && Singleton::getInstance()->chessboard[i - k][j + k].value[1] == blok) break;

		if (-1 < i - k && 8 > j + k && Singleton::getInstance()->chessboard[i - k][j + k].value[1] == targetColour)
		{
			Singleton::getInstance()->chessboard[i - k][j + k].inDanger = true;
			break;
		}
	}

	//Alt Sol Taraf kontrolü
	for (int k = 1; k < 8; k++)
	{
		if (8 > i + k && -1 < j - k && Singleton::getInstance()->chessboard[i + k][j - k].value[1] == blok) break;

		if (8 > i + k && -1 < j - k && Singleton::getInstance()->chessboard[i + k][j - k].value[1] == targetColour)
		{
			Singleton::getInstance()->chessboard[i + k][j - k].inDanger = true;
			break;
		}
	}

	//Alt Sað Taraf kontrolü
	for (int k = 1; k < 8; k++)
	{
		if (8 > i + k && 8 > j + k && Singleton::getInstance()->chessboard[i + k][j + k].value[1] == blok) break;

		if (8 > i + k && 8 > j + k && Singleton::getInstance()->chessboard[i + k][j + k].value[1] == targetColour)
		{
			Singleton::getInstance()->chessboard[i + k][j + k].inDanger = true;
			break;
		}
	}

}

void RookMove(int i, int j, char targetColour) { // siyah ve beyaz kale kontrolü
	char blok;
	if (targetColour == 'b') blok = 's'; else blok = 'b';

	//Yukarý Taraf kontrolü
	for (int k = 1; k < 8; k++)
	{
		if (-1 < i - k && Singleton::getInstance()->chessboard[i - k][j].value[1] == blok) break;

		if (-1 < i - k && Singleton::getInstance()->chessboard[i - k][j].value[1] == targetColour)
		{
			Singleton::getInstance()->chessboard[i - k][j].inDanger = true;
			break;
		}
	}

	//Sað Taraf kontrolü
	for (int k = 1; k < 8; k++)
	{
		if (8 > j + k && Singleton::getInstance()->chessboard[i][j + k].value[1] == blok) break;

		if (8 > j + k && Singleton::getInstance()->chessboard[i][j + k].value[1] == targetColour)
		{
			Singleton::getInstance()->chessboard[i][j + k].inDanger = true;
			break;
		}

	}

	//Sol Taraf kontrolü
	for (int k = 1; k < 8; k++)
	{
		if (-1 < j - k && Singleton::getInstance()->chessboard[i][j - k].value[1] == blok) break;

		if (-1 < j - k && Singleton::getInstance()->chessboard[i][j - k].value[1] == targetColour)
		{
			Singleton::getInstance()->chessboard[i][j - k].inDanger = true;
			break;
		}
	}

	//Alt Taraf kontrolü
	for (int k = 1; k < 8; k++)
	{
		if (8 > i + k && Singleton::getInstance()->chessboard[i + k][j].value[1] == blok) break;

		if (8 > i + k && Singleton::getInstance()->chessboard[i + k][j].value[1] == targetColour)
		{
			Singleton::getInstance()->chessboard[i + k][j].inDanger = true;
			break;
		}
	}
}

void KingMove(int i, int j, char targetColour) { // Siyah ve beyaz þah kontrolü
	//Yukarýdan Aþaðý sað çapraz kontrolü
	if (i < 7 && j < 7 && Singleton::getInstance()->chessboard[i + 1][j + 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i + 1][j + 1].inDanger = true;

	//Yukarýdan Aþaðý sol çapraz kontrolü
	if (i < 7 && 0 < j && Singleton::getInstance()->chessboard[i + 1][j - 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i + 1][j - 1].inDanger = true;

	//Aþaðýdan Yukarý sað çapraz kontrolü
	if (0 < i && j < 7 && Singleton::getInstance()->chessboard[i - 1][j + 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i - 1][j + 1].inDanger = true;

	//Aþaðýdan Yukarý sol çapraz kontrolü
	if (0 < i && 0 < j && Singleton::getInstance()->chessboard[i - 1][j - 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i - 1][j - 1].inDanger = true;

	//Aþaðýdan Yukarý kontrolü
	if (0 < i && Singleton::getInstance()->chessboard[i - 1][j].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i - 1][j].inDanger = true;

	//Sað Taraf kontrolü
	if (7 > j && Singleton::getInstance()->chessboard[i][j + 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i][j + 1].inDanger = true;

	//Sol Taraf kontrolü
	if (0 < j && Singleton::getInstance()->chessboard[i][j - 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i][j - 1].inDanger = true;

	//Yukarýdan Aþaðý kontrolü
	if (7 > i && Singleton::getInstance()->chessboard[i + 1][j].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i + 1][j].inDanger = true;
}

void FullPoints(char c, float* points) { // Taþ tehdit altýnda deðilse skora katkýsý
	switch (c)
	{
	case 'p':
		*points += 1;
		break;
	case 'a':
		*points += 3;
		break;
	case 'f':
		*points += 3;
		break;
	case 'k':
		*points += 5;
		break;
	case 'v':
		*points += 9;
		break;
	case 's':
		*points += 100;
		break;
	default:
		break;
	}
}
void HalfPoints(char c, float* points) { //taþ tehdit altýnda ise (inDanger is true ) skora katkýsý

	switch (c)
	{
	case 'p':
		*points += 0.5;
		break;
	case 'a':
		*points += 1.5;
		break;
	case 'f':
		*points += 1.5;
		break;
	case 'k':
		*points += 2.5;
		break;
	case 'v':
		*points += 4.5;
		break;
	case 's':
		*points += 50;
		break;
	default:
		break;
	}
}


void CalculateClass::CalculateScore() { // Hesaplamayý yapar

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Singleton::getInstance()->chessboard[i][j].value[1] == 's') // siyah taþ için hesaplar
			{
				switch (Singleton::getInstance()->chessboard[i][j].value[0]) // mevcut taþýn adýný tespit eder
				{
				case 'p':
					PawnBlackMove(i, j);
					break;
				case 'a':
					KnightMove(i, j, 'b');
					break;
				case 'f':
					BishopMove(i, j, 'b');
					break;
				case 'k':
					RookMove(i, j, 'b');
					break;
				case 'v':
					BishopMove(i, j, 'b');
					RookMove(i, j, 'b');
					break;
				case 's':
					KingMove(i, j, 'b');
					break;
				default:
					break;
				}
			}
			else if (Singleton::getInstance()->chessboard[i][j].value[1] == 'b') { // beyaz taþ için hesaplar

				switch (Singleton::getInstance()->chessboard[i][j].value[0]) //mevcut taþýn adýný bulur
				{
				case 'p':
					PawnWhiteMove(i, j);
					break;
				case 'a':
					KnightMove(i, j, 's'); // ben (i,j) deki beyaz bir atým. önümde yiyebiileceðim siyah bir taþ var mý ?
					break;
				case 'f':
					BishopMove(i, j, 's');
					break;
				case 'k':
					RookMove(i, j, 's');
					break;
				case 'v':
					BishopMove(i, j, 's');
					RookMove(i, j, 's');
					break;
				case 's':
					KingMove(i, j, 's');
					break;
				default:
					break;
				}

			}

		}
	}
	// bu aþamada tehlike altýndaki tüm taþlarýn inDanger deðiþkeni true ya çekilmiþ durumda

	cout << "    0 1 2 3 4 5 6 7" << endl;
	cout << "    - - - - - - - -" << endl;

	for (int i = 0; i < 8; i++) {   // tehlike altýndaki taþlar 1 ile iþaretlenerek satranç tahtasý ekrana basýlýr
		cout << i << " | ";
		for (int j = 0; j < 8; j++) {
			cout << Singleton::getInstance()->chessboard[i][j].inDanger << " ";
		}
		cout << endl;
	}


	float whiteTotal = 0;
	float blackTotal = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Singleton::getInstance()->chessboard[i][j].value[1] == 's') { // taþ siyah ise

				if (Singleton::getInstance()->chessboard[i][j].inDanger == false) { // ve tehlike altýnda deðilse

					FullPoints(Singleton::getInstance()->chessboard[i][j].value[0], &blackTotal); // siyah takýma full katký sunar
				}
				else
				{
					HalfPoints(Singleton::getInstance()->chessboard[i][j].value[0], &blackTotal); // tehlike altýnda ise yarým katký sunar
				}

			}
			else if (Singleton::getInstance()->chessboard[i][j].value[1] == 'b') {  // taþ beyaz ise

				if (Singleton::getInstance()->chessboard[i][j].inDanger == false) { // ve tehlike altýnda deðilse 
					FullPoints(Singleton::getInstance()->chessboard[i][j].value[0], &whiteTotal); // beyaz takýma full katký sunar
				}
				else
				{
					HalfPoints(Singleton::getInstance()->chessboard[i][j].value[0], &whiteTotal); // tehlike altýnda ise yarým katký sunar
				}
			}
		}
	}

	cout << endl;

	cout << "Siyah Toplam Puan : " << blackTotal << endl;
	cout << "Beyaz Toplam Puan : " << whiteTotal << endl;

}
