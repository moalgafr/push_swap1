/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:36:51 by moalgafr          #+#    #+#             */
/*   Updated: 2023/07/03 03:01:17 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_data *data)
{
	tag_index(data);
	fill_radix_stack_a(data);
	sort_large_stack(data);
}

void	commence(t_data *data)
{
	get_arg_num(data);
	fill_input_unsorted(data);
	fill_copy_sorted(data);
	check_repeat(data);
	if (array_sorted_or_not(data) == 0)
		exit_free_err(data);
	if (data->a_count > 5)
		radix_sort(data);
	else
	{
		fill_stack(data);
		sort_small_stack(data);
	}
}

void	get_args(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	data->values = ft_strdup("");
	while (i < argc)
	{
		data->str_temp = data->values;
		data->values = ft_strjoin(data->str_temp, argv[i]);
		free (data->str_temp);
		data->str_temp = NULL;
		data->str_temp = data->values;
		data->values = ft_strjoin(data->str_temp, " ");
		free (data->str_temp);
		data->str_temp = NULL;
		i++;
	}
	error_checks(data);
	data->str_values = ft_split(data->values, ' ');
	if (data->str_values[1] == NULL)
		return ;
	
	commence(data);
}

int	is_valid_num(char **av)
{
	int	i;
	int	j;

	j = 0;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if ((av[j][i] == '+' || av[j][i] == '-'))
				i++;
			else if (av[j][i] >= '0' && av[j][i] <= '9')
				i++;
			else if (((av[j][i] >= 9 && av[j][i] <= 13) || av[j][i] == 32))
				i++;
			else
				return (0);
		}
		j++;
	}
	return (1);
}

void ft_error1(char **split) 
{
	int j;

	j = 0;
	write (2, "Error\n", 6);
	if (split) {
		while (split[j])
		{
			free(split[j]);
			j++;
		}
	}
	free(split);
	exit(1);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	if (ac < 2)
		return (0);
	i = 0;
	while (ac == 2 && av[1][i] != 0 && av[1][i] == ' ')
		++i;
	if (ac == 2 && av[1][i] == 0)
		ft_error1(NULL);
	if(!is_valid_num(av + 1))
		ft_error1(NULL);
	i = 0;
	while (i < ac)
	{
		if (av[i][0] == 0)
			empty_arg_error();
		i++;
	}
	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (1);
	get_args(ac, av, data);
	free_all(data);
}
