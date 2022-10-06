#include "monty.h"

/**
 * _strtok - tokenizes a string
 * @str: the string
 * @delims: delimeters
 * Return: pointer to tokens
 */
char **_strtok(char *str, char *delims)
{
	int wc = 0;
	char **words = NULL;
	int len, i = 0, j = 0;

	wc = word_count(str, delims);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	while (i < wc)
	{
		len = word_len(str, delims);
		words[i] = malloc((len + 1) * sizeof(char));
		if (words[i] == NULL)
			return (NULL);
		str = get_word(str, delims);
		for (j = 0; j < len; j++)
			words[i][j] = *str++;
		words[i][j] = '\0';
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * get_word - gets word from string
 * @str: the string to be checked
 * @delims: delimeters
 * Return: pointer to beggining of the word
 */
char *get_word(char *str, char *delims)
{
	while (*(str) != '\0')
	{
		if (check_delim(*str, delims))
		{
			str++;
			continue;
		}
		break;
	}
	return (str);
}

/**
 * word_count - counts number of words in a string
 * @str: the string to be checked
 * @delims: delimeters
 * Return: number of words
 */
int word_count(char *str, char *delims)
{
	int i, wc = 0;
	bool status = true;

	for (i = 0; str[i]; i++)
	{
		if (check_delim(str[i], delims))
			status = true;
		else if (status == true)
		{
			wc++;
			status = false;
		}
	}
	return (wc);
}

/**
 * check_delim - checks if a character is a delimeter
 * @c: the character to be checked
 * @delims: the delimeters
 * Return: True if char is delimeter, else false
 */
bool check_delim(char c, char *delims)
{
	int i;

	for (i = 0; delims[i]; i++)
	{
		if (delims[i] == c)
			return (true);
	}
	return (false);
}

/**
 * word_len - returns leght of given word
 * @str: the word to be checked
 * @delims: delimeters
 * Return: length of the word
 */
int word_len(char *str, char *delims)
{
	int i, len = 0;

	for (i = 0; check_delim(str[i], delims); i++)
		continue;
	for (; !check_delim(str[i], delims) && str[i] != '\0'; i++)
		len++;

	return (len);
}
