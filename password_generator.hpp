#ifndef PASSWORD_GENERATOR_HPP
#define PASSWORD_GENERATOR_HPP

#include <string>
#include <ctime>
#include <cctype>

std::string generatePassword(int length, bool includeDigits, bool includeSpecialChars)
{
	const std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	const std::string digits = "0123456789";
	const std::string specialChars = "!@#$%^&*()_-+=<>?";

	std::string characters = letters;
	if (includeDigits)
		characters += digits;
	if (includeSpecialChars)
		characters += specialChars;

	std::string password;
	for (int i = 0; i < length; i++)
		password += characters[rand() % characters.length()];

	return password;
}

// Function to validate the length of a password
bool validatePasswordLength(int length) 
{
    return (length >= 6 && length <= 64);
}

// Function to validate the number of passwords
bool validateNumberOfPasswords(int numPasswords) 
{
    return (numPasswords >= 1 && numPasswords <= 10000);
}

// Function to validate user's yes/no choice
bool validateYesNoChoice(char choice)
{
	return (choice == 'y' || choice == 'n');
}

#endif