#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

void getEnter()
{
	std::cin.get(); 
	system("cls");
}

void setTextColor(std::string newColor = "") {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	std::transform(newColor.begin(), newColor.end(), newColor.begin(), ::tolower);

	if (newColor == "red")
	{
		SetConsoleTextAttribute(console, FOREGROUND_RED);
	}
	else if (newColor == "green")
	{
		SetConsoleTextAttribute(console, FOREGROUND_GREEN);
	}
	else if (newColor == "blue")
	{
		SetConsoleTextAttribute(console, FOREGROUND_BLUE);
	}
	else if (newColor == "yellow")
	{
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN);
	}
	else if (newColor == "purple")
	{
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE);
	}
	else
	{
		SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
}

void showMassage(std::string text, std::string textColor = "") {
	setTextColor(textColor);
	std::cout << text;
	setTextColor("white");
}

void showError(std::string errorText) {
	std::transform(errorText.begin(), errorText.end(), errorText.begin(), ::toupper);
	setTextColor("red");
	std::cout << "\nERROR: " << errorText;
	setTextColor("white");
}

std::string getInput() {
	try
	{
		std::string input;
		std::cin >> input;
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		return input;
	}
	catch (const std::exception&)
	{
		showError("invalid argument - enter a string\n");
		return "";
	}
}