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
t_cd_lst	*create_cd_list(void);
void	add_command(int len, const char *str, t_cd_deq *cmd_list)


#endif
