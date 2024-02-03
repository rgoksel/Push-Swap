/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:05:28 by rdemiray          #+#    #+#             */
/*   Updated: 2023/08/28 21:09:51 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack_a)
{
	int	tmp;
	int	a;

	a = ft_lstsize(stack_a);
	if (a <= 1)
		return ;
	if (stack_a && stack_a->next)
	{
		tmp = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = tmp;
	}
	write(1, "sa\n", 3);
}

void	ft_rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*next_null;
	t_stack	*tmp2;
	int		a;

	a = ft_lstsize(*stack_a);
	if (a <= 1)
		return ;
	tmp2 = *stack_a;
	tmp = ft_lstlast(*stack_a);
	while ((*stack_a)->next)
	{
		next_null = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	tmp->next = tmp2;
	next_null->next = NULL;
	write(1, "rra\n", 4);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		b;

	b = ft_lstsize(*stack_b);
	if (!b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		a;

	a = ft_lstsize(*stack_a);
	if (a == 0)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "pb\n", 3);
}

void	ft_ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	last = ft_lstlast(*stack_a);
	last->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}
