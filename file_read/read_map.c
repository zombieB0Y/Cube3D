#include "../cube.h"

void    read_map(void)
{
	char	*line;
	char    *tmp;
	bool    valid;

	while (1)
	{
		tmp = get_next_line(cube()->fd);
		if (!tmp)
			break ;
		if (!check_for_whitespace(tmp))
			break ;
	}
	if (!tmp)
	{
		ft_putstr_fd("Error: empty map file\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
	valid = false;
	while (1)
	{
		if (!tmp)
			line = get_next_line(cube()->fd);
		else
		{
			line = tmp;
			tmp = NULL;
		}
		if (!line)
			break ;
		if (check_for_whitespace(line))
		{
			valid = true;
			continue;
		}
		if (valid)
		{
			ft_putstr_fd("Error: map must start with a valid line\n", 2);
			gc_collect();
			exit(EXIT_FAILURE);
		}
		if (!cube()->parse->map->map)
			cube()->parse->map->map = gc_malloc(sizeof(char *) * 1);
		else
			cube()->parse->map->map = ft_realloc(cube()->parse->map->map, sizeof(char *) * (cube()->parse->map->height + 1),
							sizeof(char *) * (cube()->parse->map->height + 2));
		if (!cube()->parse->map->map)
		{
			gc_collect();
			exit(EXIT_FAILURE);
		}
		ft_memset(line + ft_strlen(line) - 1, '\0', 1);
		if (!cube()->parse->map->width)
			cube()->parse->map->width = ft_strlen(line);
		cube()->parse->map->map[cube()->parse->map->height] = line;
		cube()->parse->map->height++;
	}
	if (cube()->parse->map->height == 0 || cube()->parse->map->width == 0)
	{
		ft_putstr_fd("Error: empty map\n", 2);
		gc_collect();
		exit(EXIT_FAILURE);
	}
	printf("Map loaded successfully with width: %d and height: %d\n",
		cube()->parse->map->width, cube()->parse->map->height);
}
void	print_map(void)
{
	int i;

	printf("Map:\n");
	for (i = 0; i < cube()->parse->map->height; i++)
		printf("%s\n", cube()->parse->map->map[i]);
}
