/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:55:29 by amarti            #+#    #+#             */
/*   Updated: 2025/06/12 11:16:55 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

int		open_infile(char *filename);
int		open_outfile(char *filename);
char	*find_path_in_env(char **envp);
char	**split_path(char *path_str);
char	*get_cmd_path(char *cmd, char **envp);
void	free_array(char **array);
char	**parse_cmd(char *cmd_str);
void	child_process_1(int *pipefd, char *infile_nme, char *cmd, char **envp);
void	child_process_2(int *pipefd, char *outfile_nme, char *cmd, char **envp);
