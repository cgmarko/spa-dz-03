#include "Menu.h"

Menu::Menu()
{
	currentSelect = 0;
	bool gameStarted = false;
	menuSelection.insert(make_pair( 0, "New game"));
	menuSelection.insert(make_pair( 1, "Continue"));
	menuSelection.insert(make_pair(2, "Quit"));
	menuSelection.insert(make_pair(3, "Build a Wall!"));
	menuSelection.insert(make_pair(4, "Game is on!"));
}

pair<int, string> Menu::getCurrentSelect()
{
	return *menuSelection.find(currentSelect);
}

void Menu::setCurrentSelect(int i)
{
	currentSelect = i;
}

string Menu::getString(int i)
{
	return menuSelection.find(i)->second;
}

void Menu::up()
{
	switch (currentSelect)
	{
	case 0:
		currentSelect = 2;
		break;
	case 1:
		currentSelect = 0;
		break;
	case 2:
		if (gameStarted)
		{
			currentSelect = 1;
		}
		else
		{
			currentSelect = 0;
		}
		break;
	default:
		break;
	}
}

void Menu::down()
{
	switch (currentSelect)
	{
	case 0:
		if (gameStarted)
		{
			currentSelect = 1;
		}
		else
		{
			currentSelect = 2;
		}
		break;
	case 1:
		currentSelect = 2;
		break;
	case 2:
		currentSelect = 0;
		break;
	default:
		break;
	}
}

bool Menu::getGameStarted()
{
	return gameStarted;
}

void Menu::setGameStarted()
{
	gameStarted = true;
}
