#include <iostream>
#include <fstream>
#include <vector>

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	std::vector<int>	data;
	int		prev;
	int		current;
	int		count = 0;

	input.open( "input.txt" );

	if ( input.is_open() ) {
		while ( getline( input, line ) ) {
			data.push_back( stoi( line ) );
		}
		prev = data[0] + data[1] + data[2];
		for ( unsigned long i = 1; i < data.size() - 2; i++ )
		{
			current = data[i] + data[i + 1] + data[i + 2];
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
