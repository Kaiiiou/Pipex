/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:55:29 by amarti            #+#    #+#             */
/*   Updated: 2025/06/09 16:50:02 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// # include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
#include <fcntl.h>

int		open_infile(char *filename);
int		open_outfile(char *filename);
char	*find_path_in_env(char **envp);
char	**split_path_dirs(char *path_str);
char	*get_cmd_path(char *cmd, char **envp);
