/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:25:57 by smorel            #+#    #+#             */
/*   Updated: 2021/02/18 10:26:24 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libasm.h>

static void	local_str_len_cpy_cmp(void)
{
	char str1[50];
	char str2[50];
	char str3[50];

	printf("\tft_strlen\n\n");
	printf("length difference : %lu\n", ft_strlen("test") - strlen("test"));
	printf("length difference : %lu\n", ft_strlen("") - strlen(""));
	printf("length difference : %lu\n", ft_strlen("hello world") -\
	strlen("hello world"));
	printf("-------------------------------\n");
	printf("\tft_strcpy\n\n");
	strcpy(str1, "Ceci est un test ! ");
	strcpy(str3, "Hello!:p");
	ft_strcpy(str2, str1);
	printf("cmp str1|str2: %d\t|%s|\t|%s|\n", strcmp(str1, str2), str1, str2);
	ft_strcpy(str2, str3);
	printf("cmp str3|str2: %d\t|%s|\t|%s|\n", strcmp(str3, str2), str3, str2);
	printf("-------------------------------\n\n");
	printf("\tft_strcmp\n\n");
	printf("cmp diff str1|str2: %d\t|%s|\t|%s|\n", ft_strcmp(str1, str2)\
	- strcmp(str1, str2), str2, str1);
	printf("cmp diff str1|str2: %d\t|%s|\t|%s|\n", ft_strcmp(str2, str1)\
	- strcmp(str2, str1), str2, str1);
	printf("cmp diff str3|str2: %d\t|%s|\t|%s|\n", ft_strcmp(str3, str2)\
	- strcmp(str3, str2), str3, str2);
}

static void	local_strdup(void)
{
	char str1[50];
	char *str2;
	char str3[50];

	ft_strcpy(str1, "Coucou les petits loups");
	ft_strcpy(str3, "It's working !!");
	str2 = NULL;
	printf("-------------------------------\n\n");
	printf("\tft_strdup\n\n");
	str2 = ft_strdup(str1);
	printf("|%s|\t|%s|\n", str2, str1);
	free(str2);
	str2 = ft_strdup(str3);
	printf("|%s|\t|%s|\n", str2, str3);
	free(str2);
}

static void	local_write_and_read(char *file)
{
	int		i;
	int		fd;
	char	*buf;
	int		ret;

	i = 10;
	printf("-------------------------------\n\n");
	printf("\t%dx : ft_write\n\n", i);
	while (i--)
		ft_write(1, "Hello\n", 6);
	printf("-------------------------------\n\n");
	printf("\tft_read\n\n");
	fd = open(file, O_RDONLY);
	buf = malloc(21);
	if ((ret = ft_read(fd, buf, 200)) < 0)
		return ;
	buf[ret] = '\0';
	printf("%s\n", buf);
	free(buf);
}

int			main(int argc, char **argv)
{
	(void)argc;
	local_str_len_cpy_cmp();
	local_strdup();
	local_write_and_read(argv[1]);
	return (0);
}
