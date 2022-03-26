/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:47:28 by aboumadi          #+#    #+#             */
/*   Updated: 2022/03/19 22:49:50 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <mlx.h>

typedef struct s_all
{
	int		h;
	int		l;
	int		players;
	int		itemse;
	int		exits;
	int		x;
	int		y;
	int		count_mouv;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*player;
	void	*wall;
	void	*hero;
	void	*exit;
	void	*collect;
	void	*floor;
}	t_all;

void	ft_check_extention(char *name);
int		ft_strcmp(char *s1, char *s2);
void	ft_check_extention(char *file);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	check_itms(t_all *map);
void	check_wall(t_all *map);
void	ft_read_map(int fd, t_all *nbl, char *file);
void	ft_intialise(t_all *map);
void	count_line(t_all *nbl, char *file);
char	*get_line(int fd, char	**line);
char	*ft_strjoin(char *str, char *buff);
char	*ft_strchr(char *str, char c);
int		ft_strlen2(const char *str);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_substr(char *src, int s, size_t len);
void	ft_error(int w, t_all *map);
int		count_items(t_all *map, char c);
void	find_player(t_all *map);
int		key_board(int key, t_all *map);
void	ft_mouv(t_all *map, int x, int y);
void	put_image(t_all *map);
void	ft_free(t_all *map);
int		destroy_window(t_all *map);
void	ft_parsing(char **av, t_all *map2);

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
void	ft_putnbr_base10(int nb, int *j);
void	ft_putnbr_base10_ns2(unsigned int nb, int *j);

#endif
