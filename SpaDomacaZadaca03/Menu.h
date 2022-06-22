#pragma once
#include <string>
#include <map>
using namespace std;
class Menu
{
private:
	map<int, string> menuSelection;
	int currentSelect;
	bool gameStarted;
public:
	Menu();
	pair<int, string> getCurrentSelect();
	string getString(int i);
	void setCurrentSelect(int i);
	void up();
	void down();
	bool getGameStarted();
	void setGameStarted();

};

