/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:45:15 by amoubare          #+#    #+#             */
/*   Updated: 2022/04/12 01:39:30 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	rrr(t_pile *a, t_pile *b, char *str)
{
	reverse_rotate(a, "");
	reverse_rotate(b, "");
	ft_putstr(str);
}

void	nadi(char **stock, char **ligne)
{
	char	*temp;
	int		x;

	x = ft_int_strchr(*stock, '\n') + 1;
	*ligne = ft_substr(*stock, 0, x);
	temp = *stock;
	*stock = ft_substr(*stock, x, ft_strlen(*stock));
	free(temp);
}

char	*ft_frree(char **lost)
{
	if (*lost)
		free(*lost);
	*lost = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			i;
	char		buff[5];
	char		*ligne;
	static char	*stock;
	char		*temp;

	while (ft_int_strchr(stock, '\n') == -1)
	{
		i = read(fd, buff, 4);
		if (i == 0 || i == -1)
		{
			if (stock && stock[0] == '\0')
				ft_frree(&stock);
			ligne = stock;
			stock = NULL;
			return (ligne);
		}
		buff[i] = '\0';
		temp = stock;
		stock = ft_strjoin(stock, buff);
		ft_frree(&temp);
	}
	nadi(&stock, &ligne);
	return (ligne);
}
