#include "ft_type.h"
#include "ft_utils.h"

t_list	*create_list()
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == 0)
		return (0);
	ft_memset(lst, 0, sizeof(t_list));
	return (lst);
}

