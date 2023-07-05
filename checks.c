/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 01:36:42 by moalgafr          #+#    #+#             */
/*   Updated: 2023/07/03 00:18:28 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_repeat(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < (data->a_count - 1))
	{
		j = i + 1;
		while (j < data->a_count)
		{
			if (data->input[i] == data->input[j])
			{
				write (2, "Error\n", 6);
				free_all(data);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

// int	check_zero(char *str, char *s2)
// {
// 	if (ft_strlen(str) != ft_strlen(s2))
// 		return (1);
// 	while (*str && *s2)
// 	{
// 		if (*str != *s2)
// 			return (0);
// 		str++;
// 		s2++;
// 	}
// 	if ((!*str && !*s2))
// 		return (1);
// 	return (0);
// }

// int	is_all_digit(char *s)
// {
// 	while (*s && (*s == ' ' || *s == '\t'))
// 		s++;
// 	if (*s == '-' || *s == '+')
// 		s++;
// 	while (*s)
// 	{
// 		if (!ft_isdigit(*s))
// 			return (ERROR);
// 		s++;
// 	}
// 	return (1);
// }

// int	ft_count(const char *str)
// {
// 	char	**list;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	list = ft_split(str, ' ');
// 	while (list[i])
// 	{
// 		if (is_all_digit(list[i]) == ERROR)
// 			return (ERROR);
// 		i++;
// 	}
// 	while (list[j])
// 		free(list[j++]);
// 	free(list);
// 	return (i);
// }

// int	ft_check_args(int ac, char **av, t_data *data)
// {
// 	int		i;
// 	int		count;

// 	i = 1;
// 	count = 0;
// 	while (av[i])
// 	{
// 		count += ft_count(av[i]);
// 		if (ft_count(av[i]) == ERROR)
// 			return (ERROR);
// 		i++;
// 	}
// 	data->a_count = count;
// 	return (1);
// }
