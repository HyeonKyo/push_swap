#include "ft_type.h"
#include "ft_utils.h"

char	*new_str(int size, const char *str)
{
	int		i;
	char	*new;

	new = (char *)malloc(sizeof(size + 1));
	if (new == 0)
		exit(2);
	i = -1;
	while (++i < size)
		new[i] = str[i];
	return (new);
}

t_cd_lst	*create_cd_list(void)
{
	t_cd_lst	*lst;

	lst = (t_cd_lst *)malloc(sizeof(t_cd_lst));
	if (lst == 0)
		exit(2);
	ft_memset(lst, 0, sizeof(t_cd_lst));
	return (lst);
}

void	add_command(int len, const char *str, t_cd_deq *cmd_list)
{
	cmd_list->last->cmd = new_str(len, str);
	cmd_list->last->next = create_cd_list();
	cmd_list->size++;
}