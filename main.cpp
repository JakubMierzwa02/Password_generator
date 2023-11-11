#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <limits>

#include "password_generator.hpp"

int main()
{
	srand(time(0));

	int numPasswords, length;
	char digitChoice, specialCharChoice;

	std::cout << "How many passwords generate: ";
	std::cin >> numPasswords;

	while (true)
	{
		std::cout << "How many password to generate (1 to 10000): ";
		std::cin >> numPasswords;

		// Check for valid numeric input
		if (std::cin.fail())
		{
			std::cout << "Invalid input. Please enter a number." << std::endl;
			// Clear the error flag
			std::cin.clear();
			// Ignore the rest of the line
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		// Validate the number of passwords
		if (numPasswords < 1 || numPasswords > 10000)
		{
			std::cout << "Error: The number of passwords should be between 1 and 10000." << std::endl;
			continue;
		}
		break;
	}
	
	while (true)
	{
		std::cout<<"Enter the length of the passwords (6 to 64): ";
		std::cin >> length;

		// Check for valid numeric input
		if (std::cin.fail())
		{
			std::cout << "Invalid input. Please enter a number." << std::endl;
			// Clear the error flag
			std::cin.clear();
			// Ignore the rest of the line
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		// Validate the length of the password
		if (length < 6 || length > 64)
		{
			std::cout << "Error: Password length should be between 6 and 64." << std::endl;
			// Ask for input again
			continue;
		}
		break;
	}

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