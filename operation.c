/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:10:30 by moalgafr          #+#    #+#             */
/*   Updated: 2023/07/02 21:57:49 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *stack, int *count, int code)
{
	int	i;
	int	j;
	int	temp_count;
	int	temp;

	i = 1;
	j = 0;
	temp_count = *count - 1;
	temp = 0;
	temp = stack[0];
	while ((temp_count) > 0)
	{
		stack[j++] = stack[i++];
		temp_count--;
	}
	stack[j] = temp;
	if (code == 1)
		write(1, "ra\n", 3);
	else if (code == 2)
		write(1, "rb\n", 3);
}

void	rev_rotate(t_data *data, int code)
{
	int	temp_count;
	int	temp;

	temp_count = data->a_count - 1;
	temp = 0;
	temp = data->stack_a[temp_count];
	while ((temp_count) > 0)
	{
		data->stack_a[temp_count] = data->stack_a[temp_count - 1];
		temp_count--;
	}
	data->stack_a[0] = temp;
	if (code == 1)
		write(1, "rra\n", 4);
	else if (code == 2)
		write(1, "rrb\n", 4);
}

void	swap(int *stack, int code)
{
	int	temp;
	int	top;

	top = 0;
	temp = stack[top + 1];
	stack[top + 1] = stack[top];
	stack[top] = temp;
	if (code == 1)
		write(1, "sa\n", 3);
	else if (code == 2)
		write(1, "sb\n", 3);
}

void	rotate_a_and_b(t_data *data, int code)
{
	rotate(data->stack_a, &data->a_count, NONE);
	rotate(data->stack_a, &data->a_count, NONE);
	if (code == NONE)
		write(1, "rr\n", 3);
}

void	rev_rotate_ab(t_data *data, int code)
{
	rev_rotate(data, NONE);
	rev_rotate(data, NONE);
	if (code == NONE)
		write(1, "rrr\n", 4);
}
