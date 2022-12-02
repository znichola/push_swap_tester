/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:23:19 by znichola          #+#    #+#             */
/*   Updated: 2022/12/02 11:56:47 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	do_op(t_stack *s, int op)
{
	if (op == SA)
		return (sa_(s));
	if (op == SB)
		return (sb_(s));
	if (op == SS)
		return (ss_(s));
	if (op == PA)
		return (pa_(s));
	if (op == PB)
		return (pb_(s));
	if (op == RA)
		return (ra_(s));
	if (op == RB)
		return (rb_(s));
	if (op == RR)
		return (rr_(s));
	if (op == RRA)
		return (rra_(s));
	if (op == RRB)
		return (rrb_(s));
	if (op == RRR)
		return (rrr_(s));
	return (ERROR);
}

int	print_stack(t_stack *s)
{
	int	i;

	i = s->size;
	ft_printf("a  b\n");
	while (i--)
	{
		if (s->root_a + i <= s->a)
			ft_printf("%-2d", s->root_a[i]);
		ft_printf(" ");
		if (s->root_b + i <= s->b)
			ft_printf("%-2d", s->root_b[i]);
		ft_printf("\n");
	}
	return (SUCCESS);
}

int	execute_ops(t_stack *s)
{
	int	i;

	while (s->ops_root <= s->ops)
		if (do_op(s, *s->ops_root++))
			return (message_ret(ERROR, 2, "ops exe error"));
	i = 0;
	while (s->solution[i] == s->root_a[i] && i < s->size)
		i++;
	print_stack(s);
	if (i == s->size)
		return (SUCCESS);
	return (FAILURE);
}
