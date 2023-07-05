/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moalgafr <moalgafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:50:47 by moalgafr          #+#    #+#             */
/*   Updated: 2023/06/25 12:55:37 by moalgafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countstr(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
		i++;
		if (s[i] != '\0' && s[i] != c)
		{
			count++;
			i++;
		}
		while (s[i] != '\0' && s[i] != c)
		i++;
	}
	return (count);
}

int	ft_spliter(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	i++;
	return (i);
}

char	*ft_word(const char *s, char c)
{
	int		size;
	int		i;
	char	*word;

	i = 0;
	size = ft_spliter(s, c);
	word = (char *)malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	while (i < size)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	char	*s1;
	char	**str;

	s1 = (char *)s;
	if (!s)
		return (NULL);
	i = 0;
	str = (char **) malloc(sizeof(char *) * (ft_countstr(s, c) + 1));
	if (!str)
		return (NULL);
	while (*s1 != '\0')
	{
		while (*s1 != '\0' && *s1 == c)
			s1++;
		if (*s1 != '\0')
		{
			str[i] = ft_word(s1, c);
			i++;
		}
		while (*s1 != '\0' && *s1 != c)
		s1++;
	}
	str[i] = NULL;
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
