/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emastran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:02:50 by emastran          #+#    #+#             */
/*   Updated: 2026/02/03 13:25:05 by emastran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int check(char *str, char *charset)
{
	int i;

	i = 0;
	while(*charset)
	{
		if(str[i] == charset[i])
			return (1);
		i++;
	}
	return (0);
}
int count(char *str)
{
	int	i;
	int	count;

	while(str[i])
	{
		while(str[i] && check(str[i], charset))
			i++;
		if (str[i] && !check(str[i], charset))
			count++;
		while (str[i] && !check(str[i], charset))
			i++;
	}
	return (count);
}
char **ft_split(char *str, char *charset)
{
	
}
