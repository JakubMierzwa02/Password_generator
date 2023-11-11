#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "password_generator.hpp"

int main()
{
	srand(time(0));

	int numPasswords, length;
	char digitChoice, specialCharChoice;

	std::cout << "How many passwords generate: ";
	std::cin >> numPasswords;

	std::cout << "Password length: ";
	std::cin >> length;

	std::cout << "Include numbers (y/n): ";
	std::cin >> digitChoice;

	std::cout << "Include special characters (y/n): ";
	std::cin >> specialCharChoice;

	bool includeDigits = (digitChoice == 'y');
	bool includeSpecialChars = (specialCharChoice == 'y');

	std::vector<std::string> passwords;
	for (int i = 0; i < numPasswords; i++)
		passwords.push_back(generatePassword(length, includeDigits, includeSpecialChars));

	std::ofstream outFile("passwords.txt");

	for (const auto& password : passwords)
	{
		std::cout << password << '\n';
		outFile << password << '\n';
	}

	outFile.close();

	return 0;
}