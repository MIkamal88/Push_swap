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
		err_hndl("Error");
	ps = init_pushswap(argc, argv);
	do_pb(&ps->stack_a, &ps->stack_b);
	//pushswap
	//free_stacks
}
