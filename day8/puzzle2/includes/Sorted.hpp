#ifndef SORTED_HPP
#define SORTED_HPP

#include <vector>
#include <string>
char	compare( std::string one, std::string other ) {
	for ( unsigned long i = 0; i < other.length(); i++ )
		if ( one.find( other[i], 0 ) == std::string::npos )
			return other[i];
	return 0;
}

char	compare_all( std::string one, std::string other ) {
	if ( one.length() != other.length() )
		return 1;
	for ( unsigned long i = 0; i < other.length(); i++ )
		if ( one.find( other[i], 0 ) == std::string::npos )
			return 1;
	return 0;
}

class Sorted {

	private:

	char	a;
	char	c;
	char	d;
	char	e;
	char	g;
	std::string	numbers[10];

	public:

	Sorted( std::vector<std::string> list ) {
		this->set_a( list );
		this->set_cde( list );
		this->set_g( list );
	};
	~Sorted( void ){};

	void	set_a( std::vector<std::string> list ) {
		for ( unsigned long i = 0; i < list.size(); i++ ) {
			if ( list[i].length() == 2 )
				this->numbers[1] = list[i];
			if ( list[i].length() == 3 )
				this->numbers[7] = list[i];
			if ( list[i].length() == 4 )
				this->numbers[4] = list[i];
			if ( list[i].length() == 7 )
				this->numbers[8] = list[i];
		}
		this->a = compare( this->numbers[0], this->numbers[7] );
	}

	void	set_cde( std::vector<std::string> list ) {
		std::string options[3];
		std::string nbr4;
		std::string nbr1;
		int			count = 0;
		char		x[3];

		for ( unsigned long i = 0; i < list.size(); i++ )
			if ( list[i].length() == 6 )
				options[count++] = list[i];
		x[0] = compare( options[0], options[1] );
		x[1] = compare( options[1], options[2] );
		x[2] = compare( options[2], options[0] );
		for ( unsigned long i = 0; i < 3; i++ ) {
			if ( this->numbers[1].find( x[i], 0 ) != std::string::npos )
				this->d = x[i];
			else if ( this->numbers[4].find( x[i], 0 ) != std::string::npos )
				this->c = x[i];
			if ( this->numbers[4].find( x[i], 0 ) == std::string::npos )
				this->e = x[i];
		}
		for ( int i = 0; i < 3; i++ ) {
			if ( options[i].find( this->d, 0 ) == std::string::npos )
				this->numbers[6] = options[i];
			if ( options[i].find( this->e, 0 ) == std::string::npos )
				this->numbers[9] = options[i];
			if ( options[i].find( this->c, 0 ) == std::string::npos )
				this->numbers[0] = options[i];
		}
	}

	void	set_g( std::vector<std::string> list ) {
		std::string options[3];
		int			count = 0;

		for ( unsigned long i = 0; i < list.size(); i++ )
			if ( list[i].length() == 5 )
				options[count++] = list[i];
		for ( unsigned long i = 0; i < options[0].length(); i++ )
			if ( options[1].find( options[0][i], 0 ) != std::string::npos 
				&& options[2].find( options[0][i], 0 ) != std::string::npos 
				&& options[0][i] != this->a && options[0][i] != this->c )
				this->g = options[0][i];
		for ( unsigned long i = 0; i < 3; i++ ) {
			if ( options[i].find( this->e, 0 ) == std::string::npos ) {
				if ( options[i].find( this->d, 0 ) == std::string::npos )
					this->numbers[5] = options[i];
				else
					this->numbers[3] = options[i];
			} else
				this->numbers[2] = options[i];
		}
	}

	std::string get_number( int i ) {
		return this->numbers[i];
	}

};


#endif
