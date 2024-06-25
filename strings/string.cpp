#include <iostream>

int getLength(const char* str)
{
    int i = 0;
    for(; str[i]!='\0'; i++);
    return i;
}

void changeCase(char* str)
{
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z') 
            str[i] -= 32;
        else if(str[i] >= 'A' && str[i] <= 'Z') 
            str[i] += 32;
    }
}

void countVowelsAndConsonants(char* str)
{
    int vcount = 0;
    int ccount = 0;
    for(int i=0; str[i]!='\0'; i++)
    {
        if( str[i] == 'a' || str[i] == 'A' ||
            str[i] == 'e' || str[i] == 'E' ||
            str[i] == 'i' || str[i] == 'I' ||
            str[i] == 'o' || str[i] == 'O' ||
            str[i] == 'u' || str[i] == 'U') vcount++;
        else if(
            str[i] > 'a' && str[i] <= 'z' ||
            str[i] > 'A' && str[i] <= 'Z'
        ) ccount++;
    }
    std::cout << "Vowels: " << vcount << '\n';
    std::cout << "Consonants: " << ccount << '\n';
}

int numberOfWords(char* str)
{
    int count = 1;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ' && str[i-1] != ' ')
        {
            count++;
        }
    }
    return count;
}

void captalize(char* str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(i == 0 || str[i-1] == ' ')
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] -= 32;
            }
        }
    }
}

bool validate(char* str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if( !(str[i] >= 'A' && str[i] <= 'Z') &&
            !(str[i] >= 'a' && str[i] <= 'z') &&
            !(str[i] >= '0' && str[i] <= '9'))
            return false;
    }
    return true;
}

void reverse(char* str)
{
    int j = getLength(str) - 1;

    for(int i = 0; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

char* reverseAux(const char* str)
{
    char* reverse = new char[getLength(str) + 1];

    int i = 0;
    for(; str[i] != '\0'; i++);
    i--;
    int j = 0;
    for(; i >= 0; i--, j++)
    {
        reverse[j] = str[i];
    }
    reverse[j] = '\0';
    return reverse;
}

void compare(char* str1, char* str2)
{
    int i = 0;
    int j = 0;
    for(; str1[i] != '\0' && str2[i] != '\0'; i++, j++)
    {
        if(str1[i] != str2[j]) break;
    }
    if(str1[i] < str2[j])       std::cout << str1 << " is smaller\n";
    else if(str1[i] > str2[j])  std::cout << str2 << " is smaller\n";
    else                        std::cout << "equal\n";
}

bool isPalindromeAux(char* str)
{
    char* reversedStr = reverseAux(str);

    for(int i = 0, j = 0; str[i] != '\0'; i++, j++)
    {
        if(str[i] != reversedStr[j])
        {
            delete[] reversedStr;
            return false;
        }
    }
    delete[] reversedStr;
    return true;
}

bool isPalindrome(char* str)
{
    int j = getLength(str) - 1;

    for(int i = 0; i <= j; i++, j--)
    {
        if(str[i] != str[j]) return false;
    }
    return true;
}

int main()
{
    char str[] = "madam";
    std::cout << isPalindrome(str) << '\n';

    return 0;
}