/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 08:21:01 by m_kamal           #+#    #+#             */
/*   Updated: 2023/06/04 08:33:01 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/*	rotate:
	Rotates the top node of a stack to the bottom
*/
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*bottom;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	bottom = find_bottom(*stack);
	bottom->next = tmp;
}

/*	do_ra:
	Sends the top node of stack A to the bottom.
	Prints "ra" to stdout.
*/
void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/*	do_rb:
	Sends the top node of stack B to the bottom.
	Prints "rb" to stdout.
*/
void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

/*	do_rr:
	Sends the top node of both stacks A & B to the bottom.
	Prints "rr" to stdout.
*/
void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
