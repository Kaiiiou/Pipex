/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai-iou <kai-iou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:56:06 by amarti            #+#    #+#             */
/*   Updated: 2025/06/13 20:00:57 by kai-iou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

char	**parse_cmd(char *cmd_str)
{
	if (!cmd_str)
		return (NULL);
	return (ft_split(cmd_str, ' '));
}

void	execute_cmd(char *cmd_str, char **envp)
{
	char	**cmdp;
	char	*path;

	if (!cmd_str || cmd_str[0] == '\0' || !envp)
		exit(1);
	cmdp = parse_cmd(cmd_str);
	if (!cmdp)
		exit(1);
	if (access(cmdp[0], F_OK | X_OK) == 0)
		path = ft_strdup(cmdp[0]);
	else
		path = get_cmd_path(cmdp[0], envp);
	if (!path)
	{
		free_array(cmdp);
		ft_putstr_fd("command not found\n", 2);
		exit(1);
	}
	if (execve(path, cmdp, envp) == -1)
	{
		perror("execve failed");
		free(path);
		free_array(cmdp);
		exit(1);
	}
}

void	child_process_1(int *pipefd, char *infile_nme, char *cmd, char **envp)
{
	int	infile_fd;

	infile_fd = open_infile(infile_nme);
	if (infile_fd == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		exit(1);
	}
	dup2(infile_fd, 0);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	close(pipefd[1]);
	close(infile_fd);
	execute_cmd(cmd, envp);
}

void	child_process_2(int *pipefd, char *outfile_nme, char *cmd, char **envp)
{
	int	outfile_fd;

	outfile_fd = open_outfile(outfile_nme);
	if (outfile_fd == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		exit(1);
	}
	dup2(pipefd[0], 0);
	dup2(outfile_fd, 1);
	close(pipefd[0]);
	close(pipefd[1]);
	close(outfile_fd);
	execute_cmd(cmd, envp);
}
