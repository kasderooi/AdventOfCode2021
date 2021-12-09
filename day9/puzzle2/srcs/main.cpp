#include <iostream>
#include <fstream>
#include <string>
#include "map.hpp"

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	std::vector<std::string> init_list;
	Map				themap;
	
	input.open( "input.txt" );
	if ( input.is_open() ) {
		while ( getline( input, line ) )
			init_list.push_back(line);
	} else
		return (1);
	themap.initialize_map( init_list );
	themap.check_if_low();
	input.close();
	return (0);
}
