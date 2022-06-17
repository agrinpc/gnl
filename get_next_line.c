/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miahmadi <miahmadi@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:31:14 by miahmadi          #+#    #+#             */
/*   Updated: 2022/06/17 15:41:06 by miahmadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	get_res(char *strs[2],
			char **tmp, int ints[3])
{
	if (ints[BYTES_READ] == 0)
	{
		ints[NL_IND] = 1;
		if (!strs[RES_STR] || !strs[RES_STR][0])
		{
			free(strs[RES_STR]);
			strs[RES_STR] = NULL;
			free(*tmp);
			*tmp = NULL;
		}
	}
	else
	{
		ints[NL_IND] = ret_nl_make_zero(strs[CUR_STR], ints[BYTES_READ], 0);
		if (ints[NL_IND] < ints[BYTES_READ] - 1 && ints[NL_IND] >= 0)
		{
			ft_strtcpy(*tmp, strs[CUR_STR], ints, 1);
			write_num(*tmp, ints[BYTES_READ] - ints[NL_IND] - 1);
			ints[BYTES_READ] = ints[NL_IND] + 1;
		}
		strs[RES_STR] = ft_strjoin(strs[RES_STR], strs[CUR_STR], ints[RES_SIZE], ints[BYTES_READ]);
		ints[RES_SIZE] += ints[BYTES_READ];
	}
}

static char	*free_res(char *str)
{
	free(str); 
	str = NULL;
	return (NULL);
}

static int	initialize(char *strs[2], int ints[3], char cur[BUFFER_SIZE], char *tmp)
{
	ints[NL_IND] = -1;
	ints[BYTES_READ] = 0;
	ints[RES_SIZE] = 0;
	strs[RES_STR] = malloc(1);
	if (!strs[RES_STR])
		return (0);
	if (!tmp)
	{
		tmp = malloc(NUM_BUF + BUFFER_SIZE);
		if (!tmp)
			return (free_res(strs[RES_STR]));
		ret_nl_make_zero(tmp, NUM_BUF + BUFFER_SIZE, 1);
	}
	strs[RES_STR][0] = 0;
	strs[CUR_STR] = cur;
	return (1);
}

char	*get_next_line(int fd)
{
	int			ints[3];
	static char	*tmp;
	char		cur[BUFFER_SIZE];
	char		*strs[2];

	if (fd < 0 || read(fd, 0, 0) < 0 || !initialize(strs, ints, cur, tmp))
		return (NULL);
;	while (ints[NL_IND] == -1)
	{
		ints[BYTES_READ] = read_num(tmp);
		if (ints[BYTES_READ] > 0)
		{
			ft_strtcpy(cur, tmp, ints, 0);
			ret_nl_make_zero(tmp, NUM_BUF + BUFFER_SIZE, 1);
		}
		else
			ints[BYTES_READ] = read(fd, cur, BUFFER_SIZE);
		if (ints[BYTES_READ] < 0)
			return (free_res(strs[RES_STR]));
		else
			get_res(strs, &tmp, ints);
	}
	return (strs[RES_STR]);
}

int main()
{
	char *s;
	int fd;
	
	fd = open("test", O_RDONLY);
	s = "";
	sleep(2);
	while (s)
	{
		s = get_next_line(fd);
		// printf("%s\n", s);
		free(s);
	}
	return (0);
}
