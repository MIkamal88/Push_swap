/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:44:34 by m_kamal           #+#    #+#             */
/*   Updated: 2023/06/01 08:45:37 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// !Fix get numbers function!

#include "../includes/pushswap.h"

/*	new_node:
	Mallocs and returns the first stack
*/
static t_stack	*new_node(int num)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = num;
	new->index = 0;
	new->next = NULL;
	return (new);
}

/*	find_bottom:
	Returns last node in the stack
*/
static t_stack	*find_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/*	Attach_node_to_tail:
	Adds a node to the tail end of the stack
*/
static void	attach_node_to_tail(t_stack **stack, t_stack *node)
{
	t_stack	*tail;

	if (!*stack)
		return ;
	tail = find_bottom(*stack);
	tail->next = node;
}

/*	fill_stack:
	Fills stack_a with values
	Return: if values are out of INT_MAX/MIN it returns error
	and exits the program.
*/
t_stack	*fill_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		num;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			err_hndl("Error");
		if (i == 1)
			stack_a = new_node(num);
		else
			attach_node_to_tail(&stack_a, new_node(num));
		i++;
	}
	return (stack_a);
}
