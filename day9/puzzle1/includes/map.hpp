#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <string>

class Map {

	private:

	int		_x;
	int		_y;
	int**	_map;

	public:

	Map( void ) : _x(0), _y(0), _map(NULL) {};
	~Map( void ) {delete[] _map;};

	void initialize_map( std::vector<std::string> init_list ) {
		_x = init_list.size();
		_y = init_list[0].length();
		_map = new int*[_x];

		for ( int x = 0; x < _x; x++ ) {
			_map[x] = new int[_y];
			for ( int y = 0; y < _y; y++ ) {
				_map[x][y] = init_list[x][y] - '0';
			}
		}
	}
	int	check_if_low( void ) {
		int	check;
		int ret = 0;

		for ( int x = 0; x < _x; x++ ) {
			for ( int y = 0; y < _y; y++ ) {
				check = 0;
				if (y < _y - 1) {
					if (_map[x][y + 1] > _map[x][y])
						check++;
				} else
					check++;
				if (y > 0) {
					if (_map[x][y - 1] > _map[x][y])
						check++;
				} else
					check++;
				if (x < _x - 1) {
					if (_map[x + 1][y] > _map[x][y])
						check++;
				} else
					check++;
				if (x > 0) {
					if (_map[x - 1][y] > _map[x][y])
						check++;
				} else
					check++;
				if ( check == 4 )
					ret += _map[x][y] + 1;
			}
		}
		return ret;
	}

};

#endif
