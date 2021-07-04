#ifndef FT_TYPE_H
# define FT_TYPE_H
# include <stdlib.h>

typedef	struct	s_pivot
{
	int	big;
	int	sml;
}				t_pivot;


typedef struct	s_list
{
	int	data;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct	s_deque
{
	int		size;
	t_list	*top;
	t_list	*bot;
}				t_deque;

#endif