#include "shell.h"

/****/
void removeLeadingSpaces(char *str) {
	int i = 0;
	int j = 0;

	while (str[i] == ' ' || str[i] == '\t') {
		i++;
	}

	while (str[i] != '\0') {
		str[j] = str[i];
		i++;
		j++;
	}

	str[j] = '\0';
}

int execute_multi_command(memory *m)
{
	char **commands = arr_of_tokens(m->command, ";");
	char **s = commands;
	m->commands = commands;
	m->current_command = m->command;
	while (*s)
	{
		removeLeadingSpaces(*s);
		m->command = (*s);
		execute_commandV(m);
		s++;
	}
	m->command = m->current_command;
	free_array_of_strings(commands);

	return (0);
}