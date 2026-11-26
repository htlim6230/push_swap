/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:56:08 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/26 16:14:01 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef	struct s_data
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_data;

/* Helper: Find the array index of the element with a specific rank */
static int	get_pos_by_index(int *data, int size, int target_idx)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (data[i] == target_idx)
			return (i);
		i++;
	}
	return (-1);
}

/* Phase 1: Push elements from A to B in n chunks */
void	push_chunks_to_b(t_data *data, int num_chunks)
{
	int	total_size;
	int	chunk_size;
	int	current_limit;
	int	pushed;

	total_size = data->size_a;
	chunk_size = total_size / num_chunks;
	current_limit = chunk_size;
	pushed = 0;
	while (data->size_a > 0)
	{
		if (data->a[0] < current_limit)
		{
			pb(data);
            /* Butterfly optimization: rotate B if in the lower half of the chunk */
			if (data->b[0] < current_limit - (chunk_size / 2))
				rb(data);
			pushed++;
		}
		if (pushed == current_limit && current_limit < total_size)
			current_limit += chunk_size;
		else
			ra(data);
	}
}

/* Phase 2: Pull largest elements from B back to A in order */
void	push_back_to_a(t_data *data)
{
	int	max_idx;
	int	pos;

	max_idx = data->size_b - 1;
	while (data->size_b > 0)
	{
		pos = get_pos_by_index(data->b, data->size_b, max_idx);
        /* Rotate B using the shortest path based on current size_b */
		if (pos <= data->size_b / 2)
		{
			while (data->b[0] != max_idx)
				rb(data);
		}
		else
		{
			while (data->b[0] != max_idx)
				rrb(data);
		}
		pa(data);
		max_idx--;
	}
}

/* Entry point */
void	chunk_sort(t_data *data)
{
	int	num_chunks;

	if (data->size_a <= 100)
		num_chunks = 5;
	else
		num_chunks = 12;
	push_chunks_to_b(data, num_chunks);
	push_back_to_a(data);
}
