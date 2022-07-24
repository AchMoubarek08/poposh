/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigSortt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:20:24 by amoubare          #+#    #+#             */
/*   Updated: 2022/04/08 23:21:58 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertionsortt(t_pile *a, t_pile *b, int argc)
{
	int	i;

	while (!stack_vide(*a))
	{
		i = getmin(*a);
		if (i <= argc / 2)
		{
			while (i-- > 1)
			{
				*a = rotate_stack(*a, "ra\n");
			}
			push_to_stack(a, b, "pb\n");
		}
		else if (i == argc)
			reverse_rotate(a, "rra\n");
		else
		{
			while (i++ < argc)
			{
				reverse_rotate(a, "rra\n");
			}
			push_to_stack(a, b, "pb\n");
		}
		argc--;
	}
}

void	fill_a(t_pile *a, t_pile *b, int argc)
{
	while (argc > 1)
	{
		push_to_stack(b, a, "");
		argc--;
	}
}

void	insertionsort(t_pile *a, t_pile *b, int argc)
{
	int	i;

	while (!stack_vide(*a))
	{
		i = getmin(*a);
		if (i == argc)
			reverse_rotate(a, "");
		else if (i <= argc / 2)
		{
			while (i-- > 1)
			{
				*a = rotate_stack(*a, "");
			}
			push_to_stack(a, b, "");
		}
		else
		{
			while (i++ < argc)
			{
				reverse_rotate(a, "");
			}
			push_to_stack(a, b, "");
		}
		argc--;
	}
}

void	pushmax(t_pile *a, t_pile *b)
{
	int		i;
	int		size;

	size = lst_size(*b);
	while (!stack_vide(*b))
	{
		i = getmaxindex(*b);
		if (i > lst_size(*b) / 2 && i != 1)
		{
			while (i <= lst_size(*b))
			{
				reverse_rotate(b, "rrb\n");
				i++;
			}
		}
		else if (i <= size / 2 && i != 1)
		{
			while (i > 1)
			{
				*b = rotate_stack(*b, "rb\n");
				i--;
			}
		}
		push_to_stack(b, a, "pa\n");
	}
}

int	count_argc(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
