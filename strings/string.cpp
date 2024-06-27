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

void findDuplicates(char* str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != -1)
        {
            int count = 1;
            for(int j = i+1; str[j] != '\0'; j++)
            {
                if(str[i] == str[j])
                {
                    count++;
                    str[j] = -1;
                }
            }
            std::cout << str[i] << '(' << count << ") ";
        }
    }
    std::cout << '\n';
}

void findDuplicatesHash(const char* str)
{
    // 52 são todas as letras maiúsculas e minúsculas, esse () já inicializa tudo com zeros
    int* hash = new int[52]();

    //Contabilizar a frequência dos caracteres
    for(int i = 0; str[i] != '\0'; i++)
    {
        if (std::islower(str[i]))
            hash[str[i] - 'a']++;
        else if (std::isupper(str[i]))
            hash[str[i] - 'A' + 26]++;
    }

    // Imprimir os caracteres duplicados
    for(int i = 0; i < 26; i++)
    {
        if(hash[i] > 1)
        {
            std::cout << char(i + 'a') << '(' << hash[i] << ") ";
        }
    }
    for(int i = 26; i < 52; i++)
    {
        if(hash[i] > 1)
        {
            std::cout << char(i - 26 + 'A') << '(' << hash[i] << ") ";
        }
    }

    delete[] hash;
    std::cout << '\n';
}

void findDuplicatesBitwise(const char* str)
{
    // Using this method it is not possible to know how many times the char is repeated,
    // but it is possible to know if it is duplicated at least one time
    int h = 0, x = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        x = 1;
        x = x << (str[i] - 97);
        if((x & h) > 0) std::cout << str[i] << " is duplicated.\n";
        else h = x | h;
    }
}

bool isAnagram(char* str1, char* str2)
{
    int* hash = new int[26]();

    for(int i = 0; str1[i] != '\0'; i++)
        hash[str1[i] - 97]++;

    for(int i = 0; str2[i] != '\0'; i++)
    {
        hash[str2[i] - 97]--;

        if(hash[str2[i] - 97] < 0)
            return false;
    }
    return true;

    delete[] hash;
}

void permutation(char* str, int k)
{
    static int aux[10] = {0};
    static char res[10];
    
    if(str[k] == '\0')
    {
        res[k] = '\0';
        std::cout << res << '\n';
    }
    else
    {
        for(int i = 0; str[i]!='\0'; i++)
        {
            if(aux[i] == 0)
            {
                res[k] = str[i];
                aux[i] = 1;
                permutation(str, k+1);
                aux[i] = 0;
            }
        }
    }
}

int main()
{
    char str[] = "ABC";
    permutation(str, 0);
    std::cout << '\n';

    return 0;
}