/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 21:59:00 by marza-ga          #+#    #+#             */
/*   Updated: 2022/07/15 10:31:38 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_leaks(void)
{
}

void	get_map_name(t_mlx *mlx, int argc, char **argv)
{
	int	i;

	if (argc != 2)
		exit_error_get_map_name(1, mlx);
	i = -1;
	while (argv[1][++i])
		;
	if (i < 4)
		exit_error_get_map_name(2, mlx);
	if (argv[1][i] != '\0' || argv[1][i - 1] != 'b' || argv[1][i - 2]
		!= 'u' || argv[1][i - 3] != 'c' || argv[1][i - 4] != '.')
		exit_error_get_map_name(3, mlx);
	mlx->map_name = argv[1];
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	errno = 0;
	if (!mlx.mlx_ptr)
		return (0);
	get_map_name(&mlx, argc, argv);
	mlx.map = parse_initial_map(&mlx);
	check_map(&mlx);
	init_raycast_vars(&mlx);
	init_game_data(&mlx);
	init_game_images(&mlx);
	mlx.win = mlx_new_window(mlx.mlx_ptr, 640, 480, "CUB3D");
	errno = 0;
	mlx_do_key_autorepeaton(mlx.mlx_ptr);
	mlx_mouse_move(mlx.win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	mlx_mouse_hide();
	mlx_hook(mlx.win, 2, 0, input, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &render, &mlx);
	mlx_hook(mlx.win, 17, 0, &exit_game, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
