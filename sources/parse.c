/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:50:42 by m_kamal           #+#    #+#             */
/*   Updated: 2023/06/02 08:42:31 by m_kamal          ###   ########.fr       */
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
		merged = ft_strjoin(merged, argv[i]);
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

/*	get_numbers:
	Splits the numbers, performs atoi
	Feed into an array and frees
*/
int	*get_numbers(int argc, char **argv)
{
	char	**data;
	char	*merged_data;
	int		*arr;
	int		data_len;
	int		i;

	merged_data = merge_data(argc, argv);
	data_len = count_x(merged_data, ' ');
	data = ft_split(merged_data, ' ');
	arr = malloc(sizeof(int) * data_len);
	i = 0;
	while (i < data_len)
	{
		arr[i] = ft_atoi(data[i]);
		free(data[i]);
		i++;
	}
	free(data);
	free(merged_data);
	return (arr);
}
