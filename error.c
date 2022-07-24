/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:23:42 by amoubare          #+#    #+#             */
/*   Updated: 2022/04/16 21:44:43 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorttwo(t_pile *a)
{
	if ((*a)->i > (*a)->next->i)
		reverse_rotate(a, "rra\n");
}

void	check_dup(t_pile a)
{
	t_pile	st;

	while (!stack_vide(a))
	{
		st = a->next;
		while (!stack_vide(st))
		{
			if (a->i == st->i)
				ft_error();
			st = st->next;
		}
		a = a->next;
	}
}

void	is_sorted(t_pile a, int argc)
{
	int	flag;

	flag = 0;
	(void)argc;
	while (!stack_vide(a) && a->next != NULL)
	{
		if (a->i > a->next->i)
			flag = 1;
		a = a->next;
	}
	if (flag == 0)
		exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	a;
	long	k;

	k = 0;
	a = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
	{
		if (str[i] == '-')
			a = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error();
		k = k * 10 + str[i] - '0';
		i++;
	}
	if ((k > (long)2147483648 && a == -1) || (k > (long)2147483647 && a != -1))
		ft_error();
	return (k * a);
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}
