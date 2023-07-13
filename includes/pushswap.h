/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:02:07 by m_kamal           #+#    #+#             */
/*   Updated: 2023/07/13 14:01:32 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	char	*merged_data;
	int		*arr;
	int		data_len;
}	t_data;

typedef struct s_pushswap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	*data;
	int		size;
}	t_pushswap;

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
t_data	*parse_data(int argc, char **argv);

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

//    sort
int		is_sorted(t_stack *stack);
void	sort_3(t_pushswap *ps);
void	sort_5(t_pushswap *ps);
void	sort(t_pushswap *ps);

//	Filling stack
void	assign_index(t_stack *stack_a, int size);
t_stack	*find_second_last(t_stack *stack);
t_stack	*find_bottom(t_stack *stack);
t_stack	*fill_stack(t_pushswap *ps);
void	exit_err(char *err);
void	err_hndl(char *err, t_pushswap *ps);
void	free_all(t_pushswap *ps);

#endif

