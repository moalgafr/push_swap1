/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 00:02:01 by moalgafr          #+#    #+#             */
/*   Updated: 2023/07/03 01:18:43 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void   put_num_to_stackA(int ac, char **av, t_data *data)
// {
// 	char	**tmp;
// 	int		i;
// 	int		j;
// 	int		l;

// 	i = 0;
// 	j = 0;
// 	l = 0;
// 	data->stack_a = ft_calloc(sizeof(int), data->a_count + 1);
// 	data->stack_b = ft_calloc(sizeof(int), data->a_count + 1);
// 	while (av[i + 1])
// 	{
// 		tmp = ft_split(av[i + 1], ' ');
// 		j = 0;
// 		while (tmp[j])
// 		{
// 			data->stack_a[l] = ft_atoi(tmp[j], data);
// 			l++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	j = 0;
// 	while (tmp[j])
// 		free(tmp[j++]);
// 	free(tmp);

// }
void	exit_free_err(t_data *data)
{
	// int	j;

	// j = 0;
	free_all(data);
	// while (data->str_values[j])
	// {
	// 	free(data->str_values[j]);
	// 	j++;
	// }
	// free(data->str_values);
	// free(data);
	exit (0);
}

void	fill_stack(t_data *data)
{
	int	j;
	int	count;

	data->stack_a = (int *)malloc(sizeof(int) * data->a_count);
	if (!data->stack_a)
		return ;
	j = 0;
	count = data->a_count;
	while (count > 0)
	{
		data->stack_a[j] = ft_atoi(data->str_values[j], data);
		--count;
		j++;
	}
}

int	is_digit2(char *str, int i)
{
	bool	minus;
	bool	plus;

	minus = false;
	plus = false;
	if (str[i] == '-' && minus == false)
			minus = true;
	else if (str[i] == '-' && minus == true)
		return (1);
	else
		minus = false;
	if (str[i] == '+' && plus == false)
		plus = true;
	else if (str[i] == '+' && plus == true)
		return (1);
	else
		plus = false;
	if (str[i] == '+' && str[i + 1] == '-')
		return (1);
	else if (str[i] == '-' && str[i + 1] == '+')
		return (1);
	if (!((str[i] >= 48 && str[i] <= 57) || str[i] == 32
			|| str[i] == '-' || str[i] == '+'))
		return (1);
	return (0);
}

int	ft_isdigit_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		is_digit2(str, i);
		i++;
	}
	return (0);
}
