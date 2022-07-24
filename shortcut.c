/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:47:34 by amoubare          #+#    #+#             */
/*   Updated: 2022/04/12 02:08:49 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	minisort(int argc, t_pile *a, t_pile *b)
{
	if (argc == 3)
		sorttwo(a);
	else if (argc == 4)
		*a = sorttree(*a);
	else if (argc == 5)
		sortfour(a, b);
	else if (argc == 6)
		sortfive(a, b);
	else if (argc > 6 && argc < 30)
	{
		insertionsortt(a, b, argc);
		push_back_to_a(a, b, argc - 1, 1);
	}
}

void	bigsort(int *p, char **argv, t_pile *a, t_pile *b)
{
	int	i;

	i = 0;
	if (count_argc(argv) > 350)
	{
		getcunk_hundred(new_pile(), count_argc(argv), p, argv);
		while (i < 10)
		{
			push_chunks_to_b(a, b, argv, p);
			i++;
		}
		i = 11;
	}
	else
	{
		getcunk(new_pile(), count_argc(argv), p, argv);
		while (i < 3)
		{
			push_chunks_to_b(a, b, argv, p);
			i++;
		}
		i = 4;
	}
	finish(argv, a, b, i);
}

void	finish(char **argv, t_pile *a, t_pile *b, int i)
{
	insertionsortt(a, b, count_argc(argv));
	push_back_to_a(a, b, count_argc(argv) - 1, i);
	pushmax(a, b);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
