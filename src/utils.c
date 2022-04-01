/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:21:07 by aanghel          #+#    #+#             */
/*   Updated: 2022/03/25 01:29:17 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	let;

	i = 0;
	let = c;
	while (s[i] != let && s[i] != '\0')
	{
		i++;
	}
	if (s[i] == let)
	{
		return ((char *)s + i);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		c;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char)
			* (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (str == NULL)
		return (0);
	i = 0;
	c = 0;
	while (s1[c] != '\0')
	{
		str[c] = s1[c];
		c++;
	}
	while (s2[i] != '\0')
		str[c++] = s2[i++];
	str[c] = '\0';
	free(s1);
	return (str);
}

size_t	find_newline(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\n')
		i++;
	i++;
	return (i);
}

int	ft_exit(void)
{
	exit(0);
	return (0);
}
