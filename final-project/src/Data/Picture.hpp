#ifndef PICTURE_HPP
#define PICTURE_HPP
class Picture {
    private:
        int index;
        std::string name;
        int year;
        short nominations;
        float rating;
        short duration;
        Genre genre1;
        Genre genre2;
        Month release;
        short metacritic;
        std::string synopsis;

        Picture();
    public:
        Picture(int index, std::string name, std::string year, std::string nominations, std::string rating, std::string duration, std::string genre1, std::string genre2, std::string release, std::string metacritic, std::string synopsis);
        int getIndex();
        std::string getName();
        int getYear();
        short getNominations();
        float getRating();
        short getDuration();
        Genre getGenre1();
        Genre getGenre2();
        Month getRelease();
        short getMetacritic();
        std::string getSynopsis();
        
        void print();
        std::string toCsvFormat();
};
#endif
