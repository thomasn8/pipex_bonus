/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:44:55 by tnanchen          #+#    #+#             */
/*   Updated: 2021/11/17 15:58:46 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(const char *str, char c)
{
	int	i;
	int	switcher;

	i = 0;
	switcher = 0;
	while (*str)
	{
		if (*str != c && switcher == 0)
		{
			switcher = 1;
			i++;
		}
		else if (*str == c)
			switcher = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int word_n, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	if (start == end && !word_n)
		return (NULL);
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		word[i++] = str[start++];
	word[i] = 0;
	return (word);
}

static char	**words_split(char **tab, char const *s, char c)
{
	int	i;
	int	start;
	int	end;
	int	word;

	i = 0;
	start = 0;
	end = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		end = i;
		if (!s[i] && start == end && word > 0)
			return (tab);
		tab[word] = word_dup(s, word, start, end);
		word++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;

	if (!s)
		return (0);
	words = words_count(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (0);
	if (!(words_split(tab, s, c)))
	{
		free(tab);
		return (NULL);
	}
	tab[words] = NULL;
	return (tab);
}
