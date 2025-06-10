/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:56:06 by amarti            #+#    #+#             */
/*   Updated: 2025/06/09 16:49:49 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

int	open_infile(char *filename)
{
	int	fd;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror("error open infile");
	return (fd);
}

int	open_outfile(char *filename)
{
	int	fd;
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		perror("error open outfile");
	return (fd);
}

char get_cmd_path(char **cmd, char **envp)
{
	
}