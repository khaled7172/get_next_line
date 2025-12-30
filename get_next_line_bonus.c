/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 03:52:05 by khhammou          #+#    #+#             */
/*   Updated: 2025/12/28 01:43:06 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*buf;
	char		*output;
	ssize_t		r;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (ft_extracter(stash[fd]) == -1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == 0 || r == -1)
			return (helper(r, fd, stash, buf));
		buf[r] = '\0';
		stash[fd] = ft_strjoin(buf, stash[fd]);
	}
	free(buf);
	output = ft_extract_line(stash[fd]);
	stash[fd] = ft_update_stash(stash[fd]);
	return (output);
}

char	*helper(ssize_t r, int fd, char **stash, char *buf)
{
	char	*output;

	output = NULL;
	if (r == 0 && stash[fd] != NULL && ft_strlen(stash[fd]) > 0)
		output = ft_extract_line(stash[fd]);
	free(buf);
	if (stash[fd] != NULL)
	{
		free(stash[fd]);
		stash[fd] = NULL;
	}
	return (output);
}

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	char	*line1;
// 	char	*line2;

// 	fd1 = open("test1.txt", O_RDONLY);
// 	fd2 = open ("test2.txt", O_RDONLY);
// 	if (fd1 < 0 || fd2 < 0)
// 		return (1);
// 	while (1)
// 	{
// 		line1 = get_next_line(fd1);
// 		line2 = get_next_line(fd2);
// 		if (!line1 && !line2)
// 			break ;
// 		if (line1)
// 		{
// 			printf("FD1: %s\n", line1);
// 			free(line1);
// 		}
// 		if (line2)
// 		{
// 			printf("FD2: %s", line2);
// 			free(line2);
// 		}
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
