/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:34:13 by amoubare          #+#    #+#             */
/*   Updated: 2022/07/24 23:22:21 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	high_to_low(t_pile a, int argc)
{
	int	flag;

	flag = 0;
	(void)argc;
	while (!stack_vide(a) && a->next != NULL)
	{
		if (a->i < a->next->i)
			flag = 1;
		a = a->next;
	}
	if (flag == 0)
		return (1);
	else
		return (0);
}

void	izi(t_pile *a, t_pile *b, int argc)
{
	argc = argc - 1;
	while (!stack_vide(*a))
		push_to_stack(a, b, "pb\n");
	while (--argc)
	{
		reverse_rotate(b, "rrb\n");
		push_to_stack(b, a, "pa\n");
	}
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_pile	a;
	t_pile	b;
	int		*p;

	p = (int *)malloc(200);
	argv_to_a(&a, argc, argv);
	check_dup(a);
	is_sorted(a, argc);
	p[0] = getminelem(a) - 1;
	if (argc > 2 && argc < 30)
		minisort(argc, &a, &b);
	else
	{
		if (high_to_low(a, argc))
			izi(&a, &b, argc);
		else
			bigsort(p, argv, &a, &b);
	}
}
