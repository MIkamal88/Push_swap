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
 * Sorting is done by index rather than value
 */
void sort_3(t_stack **stack)
{
  int highest;

  if (is_sorted(*stack))
    return ;
  highest = highest_index(*stack);
  if ((*stack)->index == highest)
    do_ra(stack);
  else if ((*stack)->next->index == highest)
      do_rra(stack);
  else if ((*stack)->index > (*stack)->next->index)
      do_sa(stack);
}

