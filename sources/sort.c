/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:14:26 by m_kamal           #+#    #+#             */
/*   Updated: 2023/06/07 15:14:38 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/* highest_index:
 * Returns the highest index in a stack.
 */
static int  highest_index(t_stack *stack)
{
  int index;
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
void sort_3(t_pushswap *ps)
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

void sort(t_pushswap *ps)
{
  int highest;
  int pushed;

  pushed = 0;
  if (is_sorted(ps->stack_a))
    return ;
  while (ps->size - pushed != 3)
  {
    if ((ps->stack_a)->index <= ps->size)
    {
      do_pb(&ps->stack_a, &ps->stack_b);
      pushed++;
    }
    else
      do_ra(&ps->stack_a);
  }
  sort_3(ps);
  while (ps->stack_b)
  {
    do_pa(&ps->stack_a, &ps->stack_b);
    highest = highest_index(ps->stack_a);
    if (ps->stack_a->index == highest)
      do_ra(&ps->stack_a);
  }
}
