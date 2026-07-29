#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

#define BUF_SIZE 1024

/**
 * open_source - opens the source file for reading
 * @filename: the name of the file to open
 *
 * Return: the file descriptor
 */
int open_source(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_dest - opens (or creates) the destination file for writing
 * @filename: the name of the file to open
 *
 * Return: the file descriptor
 */
int open_dest(char *filename)
{
	int fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (fd);
}

/**
 * copy_loop - copies data from one file descriptor to another
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @argv: program arguments, used for error messages
 *
 * Return: Nothing.
 */
void copy_loop(int fd_from, int fd_to, char *argv[])
{
	char buf[BUF_SIZE];
	ssize_t r, w;

	r = read(fd_from, buf, BUF_SIZE);
	while (r > 0)
	{
		w = write(fd_to, buf, r);
		if (w == -1 || w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
		r = read(fd_from, buf, BUF_SIZE);
	}
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
}

/**
 * close_fd - closes a file descriptor, exiting on failure
 * @fd: the file descriptor to close
 *
 * Return: Nothing.
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_source(argv[1]);
	fd_to = open_dest(argv[2]);
	copy_loop(fd_from, fd_to, argv);
	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
