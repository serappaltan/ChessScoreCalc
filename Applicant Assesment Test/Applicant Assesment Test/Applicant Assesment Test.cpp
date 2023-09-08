#include <iostream>
#include <fstream>
#include "SingletonClass.cpp"
#include "CalculateClass.h"

Singleton* Singleton::instancePtr = NULL;

int main() {
	std::string filePath;
	std::ifstream inputFile;
	
	do {
		std::cout << "Lutfen Dosya Yolu Giriniz : ";
		std::getline(std::cin, filePath);

		inputFile.open(filePath);

		if (!inputFile.is_open())
			std::cerr << "Girilen Dosya Yolu Gecersiz!" << std::endl;

	} while (!inputFile.is_open());

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::string str;	inputFile >> str;
			Singleton::getInstance()->setValues(i, j, str);
			Singleton::getInstance()->setStatus(i, j, false);
		}
	}

	inputFile.close();

	std::cout << std::endl << "Dizi Yuklendi ve Hesaplandi!" << std::endl;
	std::cout << "!!!Siyah taslarin ust kisimda oldugu varsayilarak hesaplanmistir!!!" << std::endl << std::endl;

	CalculateClass* obj = new CalculateClass;
	obj->CalculateScore();
	
	return 0;
}
