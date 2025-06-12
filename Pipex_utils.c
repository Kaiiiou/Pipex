/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:31:59 by amarti            #+#    #+#             */
/*   Updated: 2025/06/12 11:19:50 by amarti           ###   ########.fr       */
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

char	*find_path_in_env(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	**split_path(char *path_str)
{
	if (!path_str)
		return (NULL);
	return (ft_split(path_str, ':'));
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free (array);
}
