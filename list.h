#ifndef LIST_H
# define LIST_H
# include <stdlib.h>
# include "ft_type.h"

t_list	*create_list(void);
t_deque	*create_deque(void);
void	fillin_deque(t_deque *deq, int num);
t_deque	*create_deque_B(int size);
void	clear_deque(t_deque *deq);

#endif
