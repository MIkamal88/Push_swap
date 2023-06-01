/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:24:06 by m_kamal           #+#    #+#             */
/*   Updated: 2023/05/30 19:38:34 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/*	arg_is_number:
	Checks if the argument is a number or not
	Returns: 1 if number, 0 if not
*/
static int	arg_is_number(char *argv)
{
	int	i;

	i = 0;
	if (ft_is_sign(argv[i]) && argv[i + 1])
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] != '\0' && !ft_isdigit(argv[i]))
		return (0);
	return (1);
}

/*	arg_is_zero:
	Checks if the argument is 0 to avoid snide cases of +0, -0, 000
	and duplicates of 0 too.
	Returns: 1 if argument is zero, 0 if not
*/
static int	arg_is_zero(char *argv)
{
	int	i;

	i = 0;
	if (ft_is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

/*	arg_is_duplicate:
	checks if the argument list has duplicated numbers
	Returns: 1 if a duplicate is found, 0 if not
*/
static int	arg_is_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (argv[i])
	{
		while (argv[j])
		{
			if (i != j && ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
		return (0);
	}
}

/*	correct input:
	checks if the given arguments are numbers and without duplicates
	Returns: 1 if valid, 0 if not
*/
int	correct_input(char **argv)
{
	int	i;
	int	zeroes;

	zeroes = 0;
	i = 1;
	while (argv[i])
	{
		if (!arg_is_number(argv[i]))
			return (0);
		zeroes += arg_is_zero(argv[i]);
		i++;
	}
	if (zeroes > 1)
		return (0);
	if (arg_is_duplicate(argv))
		return (0);
	return (1);
}
