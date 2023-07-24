/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:22:42 by m_kamal           #+#    #+#             */
/*   Updated: 2023/07/24 14:41:52 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	free_data(t_data *data)
{
	if (!data)
		return ;
	free(data->merged_data);
	free(data->arr);
	free(data);
}

static void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

void	free_all(t_pushswap *ps)
{
	if (!ps)
		return ;
	free_data(ps->data);
	free_stack(&ps->stack_a);
	free_stack(&ps->stack_b);
	free(ps);
}

void	exit_err(char *err)
{
	write(2, err, 6);
	exit(1);
}

void	err_hndl(char *err, t_pushswap *ps)
{
	free_data(ps->data);
	if (ps->stack_a != NULL)
		free_stack(&ps->stack_a);
	if (ps->stack_b != NULL)
		free_stack(&ps->stack_b);
	write(2, err, 6);
	exit(1);
}
