#include <gtest/gtest.h>
#include "..\password_generator.hpp"

// Password length test
TEST(PasswordGeneratorTest, LengthTest)
{
	int length = 10;
	std::string password = generatePassword(length, true, true);
	ASSERT_EQ(length, password.size());
}

TEST(PasswordGeneratorTest, ContentTest)
{
	std::string password = generatePassword(10, true, true);

	bool hasNumber = false;
	bool hasSpecialChar = false;
	for (char c : password)
	{
		if (isdigit(c))
			hasNumber = true;
		if (ispunct(c))
			hasSpecialChar = true;
	}

	ASSERT_TRUE(hasNumber);
	ASSERT_TRUE(hasSpecialChar);
}

// Randomness test
TEST(PasswordGeneratorTest, RandomnessTest) 
{
    std::string password1 = generatePassword(10, true, true);
    std::string password2 = generatePassword(10, true, true);
    ASSERT_NE(password1, password2);
}

TEST(PasswordGeneratorTest, UniquenessTest)
{
	std::set<std::string> generated_passwords;
	for (int i = 0; i < 1000; i++)
	{
		std::string password = generatePassword(10, true, true);
		ASSERT_TRUE(generated_passwords.find(password) == generated_passwords.end());
		generated_passwords.insert(password);
	}
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}