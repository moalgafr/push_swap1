/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:26:32 by moalgafr          #+#    #+#             */
/*   Updated: 2023/07/03 03:00:21 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_free_err2(t_data *data)
{
	// free(data->input);
	// free(data->copy);
	// free(data);
	write (2, "Error\n", 6);
	free_all(data);
	exit (0);
}

void	ft_error(t_data *data)
{
	int	j;

	j = 0;
	if (!data)
	{
		write (2, "Error\n", 6);
		exit(0);
	}
	write (2, "Error\n", 6);
	while (data->str_values[j])
	{
		free(data->str_values[j]);
		j++;
	}
	free(data->str_values);
	free(data->input);
	free(data->copy);
	free(data->stack_a);
	free(data);
	exit (0);
	return ;
}

void	error_checks(t_data *data)
{
	if (ft_isdigit_space(data->values) == 1)
	{
		write (2, "Error\n", 6);
		exit_free_err2(data);
	}
}

void	empty_arg_error(void)
{
	write (2, "Error\n", 6);
	exit (0);
}

void	free_all(t_data *data)
{
	int	j;

	j = 0;
	while (data->str_values[j])
	{
		free(data->str_values[j++]);
	}
	free(data->str_values);
	free(data->values);
	free(data->stack_a);
	free(data->stack_b);
	free(data->copy);
	free(data->input);
	free(data);
}
