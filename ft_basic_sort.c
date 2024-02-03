/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:28:00 by rdemiray          #+#    #+#             */
/*   Updated: 2023/08/29 16:19:53 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min(t_stack *stack)
{
	int		min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

void	ft_3_element(t_stack **stack_a)
{
	t_stack	*temp;
	int		first;
	int		second;
	int		third;

	temp = *stack_a;
	first = temp->content;
	second = temp->next->content;
	third = temp->next->next->content;
	if (first > second && second < third && first < third)
		ft_sa(*stack_a);
	if (first < second && second > third && first < third)
	{
		ft_rra(stack_a);
		ft_sa(*stack_a);
	}
	else if (first > second && second > third)
	{
		ft_sa(*stack_a);
		ft_rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ft_ra(stack_a);
	else if (first < second && second > third && first > third)
		ft_rra(stack_a);
}

void	ft_4_element(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = ft_get_min(*stack_a);
	while ((*stack_a)->content != min)
		ft_rra(stack_a);
	ft_pb(stack_a, stack_b);
	ft_3_element(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_5_element(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		min_value;
	int		i;

	i = 0;
	temp = *stack_a;
	min_value = ft_get_min(*stack_a);
	while (temp->content != min_value)
	{
		i++;
		temp = temp->next;
	}
	if (i < 3)
	{
		while ((*stack_a)->content != min_value)
			ft_ra(stack_a);
	}
	else
	{
		while ((*stack_a)->content != min_value)
			ft_rra(stack_a);
	}
	ft_pb(stack_a, stack_b);
	ft_4_element(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_basic_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 1)
		return ;
	else if (size == 2)
		ft_sa(*stack_a);
	else if (size == 3)
		ft_3_element(stack_a);
	else if (size == 4)
		ft_4_element(stack_a, stack_b);
	else if (size == 5)
		ft_5_element(stack_a, stack_b);
}
