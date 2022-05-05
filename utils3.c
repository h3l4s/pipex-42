/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:21:52 by glaverdu          #+#    #+#             */
/*   Updated: 2021/09/28 10:24:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**create_argv1(char **argv, int *i)
{
	char	**argv1;

	argv1 = ft_split(argv[2], ' ');
	argv1 = check_first_cmd(i, argv1);
	return (argv1);
}

char	**create_argv2(char **argv, int *i, char **argv1, int *tab_fd)
{
	char	**argv2;

	argv2 = ft_split(argv[3], ' ');
	argv2 = check_second_cmd(i, argv2, argv1, tab_fd);
	return (argv2);
}

int	temp_strcat(char *src, char *str, int i, int j)
{
	str[i++] = '/';
	while (src[j])
		str[i++] = src[j++];
	return (i);
}

char	*ft_strcat(char *src2, char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!src2 || !src)
		return (NULL);
	while (src2[i])
		i++;
	while (src[j])
		j++;
	str = malloc(sizeof(char) * ((i + j) + 2));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (src2[j])
		str[i++] = src2[j++];
	j = 0;
	if (!(src[0] == 'l' && src[1] == '9' && src[2] == '7'
			&& src[3] == 'b' && src[4] == '3' && src[5] == 'a'))
		i = temp_strcat(src, str, i, j);
	str[i] = '\0';
	return (str);
}
