/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:56:06 by amarti            #+#    #+#             */
/*   Updated: 2025/06/10 16:10:52 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

char	**parse_cmd(char *cmd_str)
{
	if (!cmd_str)
		return(NULL);
	return(ft_split(cmd_str, ' '));
}

void	execute_cmd(char *cmd_str, char **envp)
{
	char	**cmdp;
	char	*path;

	if (!cmd_str || !envp)
		return ;
	
	cmdp = parse_cmd(cmd_str);
	if (!cmdp)
		return ;
	path = get_cmd_path(cmdp[0], envp);
	if (!path)
	{
		free_array(cmdp);
		perror("command not found");
		exit(1);
	}
	execve(path, cmdp, envp);
	perror("execve failed");
	exit(1);
}

void	child_process_1(int *pipefd, int infile_fd, char *cmd, char **envp)
{
	dup2(infile_fd, 0);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	close(pipefd[1]);
	execute_cmd(cmd, envp);
}

void child_process_2(int *pipefd, int outfile_fd, char *cmd, char **envp)
{
	dup2(pipefd[0], 0);
	dup2(outfile_fd, 1);
	close(pipefd[0]);
	close(pipefd[1]);
	execute_cmd(cmd, envp);
}