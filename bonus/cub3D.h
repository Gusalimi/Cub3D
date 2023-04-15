/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:12:26 by fcherrie          #+#    #+#             */
/*   Updated: 2023/03/27 13:08:19 by fcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../.MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define BLC 100
# define SPEED 10
# define FOV 60
# define RAY 720
# define ROTATE_CAM 4
# define LOOK 580

typedef struct s_texture
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*door;
	char			*do1;
	char			*do2;
	char			*do3;
	char			*do4;
	char			*do5;
	char			*do6;
	char			*do7;
	char			*do8;
	char			*c;
	char			*f;
	int				crgb[3];
	int				frgb[3];
	mlx_image_t		*door_i;
	mlx_image_t		*do1_i;
	mlx_image_t		*do2_i;
	mlx_image_t		*do3_i;
	mlx_image_t		*do4_i;
	mlx_image_t		*do5_i;
	mlx_image_t		*do6_i;
	mlx_image_t		*do7_i;
	mlx_image_t		*do8_i;
	mlx_image_t		*no_i;
	mlx_image_t		*so_i;
	mlx_image_t		*we_i;
	mlx_image_t		*ea_i;
	mlx_image_t		*render;
	mlx_image_t		*mmap;
}					t_txtur;

typedef struct s_player
{
	float	p_x;
	float	p_y;
	float	p_l;
	float	*r_x;
	float	*r_y;
	char	*r_w;
	float	*r_c;
	int		j;
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

/* (}---------------{      Move and play     }------------------{) */
void				move_player(t_map *m, char dir);
void				rotate_cam(t_map *map, char dir);
int					can_move(t_map *map, char dir);

/* (}---------------{         Raycast        }------------------{) */
void				set_radius(t_map *map, float rad, int i);

/* (}---------------{        Display2D       }------------------{) */
int					display2D(t_map *map);
void				draw_line(t_map *map);
void				display_minimap(t_map *map);

/* (}---------------{        Display3D       }------------------{) */
void				display_3d(t_map *map, float rad_c);
int					get_rgba(int r, int g, int b, int a);
uint8_t				*get_add_ea(t_map *m, float hp, float p, int i);
uint8_t				*get_add_no(t_map *m, float hp, float p, int i);
uint8_t				*get_add_so(t_map *m, float hp, float p, int i);
uint8_t				*get_add_we(t_map *m, float hp, float p, int i);
uint8_t				*get_add_dea(t_map *m, float hp, float p, int i);
uint8_t				*get_add_dno(t_map *m, float hp, float p, int i);
uint8_t				*get_add_dso(t_map *m, float hp, float p, int i);
uint8_t				*get_add_dwe(t_map *m, float hp, float p, int i);

/* (}---------------{         Texture       }------------------{) */
int					init_door(t_map *map, mlx_texture_t *tmp_t);
int					init_do1(t_map *map, mlx_texture_t *tmp_t);
int					init_do2(t_map *map, mlx_texture_t *tmp_t);
int					init_do3(t_map *map, mlx_texture_t *tmp_t);
int					init_do4(t_map *map, mlx_texture_t *tmp_t);
int					init_do5(t_map *map, mlx_texture_t *tmp_t);
int					init_do6(t_map *map, mlx_texture_t *tmp_t);
int					init_do7(t_map *map, mlx_texture_t *tmp_t);
int					init_do8(t_map *map, mlx_texture_t *tmp_t);
/* (}---------------{          Utils         }------------------{) */
void				*dsp_error(char *text);
char				**dsp_error_read(char *text);
void				*free_tab(char **tab);
void				*free_map(t_map *map);
char				*ft_catline(char *dest, char *src);
int					has_nl(char *line);
void				good_wall(t_map *map);
void				look_for_door(t_map *map, char *temp);
void				look_for_wall(t_map *map, char *temp);

/* (}---------------{           Init         }------------------{) */
int					get_assets_all(t_map *map);
int					get_assets(char **s);
int					get_colors(char *s, int tab[3]);
int					init_textures(t_map *map);

#endif
