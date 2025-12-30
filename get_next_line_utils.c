/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhammou <khhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:42:37 by khhammou          #+#    #+#             */
/*   Updated: 2025/12/14 01:18:19 by khhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strjoin(char *buf, char *stash)
{
	int		len_buf;
	int		len_stash;
	char	*joined;
	char	*start;
	char	*st_stash;

	if (!buf)
		return (NULL);
	len_buf = ft_strlen(buf);
	len_stash = ft_strlen(stash);
	st_stash = stash;
	joined = malloc(len_buf + len_stash + 1);
	if (!joined)
		return (NULL);
	joined[len_buf + len_stash] = '\0';
	start = joined;
	if (stash != NULL)
		while (*stash != '\0')
			*joined++ = *stash++;
	while (*buf)
		*joined++ = *buf++;
	free(st_stash);
	return (start);
}

int	ft_extracter(char *stash)
{
	int		i;

	if (!stash)
		return (-1);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_update_stash(char *stash)
{
	int		end;
	int		len;
	int		i;
	char	*new;
	char	*start;

	i = 0;
	end = ft_extracter(stash);
	if (end == -1)
	{
		free(stash);
		return (NULL);
	}
	len = ft_strlen(stash) - (end + 1);
	new = malloc(len + 1);
	start = new;
	while (stash[end + 1] != '\0')
	{
		new[i] = stash[end + 1];
		i++;
		end++;
	}
	new[i] = '\0';
	free(stash);
	return (start);
}

char	*ft_extract_line(char *stash)
{
	int		end;
	char	*line;
	char	*start;
	int		i;
	int		len;

	i = 0;
	if (!stash)
		return (NULL);
	end = ft_extracter(stash);
	if (end == -1)
		len = ft_strlen(stash);
	else
		len = end + 1;
	line = malloc (len + 1);
	if (!line)
		return (NULL);
	start = line;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (start);
}
