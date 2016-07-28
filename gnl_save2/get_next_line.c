/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 19:07:44 by aoudin            #+#    #+#             */
/*   Updated: 2016/07/26 17:52:09 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		test_read_next(char *buf, int counter)
{
	int		i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[counter] && buf[counter] != '\n')
	{
		i++;
		counter++;
	}
	return (i);
}

static void		ft_storeline(t_data *gnl, char **line)
{
	char	*str;
	int		len;

	len = test_read_next(gnl->store_buf, 0);
	*line = ft_strndup(gnl->store_buf, len - 1);
	str = gnl->store_buf;
	gnl->store_buf = ft_strsub(str, len + 1, ft_strlen(str) - len);
	gnl->l_read = 1;
	if (str[0] == '\0')
		gnl->l_read = 0;
}

static int		test_read(t_data *gnl, char *buf, int fd, char **line)
{
	int		ret;
	char	*tmp;

	ret = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (!(gnl->store_buf))
			gnl->store_buf = ft_strnew(BUFF_SIZE);
		buf[ret] = '\0';
		tmp = gnl->store_buf;
		gnl->store_buf = ft_strjoin(tmp, buf);
		free(tmp);
	}
	if (ret == -1)
		return (-1);
	if (ret == 0)
	{
		ft_storeline(gnl, line);
		if (gnl->l_read == 1)
		{
			gnl->l_read = 0;
			return (1);
		}
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char			*buf;
	int				i;
	int				ret;
	static t_data	*gnl = NULL;

	i = 0;
	if (!gnl)
	{
		if (!(gnl = (t_data*)ft_memalloc(sizeof(t_data))))
			return (-1);
	}
	if (fd < 0 || !line)
		return (-1);
	if (!(buf = (char*)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	*line = ft_strdup("");
	ret = test_read(gnl, buf, fd, line);
	if (ret == -1)
		return (-1);
	return (ret);
}
