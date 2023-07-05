/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 01:36:10 by moalgafr          #+#    #+#             */
/*   Updated: 2023/07/03 02:54:57 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# define STACK_A 1
# define STACK_B 2
# define NONE 0
# define ERROR -1

typedef struct s_data
{
	int		*stack_a;
	int		*stack_b;
	int		a_count;
	int		b_count;
	int		*input;
	int		*copy;
	char	**list;
	char	*str_temp;
	char	*values;
	char	**str_values;
	int		top;
	int		*stack_temp;
	long long		res;
	int		sign;
	int	i;
}		t_data;

// operation:
void	rotate(int *stack, int *count, int code);
void	rotate_a_and_b(t_data *data, int code);
void	rev_rotate(t_data *data, int code);
void	rev_rotate_ab(t_data *data, int code);
void	swap(int *stack, int code);
void	swap_ab(t_data *data);
void	push_b(t_data *data);
void	push_a(t_data *data);
void	reduce_stackA(t_data *data);
void	reduce_stackB(t_data *data);


// error handling:
int		ft_check_args(int ac, char **av, t_data *data);
void	check_repeat(t_data *data);
int		is_all_digit(char *s);
int		err(char *str);
void	exit_free_err2(t_data *data);
void	exit_free_err(t_data *data);
// int     ft_count(const char *str);
int		array_sorted_or_not2(t_data *data);
int		array_sorted_or_not(t_data *data);
void	ft_error(t_data *data);
int		is_digit2(char *str, int i);
int		ft_isdigit_space(char *str);
void	error_checks(t_data *data);
void	empty_arg_error(void);
void	free_all(t_data *data);

//Uitls:
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		ft_isdigit(int c);
void	*ft_memset(void *dest, int c, size_t len);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str, t_data *data);
char	*ft_strjoin(char const *s1, char const *s2);

//filimg the stack:
void	get_args(int argc, char **argv, t_data *data);
void	get_arg_num(t_data *data);
void	fill_stack(t_data *data);
void	put_num_to_stackA(int ac, char **av, t_data *data);
void	fill_input_unsorted(t_data *data);
void	fill_copy_sorted(t_data *data);

//algorithm:
void	sort_three_numbers(t_data *data);
void	tag_index(t_data *data);
void	fill_radix_stack_a(t_data *data);
void	sort_large_stack(t_data *data);
void	sort_small_stack(t_data *data);
void	sort_three_numbers(t_data *data);
void	sort_four(t_data *data);
void	sort_five(t_data *data);
void	insertion_sort(t_data *data);

#endif