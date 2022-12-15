#include "monty.h"

/**
 * main - entry point, starts monty interpreter
 * @argc: count of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	parsefile(file);
	return (EXIT_SUCCESS);
}
