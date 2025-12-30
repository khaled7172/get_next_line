/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:42:13 by khhammou          #+#    #+#             */
/*   Updated: 2025/12/30 21:43:03 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*output;
	ssize_t		r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (ft_extracter(stash) == -1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == 0 || r == -1)
			return (helper(r, &stash, buf));
		buf[r] = '\0';
		stash = ft_strjoin(buf, stash);
	}
	free(buf);
	output = ft_extract_line(stash);
	stash = ft_update_stash(stash);
	return (output);
}

char	*helper(ssize_t r, char **stash, char *buf)
{
	char	*output;

	output = NULL;
	if (r == 0 && *stash != NULL && ft_strlen(*stash) > 0)
		output = ft_extract_line(*stash);
	free(buf);
	if (*stash != NULL)
	{
		free(*stash);
		*stash = NULL;
	}
	return (output);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*res;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	res = get_next_line(fd);
// 	while (res)
// 	{
// 		printf("%s", res);
// 		free(res);
// 		res = get_next_line(fd);
// 	}
// 	free(res);
// 	close(fd);
// }
// int	main(void)
// {
// 	char	*res;

// 	res = get_next_line(0);  // 0 is stdin
// 	while (res)
// 	{
// 		printf("%s", res);
// 		free(res);
// 		res = get_next_line(0);
// 	}
// 	return (0);
// }
