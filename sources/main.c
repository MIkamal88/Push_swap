/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:14:01 by m_kamal           #+#    #+#             */
/*   Updated: 2023/06/01 08:44:27 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	if (!correct_input(argv))
		err_hndl("Error");
	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	//pushswap
	//free_stacks
}
