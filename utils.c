/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:21:52 by glaverdu          #+#    #+#             */
/*   Updated: 2021/09/28 10:24:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	return (NULL);
}

char	**check_first_cmd(int *i, char **argv1)
{
	char	*str;
	char	**path;
	int		k;

	k = 0;
	path = ft_split(getenv("PATH"), ':');
	if (access(argv1[0], F_OK) == 0)
	{
		ft_malloc_error(path);
		return (argv1);
	}
	while (path[k])
	{
		str = ft_strcat(path[k], argv1[0]);
		if (access(str, F_OK) == 0)
		{
			k = 0;
			break ;
		}
		k++;
		free(str);
	}
	ft_malloc_error(path);
	return (cut_first(k, i, argv1, str));
}

int	ft_cut_check_second(int k, char **argv1)
{
	k = 0;
	while ((argv1[0][k] != '/' || argv1[0][k + 1] != '\0')
			&& argv1[0][k] != '\0')
		k++;
	return (k);
}

char	**check_second_cmd(int *i, char **argv2, char **argv1, int *tab_fd)
{
	char	*str;
	char	**path;
	int		k;

	k = 0;
	k = ft_cut_check_second(k, argv1);
	argv1[0][k] = '\0';
	k = -1;
	if (*i == 12345678 && tab_fd[0] != -1)
		printf("command not found: %s\n", argv1[0]);
	path = ft_split(getenv("PATH"), ':');
	if (access(argv2[0], F_OK) == 0)
		return (error_second(path, argv2));
	while (path[++k])
	{
		str = ft_strcat(path[k], argv2[0]);
		if (access(str, F_OK) == 0)
			k = 0;
		if (access(str, F_OK) == 0)
			break ;
		free(str);
	}
	ft_malloc_error(path);
	return (cut_second(k, str, argv2, i));
}
