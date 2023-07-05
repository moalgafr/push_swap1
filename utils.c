/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:24:55 by moalgafr          #+#    #+#             */
/*   Updated: 2023/07/02 23:53:25 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_sorted_or_not(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->a_count)
	{
		if (data->input[i] != data->copy[i])
			return (1);
		i++;
	}
	return (0);
}

int	array_sorted_or_not2(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->a_count)
	{
		if (data->stack_a[i] != data->copy[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s2 && s1)
		return ((char *)s1);
	if (s2 && !s1)
		return ((char *)s2);
	if (!s2 && !s1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	len = 0;
	while (s[len])
	{
	str[len] = s[len];
	len++;
	}
	str[len] = '\0';
	return (str);
}
