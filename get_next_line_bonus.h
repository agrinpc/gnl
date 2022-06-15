/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:28:15 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/14 16:51:19 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define NUM_BUF 14
# define OPEN_MAX 10240
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, int size_s1, int size_s2);
void	ft_strtcpy(char *dest, char *src, int ints[3], int mod);
void	write_num(char *tmp, int num);
int		read_num(char *tmp);
int		ret_nl_make_zero(char *cur, int ret, int mod);

#endif