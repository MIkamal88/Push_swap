/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:44:34 by m_kamal           #+#    #+#             */
/*   Updated: 2023/07/13 14:09:48 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/*	new_node:
 *	Mallocs and returns the first stack
 */
static t_stack	*new_node(int num, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = num;
	new->index = index;
	new->next = NULL;
	return (new);
}

/*	find_bottom:
 *	Returns last node in the stack
 */
t_stack	*find_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/*	Attach_node_to_tail:
 *	Adds a node to the tail end of the stack
 */
static void	attach_node_to_tail(t_stack **stack, t_stack *node)
{
	t_stack	*tail;

	if (!*stack)
		return ;
	tail = find_bottom(*stack);
	tail->next = node;
}

/* assign_index:
 * Assigns an index to a node in order to use those indexes to arrange the stacks
 * Indexing is done from highest to lowest.
 */
void	assign_index(t_stack *stack_a, int size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

/*	fill_stack:
	Fills stack_a with values
	Return: if values are out of INT_MAX/MIN it returns error
	and exits the program.
*/
t_stack	*fill_stack(t_pushswap *ps)
{
	t_stack	*stack_a;
	int		i;
	int		*num;

	stack_a = NULL;
	num = ps->data->arr;
	i = 0;
	while (i < ps->size)
	{
		if (num[i] > INT_MAX || num[i] < INT_MIN)
			err_hndl("Error\n", ps);
		if (i == 0)
			stack_a = new_node(num[i], 0);
		else
			attach_node_to_tail(&stack_a, new_node(num[i], 0));
		i++;
	}
	return (stack_a);
}
