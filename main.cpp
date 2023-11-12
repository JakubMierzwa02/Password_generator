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
		if (!validateNumberOfPasswords(numPasswords))
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
		if (!validatePasswordLength(length))
		{
			std::cout << "Error: Password length should be between 6 and 64." << std::endl;
			// Ask for input again
			continue;
		}
		break;
	}

	// Validate user's choice for including digits
	while (true)
	{
		std::cout << "Include numbers (y/n): ";
		std::cin >> digitChoice;
		digitChoice = std::tolower(digitChoice);
		
		if (!validateYesNoChoice(digitChoice))
		{
			std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << std::endl;
			continue;
		}
		break;
	}

	// Validate user's choice for including special characters
	while (true)
	{
		std::cout << "Include special characters (y/n): ";
		std::cin >> specialCharChoice;
		specialCharChoice = std::tolower(specialCharChoice);

		if (!validateYesNoChoice(specialCharChoice))
		{
			std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << std::endl;
			continue;
		}
		break;
	}

	bool includeDigits = (digitChoice == 'y');
	bool includeSpecialChars = (specialCharChoice == 'y');

	std::vector<std::string> passwords;
	for (int i = 0; i < numPasswords; i++)
	{
		std::string password = generatePassword(length, includeDigits, includeSpecialChars);
		if (isPasswordComplex(password))
			passwords.push_back(password);
		else
			i--;
	}

	std::ofstream outFile("passwords.txt");

	for (const auto& password : passwords)
	{
		std::cout << password << '\n';
		outFile << password << '\n';
	}

	outFile.close();

	return 0;
}