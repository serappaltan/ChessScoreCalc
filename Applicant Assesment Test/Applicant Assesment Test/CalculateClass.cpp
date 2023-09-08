#include "CalculateClass.h"
#include "SingletonClass.cpp"
#include <iostream>
using namespace std;


CalculateClass::CalculateClass()
{

}

void PawnBlackMove(int i, int j) {  // siyah piyonlar� kontrol eder
	//Yukar�dan a�a�� iniyor -> Sa� �apraz kontrol�
	if (i < 7 && j < 7 && Singleton::getInstance()->chessboard[i + 1][j + 1].value[1] == 'b')
		Singleton::getInstance()->chessboard[i + 1][j + 1].inDanger = true;

	//Yukar�dan a�a�� iniyor -> Sol �apraz kontrol�
	if (i < 7 && 0 < j && Singleton::getInstance()->chessboard[i + 1][j - 1].value[1] == 'b') 
		Singleton::getInstance()->chessboard[i + 1][j - 1].inDanger = true;
}
void PawnWhiteMove(int i, int j) { // beyaz piyonlar� kontrol eder

	//A�a��dan yukar� ��k�yor -> Sa� �apraz kontrol�
	if (0 < i && j < 7 && Singleton::getInstance()->chessboard[i - 1][j + 1].value[1] == 's')
		Singleton::getInstance()->chessboard[i - 1][j + 1].inDanger = true;

	//A�a��dan yukar� ��k�yor -> Sol �apraz kontrol�
	if (0 < i && 0 < j && Singleton::getInstance()->chessboard[i - 1][j - 1].value[1] == 's')
		Singleton::getInstance()->chessboard[i - 1][j - 1].inDanger = true;
}

void KnightMove(int i, int j, char targetColour) { // siyah ve beyaz atlar� kontrol eder
	//At Yukar�-Sol Kontrol�
	if (1 < i && 0 < j && Singleton::getInstance()->chessboard[i - 2][j - 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i - 2][j - 1].inDanger = true;

	//At Yukar�-Sa� Kontrol�
	if (1 < i && j < 7 && Singleton::getInstance()->chessboard[i - 2][j + 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i - 2][j + 1].inDanger = true;

	//At Alt-Sol Kontrol�
	if (i < 6 && 0 < j && Singleton::getInstance()->chessboard[i + 2][j - 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i + 2][j - 1].inDanger = true;
	
	//At Alt-Sa� Kontrol�
	if (i < 6 && j < 7 && Singleton::getInstance()->chessboard[i + 2][j + 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i + 2][j + 1].inDanger = true;

	//At Sa�-Yukar� Kontrol�
	if (0 < i && j < 6 && Singleton::getInstance()->chessboard[i - 1][j + 2].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i - 1][j + 2].inDanger = true;

	//At Sa�-Alt Kontrol�
	if (i < 7 && j < 6 && Singleton::getInstance()->chessboard[i + 1][j + 2].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i + 1][j + 2].inDanger = true;

	//At Sol-Yukar� Kontrol�
	if (0 < i && 1 < j && Singleton::getInstance()->chessboard[i - 1][j - 2].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i - 1][j - 2].inDanger = true;

	//At Sol-Alt Kontrol�
	if (i < 7 && 1 < j && Singleton::getInstance()->chessboard[i + 1][j - 2].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i + 1][j - 2].inDanger = true;
}

void BishopMove(int i, int j, char targetColour) { // siyah ve beyaz filleri kontrol eder
	char blok;
	if (targetColour == 'b') blok = 's'; else blok = 'b'; // �n�m�ze ��kan ta� ile ayn� renk isek ilerlemeyi bitirecek

	//Yukar� Sol Taraf kontrol�
	for (int k = 1; k < 8; k++)
	{
		if (-1 < i - k && -1 < j - k && Singleton::getInstance()->chessboard[i - k][j - k].value[1] == blok) break; // �n�ndeki ta� kendi renginde ise yemiyor ve ilerlemeyi bitiriyor

		if (-1 < i - k && -1 < j - k && Singleton::getInstance()->chessboard[i - k][j - k].value[1] == targetColour) // �n�ndeki ta� hedef renkte ise o ta� tehdit alt�nda say�l�p durumu true yap�l�yor
		{
			Singleton::getInstance()->chessboard[i - k][j - k].inDanger = true;
			break;
		}
	}

	//Yukar� Sa� Taraf kontrol�
	for (int k = 1; k < 8; k++)
	{
		if (-1 < i - k && 8 > j + k && Singleton::getInstance()->chessboard[i - k][j + k].value[1] == blok) break;

		if (-1 < i - k && 8 > j + k && Singleton::getInstance()->chessboard[i - k][j + k].value[1] == targetColour)
		{
			Singleton::getInstance()->chessboard[i - k][j + k].inDanger = true;
			break;
		}
	}

	//Alt Sol Taraf kontrol�
	for (int k = 1; k < 8; k++)
	{
		if (8 > i + k && -1 < j - k && Singleton::getInstance()->chessboard[i + k][j - k].value[1] == blok) break;

		if (8 > i + k && -1 < j - k && Singleton::getInstance()->chessboard[i + k][j - k].value[1] == targetColour)
		{
			Singleton::getInstance()->chessboard[i + k][j - k].inDanger = true;
			break;
		}
	}

	//Alt Sa� Taraf kontrol�
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

void RookMove(int i, int j, char targetColour) { // siyah ve beyaz kale kontrol�
	char blok;
	if (targetColour == 'b') blok = 's'; else blok = 'b';

	//Yukar� Taraf kontrol�
	for (int k = 1; k < 8; k++)
	{
		if (-1 < i - k && Singleton::getInstance()->chessboard[i - k][j].value[1] == blok) break;

		if (-1 < i - k && Singleton::getInstance()->chessboard[i - k][j].value[1] == targetColour)
		{
			Singleton::getInstance()->chessboard[i - k][j].inDanger = true;
			break;
		}
	}

	//Sa� Taraf kontrol�
	for (int k = 1; k < 8; k++)
	{
		if (8 > j + k && Singleton::getInstance()->chessboard[i][j + k].value[1] == blok) break;

		if (8 > j + k && Singleton::getInstance()->chessboard[i][j + k].value[1] == targetColour)
		{
			Singleton::getInstance()->chessboard[i][j + k].inDanger = true;
			break;
		}

	}

	//Sol Taraf kontrol�
	for (int k = 1; k < 8; k++)
	{
		if (-1 < j - k && Singleton::getInstance()->chessboard[i][j - k].value[1] == blok) break;

		if (-1 < j - k && Singleton::getInstance()->chessboard[i][j - k].value[1] == targetColour)
		{
			Singleton::getInstance()->chessboard[i][j - k].inDanger = true;
			break;
		}
	}

	//Alt Taraf kontrol�
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

void KingMove(int i, int j, char targetColour) { // Siyah ve beyaz �ah kontrol�
	//Yukar�dan A�a�� sa� �apraz kontrol�
	if (i < 7 && j < 7 && Singleton::getInstance()->chessboard[i + 1][j + 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i + 1][j + 1].inDanger = true;

	//Yukar�dan A�a�� sol �apraz kontrol�
	if (i < 7 && 0 < j && Singleton::getInstance()->chessboard[i + 1][j - 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i + 1][j - 1].inDanger = true;

	//A�a��dan Yukar� sa� �apraz kontrol�
	if (0 < i && j < 7 && Singleton::getInstance()->chessboard[i - 1][j + 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i - 1][j + 1].inDanger = true;

	//A�a��dan Yukar� sol �apraz kontrol�
	if (0 < i && 0 < j && Singleton::getInstance()->chessboard[i - 1][j - 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i - 1][j - 1].inDanger = true;

	//A�a��dan Yukar� kontrol�
	if (0 < i && Singleton::getInstance()->chessboard[i - 1][j].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i - 1][j].inDanger = true;

	//Sa� Taraf kontrol�
	if (7 > j && Singleton::getInstance()->chessboard[i][j + 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i][j + 1].inDanger = true;

	//Sol Taraf kontrol�
	if (0 < j && Singleton::getInstance()->chessboard[i][j - 1].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i][j - 1].inDanger = true;

	//Yukar�dan A�a�� kontrol�
	if (7 > i && Singleton::getInstance()->chessboard[i + 1][j].value[1] == targetColour)
		Singleton::getInstance()->chessboard[i + 1][j].inDanger = true;
}

void FullPoints(char c, float* points) { // Ta� tehdit alt�nda de�ilse skora katk�s�
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
void HalfPoints(char c, float* points) { //ta� tehdit alt�nda ise (inDanger is true ) skora katk�s�

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


void CalculateClass::CalculateScore() { // Hesaplamay� yapar

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Singleton::getInstance()->chessboard[i][j].value[1] == 's') // siyah ta� i�in hesaplar
			{
				switch (Singleton::getInstance()->chessboard[i][j].value[0]) // mevcut ta��n ad�n� tespit eder
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
			else if (Singleton::getInstance()->chessboard[i][j].value[1] == 'b') { // beyaz ta� i�in hesaplar

				switch (Singleton::getInstance()->chessboard[i][j].value[0]) //mevcut ta��n ad�n� bulur
				{
				case 'p':
					PawnWhiteMove(i, j);
					break;
				case 'a':
					KnightMove(i, j, 's'); // ben (i,j) deki beyaz bir at�m. �n�mde yiyebiilece�im siyah bir ta� var m� ?
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
	// bu a�amada tehlike alt�ndaki t�m ta�lar�n inDanger de�i�keni true ya �ekilmi� durumda

	cout << "    0 1 2 3 4 5 6 7" << endl;
	cout << "    - - - - - - - -" << endl;

	for (int i = 0; i < 8; i++) {   // tehlike alt�ndaki ta�lar 1 ile i�aretlenerek satran� tahtas� ekrana bas�l�r
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
			if (Singleton::getInstance()->chessboard[i][j].value[1] == 's') { // ta� siyah ise

				if (Singleton::getInstance()->chessboard[i][j].inDanger == false) { // ve tehlike alt�nda de�ilse

					FullPoints(Singleton::getInstance()->chessboard[i][j].value[0], &blackTotal); // siyah tak�ma full katk� sunar
				}
				else
				{
					HalfPoints(Singleton::getInstance()->chessboard[i][j].value[0], &blackTotal); // tehlike alt�nda ise yar�m katk� sunar
				}

			}
			else if (Singleton::getInstance()->chessboard[i][j].value[1] == 'b') {  // ta� beyaz ise

				if (Singleton::getInstance()->chessboard[i][j].inDanger == false) { // ve tehlike alt�nda de�ilse 
					FullPoints(Singleton::getInstance()->chessboard[i][j].value[0], &whiteTotal); // beyaz tak�ma full katk� sunar
				}
				else
				{
					HalfPoints(Singleton::getInstance()->chessboard[i][j].value[0], &whiteTotal); // tehlike alt�nda ise yar�m katk� sunar
				}
			}
		}
	}

	cout << endl;

	cout << "Siyah Toplam Puan : " << blackTotal << endl;
	cout << "Beyaz Toplam Puan : " << whiteTotal << endl;

}
