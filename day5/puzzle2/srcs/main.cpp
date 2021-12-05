#include <fstream>
#include "Coordinates.hpp"
#include "Map.hpp"
#include "utils.hpp"

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	std::vector<Coordinates *> coordinates;
	Map				map;
	
	input.open( "input.txt" );
	if ( input.is_open() ) {
		while ( getline( input, line ) )
			if ( line.length() ) {
				coordinates.push_back( new Coordinates( line ) );
				map.set_max( coordinates.back() );
			}
	} else
		return (1);
	map.generate_map();
	fill_map( coordinates, &map );
	std::cout << count_points( &map ) << std::endl;
	input.close();
	return (0);
}
