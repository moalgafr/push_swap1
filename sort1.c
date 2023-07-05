/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:53:57 by moalgafr          #+#    #+#             */
/*   Updated: 2023/06/30 21:54:17 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	minimum_pos(t_data *data)
{
	int	i;
	int	position;

	i = 1;
	position = 0;
	while (i < (data->a_count))
	{
		if (data->stack_a[i] < data->stack_a[position])
			position = i;
		i++;
	}
	return (position);
}

void	sort_three_numbers(t_data *data)
{
	if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[0] > data->stack_a[2])
	{
		rotate(data->stack_a, &data->a_count, STACK_A);
	}
	else if (data->stack_a[1] > data->stack_a[0]
		&& data->stack_a[1] > data->stack_a[2])
	{
		rev_rotate(data, STACK_A);
	}
	if (data->stack_a[0] > data->stack_a[1])
	{
		swap(data->stack_a, STACK_A);
	}
}

void	sort_four(t_data *data)
{
	int	min_pos;

	min_pos = minimum_pos(data);
	if (array_sorted_or_not2(data) == 0)
		return ;
	if (min_pos == 1)
		rotate(data->stack_a, &data->a_count, STACK_A);
	else if (min_pos == 2)
	{
		rotate(data->stack_a, &data->a_count, STACK_A);
		rotate(data->stack_a, &data->a_count, STACK_A);
	}
	else if (min_pos == 3)
	{
		rev_rotate(data, STACK_A);
	}
	if (array_sorted_or_not2(data) == 0)
		return ;
	push_b(data);
	sort_three_numbers(data);
	push_a(data);
}

void	sort_five(t_data *data)
{
	int	min_pos;

	min_pos = minimum_pos(data);
	if (array_sorted_or_not2(data) == 0)
		return ;
	if (min_pos == 1)
		rotate(data->stack_a, &data->a_count, STACK_A);
	else if (min_pos == 2)
	{
		rotate(data->stack_a, &data->a_count, STACK_A);
		rotate(data->stack_a, &data->a_count, STACK_A);
	}
	else if (min_pos == 3)
	{
		rev_rotate(data, STACK_A);
		rev_rotate(data, STACK_A);
	}
	else if (min_pos == 4)
		rev_rotate(data, STACK_A);
	if (array_sorted_or_not2(data) == 0)
		return ;
	push_b(data);
	sort_four(data);
	push_a(data);
}

/*
In each step, we take the current element and
compare it with the elements before it, 
shifting the larger elements one position to 
the right until we find the correct position to insert the current element.
*/
void	insertion_sort(t_data *data)
{
	int	temp;
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < data->a_count)
	{
		temp = data->copy[i];
		j = i - 1;
		while (j >= 0 && data->copy[j] > temp)
		{
			data->copy[j + 1] = data->copy[j];
			j--;
		}
		data->copy[j + 1] = temp;
		i++;
	}
}

/*
[8, 3, 5, 2, 9]
[3, 8, 5, 2, 9]
[3, 5, 8, 2, 9]
[2, 3, 5, 8, 9]
*/
