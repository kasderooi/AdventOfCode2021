#include <iostream>
#include <fstream>

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	int				prev;
	int				current;
	int				count = 0;

	input.open( "input.txt" );

	if ( input.is_open() ) {
		getline( input, line );
		prev = stoi( line );
		while ( getline( input, line ) ) {
			current = stoi( line );
			if ( current > prev )
				count++;
			prev = current;
		}
	}
	else
		return (1);
	std::cout << count << std::endl;
	return (0);
}
