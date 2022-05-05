/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:21:52 by glaverdu          #+#    #+#             */
/*   Updated: 2021/09/28 10:24:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"pipex.h"

void	ft_close_tab(int *tab_fd, char **argv1, char **argv2)
{
	ft_malloc_error2(argv1, argv2);
	if (tab_fd[0] != -1)
		close(tab_fd[0]);
	if (tab_fd[1] != -1)
		close(tab_fd[1]);
}

int	ft_what_to_return(int *tab_fd, int i)
{
	if (tab_fd[1] == -1)
		i = 1;
	if (i != 0)
		return (i);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		tab_fd[2];
	char	**argv1;
	char	**argv2;

	i = 0;
	if (argc != 5)
		return (temp_print_error());
	tab_fd[0] = open(argv[1], O_RDONLY);
	if (tab_fd[0] == -1)
		printf("%s: %s\n", strerror(errno), argv[1]);
	tab_fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (tab_fd[1] == -1)
		printf("%s: %s\n", strerror(errno), argv[4]);
	argv1 = create_argv1(argv, &i);
	if (tab_fd[0] == -1)
		argv1[0][0] = '\0';
	argv2 = create_argv2(argv, &i, argv1, tab_fd);
	if (tab_fd[1] == -1)
		argv2[0][0] = '\0';
	i = try_to_cut(argv1, argv2, i, tab_fd);
	ft_close_tab(tab_fd, argv1, argv2);
	return (ft_what_to_return(tab_fd, i));
}
