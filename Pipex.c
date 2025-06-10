/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:56:12 by amarti            #+#    #+#             */
/*   Updated: 2025/06/09 16:49:49 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"



int	main(int argc, char **argv)
{
	int	infile_fd;
	int	outfile_fd;

	if (argc != 5)
	{
		printf("usage : ./pipex infile cmd1 cmd2 outfile\n");
		return (1);
	}

	infile_fd = open_infile(argv[1]);
	outfile_fd = open_outfile(argv[4]);

	printf("infile fd: %d\n", infile_fd);
	printf("outfile fd: %d\n", outfile_fd);

	close(infile_fd);
	close(outfile_fd);

	return (0);
}