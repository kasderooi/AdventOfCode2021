#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/* 
( ) = 3
[ ] = 57
{ } = 1197
< > = 25137
*/

int	calculate_incorrect( char* buf, char c, int points ) {
	if ( buf[0] == c )
		buf[0] = 0;
	else if ( buf[0] != 0 )
		return points;
	return 0;
}

int	check_line( std::string line ) {
	int len = line.length();
	int j = 0;
	int ret = 0;
	char* buf = new char[len];
	
	memset( buf, 0, len );
	for ( int i = 0; i < len; i++ ) {
		if ( line[i] == '(' || line[i] == '[' || line[i] == '{' || line[i] == '<' ) {
			buf[j++] = line[i];
		} else {
			switch ( line[i] ) {
				case ')' : 	ret += calculate_incorrect( &buf[--j], '(', 3 );
							break;
				case ']' :	ret += calculate_incorrect( &buf[--j], '[', 57 );
							break;
				case '}' :	ret += calculate_incorrect( &buf[--j], '{', 1197 );
							break;
				case '>' :	ret += calculate_incorrect( &buf[--j], '<', 25137 );
							break;
			}
		}
	}
	delete[] buf;
	return ret;
}

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	std::vector<std::string> init_list;
	int ret = 0;
	
	input.open( "input.txt" );
	if ( input.is_open() ) {
		while ( getline( input, line ) )
			init_list.push_back(line);
	} else
		return (1);
	for ( std::vector<std::string>::iterator it = init_list.begin(); it < init_list.end(); it++ ){
		ret += check_line( *it );
	}
	std::cout << ret << std::endl;
	input.close();
	return (0);
}
