#include <iostream>
#include <fstream>
#include <vector>
#include "Fish.hpp"

void split_to_int( std::vector<int> *init_list, std::string line, char c ) {
	int buf = 0;

	for ( int i = 0; line[i]; i++ ) {
		if ( line[i] != c ) {
			buf *= 10;
			buf += line[i] - 48;
		} else if ( i != 0 && line[i + 1] != c ) {
			(*init_list).push_back( buf );
			buf = 0;
		}
	}
	(*init_list).push_back( buf );
}

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	std::vector<int> init_list;
	std::vector<Fish*> fish;
	int					ret = 0;
	
	input.open( "input.txt" );
	if ( input.is_open() ) {
		getline( input, line );
		split_to_int( &init_list, line, ',' );
	} else
		return (1);
	for ( std::vector<int>::iterator it = init_list.begin(); it < init_list.end(); it++ )
		fish.push_back( new Fish( *it ));
	for (int i = 0; i < 80; i++)
		for ( std::vector<Fish*>::iterator it = fish.begin(); it < fish.end(); it++ )
			(*it)->new_day();
	for ( std::vector<Fish*>::iterator it = fish.begin(); it < fish.end(); it++ )
		ret += (*it)->count_offspring();
	ret += fish.size();
	std::cout << ret << std::endl;
	input.close();
	return (0);
}
