/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:14:01 by m_kamal           #+#    #+#             */
/*   Updated: 2023/07/24 14:38:41 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/* is_sorted:
 * Checks if the stack is sorted.
 * Returns 0 if the stack is not sorted, 1 if sorted
 */
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* push_swap:
 * Chooses sorting method depending on number
 * of values to be sorted.
 */
static void	push_swap(t_pushswap *ps)
{
	if (ps->size == 2 && !is_sorted(ps->stack_a))
		do_sa(&ps->stack_a);
	else if (ps->size == 3 && !is_sorted(ps->stack_a))
		sort_3(ps);
	else if (ps->size == 5 && !is_sorted(ps->stack_a))
		sort_5(ps);
	else
		if (!is_sorted(ps->stack_a))
			sort(ps);
}

/* init_pushswap:
 * Initializes the pushswap struct.
 * Returns the struct
 */
static t_pushswap	*init_pushswap(int argc, char **argv)
{
	t_pushswap	*pushswap;

	pushswap = malloc(sizeof(t_pushswap));
	pushswap->data = parse_data(argc, argv);
	pushswap->size = pushswap->data->data_len;
	pushswap->stack_a = fill_stack(pushswap);
	pushswap->stack_b = NULL;
	return (pushswap);
}

int	main(int argc, char **argv)
{
	t_pushswap	*ps;
	int			i;

	i = 0;
	if (argc < 2)
		return (0);
	while (argv[i++] && i != argc - 1)
		if (argv[i] == 0)
			exit_err("Error\n");
	if (!correct_input(argv))
		exit_err("Error\n");
	ps = init_pushswap(argc, argv);
	assign_index(ps->stack_a, ps->size + 1);
	push_swap(ps);
	free_all(ps);
}
