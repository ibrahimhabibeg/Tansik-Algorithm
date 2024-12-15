#include <string>
#include <utility>
#include "Program.cpp"

using namespace std;

class Student {
private:
    int id;
    string name;
    double arabicGrade{};
    double englishGrade{};
    double mathGrade{};
    double scienceGrade{};
    string coverLetter;

    bool (*comparator)(Program *, Program *){};

    Program *program{};

public:
    Student() = default;

    Student(int id, string name, double arabicGrade, double englishGrade, double mathGrade, double scienceGrade, string coverLetter,
            bool (*comparator)(Program *, Program *)) {
        this->id = id;
        this->name = name;
        this->arabicGrade = arabicGrade;
        this->englishGrade = englishGrade;
        this->mathGrade = mathGrade;
        this->scienceGrade = scienceGrade;
        this->coverLetter = coverLetter;
        this->comparator = comparator;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    double getArabicGrade() {
        return arabicGrade;
    }

    double getEnglishGrade() {
        return englishGrade;
    }

    double getMathGrade() {
        return mathGrade;
    }

    double getScienceGrade() {
        return scienceGrade;
    }

    string getCoverLetter() {
        return coverLetter;
    }

    bool (*getComparator())(Program *, Program *) {
        return comparator;
    }

    Program* getProgram() {
        return program;
    }

    void setId(int id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }

    void setArabicGrade(double arabicGrade) {
        this->arabicGrade = arabicGrade;
    }

    void setEnglishGrade(double englishGrade) {
        this->englishGrade = englishGrade;
    }

    void setMathGrade(double mathGrade) {
        this->mathGrade = mathGrade;
    }

    void setScienceGrade(double scienceGrade) {
        this->scienceGrade = scienceGrade;
    }

    void setCoverLetter(string coverLetter) {
        this->coverLetter = coverLetter;
    }

    void setComparator(bool (*comparator)(Program *, Program *)) {
        this->comparator = comparator;
    }

    void setProgram(Program *program) {
        this->program = program;
    }
};
