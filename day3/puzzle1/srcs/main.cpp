
#include <iostream>
#include <fstream>
#include <string>

#define len 12

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	int			mc_bits[len];
	int			line_count = 0;
	int			gamma = 0;
	int			epsilon = 0;

	input.open( "input.txt" );
	for ( int i = 0; i < len; i++ ) {
		mc_bits[i] = 0;
	}
	if ( input.is_open() ) {
		while ( getline( input, line ) ) {
			line_count++;
			for ( int i = 0; i < len; i++ )
				mc_bits[i] = mc_bits[i] + line[i] - 48;
		}
		for ( int i = 0; i < len; i++ ) 
			mc_bits[i] = round( (double)mc_bits[i] / (double)line_count );
	}
	else
		return (1);
	input.close();
	for ( int i = 0; i < len; i++ ){
		if ( mc_bits[i] ){
			gamma = gamma << 1;
			epsilon = epsilon << 1;
			gamma++;
		} else {
			gamma = gamma << 1;
			epsilon = epsilon << 1;
			epsilon++;
		}
	}
	std::cout << gamma * epsilon << std::endl;
	return (0);
}