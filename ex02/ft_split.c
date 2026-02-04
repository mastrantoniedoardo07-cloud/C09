/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emastran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:02:50 by emastran          #+#    #+#             */
/*   Updated: 2026/02/04 12:24:41 by emastran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_substrings(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && check(str[i], charset))
			i++;
		if (str[i] && !check(str[i], charset))
		{
			count++;
			while (str[i] && !check(str[i], charset))
				i++;
		}
	}
	return (count);
}

char	*copy_substring(char *str, int start, int len)
{
	char	*sub;
	int		k;

	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	k = 0;
	while (k < len)
	{
		sub[k] = str[start + k];
		k++;
	}
	sub[k] = '\0';
	return (sub);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;
	int		len;

	result = (char **)malloc(sizeof(char *) * (count_substrings(str, charset) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && check(str[i], charset))
			i++;
		if (str[i] && !check(str[i], charset))
		{
			len = 0;
			while (str[i + len] && !check(str[i + len], charset))
				len++;
			result[j] = copy_substring(str, i, len);
			if (!result[j])
				return (NULL);
			j++;
			i += len;
		}
	}
	result[j] = NULL;
	return (result);
}

/*int	main(void)
{
	char	*str;
	char	*charset;
	char	**res;
	int		i;

	str = "ciao,come.va?oggi";
	charset = ",.?";
	res = ft_split(str, charset);
	i = 0;
	while (res[i])
	{
		printf("[%s]\n", res[i]);
		i++;
	}
	return (0);
}*/
