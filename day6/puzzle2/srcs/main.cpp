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
	int					opt[5];
	int					ret = 0;
	
	input.open( "input.txt" );
	if ( input.is_open() ) {
		getline( input, line );
		split_to_int( &init_list, line, ',' );
	} else
		return (1);
	for ( int i = 1; i < 6; i++ ) {
		fish.push_back( new Fish( i ));
	}
	for (int i = 0; i < 5; i++) {
		opt[i] = 0;
		for (int it = 0; it < 256; it++)
			fish[i]->new_day();
		opt[i] += fish[i]->count_offspring();
		std::cout << opt[i] << std::endl;
	}
	for ( std::vector<int>::iterator it = init_list.begin(); it < init_list.end(); it++) {
		for (int i = 0; i < 5; i++)
			if (*it == i + 1)
				ret += opt[i];
	}
	ret += init_list.size();
	std::cout << ret << std::endl;
	input.close();
	return (0);
}
