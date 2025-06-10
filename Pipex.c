/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:56:12 by amarti            #+#    #+#             */
/*   Updated: 2025/06/10 18:53:18 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

char *get_cmd_path(char *cmd, char **envp)
{
	char	*path;
	char	**array_paths;
	char	*full_path;
	char	*temp;
	int		i;

	i = 0;
	path = find_path_in_env(envp);
	if (!path)
		return (NULL);
	array_paths = split_path(path);
	if (!array_paths)
		return (NULL);
	while(array_paths[i])
	{
		temp = ft_strjoin(array_paths[i], "/");
		full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free_array(array_paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_array(array_paths);
	return (NULL);
}

int	main(int argc, char **argv, char** envp)
{
	int	infile_fd;
	int	outfile_fd;
	int	pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	{
		printf("usage : ./pipex infile cmd1 cmd2 outfile\n");
		return (1);
	}
	infile_fd = open_infile(argv[1]);
	outfile_fd = open_outfile(argv[4]);
	if(pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork");
		return (1);
	}
	if (pid1 == 0)
		child_process_1(pipefd, infile_fd, argv[2], envp);
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("fork");
		return (1);
	}
		if (pid2 == 0)
		child_process_2(pipefd, outfile_fd, argv[3], envp);
	close(infile_fd);
	close(outfile_fd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return (0);
}
