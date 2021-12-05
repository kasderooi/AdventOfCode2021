#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <vector>
#include "Coordinates.hpp"
#include "Map.hpp"

void	print_vec( std::vector<Coordinates *> print );
void	print_map( Map *map );
int		count_points( Map *map );
void	fill_map( std::vector<Coordinates *> coordinates, Map *map );

#endif
