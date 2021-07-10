#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

void	print_cmd(t_info *info)
{
	int	i;
	t_cmd_lst *cur;

	cur = info->cmd->head;
	i = -1;
	while (++i < info->cmd->size)
	{
		printf("%s\n", cur->cmd);
		cur = cur->next;
	}
}