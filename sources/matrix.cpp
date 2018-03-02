#include "matrix.hpp"

matrix_t::matrix_t() : elements_{ nullptr }, rows_{ 0 }, collumns_{ 0 }
{
}

matrix_t::matrix_t( matrix_t const & other )
{
	 rows_ = matrix. rows_;
	collumns_ = matrix.collumns_;
	elements_ = new int *[ rows_];
	for (unsigned int i = 0; i <  rows_; ++i) {
	elements_[i] = new int[collumns_];
		for (unsigned int j = 0; j < collumns_; ++j) {
			elements_[i][j] = matrix.elements_[i][j];
		}
	}
}

matrix_t & matrix_t::operator =( matrix_t const & other )
{
	for (unsigned int i = 0; i < rows_; ++i) {
		delete[] elements_[i];
	}
	delete[] elements_;
	rows_ = matrix.rows_;
	collumns_ = matrix.collumns_;
	elements_ = new int * [rows_];
	for (unsigned int i = 0; i < rows_; ++i) {
		elements_[i] = new int[collumns_];
		for (unsigned int j = 0; j < collumns_; ++j) {
			elements_[i][j] = matrix.elements_[i][j];
		}
	}			
	return *this;
}

matrix_t::~matrix_t()
{
	for (unsigned int i = 0; i < rows_; i++) {
		delete [] elements_[i];
	}
	delete []elements_;
}

std::size_t matrix_t::rows() const
{
	
    return rows_;
}

std::size_t matrix_t::collumns() const
{
    return collumns_;
}

matrix_t matrix_t::operator +( matrix_t const & other ) const
{
	matrix_t result;
	
	if (rows_ == other.rows_ && collumns == other.collumns_) {
	  	result.elements_ = new int *[rows_];
		for (unsigned int i = 0; i<collumns_; i++) {
			matrix3.data[i] = new int [this->columns];
		}
		result.rows_ = rows_;
		result.collumns_ = collumns_;
		
		for (unsigned int i = 0; i<rows_; i++) {
			for (unsigned int j = 0; j<collumns_; j++) {
				result.elements_[i][j] = elements_[i][j] + other.elements_[i][j];
			}
		}
	}
	else {
		cout << endl << "You can`t make this action";
		exit(0);
	}

	return result;
}

matrix_t matrix_t::operator -( matrix_t const & other ) const
{
	matrix_t result;
	
	if (rows_ == other.rows_ && collumns == other.collumns_) {
	  	result.elements_ = new int *[rows_];
		for (unsigned int i = 0; i<collumns_; i++) {
			matrix3.data[i] = new int [this->columns];
		}
		result.rows_ = rows_;
		result.collumns_ = collumns_;
		
		for (unsigned int i = 0; i<rows_; i++) {
			for (unsigned int j = 0; j<collumns_; j++) {
				result.elements_[i][j] = elements_[i][j] - other.elements_[i][j];
			}
		}
	}
	else {
		cout << endl << "You can`t make this action";
		exit(0);
	}

	return result;
}

matrix_t matrix_t::operator *( matrix_t const & other ) const
{
	matrix_t result;
	
	if (collumns_ == other.rows_) {
  		result.elements_ = new int *[other.rows_];
		for (unsigned int i = 0; i<rows_; i++) {
			result.elements_[i] = new int [collumns_];
	    }
	    result.rows_ = other.rows_;
	    result.collumns_ = columns_;
	    
		for (unsigned int i = 0; i < rows_; ++i) {
			for (unsigned int j = 0; j < other.collumns_; ++j) {
				int result_ = 0;
				for (unsigned int k = 0; k < other.rows_; ++k) {
					result_ += elements_[i][k] * other.elements_[k][j];
				}
				result.elements_[i][j] = result_;
			}
		}
	}
	else {
		cout << endl << "You can`t make this action";
		exit(0);
	}

	return result;
}

matrix_t & matrix_t::operator -=( matrix_t const & other )
{
	if (rows_ == other.rows_ && collumns == other.collumns_) {
		for (unsigned int i = 0; i<rows_; i++) {
			for (unsigned int j = 0; j<collumns_; j++) {
				elements_[i][j] -= other.elements_[i][j];
			}
		}
	}
	else {
		cout << endl << "You can`t make this action";
		exit(0);
	}
	
	return *this;
}

matrix_t & matrix_t::operator +=( matrix_t const & other )
{
	if (rows_ == other.rows_ && collumns == other.collumns_) {
		for (unsigned int i = 0; i<rows_; i++) {
			for (unsigned int j = 0; j<collumns_; j++) {
				elements_[i][j] += other.elements_[i][j];
			}
		}
	}
	else {
		cout << endl << "You can`t make this action";
		exit(0);
	}
	
	return *this;
}

matrix_t & matrix_t::operator *=( matrix_t const & other )
{
	matrix_t result (this);
	
	if (collumns_ == other.rows_) {
	    
		for (unsigned int i = 0; i < rows_; ++i) {
			for (unsigned int j = 0; j < other.collumns_; ++j) {
				int result_ = 0;
				for (unsigned int k = 0; k < other.rows_; ++k) {
					result_ += elements_[i][k] * other.elements_[k][j];
				}
				result.elements_[i][j] = result_;
			}
		}
		*this = result;
	}
	else {
		cout << endl << "You can`t make this action";
		exit(0);
	}
	
	return *this;
}

std::istream & matrix_t::read( std::istream & stream )
{
    std::size_t rows;
    std::size_t collumns;
    char symbol;
    
    bool success = true;
    if( stream >> rows && stream >> symbol && symbol == ',' && stream >> collumns ) {
        float ** elements = new float *[ rows ];
        for( std::size_t i = 0; success && i < rows; ++i ) {
            elements[ i ] = new float[ collumns ];
            for( std::size_t j = 0; j < collumns; ++j ) {
                if( !( stream >> elements[ i ][ j ] ) ) {
                    success = false;
                    break;
                }
            }
        }
        
        if( success ) {
            for( std::size_t i = 0; i < rows_; ++i ) {
                delete [] elements_[ i ];
            }
            delete [] elements_;
            
            rows_ = rows;
            collumns_ = collumns;
            elements_ = elements;
        }
        else {
            for( std::size_t i = 0; i < rows; ++i ) {
                delete [] elements[ i ];
            }
            delete [] elements;
        }
    }
    else {
        success = false;
    }
    
    if( !success ) {
        stream.setstate( std::ios_base::failbit );
    }
    
	return stream;
}

std::ostream & matrix_t::write( std::ostream & stream ) const
{
    stream << rows_ << ", " << collumns_;
    for( std::size_t i = 0; i < rows_; ++i ) {
        stream << '\n';
        for( std::size_t j = 0; j < collumns_; ++j ) {
            stream << elements_[ i ][ j ];
            if( j != rows_ - 1 ) {
                stream << ' ';
            }
        }
    }
    
	return stream;
}
