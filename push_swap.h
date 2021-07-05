/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:58 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/05 14:42:59 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
//input1
void	vaild_input(char *argv, int *fg);
void	check_insert(int ac, char **argv);
char	*merge_input(int ac, char **av);
unsigned int	absol(int n);
void	ps_atoi(int *idx, int sign, char *str, t_deque *deq);
//input2
t_deque	*insert_data(char *str);
t_deque	*check_dup_num(char *str);
t_deque	*check_input(int ac, char **av);
void	make_stack(int ac, char **av, t_deque **deq_A, t_deque **deq_B);

//command
void	sa(t_deque *deq_A, t_cd_deq *cmd_list);
void	sb(t_deque *deq_B, t_cd_deq *cmd_list);
void	ss(t_deque *deq_A, t_deque *deq_B, t_cd_deq *cmd_list);
void	pa(t_deque *deq_A, t_deque *deq_B, t_cd_deq *cmd_list);
void	pb(t_deque *deq_A, t_deque *deq_B, t_cd_deq *cmd_list);
void	ra(t_deque *deq_A, t_cd_deq *cmd_list);
void	rb(t_deque *deq_B, t_cd_deq *cmd_list);
void	rr(t_deque *deq_A, t_deque *deq_B, t_cd_deq *cmd_list);
void	rra(t_deque *deq_A, t_cd_deq *cmd_list);
void	rrb(t_deque *deq_B, t_cd_deq *cmd_list);
void	rrr(t_deque *deq_A, t_deque *deq_B, t_cd_deq *cmd_list);

#endif
