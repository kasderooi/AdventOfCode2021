#ifndef FISH_HPP
#define FISH_HPP

#include <vector>

class Fish {

	private:

		int					_days;
		std::vector<Fish*>	_offspring;

	public:

		Fish ( void ) : _days( 8 ), _offspring() {};
		Fish( int days ) : _days( days ), _offspring() {};
		~Fish( void ) {};

		void new_day( void ) {
			for ( std::vector<Fish*>::iterator it = _offspring.begin(); it < _offspring.end(); it++)
				(*it)->new_day();
			_days--;
			if ( _days < 0 )
				this->reproduce();
		}

		void reproduce( void ) {
			Fish*	kid = new Fish;
			_days = 6;
			this->_offspring.push_back( kid );
		}

		int count_offspring( void ) {
			int ret = 0;

			for ( std::vector<Fish*>::iterator it = _offspring.begin(); it < _offspring.end(); it++)
				ret += (*it)->count_offspring();
			ret += _offspring.size();
			return ret;
		}

		void delete_offspring( void ) {
			for ( std::vector<Fish*>::iterator it = _offspring.begin(); it < _offspring.end(); it++)
				(*it)->delete_offspring();
			for ( std::vector<Fish*>::iterator it = _offspring.begin(); it > _offspring.end(); it++)
				delete (*it);
		}
};

#endif
