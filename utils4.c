/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:21:52 by glaverdu          #+#    #+#             */
/*   Updated: 2021/09/28 10:24:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cut_second(int k, char *str, char **argv2, int *i)
{
	if (!k)
	{
		free(argv2[0]);
		argv2[0] = ft_strcat(str, "l97b3a");
		free(str);
		return (argv2);
	}
	printf("command not found: %s\n", argv2[0]);
	*i = 127;
	if (*i != 127)
		*i = 1;
	return (argv2);
}

char	**error_second(char **path, char **argv2)
{
	ft_malloc_error(path);
	return (argv2);
}

char	**cut_first(int k, int *i, char **argv1, char *str)
{
	char	**temp;

	if (!k)
	{
		free(argv1[0]);
		argv1[0] = ft_strcat(str, "");
		free(str);
		return (argv1);
	}
	else
		*i = 12345678;
	temp = (char **)malloc(sizeof(char *) * (2));
	temp[0] = ft_strcat(argv1[0], "");
	temp[1] = NULL;
	if (*i == 12345678)
	{
		ft_malloc_error(argv1);
		return (temp);
	}
	return (argv1);
}

char	**ft_malloc_error2(char **tab, char **tab2)
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
	i = 0;
	while (tab2[i])
	{
		free(tab2[i]);
		i++;
	}
	if (tab2)
		free(tab2);
	return (NULL);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || !fd)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
