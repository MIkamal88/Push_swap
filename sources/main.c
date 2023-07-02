/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:14:01 by m_kamal           #+#    #+#             */
/*   Updated: 2023/06/06 19:32:44 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/* is_sorted:
 * Checks if the stack is sorted.
 * Returns 0 if the stack is not sorted, 1 if sorted
 */
int is_sorted(t_stack *stack)
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
static void push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
  if (size == 2 && !is_sorted(*stack_a))
    do_sa(stack_a);
  else if (size == 3)
    sort_3(stack_a);
//  else if (size > 3 && !is_sorted(*stack_a))
//    sort(stack_a, stack_b);
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
	pushswap->stack_a = fill_stack(pushswap);
	pushswap->stack_b = NULL;
	pushswap->size = pushswap->data->data_len;
	return (pushswap);
}

int	main(int argc, char **argv)
{
	t_pushswap	*ps;

	if (argc < 2)
		return (0);
	if (!correct_input(argv))
		err_hndl("Error", ps);
	ps = init_pushswap(argc, argv);
	push_swap(&ps->stack_a, &ps->stack_b, ps->size);
  while (ps->stack_a->next)
  {
    printf("Value = %d Index = %d\n", ps->stack_a->value, ps->stack_a->index);
    ps->stack_a = ps->stack_a->next;  
  }
  printf("Value = %d Index = %d\n", ps->stack_a->value, ps->stack_a->index); 
  //free_stacks
}
