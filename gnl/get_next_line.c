/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudin <aoudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 19:07:44 by aoudin            #+#    #+#             */
/*   Updated: 2016/07/27 18:02:35 by aoudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			test_read_next(char *str, int counter)
{
	int				i;

	i = 0;
	if (!str)
		return (0);
	while (str[counter] && str[counter] != '\n')
	{
		i++;
		counter++;
	}
	return (i);
}

static void			ft_storeline(t_data *gnl, char **line)
{
	char			*str;
	int				len;

	len = test_read_next(gnl->store_buf, 0);
	*line = ft_strndup(gnl->store_buf, len - 1);
	str = gnl->store_buf;
	gnl->store_buf = ft_strsub(str, len + 1, ft_strlen(str) - len);
	gnl->l_read = 1;
	if (str[0] == '\0')
		gnl->l_read = 0;
	free(str);
}

static int			test_read(t_data *gnl, char *buf, int fd, char **line)
{
	int				ret;
	char			*tmp;

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

/*static t_data		*ft_find_fd(t_data **begin_list, int fd)
{
	t_data			*tmp_list;

	tmp_list = *begin_list;
	if (tmp)
	{
		while (tmp)
		{
			if (fd == tmp->i_fd)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(gnl, tmp);
	return (tmp);
}
*/
int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static t_data	*gnl = NULL;
	t_data			*begin_list;

	if (fd < 0 || line == NULL || read(fd, buf, 0))	
		return (-1);
	if (!gnl)
	{
		if (!(gnl = (t_data*)ft_memalloc(sizeof(t_data))))
			return (-1);
	}
//	gnl.i_fd = fd;
//	begin_list = gnl;
//	gnl = ft_find_fd(begin_list, fd);
	ret = test_read(gnl, buf, fd, line);
	if (ret == -1)
		return (-1);
	return (ret);
}
