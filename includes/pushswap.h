/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:02:07 by m_kamal           #+#    #+#             */
/*   Updated: 2023/06/05 15:20:43 by m_kamal          ###   ########.fr       */
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

//	Libft
int		ft_isdigit(char c);
int		ft_is_sign(char c);
size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*modded_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s);
void	ft_putstr(char *s);

//	Filtering Program input
int		correct_input(char **argv);

//	Fixing numbers list
int		*get_numbers(int argc, char **argv);

//	Moves
//		Push
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
//		Swap
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);
//		Rotate
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
//		Reverse Rotate
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

//	Filling stack
t_stack	*find_second_last(t_stack *stack);
t_stack	*find_bottom(t_stack *stack);
t_stack	*fill_stack(int argc, char **argv);
void	err_hndl(char *err);

#endif

//Handling INT_MAX and INT_MIN?
