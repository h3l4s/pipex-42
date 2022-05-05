/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:21:52 by glaverdu          #+#    #+#             */
/*   Updated: 2021/09/28 10:28:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/types.h>
# include <sys/wait.h>

char	**ft_split(char const *s, char c);
int		fork1(int fd[], char **argv1, char **argv);
int		fork2(int fd[], char **argv2, char **argv);
char	**check_first_cmd(int *i, char **argv1);
char	*ft_strcat(char *src2, char *src);
char	**check_second_cmd(int *i, char **argv2, char **argv1, int *tab_fd);
int		temp_print_error(void);
int		check_return_value(int i, int pid2, int pid1);
int		try_to_cut(char **argv1, char **argv2, int i, int *tab_fd);
int		temp_pid1(int *fd, char **argv1, int fdFile);
int		temp_pid2(int *fd, char **argv2, int fdFile2);
char	**create_argv1(char **argv, int *i);
char	**create_argv2(char **argv, int *i, char **argv1, int *tab_fd);
char	**ft_malloc_error(char **tab);
char	**test(char **argv2, char **argv, int i);
char	**cut_first(int k, int *i, char **argv1, char *str);
char	**error_second(char **path, char **argv2);
char	**cut_second(int k, char *str, char **argv2, int *i);
char	**ft_malloc_error2(char **tab, char **tab2);
int		ft_what_to_return(int *tab_fd, int i);
void	ft_close_tab(int *tab_fd, char **argv1, char **argv2);
int		ft_cut_check_second(int k, char **argv1);

#endif
