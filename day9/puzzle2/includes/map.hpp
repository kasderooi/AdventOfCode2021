#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <vector>
#include <string>

class Map {

	private:

	int		_x;
	int		_y;
	int**	_map;
	int**	_key;
	std::vector<int> basin;

	public:

	Map( void ) : _x(0), _y(0), _map(NULL) {};
	~Map( void ) { delete[] _map; delete[] _key; };

	void initialize_map( std::vector<std::string> init_list ) {
		_x = init_list.size();
		_y = init_list[0].length();
		_map = new int*[_x];
		_key = new int*[_x];

		for ( int x = 0; x < _x; x++ ) {
			_key[x] = new int[_y];
			_map[x] = new int[_y];
			for ( int y = 0; y < _y; y++ ) {
				_map[x][y] = init_list[x][y] - '0';
				_key[x][y] = 0;
			}
		}
	}

	void go_right( int x, int y, int* ret ) {
		if ( ++y == _y )
			return ;
		if ( _map[x][y] < 9 && _key[x][y] == 0 ) {
			*ret += 1;
			_key[x][y] = 1;
			go_right( x, y, ret );
			go_up( x, y, ret );
			go_down( x, y, ret );
		}
	}

	void go_left( int x, int y, int* ret ) {
		if ( y-- == 0 )
			return ;
		if ( _map[x][y] < 9 && _key[x][y] == 0 ) {
			*ret += 1;
			_key[x][y] = 1;
			go_left( x, y, ret );
			go_up( x, y, ret );
			go_down( x, y, ret );
		}
	}

	void go_up( int x, int y, int* ret ) {
		if ( x-- == 0 )
			return;
		if ( _map[x][y] < 9 && _key[x][y] == 0 ) {
			*ret += 1;
			_key[x][y] = 1;
			go_up( x, y, ret );
			go_left( x, y, ret );
			go_right( x, y, ret );
		}
	}

	void go_down( int x, int y, int* ret ) {
		if ( ++x == _x )
			return;
		if ( _map[x][y] < 9 && _key[x][y] == 0 ) {
			*ret += 1;
			_key[x][y] = 1;
			go_down( x, y, ret );
			go_left( x, y, ret );
			go_right( x, y, ret );
		}
	}

	int	check_the_basin( int x, int y ) {
		int ret = 1;
	
		_key[x][y] = 1;
		this->go_up( x, y, &ret );
		this->go_down( x, y, &ret );
		this->go_right( x, y, &ret );
		this->go_left( x, y, &ret );
		return ret;
	}

	int	check_if_low( void ) {
		int	check;
		int ret = 0;

		for ( int x = 0; x < _x; x++ ) {
			for ( int y = 0; y < _y; y++ ) {
				check = 0;
				if ( y >= _y - 1) {
					check++;
				} else if ( _map[x][y + 1] > _map[x][y] )
					check++;
				if (y <= 0) {
					check++;
				} else if ( _map[x][y - 1] > _map[x][y] )
					check++;
				if ( x >= _x - 1 ) {
					check++;
				} else if ( _map[x + 1][y] > _map[x][y] )
					check++;
				if ( x <= 0 ) {
					check++;
				} else if ( _map[x - 1][y] > _map[x][y] )
					check++;
				if ( check == 4 )
					basin.push_back( check_the_basin( x, y ) );
			}
		}
		return ret;
	}

	void print_basin( void ) {
		int nbr1 = 0;
		int nbr2 = 0;
		int nbr3 = 0;
		for ( std::vector<int>::iterator it = basin.begin(); it < basin.end(); it++ ) {
			if ( (*it) > nbr1 ){
				nbr3 = nbr2;
				nbr2 = nbr1;
				nbr1 = (*it);
			} else if ( (*it) > nbr2 ){
				nbr3 = nbr2;
				nbr2 = (*it);
			} else if ( (*it) > nbr3 ){
				nbr3 = (*it);
			}
		}
		std::cout << nbr1 * nbr2 * nbr3 << std::endl;
	}

};

#endif
