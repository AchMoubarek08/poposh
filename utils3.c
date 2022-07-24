/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:41:22 by amoubare          #+#    #+#             */
/*   Updated: 2022/04/08 22:02:02 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	push_stack(t_pile st, int x)
{
	pileElement	*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		return (NULL);
	element->i = x;
	element->next = st;
	return (element);
}

t_pile	pop_stack(t_pile st)
{
	pileElement	*element;

	if (stack_vide(st))
		return (new_pile());
	element = st;
	st = st->next;
	return (st);
}

int	getmin(t_pile a)
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
	while (head->i != s)
	{
		i++;
		head = head->next;
	}
	return (i);
}

t_pile	get_last(t_pile a)
{
	if (stack_vide(a))
		return (a);
	while (!stack_vide(a->next->next))
	{
		a = a->next;
	}
	return (a);
}

t_pile	cpy_args(int argc, char **argv)
{
	t_pile	cp;

	cp = new_pile();
	while (argc > 1)
	{
		cp = push_stack(cp, ft_atoi(argv[argc - 1]));
		argc--;
	}
	return (cp);
}
