/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:14:00 by ceccentr          #+#    #+#             */
/*   Updated: 2020/08/19 11:14:17 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include <math.h>
# define TEXT_SIZE 64
# define SPEED 0.2
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define LEFT 123
# define RIGHT 124
# define SPACE 49

typedef	struct		s_config
{
	int				win_w;
	int				win_h;
	int				map_w;
	int				map_h;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
	int				floor[3];
	int				ceilling[3];
	char			*map_temp;
}					t_conf;

typedef struct		s_pic
{
	void			*texture;
	char			*addr;
	int				img_width;
	int				img_height;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	float			sprite_x;
	float			sprite_y;
	int				text_id;
	struct s_pic	*next;
}					t_pic;

typedef struct		s_data
{
	void			*img;
	void			*mlx;
	void			*mlx_win;
	int				img_width;
	int				img_height;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	float			player_x;
	float			player_y;
	float			player_a;
	int				sprite_x;
	int				sprite_y;
	char			*map;
	size_t			rect_w;
	size_t			rect_h;
	float			fov;
	float			*t;
	int				column_h;
	int				hp;
	int				hand;
	int				bonus;
	int				screen;
	t_pic			*pic;
	t_conf			*config;
}					t_data;

int					ft_exit(int keycode, t_data *img);
int					config(t_conf *param, t_data *img, char *arg);
void				clear_buf(char **buf);
int					ft_color(t_conf *param, char *line);
int					ft_map(t_conf *param, char *line);
int					ft_parse_map(t_conf *param, t_data *img);
int					ft_parse_pos(t_data *img, t_conf *config, char *text_id);
t_pic				*ft_new_elem(t_data *img, char *text_id, int y, int sprid);
unsigned int		ft_puck_rgb(unsigned int r, unsigned int g, unsigned int b);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int		my_mlx_pixel_take(t_pic *data, int x, int y);
int					ft_render(t_data *img, float ray_x, float ray_y, int i);
t_pic				*ft_search_texture_id(t_data *img, int	text_id);
int					ft_ray(t_data *img);
int					ft_key(int keycode, t_data *img);
int					ft_check_wall(t_data *img);
int					ft_sprite(t_data *img);
int					ft_ceilling(t_data *img, int i, float t, float ray);
int					ft_floor(t_data *img, int i, float t, float ray);
unsigned int		ft_load_picture(t_data *img, int x, int y, int textid);
int					ft_shoot(t_data *img);
int					ft_check_wh(t_conf *param, t_data *img, char *arg);
int					ft_sort(t_data *img, float *dist, int *sort);
int					ft_screenshot(t_data *img, char *str);
void				int_to_char(unsigned char *c, int i);
void				init_param(t_conf *param);

#endif
