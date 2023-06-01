/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:02:07 by m_kamal           #+#    #+#             */
/*   Updated: 2023/06/01 08:38:41 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

// # include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

//		Filtering Program input
int		ft_isdigit(char c);
int		ft_is_sign(char c);
int		ft_strcmp(const char *s1, const char *s2);
int		correct_input(char **argv);

//		Filling stack
t_stack	*fill_stack(int argc, char **argv);


int		ft_atoi(const char *str);
void	err_hndl(char *err);

#endif

//Handling INT_MAX and INT_MIN?
