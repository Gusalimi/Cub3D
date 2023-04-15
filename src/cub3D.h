/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:12:26 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/27 16:22:07 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../.MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

# define BLC 100
# define SPEED 10
# define FOV 60
# define RAY 720
# define ROTATE_CAM 2
# define LOOK 580

typedef struct s_texture
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*c;
	char			*f;
	int				crgb[3];
	int				frgb[3];
	mlx_texture_t	*no_t;
	mlx_texture_t	*so_t;
	mlx_texture_t	*we_t;
	mlx_texture_t	*ea_t;
	mlx_image_t		*no_i;
	mlx_image_t		*so_i;
	mlx_image_t		*we_i;
	mlx_image_t		*ea_i;
	mlx_image_t		*render;
}					t_txtur;

typedef struct s_player
{
	float	p_x;
	float	p_y;
	float	p_l;
	float	*r_x;
	float	*r_y;
	char	*r_w;
}				t_player;

typedef struct s_map
{
	char			**map;
	t_txtur			img;
	t_player		p;
	mlx_t			*mlx;
	int				s_x;
	int				s_y;
}					t_map;

/* (}---------------{         Parsing         }------------------{) */
t_map				*init_map(int argc, char **argv);
void				*check_map(t_map *map);
char				**get_map(char *file, t_map *map, char *line, char *temp);
int					resize_map(t_map *map, int i, int size);

/* (}---------------{      Move and play     }------------------{) */
void				move_player(t_map *m, char dir);
void				rotate_cam(t_map *map, char dir);
int					can_move(t_map *map, char dir);

/* (}---------------{         Raycast        }------------------{) */
void				set_radius(t_map *map, float rad, int i);

/* (}---------------{        Display2D       }------------------{) */
int					display2D(t_map *map);
void				draw_line(t_map *map);

/* (}---------------{        Display3D       }------------------{) */
void				display_3d(t_map *map, float rad_c);
int					get_rgba(int r, int g, int b, int a);
uint8_t				*get_add_ea(t_map *m, float hp, float p, int i);
uint8_t				*get_add_no(t_map *m, float hp, float p, int i);
uint8_t				*get_add_so(t_map *m, float hp, float p, int i);
uint8_t				*get_add_we(t_map *m, float hp, float p, int i);

/* (}---------------{          Utils         }------------------{) */
void				*dsp_error(char *text);
char				**dsp_error_read(char *text);
void				*free_tab(char **tab);
void				*free_map(t_map *map);
char				*ft_catline(char *dest, char *src);
int					has_nl(char *line);
void				good_wall(t_map *map);

/* (}---------------{           Init         }------------------{) */
int					get_assets(char **s);
int					get_colors(char *s, int tab[3]);
int					init_textures(t_map *map);
void				check_info(t_map *map, char *temp);

#endif
