/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:48:49 by abonnefo          #+#    #+#             */
/*   Updated: 2023/02/01 16:59:49 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define ESC 65307
# define W 119
# define A 97
# define D 100
# define S 115
# define UP 65362
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>
# include <string.h>

# include "../includes/ft_printf.h"
# include "../includes/get_next_line.h"
# include "../includes/libft.h"
# include "../minilibx/mlx.h"

typedef struct s_image {
	int		img_width;
	int		img_height;
	void	*img_sand;
	void	*img_cactus;
	void	*img_cowboy;
	void	*img_gold;
	void	*img_horse;
	char	*path_sand;
	char	*path_cactus;
	char	*path_cowboy;
	char	*path_gold;
	char	*path_horse;
}				t_image;

typedef struct s_data {
	void			*mlx;
	void			*mlx_ptr;
	void			*mlx_win;
	char			**tab;
	int				window_width;
	int				window_height;
	int				count;
	int				size_x;
	int				size_y;
	int				x;
	int				y;
	int				player_y;
	int				player_x;
	int				offset_x;
	int				offset_y;
	int				collectible;
	struct s_image	*img;
}				t_data;

/********************************* check_items ********************************/

int		ft_count_items(char **tab, char elem);
int		ft_check_items(char **tab);

/******************************* check_lines_map ******************************/

int		ft_check_first_and_last_line(char **tab);
int		ft_check_first_and_last_side(char **tab);
int		ft_check_equal_lenght(char **tab);

/********************************** check_map *********************************/

void	ft_check_backslash(char *str);
int		ft_check_if_rectangle(char **tab);

/********************************* check_path *********************************/

int		ft_search_perso_x(int y, int x, char to_find, char **tab);
int		ft_search_perso_y(int y, int x, char to_find, char **tab);
void	ft_map_replace_e(char **tab, int size_y, int size_x);

/******************************* close_window *******************************/

void	ft_exit_game(t_data *data);
int		ft_close_esc(int keycode, t_data *data);
int		ft_close_mouse(t_data *data);

/********************************* key_press *********************************/

int		ft_key_press(int keycode, t_data *data);

/********************************* move_perso *********************************/

void	ft_move_up(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_left(t_data *data);
void	ft_move_right(t_data *data);

/********************************* put_in_tab *********************************/

void	ft_free_tab(char **tab);
char	**ft_put_in_tab(char *map);
void	ft_search_and_replace(char **tab, int y, int x);
int		ft_check_ultimate_path(char **tab);

/******************************* put_in_window *******************************/

void	ft_put_into_window(t_data *data, char **tab);
void	ft_init_images(t_image *img);

/*********************************** utils ***********************************/

int		ft_count_width(char **tab);
int		ft_count_height(char **tab);

#endif