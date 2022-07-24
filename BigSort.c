/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigSort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:29:18 by amoubare          #+#    #+#             */
/*   Updated: 2022/04/08 22:02:31 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	getcunk(t_pile cp, int argc, int *p, char **argv)
{
	t_pile	b;
	int		i;
	int		j;
	t_pile	head;
	int		k;

	b = new_pile();
	i = 0;
	j = 1;
	cp = cpy_args(argc, argv);
	insertionsort(&cp, &b, argc);
	fill_a(&cp, &b, argc);
	head = cp;
	while (i <= (argc - 2))
	{
		k = 0;
		while (k++ < 4)
		{
			if (i == k * (argc - 2) / 4)
				p[j++] = cp->i;
		}
		i++;
		cp = cp->next;
	}
	ft_free(&head);
}

void	getcunk_hundred(t_pile cp, int argc, int *p, char **argv)
{
	t_pile	b;
	int		i;
	int		j;
	int		k;
	t_pile	head;

	i = 0;
	j = 1;
	cp = cpy_args(argc, argv);
	insertionsort(&cp, &b, argc);
	fill_a(&cp, &b, argc);
	head = cp;
	while (i <= (argc - 2))
	{
		k = 0;
		while (k++ < 11)
		{
			if (i == k * (argc - 2) / 11)
				p[j++] = cp->i;
		}
		i++;
		cp = cp->next;
	}
	ft_free(&head);
}

void	push_chunks_to_b(t_pile *a, t_pile *b, char **argv, int *p)
{
	t_pile		temp;
	t_pile		tmp;
	int			i;
	static int	k;
	int			j;

	i = 0;
	j = count_argc(argv);
	temp = cpy_args(j, argv);
	tmp = temp;
	while (!stack_vide(temp) && i <= j)
	{
		if (p[k + 1] && temp->i <= p[k + 1] && temp->i > p[k])
		{
			pushchunk(a, b, j, temp);
		}
		temp = temp->next;
	}
	ft_free(&tmp);
	k++;
}

void	pushchunk(t_pile *a, t_pile *b, int j, t_pile temp)
{
	int	i;

	i = getindex(*a, temp->i);
	if (i == j)
		reverse_rotate(a, "rra\n");
	else if (i <= (j - 1) / 2)
	{
		while (i > 1)
		{
			*a = rotate_stack(*a, "ra\n");
			i--;
		}
	}
	else if (i >= (j - 1) / 2)
	{
		while (i <= j - 3)
		{
			reverse_rotate(a, "rra\n");
			i++;
		}
	}
	push_to_stack(a, b, "pb\n");
}

void	push_back_to_a(t_pile *a, t_pile *b, int argc, int div)
{
	int	i;

	i = 0;
	while (!stack_vide(*b) && i < argc / div)
	{
		push_to_stack(b, a, "pa\n");
		i++;
	}
}
