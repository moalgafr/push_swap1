/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:01:22 by moalgafr          #+#    #+#             */
/*   Updated: 2023/07/03 02:46:08 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_data *data)
{
	data->res = 0;
	data->sign = 1;
	data->i = 0;
	while (str[data->i] == ' ' || str[data->i] == '\t')
		data->i++;
	if (str[data->i] == '-' || str[data->i] == '+')
	{
		if (str[data->i] == '-')
			data->sign = -1;
		data->i++;
	}
	if (!(str[data->i] >= '0' && str[data->i] <= '9'))
			exit_free_err2(data);
	while (str[data->i] >= '0' && str[data->i] <= '9')
	{
		data->res = data->res * 10 + str[data->i] - '0';
		if (data->res > INT_MAX || data->res < INT_MIN)
			exit_free_err2(data);
		data->i++;
	}
	if (!((str[data->i] >= '0' && str[data->i] <= '9')
			|| (str[data->i] == ' ' || str[data->i] == '\0')))
			exit_free_err2(data);
	return ((int)(data->res * data->sign));
}


void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (count > INT_MAX || size > INT_MAX || (size * count) > INT_MAX)
		return (NULL);
	res = malloc(count * size);
	if (!res)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)dest)[i] = c;
		i++;
	}
	return (dest);
}
