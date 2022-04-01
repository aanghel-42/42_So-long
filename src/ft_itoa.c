/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:01:51 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/25 03:07:20 by aanghel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		sign;
	int		nlen;

	if (n < 0)
		sign = 1;
	else
		sign = 0;
	nlen = ft_len(n);
	s = (char *)malloc(sizeof(char) * nlen + sign + 1);
	if (s == NULL)
		return (NULL);
	s = s + nlen + sign;
	*s = '\0';
	if (!n)
		*--s = '0';
	while (n != 0)
	{
		*--s = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (sign == 1)
		*--s = '-';
	return (s);
}
