#ifndef ACTOR_COMPARATOR_HPP
#define ACTOR_COMPARATOR_HPP
#include "../Actor.hpp"

/*
 * index  - 1
 * year   - 2
 * award  - 3
 * winner - 4
 * name   - 5
 * film   - 6
 */
class Field {
    public:
        unsigned char number; //which field are we dealing with
        char value; 
        char (*func)(Actor *, Actor *, bool);
        
        Field() { 
            this->number = 0;
            this->value = 0;
        }
};

/*
 * Comparator for Actors - flags for each of the fields.
 * If flag value is positive then sort in order
 * If flag is zero do not sort on field
 * If flag is negative, reverse sort
 * only one flag may be set at a time. 
 */
class ActorComparator {
    private:
        const unsigned short size  = 6;
        Field * fields; 
        
        void setField(unsigned short number, char value);
    public:
        ActorComparator();
        ActorComparator(ActorComparator* ac); // Copy flags
        ~ActorComparator();
        char* copyFieldValues();
        char operator()(Actor *one, Actor *two);
        void setIndex(char value);
        void setYear(char value);
        void setAward(char value);
        void setWinner(char value);
        void setName(char value);
        void setFilm(char value);
        void insertionSortFields(Field* fields, unsigned short size);
        void clear();
    
};
#endif
