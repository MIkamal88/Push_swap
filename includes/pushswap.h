/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:02:07 by m_kamal           #+#    #+#             */
/*   Updated: 2023/06/04 08:42:36 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

// # include "../libft/libft.h"
# include <stdio.h>
# include <stdint.h>
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

//		Fixing numbers list
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_strjoin(char *s1, char *s2);
int		*get_numbers(int argc, char **argv);

//		Filling stack
t_stack	*find_second_last(t_stack *stack);
t_stack	*find_bottom(t_stack *stack);
t_stack	*fill_stack(int argc, char **argv);
void	err_hndl(char *err);
void	ft_putstr(char *s);

#endif

//Handling INT_MAX and INT_MIN?
