#include <string>
#include <ctime>

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