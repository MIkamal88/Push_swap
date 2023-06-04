/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:00:30 by m_kamal           #+#    #+#             */
/*   Updated: 2023/06/04 08:22:14 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/*	swap_nodes:	used for 'sa', 'sb', 'ss'
	Swap the first 2 nodes of a stack.
	Do nothing if only one or no nodes.
*/
static void	swap_nodes(t_stack **stack)
{
	int	tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

/*	do_sa:	Swaps the top 2 nodes of stack a
	prints "sa" to stdout
*/
void	do_sa(t_stack **stack_a)
{
	swap_nodes(stack_a);
	ft_putstr("sa\n");
}

/*	do_sb:	Swaps the top 2 nodes of stack b
	prints "sb" to stdout
*/
void	do_sb(t_stack **stack_b)
{
	swap_nodes(stack_b);
	ft_putstr("sa\n");
}

/*	do_ss:	Swaps the top 2 nodes of both stacks a, b
	prints "ss" to stdout
*/
void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	ft_putstr("ss\n");
}
