#include <iostream>
#include <fstream>
#include <vector>

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
	unsigned long long	fish[8];
	unsigned long long	buf = 0;
	unsigned long long	ret = 0;
	
	input.open( "input.txt" );
	if ( input.is_open() ) {
		getline( input, line );
		split_to_int( &init_list, line, ',' );
	} else
		return (1);
	for ( int i = 0; i < 9; i++ )
		fish[i] = 0;
	for ( std::vector<int>::iterator it = init_list.begin(); it < init_list.end(); it++ )
		fish[*it]++;
	for ( int i = 0; i < 256; i++ ) {
		buf = fish[0];
		for (int i = 0; i < 8; i++ )
			fish[i] = fish[i + 1];
		fish[8] = buf;
		fish[6] += buf;
	}
	for ( int i = 0; i < 9; i++ )
		ret += fish[i];
	std::cout << ret << std::endl;
	input.close();
	return (0);
}
