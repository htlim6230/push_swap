/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hui-tinl <hui-tinl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 20:17:14 by hui-tinl          #+#    #+#             */
/*   Updated: 2026/11/26 20:26:41 by hui-tinl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
input


ft_atoi // converts a string to an integer to check all is integer

void parse_inputs(int argc, char **argv, t_data *data)
{
    int i;
    int j;

    data->size_a = argc - 1;
    data->a = malloc(sizeof(int) * data->size_a);
    data->b = malloc(sizeof(int) * data->size_a);
    if (!data->a || !data->b)
        exit(EXIT_FAILURE); // Handle memory allocation failure

    for (i = 0; i < data->size_a; i++)
    {
        data->a[i] = ft_atoi(argv[i + 1]);
        // Check for duplicates
        for (j = 0; j < i; j++)
        {
            if (data->a[i] == data->a[j])
            {
                fprintf(stderr, "Error: Duplicate values are not allowed.\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    data->size_b = 0; // Initialize size of stack B
}