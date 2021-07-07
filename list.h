/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:48 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/05 14:42:49 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <stdlib.h>
# include "ft_type.h"

//list
t_list	*create_list(void);
t_deque	*create_deque(void);
void	fillin_deque(t_deque *deq, int num);
t_deque	*create_deque_B(int size);
void	clear_deque(t_deque *deq);
void	del_top_node(t_deque *deq);
void	del_bottom_node(t_deque *deq);

//list_cmd
char	*new_str(int size, const char *str);
t_cmd_lst	*create_cmd_list(void);
void	add_command(int len, const char *str, t_cmd_deq *cmd_list);
void	setup_info(t_info *info);

//base_list
t_base_list	*create_base_list(void);
int		pop_base(t_base *base);
void	push_base(t_base *base, int input);
void	add_base(t_deque *deq_B, t_info *info, int rb_cnt);


#endif
