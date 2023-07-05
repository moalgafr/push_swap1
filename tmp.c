/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:19:51 by moalgafr          #+#    #+#             */
/*   Updated: 2023/06/30 21:42:53 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// void copy_stack(int *data, int *temp_b, int	count) 
// {
//     int i;

//     i = 1;
//     while (i < count + 1)
//     {
//         temp_b[i] = data[i - 1];
//         i++;
//     }  
// }

// void reduce_stack(t_data *data)
// {
//     int *temp_a;
//     int j;

//     temp_a = (int *)malloc(sizeof(int) * (data->a_count - 1));
//     j = 0; 
//     while (j < data->a_count - 1) 
//     {
//         temp_a[j] = data->stack_a[j + 1];
//         j++;
//     }
//     free(data->stack_a);
//     data->stack_a = temp_a;
//     data->a_count--;
// }
// void	do_push(int	*st_from, int *st_to, int *c_from, int *c_to)
// {
// 	int j;
//     int *temp_b;
//     if (*c_from == 0)
//      return ;
//     if (*c_to > 0)
//     {
//         temp_b = (int *)malloc(sizeof(int) * (*c_to + 2));
//         copy_stack(st_to, temp_b, *c_to);
//         temp_b[0] = st_from[0];
//     } 
//     else 
//     {
//         temp_b = (int *)malloc(sizeof(int));
//         temp_b[0] = st[0];
//     }
//     reduce_stack(data);
//     free(data->stack_b);
//     data->stack_b = temp_b;
//     data->b_count++;
//     write(1, "pb\n", 3);
// }

// void    push(t_data *data, int code) 
// {
// 	if ( code == 1)
// 	{
// 		do_push(data->stack_a, data->stack_b, data->a_count, data->b_count);
// 		write(1, "pb\n", 3);
// 	}
// 	else if ( code == 2)
// 	{
// 		do_push(data->stack_b, data->stack_a, data->b_count, data->a_count);
// 		write(1, "pa\n", 3);
// 	}
// }
