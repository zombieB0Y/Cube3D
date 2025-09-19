#include "../cube.h"

void	add_border(void)
{
	char	**new_map;
	int		i;

	i = 0;

	new_map = gc_malloc(sizeof(char *) * (cube()->parse->map->height + 3));
	if (!new_map)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
	while (i < cube()->parse->map->height + 2)
    {
        new_map[i] = gc_malloc(sizeof(char) * (cube()->parse->map->width + 3));
        if (!new_map[i])
        {
            gc_collect();
            exit(EXIT_FAILURE);
        }
        ft_memset(new_map[i], ' ', cube()->parse->map->width + 2);
        new_map[i][cube()->parse->map->width + 2] = '\0';
        i++;
    }
	new_map[i] = NULL;
	i = 0;
	int j;
	j = 0;
	while (i < cube()->parse->map->height)
	{
		j = 0;
		while ((size_t)j < ft_strlen(cube()->parse->map->map[i]))
		{
			new_map[i + 1][j + 1] = cube()->parse->map->map[i][j];
			j++;
		}
		i++;
	}
	cube()->parse->map->map = new_map;
}

char	*get_tmp(void)
{
	while (1)
	{
		cube()->parse->tmp = get_next_line(cube()->fd);
		if (!cube()->parse->tmp)
			break ;
		if (!check_for_whitespace(cube()->parse->tmp))
			break ;
	}
	if (!cube()->parse->tmp)
	{
		ft_putstr_fd("Error: empty map file\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
	return (cube()->parse->tmp);
}

void	check_for_valid_map(void)
{
	if (cube()->parse->map->height == 0 || cube()->parse->map->width == 0)
	{
		ft_putstr_fd("Error: empty map\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
	add_border();
}
void	init_line()
{

	if (!cube()->parse->tmp)
		cube()->parse->line = get_next_line(cube()->fd);
	else
	{
		cube()->parse->line = cube()->parse->tmp;
		cube()->parse->tmp = NULL;
	}
}
void	alloc_space(bool valid)
{
	if (valid)
	{
		ft_putstr_fd("Error: wawawa\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
	if (!cube()->parse->map->map)
		cube()->parse->map->map = gc_malloc(sizeof(char *) * 1);
	else
		cube()->parse->map->map = ft_realloc(cube()->parse->map->map, sizeof(char *) * (cube()->parse->map->height),
						sizeof(char *) * (cube()->parse->map->height + 2));
	if (!cube()->parse->map->map)
	{
		gc_collect();
		exit(EXIT_FAILURE);
	}
}

void    read_map(void)
{
	bool    valid;

	get_tmp();
	valid = false;
	while (1)
	{
		init_line(cube()->parse->tmp);
		if (!cube()->parse->line)
			break ;
		if (check_for_whitespace(cube()->parse->line))
		{
			valid = true;
			continue;
		}
		alloc_space(valid);
		ft_memset(cube()->parse->line + ft_strlen(cube()->parse->line) - 1, '\0', 1);
		if (cube()->parse->map->width < (int)ft_strlen(cube()->parse->line))
			cube()->parse->map->width = ft_strlen(cube()->parse->line);
		cube()->parse->map->map[cube()->parse->map->height] = cube()->parse->line;
		cube()->parse->map->height++;
	}
	check_for_valid_map();
}

void	print_map(void)
{
	int i;

	printf("Map:\n");
	for (i = 0; i < cube()->parse->map->height + 2; i++)
		printf("%s\n", cube()->parse->map->map[i]);
}
