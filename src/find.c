#include "lib/find.h"
#include <stdlib.h>

int gut(const char *file);

int	isAFile(const char *path)
{
	struct stat dir;

	stat(path, &dir);
	return (S_ISREG(dir.st_mode));
}

int isASymlink(const char *path)
{
	struct stat dir;
    lstat (path, &dir);
    return (S_ISLNK(dir.st_mode));
}

int	isADir(const char *path)
{
	struct stat dir;
	stat(path, &dir);
	return (S_ISDIR(dir.st_mode));
}

void	find_file(char *paths)
{
	char *UnallowDir[] = {"//dev", "//proc"};
	for (int i = 0; i < 2; i++)
		if (strcmp(paths, UnallowDir[i]) == 0)
			return;
	struct dirent *dir = NULL;
	char filepath[512];
	DIR *path = opendir(paths);
	if (path)
	{
		while ((dir = readdir(path)) != NULL)
		{
			if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
				continue;
			snprintf(filepath, sizeof(filepath), "%s/%s", paths, dir->d_name);
			if (isADir(filepath) == 1 && isAFile(filepath) == 0 && isASymlink(filepath) == 0)
			{
				if ((strcmp(dir->d_name, ".") != 0) && (strcmp(dir->d_name, "..")) != 0)
				{
					find_file(filepath);
				}
			}
			else if (isADir(filepath) == 0 && isAFile(filepath) == 1 && isASymlink(filepath) == 0)
			{
				//printf("%s\n", filepath);
				gut(filepath);
			}
		}
		closedir(path);
	}
}
