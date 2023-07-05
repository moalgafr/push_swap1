/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:21:43 by moalgafr          #+#    #+#             */
/*   Updated: 2023/06/25 18:09:50 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_radix_stack_a(t_data *data)
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
		data->stack_a[j] = data->input[j];
		--count;
		j++;
	}
}

void	tag_index(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->a_count)
	{
		j = 0;
		while (j < data->a_count)
		{
			if (data->input[i] == data->copy[j])
			{
				data->input[i] = j;
				break ;
			}
			++j;
		}
		++i;
	}
}
