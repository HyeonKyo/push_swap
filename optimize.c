#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

void	print_cmd(t_info *info)
{
	int	i;
	t_cmd_lst *mm;

	mm = info->cmd->head;
	i = -1;
	while (++i < info->cmd->size)
	{
		printf("%s\n", mm->cmd);
		mm = mm->next;
	}
}

void	replace_command(t_cmd_deq *cmd, t_cmd_lst **cur, const char *str)
{
	t_cmd_lst	*lst;
	t_cmd_lst	*tmp;
	int			len;

	lst = create_cmd_list();
	len = (int)ft_strlen(str);
	lst->cmd = new_str(len, str);
	lst->prev = (*cur)->prev;
	(*cur)->prev->next = lst;
	lst->next = (*cur)->next->next;
	(*cur)->next->next->prev = lst;
	tmp = *cur;
	*cur = (*cur)->next;
	free(tmp);
	tmp = *cur;
	*cur = (*cur)->next;
	free(tmp);
	cmd->size--;
}

void	delete_command(t_cmd_deq *cmd, t_cmd_lst **cur)
{
	t_cmd_lst	*tmp;

	if ((*cur)->prev)
		(*cur)->prev->next = (*cur)->next->next;
	else
		cmd->head = (*cur)->next->next;
	if ((*cur)->next->next)
		(*cur)->next->next->prev = (*cur)->prev;
	else
		cmd->last = (*cur)->prev;
	tmp = *cur;
	*cur = (*cur)->next;
	free(tmp);
	tmp = *cur;
	*cur = (*cur)->next;
	free(tmp);
	cmd->size -= 2;
}

void	optimizing_check1(t_cmd_deq *cmd, t_cmd_lst **cur)
{
	char	*str;

	str = (*cur)->next->cmd;
	if (!ft_strcmp((*cur)->cmd, "ra"))
	{
		if (!ft_strcmp(str, "rrr"))
			replace_command(cmd, cur, "rrb");
		else if (!ft_strcmp(str, "rb"))
			replace_command(cmd, cur, "rr");
		else if (!ft_strcmp(str, "rra"))
			delete_command(cmd, cur);
	}
	else if (!ft_strcmp((*cur)->cmd, "rb"))
	{
		if (!ft_strcmp(str, "rrr"))
			replace_command(cmd, cur, "rra");
		else if (!ft_strcmp(str, "ra"))
			replace_command(cmd, cur, "rr");
		else if (!ft_strcmp(str, "rrb"))
			delete_command(cmd, cur);
	}
}

void	optimizing_check2(t_cmd_deq *cmd, t_cmd_lst **cur)
{
	char	*str;

	str = (*cur)->next->cmd;
	if (!ft_strcmp((*cur)->cmd, "rra"))
	{
		if (!ft_strcmp(str, "rrb"))
			replace_command(cmd, cur, "rrr");
		else if (!ft_strcmp(str, "ra"))
			delete_command(cmd, cur);
	}
	else if (!ft_strcmp((*cur)->cmd, "rrb"))
	{
		if (!ft_strcmp(str, "rra"))
			replace_command(cmd, cur, "rrr");
		else if (!ft_strcmp(str, "rb"))
			delete_command(cmd, cur);
	}
	else if (!ft_strcmp((*cur)->cmd, "rrr"))
	{
		if (!ft_strcmp(str, "ra"))
			replace_command(cmd, cur, "rrb");
		else if (!ft_strcmp(str, "rb"))
			replace_command(cmd, cur, "rra");	
		else if (!ft_strcmp(str, "rr"))
			delete_command(cmd, cur);
	}
}

int		optimize_command(t_cmd_deq *cmd)
{
	t_cmd_lst	*cur;
	t_cmd_lst	*tmp;
	int			fg;

	cur = cmd->head;
	fg = 0;
	if (!cur)
		return (0);
	while (cur && cur->next)
	{
		tmp = cur;
		if (!ft_strcmp(cur->cmd, "ra"))
			optimizing_check1(cmd, &cur);
		else if (!ft_strcmp(cur->cmd, "rb"))
			optimizing_check1(cmd, &cur);
		else if (!ft_strcmp(cur->cmd, "rra"))
			optimizing_check2(cmd, &cur);
		else if (!ft_strcmp(cur->cmd, "rrb"))
			optimizing_check2(cmd, &cur);
		else if (!ft_strcmp(cur->cmd, "rrr"))
			optimizing_check2(cmd, &cur);
		if (tmp == cur)
			cur = cur->next;
		else
			fg = 1;
	}
	return (fg);
}

/*
	1. if ra
		if next = rrr => rrb => 2개를 1개로 -> replace cmd()
		if next = rra => x -> 2개를 삭제 -> delete cmd()
		if next = rb => rr -> replace cmd()
	2. if rb
		if next = rrr => rra
		if next = rrb => x
		if next = ra => rr
	3. if rra
		if next = ra => x
		if next = rrb => rrr
	4. if rrb
		if next = rb => x
		if next = rra => rrr
	5. rrr
		ra => rrb
		rb => rra
	*/