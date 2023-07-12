/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:50:42 by m_kamal           #+#    #+#             */
/*   Updated: 2023/06/06 19:25:36 by m_kamal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/*	Merge_data:
	Joins all argv into one string
	Returns: Merged string
*/
static char	*merge_data(int argc, char **argv)
{
	int		i;
	char	*merged;

	i = 1;
	merged = ft_strdup("");
	while (i < argc)
	{
		merged = modded_strjoin(merged, argv[i]);
		i++;
	}
	return (merged);
}

static int	count_x(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

/*	Parse_data:
	Splits the numbers, performs atoi
	Feed into an array and frees
*/
t_data	*parse_data(int argc, char **argv)
{
	t_data	*data;
	char	**parsed_data;
	int		i;

	data = malloc(sizeof(t_data));
	data->merged_data = merge_data(argc, argv);
	data->data_len = count_x(data->merged_data, ' ');
	parsed_data = ft_split(data->merged_data, ' ');
	data->arr = malloc(sizeof(int) * (data->data_len));
	i = 0;
	while (i < data->data_len)
	{
		data->arr[i] = ft_atoi(parsed_data[i]);
		free(parsed_data[i]);
		i++;
	}
	free(parsed_data);
	return (data);
}
