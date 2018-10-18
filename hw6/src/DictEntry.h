#ifndef DICTENTRY_
#define DICTENTRY_
#include <string>

typedef std::string wordType;
class DictEntry
{
private:
    wordType word = "";
    wordType definition= "";
    
public:
    DictEntry(){ word=""; definition="";}
    wordType getWord(){return word;}
    void setWord(wordType _word){word = _word;}
    wordType getDef(){return definition;}
    void setDef(wordType _def){definition = _def;}
    bool operator < (const DictEntry &entry) const {
        return (word < entry.word);}
    DictEntry& operator=(DictEntry& dictEntry) {
        this->word = dictEntry.getWord();
        this->definition = dictEntry.getDef();
        return *this;
    }

};

#endif
