/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:34:39 by amoubare          #+#    #+#             */
/*   Updated: 2022/04/11 21:06:28 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	argv_to_a(t_pile *a, int argc, char **argv)
{
	while (argc > 1)
	{
		*a = push_stack(*a, ft_atoi(argv[argc - 1]));
		argc--;
	}
	return (new_pile());
}

t_pile	swap_stack(t_pile st, char *str)
{
	if (st && st->next)
	{
		swap(&st->i, &st->next->i);
		ft_putstr(str);
	}
	return (st);
}

t_pile	rotate_stack(t_pile st, char *str)
{
	t_pile	temp;

	temp = st;
	while (temp != NULL && temp->next != NULL)
	{
		swap(&temp->next->i, &temp->i);
		temp = temp->next;
	}
	ft_putstr(str);
	return (st);
}

void	push_to_stack(t_pile *a, t_pile *b, char *str)
{
	int		temp;
	t_pile	tmp;

	temp = (*a)->i;
	tmp = *a;
	*a = pop_stack(*a);
	free(tmp);
	*b = push_stack(*b, temp);
	ft_putstr(str);
}

void	reverse_rotate(t_pile *a, char *str)
{
	t_pile	last;

	last = get_last(*a);
	last->next->next = *a;
	*a = last->next;
	last->next = NULL;
	ft_putstr(str);
}
