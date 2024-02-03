/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdemiray <rdemiray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:38:05 by rdemiray          #+#    #+#             */
/*   Updated: 2023/08/29 18:29:51 by rdemiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		ft_basic_sort(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) > 5)
		ft_radix(stack_a, stack_b);
}

static	void	ft_get_stack(t_stack **stack, int argc, char **argv)
{
	t_stack	*new;
	char	**split;
	int		i;
	char	*str;

	str = NULL;
	i = 1;
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i++]);
		str = ft_strjoin(str, " ");
	}
	split = ft_split(str, ' ');
	i = 0;
	while (split[i])
	{
		new = ft_lstnew(ft_atoi(split[i++]));
		ft_lstadd_back(stack, new);
	}
	ft_double(*stack);
	ft_free_str(split);
	free(str);
	ft_index(stack);
}

void	ft_check_white_space(char **str)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	j = 0;
	flag = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]))
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			ft_error();
		flag = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return (-1);
	ft_check_white_space(argv);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_get_stack(stack_a, argc, argv);
	if (ft_check_sort(*stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	ft_double(*stack_a);
	ft_stack_sort(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0); 
}
