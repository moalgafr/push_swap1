/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:33:47 by moalgafr          #+#    #+#             */
/*   Updated: 2023/07/02 21:51:52 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	maximum_bits(t_data *data)
{
	int	max_num;
	int	max_bits;

	max_num = data->a_count - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
	{
		++max_bits;
	}
	return (max_bits);
}

void	sort_large_stack(t_data *data)
{
	int	size;
	int	i;
	int	j;
	int	num;

	data->top = data->stack_a[0];
	size = data->a_count;
	i = 0;
	while (i < maximum_bits(data))
	{
		j = 0;
		while (j++ < size)
		{
			num = data->stack_a[data->top];
			if (((num >> i) & 1) == 1)
				rotate(data->stack_a, &data->a_count, STACK_A);
			else
				push_b(data);
		}
		while (data->b_count != 0)
			push_a(data);
		i++;
	}
}
