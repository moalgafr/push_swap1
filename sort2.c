/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:46:13 by moalgafr          #+#    #+#             */
/*   Updated: 2023/07/03 02:55:33 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_input_unsorted(t_data *data)
{
	int	j;
	int	count;

	data->input = (int *)malloc(sizeof(int) * data->a_count);
	if (!data->input)
		return ;
	j = 0;
	count = data->a_count;
	while (count > 0)
	{
		data->input[j] = ft_atoi(data->str_values[j], data);
		--count;
		j++;
	}
}

void	fill_copy_sorted(t_data *data)
{
	int	j;
	int	temp_count;

	data->copy = (int *)malloc(sizeof(int) * data->a_count);
	if (!data->copy)
		return ;
	j = 0;
	temp_count = data->a_count;
	if (!data->stack_a)
	{
		while (temp_count > 0)
		{	
			data->copy[j++] = ft_atoi(data->str_values[--temp_count], data);
		}
	}
	insertion_sort(data);
}

void	sort_small_stack(t_data *data)
{
	if (data->a_count == 2)
		swap(data->stack_a, STACK_A);
	if (data->a_count == 3)
		sort_three_numbers(data);
	if (data->a_count == 4)
		sort_four(data);
	if (data->a_count == 5)
		sort_five(data);
}
