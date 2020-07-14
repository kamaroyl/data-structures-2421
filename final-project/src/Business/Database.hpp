#ifndef DATABASE_HPP
#define DATABASE_HPP
#include "TreeManager.hpp"
#include "../FileHandling/CsvParser.hpp"
#include "../FileHandling/CsvWriter.hpp"
class Database {

    private:
        TreeManager* treeManager;
        CsvParser* csvReader;
        CsvWriter* csvWriter;
        bool running;

    public:

        void run();
      
}
#endif
