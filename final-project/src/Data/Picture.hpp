#ifndef PICTURE_HPP
#define PICTURE_HPP

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

class Genre {
    public:
        enum Value {
            UNKNOWN = 0,
            ACTION,
            ADVENTURE,
            BIOGRAPHY,
            COMEDY,
            CRIME,
            DRAMA,
            FAMILY,
            FILM_NOIR,
            MUSICAL,
            MYSTERY,
            ROMANCE,
            WAR,
            WESTERN
        };
        
        Genre(){}
 
        constexpr Genre(Value value): value(value) {}

        Genre(std::string genre) {
            std::transform(genre.begin(), genre.end(), genre.begin(), ::toupper);
            if(genre == "ACTION") this->value = ACTION;
            else if(genre == "ADVENTURE") this->value = ADVENTURE;
            else if(genre == "BIOGRAPHY") this->value = BIOGRAPHY;
            else if(genre == "COMEDY") this->value = COMEDY;
            else if(genre == "CRIME") this->value = CRIME;
            else if(genre == "DRAMA") this->value = DRAMA; 
            else if(genre == "FAMILY") this->value = FAMILY;
            else if(genre == "FILM-NOIR") this->value = FILM_NOIR; 
            else if(genre == "MUSICAL") this->value = MUSICAL;
            else if(genre == "MYSTERY") this->value = MYSTERY;
            else if(genre == "ROMANCE") this->value = ROMANCE;
            else if(genre == "WAR") this->value = WAR;
            else if(genre == "WESTERN") this->value = WESTERN;
            else this->value = UNKNOWN;
        }

        bool operator==(Genre genre) const { return this->value == genre.value; }
        bool operator!=(Genre genre) const { return this->value != genre.value; }
        bool operator>(Genre genre) const { return this->value > genre.value; }
        bool operator<(Genre genre) const { return this->value < genre.value; }

        std::string toString() {
            if(this->value == ACTION) return "ACTION";
            if(this->value == ADVENTURE) return "ADVENTURE";
            if(this->value == BIOGRAPHY) return "BIOGRAPHY";
            if(this->value == COMEDY) return "COMEDY";
            if(this->value == CRIME) return "CRIME";
            if(this->value == DRAMA) return "DRAMA";
            if(this->value == FAMILY) return "FAMILY";
            if(this->value == FILM_NOIR) return "FILM-NOIR";
            if(this->value == MUSICAL) return "MUSICAL";
            if(this->value == MYSTERY) return "MYSTERY";
            if(this->value == ROMANCE) return "ROMANCE";
            if(this->value == WAR) return "WAR";
            if(this->value == WESTERN) return "WESTERN";
            return "UNKNOWN";
        }

        
    private:
        Value value;
};

static Genre genreFromString(std::string genre) {
        std::transform(genre.begin(), genre.end(), genre.begin(), ::toupper);
        if(genre == "ACTION") return Genre::ACTION;
        if(genre == "ADVENTURE") return Genre::ADVENTURE;
        if(genre == "BIOGRAPHY") return Genre::BIOGRAPHY;
        if(genre == "COMEDY") return Genre::COMEDY;
        if(genre == "CRIME") return Genre::CRIME;
        if(genre == "DRAMA") return Genre::DRAMA;
        if(genre == "FAMILY") return Genre::FAMILY;
        if(genre == "FILM-NOIR") return Genre::FILM_NOIR; 
        if(genre == "MUSICAL") return Genre::MUSICAL;
        if(genre == "MYSTERY") return Genre::MYSTERY;
        if(genre == "ROMANCE") return Genre::ROMANCE;
        if(genre == "WAR") return Genre::WAR;
        if(genre == "WESTERN") return Genre::WESTERN;
        return Genre::UNKNOWN;
}


class Month {
    public:
        enum Value {
            JANUARY = 1,
            FEBRUARY = 2,
            MARCH = 3,
            APRIL = 4,
            MAY = 5,
            JUNE = 6,
            JULY = 7,
            AUGUST = 8,
            SEPTEMBER = 9,
            OCTOBER = 10,
            NOVEMBER = 11,
            DECEMBER= 12
        };
        
        Month() {}
    
        constexpr Month(Value value): value(value) { }
        
        Month(std::string month) {
            std::transform(month.begin(), month.end(), month.begin(), ::toupper);
            if(month == "JANUARY") this->value = JANUARY;
            else if(month == "FEBRUARY") this->value = FEBRUARY;
            else if(month == "MARCH") this->value = MARCH;
            else if(month == "APRIL") this->value = APRIL;
            else if(month == "MAY") this->value = MAY;
            else if(month == "JUNE")  this->value = JUNE;
            else if(month == "JULY")  this->value = JULY;
            else if(month == "AUGUST")  this->value = AUGUST;
            else if(month == "SEPTEMBER")  this->value = SEPTEMBER;
            else if(month == "OCTOBER")  this->value = OCTOBER;
            else if(month == "NOVEMBER") this->value = NOVEMBER;
            else this->value = DECEMBER;
        }

        bool operator==(Month month) const { return this->value == month.value; }
        bool operator!=(Month month) const { return this->value != month.value; }
        bool operator>(Month month) const { return this->value > month.value; }
        bool operator<(Month month) const { return this->value < month.value; }
        
        std::string toString() {
            if(this->value == JANUARY) return "JANUARY";
            if(this->value == FEBRUARY) return "FEBRUARY";
            if(this->value == MARCH) return "MARCH";
            if(this->value == APRIL) return "APRIL";
            if(this->value == MAY) return "MAY";
            if(this->value == JUNE) return "JUNE";
            if(this->value == JULY) return "JULY";
            if(this->value == AUGUST) return "AUGUST";
            if(this->value == SEPTEMBER) return "SEPTEMBER";
            if(this->value == OCTOBER) return "OCTOBER";
            if(this->value == NOVEMBER) return "NOVEMBER";
            return "DECEMBER";
        }
        
    private:
        Value value;
        
};

static Month monthFromString(std::string month) {
    std::transform(month.begin(), month.end(), month.begin(), ::toupper);
    if(month == "JANUARY") return Month::JANUARY;
    if(month == "FEBRUARY") return Month::FEBRUARY;
    if(month == "MARCH") return Month::MARCH;
    if(month == "APRIL") return Month::APRIL;
    if(month == "MAY") return Month::MAY;
    if(month == "JUNE") return Month::JUNE;
    if(month == "JULY") return Month::JULY;
    if(month == "AUGUST") return Month::AUGUST;
    if(month == "SEPTEMBER") return Month::SEPTEMBER;
    if(month == "OCTOBER") return Month::OCTOBER;
    if(month == "NOVEMBER") return Month::NOVEMBER;
    return Month::DECEMBER;
    
}

class Picture {
    private:
        unsigned int index;
        std::string name;
        unsigned short year;
        unsigned short nominations;
        float rating;
        unsigned short duration;
        Genre genre1;
        Genre genre2;
        Month release;
        unsigned short metacritic;
        std::string synopsis;

    public:
        Picture();
        Picture(unsigned int index, std::string name, std::string year, std::string nominations, std::string rating, std::string duration, std::string genre1, std::string genre2, std::string release, std::string metacritic, std::string synopsis);
        unsigned int getIndex();
        std::string getName();
        unsigned short getYear();
        unsigned short getNominations();
        float getRating();
        unsigned short getDuration();
        Genre getGenre1();
        Genre getGenre2();
        Month getRelease();
        unsigned short getMetacritic();
        std::string getSynopsis();
        
        void setIndex(std::string index);        
        void setName(std::string name);
        void setYear(std::string year);
        void setNominations(std::string year);
        void setRating(std::string rating); 
        void setDuration(std::string duration);
        void setGenre1(std::string genre1);
        void setGenre2(std::string genre2);
        void setRelease(std::string release);
        void setMetacritic(std::string metacritic);
        void setSynopsis(std::string synopsis);

        void print();
        std::string toCsvFormat();
        friend std::ostream& operator<<(std::ostream& os, Picture& pictrue);
};
#endif
