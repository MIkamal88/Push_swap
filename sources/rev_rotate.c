/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 08:13:14 by m_kamal           #+#    #+#             */
/*   Updated: 2023/06/05 13:14:00 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"


/* find_second_last:
*	Returns the second to last node of the stack.
*/
t_stack	*find_second_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/*	rev_rotate:
	Brings the bottom node of a stack to the top.
*/
static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*second_last;

	last = find_bottom(*stack);
	second_last = find_second_last(*stack);
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;
	second_last->next = NULL;
}

/*	do_rra:
	Brings the bottom node of stack A to the top
	Prints "rra" to stdout
*/
void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

/*	do_rrb:
	Brings the bottom node of stack B to the top
	Prints "rrb" to stdout
*/
void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

/*	do_rrr:
	Brings the bottom node of both stacks A and B to the top
	Prints "rrb" to stdout
*/
void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
