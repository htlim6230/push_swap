/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:13:32 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/26 16:13:47 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data, t_stats *stats, int print)
{
	int	temp;
	int	i;

	if (data-> size_a < 2) // guard check if got enough elements to swap
		return ;
	temp = data->a[0]; // store the first element in a temporary variable
	i = 0;
	while (i < (data->size_a - 1)) // (size_a-1) to get last index of array, so we don't go overbound in data->a[i+1]
	{
		data->a[i] = data->a[i + 1];
		i++;
	}
	data->a[data->size_a - 1] = temp;
	if (stats)
		stats->ra++;
	if (print)
		write(1, "ra\n", 3);
	//ft_putstr_fd("ra", 1);
}

void	rb(t_data *data, t_stats *stats, int print)
{
	int	temp;
	int	i;

	if (data-> size_b < 2)
		return ;
	temp = s->b[0];
	i = 0;
	while (i < (s->size_b - 1))
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[size_b - 1] = temp;
	if (stats)
		stats->rb++;
	if (print)
	write(1, "rb\n", 3);
	//ft_putstr_fd("rb", 1);
}

void	rr(t_data *s, t_stats *stats)
{
	ra(s, NULL, 0);
	rb(s, NULL, 0);
	if (stats)
		stats->rr++;
	if (print)
	write(1, "rr\n", 3);
	//ft_putstr_fd("rr", 1);
}

void	rra(t_data *data, t_stats *stats, int print)
{
	int	temp;
	int	i;

	if (data-> size_a < 2)
		return ;
	temp = data->a[data->size_a - 1];
	i = data->size_a - 1;
	while (i > 0)
	{
		data->a[i] = data->a[i - 1];
		i--;
	}
	data->a[0] = temp;
	if (stats)
		stats->rra++;
	if (print)
	write(1, "rra\n", 4);
	//ft_putstr_fd("rra", 1);
}

void	rrb(t_data *data, t_stats *stats, int print)
{
	int	temp;
	int	i;

	if (data-> size_b < 2)
		return ;
	temp = data->b[data->size_b - 1];
	i = data->size_b - 1;
	while (i > 0)
	{
		data->b[i] = data->b[i - 1];
		i--;
	}
	data->b[0] = temp;
	if (stats)
		stats->rrb++;
	if (print)
	write(1, "rrb\n", 4);
	//ft_putstr_fd("rrb", 1);
}

void	rrr(t_data *data, t_stats *stats, int print)
{
	rra(data, NULL, 0);
	rrb(data, NULL, 0);
	if (stats)
		stats->rrr++;
	if (print)
	write(1, "rrr\n", 5);
	//ft_putstr_fd("rrr", 1);
}