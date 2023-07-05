/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:16:22 by moalgafr          #+#    #+#             */
/*   Updated: 2023/07/02 22:01:59 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_stack_a(t_data *data)
{
	int	i;

	data->stack_temp = (int *)malloc(sizeof(int) * (data->a_count));
	data->top = 0;
	while (data->top < (data->a_count))
	{
		data->stack_temp[data->top] = data->stack_a[data->top];
		data->top++;
	}
	free(data->stack_a);
	data->stack_a = (int *)malloc(sizeof(int) * (data->a_count + 1));
	if (!data->stack_a)
		return ;
	data->top = 0;
	i = 0;
	data->stack_a[data->top++] = data->stack_b[0];
	while (data->top < (data->a_count + 1))
	{
		data->stack_a[data->top] = data->stack_temp[i];
		data->top++;
		i++;
	}
	free(data->stack_temp);
}

static void	reduce_stack_b(t_data *data)
{
	int	j;

	data->stack_temp = (int *)malloc(sizeof(int) * data->b_count);
	data->top = 0;
	while (data->top < (data->b_count))
	{
		data->stack_temp[data->top] = data->stack_b[data->top];
		data->top++;
	}
	free(data->stack_b);
	data->stack_b = (int *)malloc(sizeof(int) * (data->b_count - 1));
	if (!data->stack_b)
		return ;
	data->b_count--;
	data->top--;
	j = 0;
	while (j < data->b_count && data->top > 0)
	{
		data->stack_b[data->top - 1] = data->stack_temp[data->top];
		data->top--;
		j++;
	}
	free(data->stack_temp);
}

void	push_a(t_data *data)
{
	data->top = 0;
	if (data->a_count == 0)
	{
		data->stack_a = (int *)malloc(sizeof(int));
		if (!data->stack_a)
			return ;
		data->stack_a[data->top] = data->stack_b[data->top];
		reduce_stack_b(data);
	}
	else
	{
		copy_stack_a(data);
		reduce_stack_b(data);
	}
	data->a_count++;
	write(1, "pa\n", 3);
}
