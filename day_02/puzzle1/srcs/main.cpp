#include <iostream>
#include <fstream>
#include <string>

int	ft_strlen(const char *str){
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	main( void ) {
	std::ifstream	input;
	std::string		line;
	int		horizontal = 0;
	int		vertical = 0;

	input.open( "input.txt" );

	if ( input.is_open() ) {
		while ( getline( input, line ) ) {
			if ( line.find("forward") != std::string::npos )
				horizontal += (line[line.length() - 1] - 48);
			if ( line.find("up") != std::string::npos )
				vertical -= (line[line.length() - 1] - 48);
			if ( line.find("down") != std::string::npos )
				vertical += (line[line.length() - 1] - 48);
		}

	}
	else
		return (1);
	std::cout << horizontal * vertical << std::endl;
	return (0);
}

