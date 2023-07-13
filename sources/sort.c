/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:14:26 by m_kamal           #+#    #+#             */
/*   Updated: 2023/07/13 14:12:42 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/* highest_index:
 * Returns the highest index in a stack.
 */
static int	highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* sort_3:
 * Sorts a stack of 3 numbers in 2 or less moves
 * Sorting is done by index rather than value.
 */
void	sort_3(t_pushswap *ps)
{
	int		highest;

	if (is_sorted(ps->stack_a))
		return ;
	highest = highest_index(ps->stack_a);
	if (ps->stack_a->index == highest)
		do_ra(&ps->stack_a);
	else if (ps->stack_a->next->index == highest)
		do_rra(&ps->stack_a);
	if (ps->stack_a->index > ps->stack_a->next->index)
		do_sa(&ps->stack_a);
}

static void	push_away(t_pushswap *ps)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (ps->size > 3 && i < ps->size && pushed < ps->size / 2)
	{
		if (ps->stack_a->index <= ps->size / 2)
		{
			do_pb(&ps->stack_a, &ps->stack_b);
			pushed++;
		}
		else
			do_ra(&ps->stack_a);
		i++;
	}
	while (ps->size - pushed > 3)
	{
		do_pb(&ps->stack_a, &ps->stack_b);
		pushed++;
	}
}

/* sort_5:
 * Sorts a stack of 5 numbers
 */
void	sort_5(t_pushswap*ps)
{
	push_away(ps);
	sort_3(ps);
	do_pa(&ps->stack_a, &ps->stack_b);
	do_pa(&ps->stack_a, &ps->stack_b);
	if (ps->stack_a->index > ps->stack_a->next->index)
		do_sa(&ps->stack_a);
}

/*sort:
 * Sorts the stacks using radix sorting algorithm.
 */
void	sort(t_pushswap *ps)
{
	int	i;
	int	j;
	int	num;
	int	max_bits;

	max_bits = 0;
	while (((ps->size - 1) >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < ps->size)
		{
			num = ps->stack_a->index;
			if ((num >> i) & 1)
				do_ra(&ps->stack_a);
			else
				do_pb(&ps->stack_a, &ps->stack_b);
		}
		while (ps->stack_b)
			do_pa(&ps->stack_a, &ps->stack_b);
	}
}
