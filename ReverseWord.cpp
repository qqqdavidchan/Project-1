#include <iostream>
#include <string>

void reverse(char *begin, char *end);
void reverseWords(char *s);
using namespace std;

/*
int main()
{
	char sentence[100];
	cout << "Please enter a short sentence " << endl;
	cin.getline(sentence, 100);
	reverseWords(sentence);
	printf("%s", sentence);
	cout << endl;
	system("PAUSE");
	return 0;
}
*/
void reverseWords(char *word)
{
	char *word_begin = word;
	char *temp = word; 

	//search for the spaces and the end
	while (*temp)
	{
		temp++;
		if (*temp == '\0')
		{
			reverse(word_begin, temp - 1);
		}
		else if (*temp == ' ')
		{
			reverse(word_begin, temp - 1);
			word_begin = temp + 1;
		}
	} 

	reverse(word, temp - 1);
}

//switch
void reverse(char *begin, char *end)
{
	char temp;
	while (begin < end)
	{
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}
