#include "Student.cpp"
#include "PriorityQueue.cpp"
#include <vector>
#include <map>

using namespace std;

class StudentMatchingSystem {
private:
    vector<Student *> students;
    vector<Program *> programs;
    map<Student *, PriorityQueue<Program *> *> programsList;
    map<Program *, PriorityQueue<Student *> *> programCircle;

    void makeStudentGoToCircle(Student *student) {
        if (programsList[student]->size() == 0)
            return;

        Program *program = programsList[student]->top();
        programCircle[program]->push(student);
        programsList[student]->pop();
    }

public:
    StudentMatchingSystem(vector<Student *> students, vector<Program *> programs) {
        this->students = students;
        this->programs = programs;
        for (Student *student: students) {
            this->programsList[student] = new PriorityQueue<Program *>(student->getComparator(), programs, false);
        }
        for (Program *program: programs) {
            this->programCircle[program] = new PriorityQueue<Student *>(program->getCompartor(), true);
        }
    }

    void match() {
        vector<Student *> toLookForNewCircle;
        for (Student *student: students)
            toLookForNewCircle.push_back(student);

        while (!toLookForNewCircle.empty()) {
            for (Student *student: toLookForNewCircle)
                makeStudentGoToCircle(student);
            toLookForNewCircle.clear();
            for (Program *program: programs)
                while (programCircle[program]->size() > program->getCapacity())
                    toLookForNewCircle.push_back(programCircle[program]->pop());
        }

        for (Program *program: programs) {
            while (!programCircle[program]->empty()) {
                Student *student = programCircle[program]->pop();
                program->addStudent(student);
                student->setProgram(program);
            }
        }
    }
};
