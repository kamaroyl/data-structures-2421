#ifndef CLI_UI_HPP
#define CLI_UI_HPP
class UiScreen {
    private:
       Menu menu; 

       void transition();
    
    public:
        std::string getUserInput();
        std::string getUserInputWithDefault(std::string default);
};

#endif
