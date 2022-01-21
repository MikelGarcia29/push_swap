/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <mikgarci@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:33:07 by mikgarci          #+#    #+#             */
/*   Updated: 2021/09/11 12:09:57 by mikgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_content
{
	int	firsta;
	int	firstb;
	int	seconda;
	int	lasta;
	int	medium;
	int	small;
	int	sizea;
	int	sizeb;
	int	cont;
	int	*list;
	int	error;
}	t_content;

char	**ft_split(char const *s, char c);
void	ft_moves(t_list **heada, t_list **headb, t_content *value);
void	ft_move1(t_list **heada, t_list **headb, t_content *value, int index);
void	ft_move2(int *change, int group, int *x, t_content *value);
int		ft_move3(t_list **heada, t_list **headb, int change);
void	ft_move4(t_list **heada, t_list **headb, t_content *value);
void	ft_fillstacks(t_list **heada, t_list **headb, int argc, char *argv[]);
void	ft_printlist(t_list *heada, t_list *headb);
int		ft_fillmedium(char **argv, int argc, t_content *value, int size);
int		ft_searchvalue(int x, int y, t_content *value, t_list *headA);
void	ft_frombtoa(t_list **heada, t_list **headb, t_content *value);
void	ft_frombtoa2(t_list **heada, t_list **headb,
			t_content *value, int index);
int		ft_mediumnum(int *temp, int size, t_content *value);
void	ft_allposition(t_list *heada, t_content *value);
void	ft_fillvalues(t_list *heada, t_list *headb, t_content *value);
void	ft_smallmoves(t_list **heada, t_content *value);
int		ft_orderstacka(t_list *heada, t_content *value);
int		ft_orderstacka2(t_list *heada, t_content *value);
int		ft_lstposition(t_list *heada, int value);
int		ft_groups(t_content *value);
int		ft_atoi(const char *str, int *a);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstnewnode(int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_swapa(t_list **heada);
void	ft_swapb(t_list **headb);
void	ft_pushb(t_list **heada, t_list **headb);
void	ft_pusha(t_list **heada, t_list **headb);
void	ft_rotatea(t_list **heada);
void	ft_rotateb(t_list **headb);
void	ft_reverserotatea(t_list **heada);
void	ft_reverserotateb(t_list **headb);
void	ft_mediummove(t_list **heada, t_list **headb, t_content *value);
void	ft_mediummove2(t_content *value, t_list **heada, int index);
void	ft_freeall(t_content *value, t_list **heada);
int		ft_isdigit(int c);
int		ft_check(int argc, char *argv[]);
int		ft_watchrepeat(t_content *list, int size);
int		*ft_createlist(int *list, t_list *temp, int sizea);
void	ft_mainmoves(t_list	**heada, t_list **headb, t_content *value);

#endif
