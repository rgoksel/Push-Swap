/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:23:24 by rdemiray          #+#    #+#             */
/*   Updated: 2023/08/29 18:10:37 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				index;
	int				content;
	struct s_stack	*next;
}	t_stack;

void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a);
void	ft_sa(t_stack *stack_a);
void	ft_rra(t_stack **stack_a);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_lstsize(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_atoi(char *str);
int		ft_check_sort(t_stack *stack_a);
int		ft_isdigit(int a);
int		ft_get_min(t_stack *stack);
void	ft_stack_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_give_stack(t_stack **stack_a, char **argv, int argc);
void	ft_basic_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_radix(t_stack **stack_a, t_stack **stack_b);
void	ft_index(t_stack **stack);
void	ft_check_str(char *str);
void	ft_error(void);
void	ft_double(t_stack *stack);
void	ft_free_str(char **str);
void	ft_free_stack(t_stack **stack);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(const char *s, char c);

#endif
