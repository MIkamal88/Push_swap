/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 08:07:35 by m_kamal           #+#    #+#             */
/*   Updated: 2023/06/04 08:21:56 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/*	push_node:	used for push a ,and push b
	Take the first node at the top of a stack and put it
	at the top of the other stack. Do nothing if
	first stack is empty.
*/
static void	push_node(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!(*src))
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

/*	do_pa:	Pushes top node of stack b to the top of stack a
	prints "pa" to stdout
*/
void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push_node(stack_b, stack_a);
	ft_putstr("pa\n");
}

/*	do_pb:	Pushes top node of stack a to the top of stack b
	prints "pb" to stdout
*/
void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push_node(stack_a, stack_b);
	ft_putstr("pb\n");
}
