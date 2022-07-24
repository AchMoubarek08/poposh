/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:33:53 by amoubare          #+#    #+#             */
/*   Updated: 2022/04/16 22:05:26 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct pileElement
{
	int					i;
	struct pileElement	*next;
}pileElement,	*t_pile;

typedef enum bool
{
	false,
	true
}t_bool;
void	sorttwo(t_pile *a);
t_pile	sorttree(t_pile st);
void	sortfour(t_pile *a, t_pile *b);
void	sortfive(t_pile *a, t_pile *b);
t_bool	stack_vide(t_pile st);
t_pile	push_stack(t_pile st, int x);
int		ft_atoi(const char *str);
t_pile	swap_stack(t_pile st, char *str);
void	ft_putstr(char *str);
void	swap(int *y, int *z);
void	print_stack(t_pile st);
t_pile	rotate_stack(t_pile st, char *str);
t_pile	new_pile(void);
void	push_to_stack(t_pile *a, t_pile *b, char *str);
t_pile	pop_stack(t_pile st);
t_pile	prep_four(t_pile a);
t_pile	prep_five(t_pile a);
void	check_dup(t_pile a);
void	insertionsort(t_pile *a, t_pile *b, int argc);
int		getmin(t_pile a);
t_pile	get_last(t_pile a);
void	reverse_rotate(t_pile *a, char *str);
void	fill_a(t_pile *a, t_pile *b, int argc);
void	getcunk(t_pile cp, int argc, int *p, char **argv);
t_pile	cpy_args(int argc, char **argv);
int		getindex(t_pile a, int val);
int		getminelem(t_pile a);
int		getmaxindex(t_pile a);
void	pushmax(t_pile *a, t_pile *b);
void	insertionsortt(t_pile *a, t_pile *b, int argc);
void	push_chunks_to_b(t_pile *a, t_pile *b, char **argv, int *p);
int		lst_size(t_pile b);
void	is_sorted(t_pile a, int argc);
void	getcunk_hundred(t_pile cp, int argc, int *p, char **argv);
void	ft_free(t_pile *a);
void	minisort(int argc, t_pile *a, t_pile *b);
void	bigsort(int *p, char **argv, t_pile *a, t_pile *b);
t_pile	argv_to_a(t_pile *a, int argc, char **argv);
int		count_argc(char **argv);
void	ft_error(void);
void	pushchunk(t_pile *a, t_pile *b, int j, t_pile temp);
void	push_back_to_a(t_pile *a, t_pile *b, int argc, int div);
int		ft_isdigit(int c);
void	finish(char **argv, t_pile *a, t_pile *b, int i);
int		high_to_low(t_pile a, int argc);
void	izi(t_pile *a, t_pile *b, int argc);

void	nadi(char **stock, char **ligne);
char	*ft_frree(char **lost);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
int		ft_int_strchr(const char *s, int c);
void	ft_result(t_pile a);
void	ss(t_pile *a, t_pile *b, char *str);
void	rr(t_pile *a, t_pile *b, char *str);
void	rrr(t_pile *a, t_pile *b, char *str);
int		ft_strcmp(char *s1, char *s2);

#endif