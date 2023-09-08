#include <string>


struct ChessStrcut { // her bir taþý ifade eder
	std::string value; // taþýn ismi .... fs ks 
	bool inDanger; // teþ tehdit altýnda ise true olur
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

	void setValues(int i, int j, std::string val) // txt den okunan deger taþa atanýr
	{
		chessboard[i][j].value = val;
	}
	void setStatus(int i, int j, bool b)  // baþlangýç için tüm taþlara false atanýr
	{
		chessboard[i][j].inDanger = b;
	}
};