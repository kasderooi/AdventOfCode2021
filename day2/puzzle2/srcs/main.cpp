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
	const char	*str;
	int		value = 0;
	int		horizontal = 0;
	int		vertical = 0;
	int		aim = 0;

	input.open( "input.txt" );

	if ( input.is_open() ) {
		while ( getline( input, line ) ) {
			str = line.c_str();
			value = (str[ft_strlen(str) - 1] - 48);
			if ( line.find("forward") != std::string::npos ) {
				horizontal += value;
				vertical += (value * aim);
			}
			if ( line.find("up") != std::string::npos )
				aim -= value;
			if ( line.find("down") != std::string::npos )
				aim += value;
		}

	}
	else
		return (1);
	std::cout << horizontal * vertical << std::endl;
	return (0);
}
