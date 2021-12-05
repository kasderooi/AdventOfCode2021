#include "utils.hpp"

void	print_vec( std::vector<Coordinates *> print ) {
	for ( std::vector<Coordinates *>::iterator it = print.begin(); it < print.end(); it++ ) {
		std::cout << (*it)->get_start()[0] << "," << (*it)->get_start()[1] << " -> " << (*it)->get_end()[0] << "," << (*it)->get_end()[1] << std::endl;
	}
}
void	print_map( Map *map ) {
	for ( int x = 0; x <= map->get_x(); x++ ) {
		for ( int y = 0; y <= map->get_y(); y++ )
			std::cout << map->get_point( x, y );
		std::cout << std::endl;
	}
}

int	count_points( Map *map ) {
	int ret = 0;
	for ( int x = 0; x <= map->get_x(); x++ ) {
		for ( int y = 0; y <= map->get_y(); y++ )
			if ( map->get_point( x, y ) >= 2 )
				ret++;
	}
	return ret;
}

void	fill_diagonal( Coordinates* coordinate, Map *map ){
	int	x[2];
	int y[2];
	int dist[2];
	y[0] = coordinate->get_start()[0];
	y[1] = coordinate->get_end()[0];
	x[0] = coordinate->get_start()[1];
	x[1] = coordinate->get_end()[1];
	dist[0] = (x[1] - x[0]) > (x[0] - x[1]) ? (x[1] - x[0]) : (x[0] - x[1]);
	dist[1] = (y[1] - y[0]) > (y[0] - y[1]) ? (y[1] - y[0]) : (y[0] - y[1]);
	
	if ( x[0] < x[1] ) {
		if ( y[0] < y[1] )
			for (int i = 0; i <= dist[0]; i++ )
				map->set_point( x[0] + i, y[0] + i );
		else
			for (int i = 0; i <= dist[0]; i++ )
				map->set_point( x[0] + i, y[0] - i );
	} else if ( x[0] > x[1] ) {
		if ( y[0] < y[1] )
			for (int i = 0; i <= dist[0]; i++ )
				map->set_point( x[0] - i, y[0] + i );
		else
			for (int i = 0; i <= dist[0]; i++ )
				map->set_point( x[0] - i, y[0] - i );
	}
}

void	fill_map( std::vector<Coordinates *> coordinates, Map *map ) {
	int	x[2];
	int y[2];
	int	start;
	int end;

	for ( std::vector<Coordinates *>::iterator it = coordinates.begin(); it < coordinates.end(); it++ ) {
		y[0] = (*it)->get_start()[0];
		y[1] = (*it)->get_end()[0];
		x[0] = (*it)->get_start()[1];
		x[1] = (*it)->get_end()[1];
		start = 0;
		end = 0;
		if ( x[0] == x[1] ) {
			start = y[0] < y[1] ? y[0] : y[1];
			end = y[0] > y[1] ? y[0] : y[1];
			for (int i = start; i <= end; i++ )
				map->set_point( x[0], i );
		} else if ( y[0] == y[1] ) {
			start = x[0] < x[1] ? x[0] : x[1];
			end = x[0] > x[1] ? x[0] : x[1];
			for (int i = start; i <= end; i++ )
				map->set_point( i, y[0] );
		} else {
			fill_diagonal( (*it), map );
		}
	}
}
