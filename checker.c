/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:58:18 by amoubare          #+#    #+#             */
/*   Updated: 2022/04/16 04:41:12 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_pile *a, t_pile *b, char *str)
{
	*a = rotate_stack(*a, "");
	*b = rotate_stack(*b, "");
	ft_putstr(str);
}

void	ss(t_pile *a, t_pile *b, char *str)
{
	*a = swap_stack(*a, "");
	*b = swap_stack(*b, "");
	ft_putstr(str);
}

void	cases(t_pile *a, t_pile *b, char **str)
{
	if (!ft_strcmp(*str, "pa\n"))
		push_to_stack(b, a, "");
	else if (!ft_strcmp(*str, "pb\n"))
		push_to_stack(a, b, "");
	else if (!ft_strcmp(*str, "ra\n"))
		*a = rotate_stack(*a, "");
	else if (!ft_strcmp(*str, "rb\n"))
		*b = rotate_stack(*b, "");
	else if (!ft_strcmp(*str, "rra\n"))
		reverse_rotate(a, "");
	else if (!ft_strcmp(*str, "rrb\n"))
		reverse_rotate(b, "");
	else if (!ft_strcmp(*str, "sa\n"))
		*a = swap_stack(*a, "");
	else if (!ft_strcmp(*str, "sb\n"))
		*b = swap_stack(*b, "");
	else if (!ft_strcmp(*str, "rrr\n"))
		rrr(a, b, "");
	else if (!ft_strcmp(*str, "rr\n"))
		rr(a, b, "");
	else if (!ft_strcmp(*str, "ss\n"))
		ss(a, b, "");
	else
		ft_error();
}

void	ft_result(t_pile a)
{
	int		flag;
	t_pile	st;

	flag = 0;
	while (!stack_vide(a) && a->next != NULL)
	{
		if (a->i > a->next->i)
		{
			printf("KO\n");
			exit(0);
		}
		st = a->next;
		a = a->next;
	}
	printf("OK\n");
}

int	main(int argc, char **argv)
{
	t_pile	a;
	t_pile	b;
	char	*str;
	char	*tmp;

	a = new_pile();
	b = new_pile();
	argv_to_a(&a, argc, argv);
	check_dup(a);
	is_sorted(a, argc);
	str = get_next_line(0);
	while (str)
	{
		cases(&a, &b, &str);
		tmp = str;
		str = get_next_line(0);
		free(tmp);
	}
	ft_result(a);
}
