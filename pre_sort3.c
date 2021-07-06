#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

void	before_bios(t_sort *repo, t_ll bios)
{
	int	i;

	i = 0;
	while (i < repo->size)
		repo->arr[i++] -= bios;
}

void	radix_sort(t_deque *deq, t_sort *repo, t_ll bios, int max)
{
	int	i;
	int	digit;

	digit = find_digit(bios + max);
	putin_data(deq, repo, bios);
	i = 1;
	while (i <= digit)
		sorting(repo, bios, i++);
	before_bios(repo, bios);
}

void	choose_pivot(t_pivot *piv, t_sort *repo)
{
	int	a;
	int	b;
	int	c;
	int	tmp;

	a = repo->size / 3;
	printf("size : %d\n", repo->size);
	tmp = (repo->size * 2) % 3;
	if (tmp == 0) 
		b = repo->size * 2 / 3;
	else if (tmp == 1)
		b = (repo->size * 2 + 2) / 3;
	else
		b = (repo->size * 2 + 1) / 3;
	b++;
	c = repo->size;
	while (b - a > c - b + 1)
		a++;
	piv->sml = a;
	piv->big = b;
	//1 ~ 14까지일 때 sml : 7, big : 11
	//1 ~ 13까지일 때 sml : 6, big : 10
	//1 ~ 12까지일 때 sml : 5, big : 9
	//1 <= a < sml은 pb만 하는 블록이므로 가장 크게
	//sml <= b < big과 big <= c는 ra, rb를 각각 실행하므로
	//마지막에 rrr로 동일한 작업을 하도록 개수를 최대한 맞춰줌.
	//but, 이 방법은 첫번째 퀵소트 시에는 오히려 비효율적
	//
}

void	clear_repo(t_sort *repo)
{
	if (repo && repo->arr)
		free(repo->arr);
	if (repo)
		free(repo);
}

void	pre_sort(t_deque *deq, int base, t_pivot *piv)
{
	int	max;
	int	min;
	int	len;
	int	i = 0;
	t_ll	bios;
	t_sort	*repo;

	len = check_stack(deq, base, &max, &min);
	repo = make_repo(len);
	bios = 0;
	if (min < 0)
		bios = -1 * min;
	radix_sort(deq, repo, bios, max);
	// printf("size : %d\n", len);
	// while (i < repo->size)
	// 	printf("arr : %lld\n", repo->arr[i++]);
	choose_pivot(piv, repo);
	clear_repo(repo);
}