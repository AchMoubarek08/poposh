/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:36:57 by amoubare          #+#    #+#             */
/*   Updated: 2022/04/08 22:04:29 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_pile st)
{
	if (stack_vide(st))
	{
		printf("Rien a afficher, la t_pile est vide.\n");
		return ;
	}
	while (!stack_vide(st))
	{
		printf("[%d]\n", st->i);
		st = st->next;
	}
}

void	swap(int *y, int *z)
{
	int	temp;

	temp = *y;
	*y = *z;
	*z = temp;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

t_pile	new_pile(void)
{
	return (NULL);
}

t_bool	stack_vide(t_pile st)
{
	if (st == NULL)
		return (true);
	return (false);
}
