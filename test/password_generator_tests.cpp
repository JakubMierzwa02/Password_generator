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

// Test the password length validation
TEST(PasswordGeneratorTest, ValidatePasswordLength)
{
	EXPECT_TRUE(validatePasswordLength(6));
	EXPECT_TRUE(validatePasswordLength(64));
	EXPECT_FALSE(validatePasswordLength(5));
	EXPECT_FALSE(validatePasswordLength(65));
}

// Test the number of passwords validation
TEST(PasswordGeneratorTest, ValidateNumberOfPasswords) 
{
    EXPECT_TRUE(validateNumberOfPasswords(1));  
    EXPECT_TRUE(validateNumberOfPasswords(10000));
    EXPECT_FALSE(validateNumberOfPasswords(0));
    EXPECT_FALSE(validateNumberOfPasswords(10001));
}

// Test the validateYesNoChoice function
TEST(PasswordGeneratorTest, ValidateYesNoChoice)
{
    EXPECT_TRUE(validateYesNoChoice('y'));
    EXPECT_TRUE(validateYesNoChoice('n'));

    EXPECT_FALSE(validateYesNoChoice('a'));
    EXPECT_FALSE(validateYesNoChoice('z'));
    EXPECT_FALSE(validateYesNoChoice('0'));
    EXPECT_FALSE(validateYesNoChoice('1'));
    EXPECT_FALSE(validateYesNoChoice('Y'));
    EXPECT_FALSE(validateYesNoChoice('N'));
}

// Test the isPasswordComplex function
TEST(PasswordGeneratorTest, CheckComplexity)
{
	EXPECT_FALSE(isPasswordComplex("1234"));
	EXPECT_FALSE(isPasswordComplex("abcd"));
	EXPECT_FALSE(isPasswordComplex("ABCD"));
	EXPECT_FALSE(isPasswordComplex("0000"));
	EXPECT_FALSE(isPasswordComplex("1aB$6789"));
	EXPECT_FALSE(isPasswordComplex("12ABCD34"));

	EXPECT_TRUE(isPasswordComplex("3*(7619p"));
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}