#include "../util/util.h"

class suitcase {

public:

	suitcase(int m = 0) :_money(m) {

		//cout << "In suitcase constructor " << endl;
	}

	~suitcase() {

		//cout << "In suitcase destructor" << endl;
	}

	suitcase& operator=(int rhs) {

		//cout << "In = operator" << endl;

		this->_money = rhs;

		return *this;

	}

	friend ostream& operator<<(ostream& o, suitcase s) {

		o << s._money << endl;

		return o;
	}

	bool operator==(int rhs) {

		return true ? this->_money == rhs : false;
	}

	bool operator!=(suitcase& rhs) {

		return !(*this == rhs);
	}

	operator int() const {

		//cout << "In int()" << endl;

		return this->_money;
	}

	int operator+(int rhs) {

		suitcase sum;

		sum._money = this->_money + rhs;

		return sum._money;
	}

	int operator/(int rhs) {

		suitcase div;

		div._money = this->_money / rhs;

		return div._money;
	}

	
private:

	int _money;
	
};

class game {

public:

	game(suitcase l[]) :_s{ 0 } {

		//cout << "In game constructor" << endl;
		for (int i = 0; i < 26; i++) {

			_s[i] = l[i];
		}
	}

	~game() {

		//cout << "In game destructor" << endl;
	}

	friend ostream& operator<<(ostream& o, game g) {

		for (int i = 0; i < 26; i++) {

			o << "Index "<< i << " = " << g._s[i] << endl;

		}		

		return o;
	}

	void shuffleArray();
	void revealCases(int num, int mycase, int roundNum);
	void showArray();
	bool generateOffer();
	bool playRounds(int myCase, bool isInteractive = false);
	void playGame(bool isInteractive = false);

	static bool ifInteractive;

private:

	//list_of_suitcases _list;
	suitcase _s[26];
};
