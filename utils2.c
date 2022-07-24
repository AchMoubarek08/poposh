/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:37:13 by amoubare          #+#    #+#             */
/*   Updated: 2022/04/08 22:01:53 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getindex(t_pile a, int val)
{
	int		i;
	t_pile	head;

	head = a;
	i = 1;
	while (head->i != val && head->next)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	lst_size(t_pile b)
{
	int	len;

	len = 0;
	while (!stack_vide(b))
	{
		len++;
		b = b->next;
	}
	return (len);
}

int	getminelem(t_pile a)
{
	int		i;
	int		s;
	t_pile	head;

	head = a;
	s = a->i;
	i = 1;
	while (!stack_vide(a))
	{
		if (a->i < s)
			s = a->i;
		a = a->next;
	}
	return (s);
}

int	getmaxindex(t_pile a)
{
	int		i;
	int		s;
	t_pile	head;

	head = a;
	s = a->i;
	i = 1;
	while (!stack_vide(a))
	{
		if (a->i >= s)
			s = a->i;
		a = a->next;
	}
	while (head->i != s)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	ft_free(t_pile *a)
{
	t_pile	temp;

	while ((*a) != NULL)
	{
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
}
