/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MiniSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:23:52 by amoubare          #+#    #+#             */
/*   Updated: 2022/04/08 22:50:49 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	sorttree(t_pile st)
{
	int	middle;
	int	bottom;

	middle = st->next->i;
	bottom = st->next->next->i;
	if (st->i > middle && middle < bottom && st->i < bottom)
		swap_stack(st, "sa\n");
	else if (st->i > middle && middle > bottom)
	{
		rotate_stack(st, "ra\n");
		swap_stack(st, "sa\n");
	}
	else if (st->i > middle && middle < bottom && st->i > bottom)
		rotate_stack(st, "ra\n");
	else if (st->i < middle && middle > bottom && st->i < bottom)
	{
		swap_stack(st, "sa\n");
		rotate_stack(st, "ra\n");
	}
	else if (st->i < middle && middle > bottom && st->i > bottom)
	{
		rotate_stack(st, "ra\n");
		rotate_stack(st, "ra\n");
	}
	return (st);
}

t_pile	prep_four(t_pile a)
{
	int	top;
	int	two;
	int	three;
	int	four;

	top = a->i;
	two = a->next->i;
	three = a->next->next->i;
	four = a->next->next->next->i;
	if (top > two && two < three && two < four)
		a = rotate_stack(a, "ra\n");
	else if (three < top && three < two && three < four)
	{
		a = rotate_stack(a, "ra\n");
		a = rotate_stack(a, "ra\n");
	}
	else if (four < top && four < two && four < three)
		reverse_rotate(&a, "rra\n");
	return (a);
}

t_pile	prep_five(t_pile a)
{
	int	two;
	int	three;
	int	four;
	int	five;

	two = a->next->i;
	three = a->next->next->i;
	four = a->next->next->next->i;
	five = a->next->next->next->next->i;
	if (a->i > two && two < three && two < four && two < five)
		a = rotate_stack(a, "ra\n");
	else if (three < a->i && three < a->next->i && three < four && three < five)
	{
		a = rotate_stack(a, "ra\n");
		a = rotate_stack(a, "ra\n");
	}
	else if (four < a->i && four < two && four < three && four < five)
	{
		reverse_rotate(&a, "rra\n");
		reverse_rotate(&a, "rra\n");
	}
	else if (five < a->i && five < two && five < three && five < four)
		reverse_rotate(&a, "rra\n");
	return (a);
}

void	sortfour(t_pile *a, t_pile *b)
{
	*a = prep_four(*a);
	push_to_stack(a, b, "pb\n");
	*a = sorttree(*a);
	push_to_stack(b, a, "pa\n");
}

void	sortfive(t_pile *a, t_pile *b)
{
	*a = prep_five(*a);
	push_to_stack(a, b, "pb\n");
	sortfour(a, b);
	push_to_stack(b, a, "pa\n");
}
