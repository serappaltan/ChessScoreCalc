#include <string>


struct ChessStrcut { // her bir ta�� ifade eder
	std::string value; // ta��n ismi .... fs ks 
	bool inDanger; // te� tehdit alt�nda ise true olur
};

class Singleton {
private:

	static Singleton* instancePtr;
	Singleton() {}

public:

	ChessStrcut chessboard[8][8];

	Singleton(const Singleton& obj) = delete;

	static Singleton* getInstance()
	{
		if (instancePtr == nullptr)
		{
			instancePtr = new Singleton();
			return instancePtr;
		}
		else
		{
			return instancePtr;
		}
	}

	void setValues(int i, int j, std::string val) // txt den okunan deger ta�a atan�r
	{
		chessboard[i][j].value = val;
	}
	void setStatus(int i, int j, bool b)  // ba�lang�� i�in t�m ta�lara false atan�r
	{
		chessboard[i][j].inDanger = b;
	}
};