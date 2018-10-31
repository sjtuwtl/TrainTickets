#ifndef SJTU_EXCEPTIONS_HPP
#define SJTU_EXCEPTIONS_HPP

#include <cstddef>

/**
 * TODO
 * Please complete them.
 */
class index_out_of_bound {
	/* __________________________ */
};

class runtime_error {
	/* __________________________ */
};

class invalid_iterator {
	/* __________________________ */
};

class container_is_empty {
	/* __________________________ */
};

class outOfBound {
	/* __________________________ */
};

class ticketError {
	
};

class trainError {};

class notEnoughTicket: public ticketError {
	
};

class ticketNotExist: public ticketError {
	
};

class noSuchTrain: public ticketError {
	
};

class alreadyExist: public trainError {

};

class trainNotExist: public trainError {

};

#endif
