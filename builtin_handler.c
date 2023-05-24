#include "shell.h"

/**
 * handle_exit - handles exit command.
 * @m: a struct.
 * Return: void.
 */

void handle_exit(struct memory *m)
{
	free_array_of_strings(m->agv);
	free(m->command);
	exit(m->last_exit_code);
}

/**
 * handle_env - handles the environments.
 * @m: a struct.
 * Return: void.
 */

void handle_env(struct memory *m)
{
	char **env;

	(void)m;
	env = environ;
	while (*env)
	{
		puts(*env);
		env++;
	}
}
