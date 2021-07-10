/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:51 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/05 14:42:52 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_type.h"
#include "ft_utils.h"

char	*new_str(int size, const char *str)
{
	int		i;
	char	*new;

	new = (char *)malloc(sizeof(size + 1));
	if (new == 0)
		merror();
	i = -1;
	while (++i < size)
		new[i] = str[i];
	return (new);
}

t_cmd_lst	*create_cmd_list(void)
{
	t_cmd_lst	*lst;

	lst = (t_cmd_lst *)malloc(sizeof(t_cmd_lst));
	if (lst == 0)
		merror();
	ft_memset(lst, 0, sizeof(t_cmd_lst));
	return (lst);
}

void	add_command(int len, const char *str, t_cmd_deq *cmd_list)
{
	cmd_list->last->cmd = new_str(len, str);
	cmd_list->last->next = create_cmd_list();
	cmd_list->size++;
}

void	setup_info(t_info *info)
{
	info->cmd = (t_cmd_deq *)malloc(sizeof(t_cmd_deq));
	if (info->cmd == 0)
		merror();
	info->cmd->head = create_cmd_list();
	info->cmd->last = info->cmd->head;
	info->cmd->size = 0;
	ft_memset(info->cnt, 0, sizeof(int) * 4);
}
