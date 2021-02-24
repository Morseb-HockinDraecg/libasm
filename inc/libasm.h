/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:21:19 by smorel            #+#    #+#             */
/*   Updated: 2021/02/22 10:21:20 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

ssize_t		ft_strlen(char *str);
char		*ft_strcpy(char *dest, char *src);
int			ft_strcmp(char *str2, char *str1);
ssize_t		ft_write(int fd, char *buf, size_t len);
ssize_t		ft_read(int fd, char *buf, size_t len);
char		*ft_strdup(char *str);

#endif
