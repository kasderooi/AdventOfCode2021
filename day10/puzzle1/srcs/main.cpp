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

int	check_line( std::string line ) {
	int len = line.length();
	int j = 0;
	int ret = 0;
	char* buf = new char[len];
	
	for ( int i = 0; i < len; i++ )
		buf[i] = 0;
	for ( int i = 0; i < len; i++ ) {
		if ( line[i] == '(' || line[i] == '[' || line[i] == '{' || line[i] == '<' ) {
			buf[j] = line[i];
			j++;
		} else if ( line[i] == ')' ) {
			if ( buf[j - 1] == '(' ) {
				j--;
				buf[j] = 0;
			} else if ( buf[j - 1] != 0 ) {
				ret += 3;
				break;
			}
		} else if ( line[i] == ']' ) {
			if ( buf[j - 1] == '[' ) {
				j--;
				buf[j] = 0;
			} else if ( buf[j - 1] != 0 ) {
				ret += 57;
				break;
			}
		} else if ( line[i] == '}' ) {
			if ( buf[j - 1] == '{' ) {
				j--;
				buf[j] = 0;
			} else if ( buf[j - 1] != 0 ) {
				ret += 1197;
				break;
			}
		} else if ( line[i] == '>' ) {
			if ( buf[j - 1] == '<' ) {
				j--;
				buf[j] = 0;
			} else if ( buf[j - 1] != 0 ) {
				ret += 25137;
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
