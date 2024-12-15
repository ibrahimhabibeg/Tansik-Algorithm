#include <bits/stdc++.h>
#include "StudentMatchingSystem.cpp"
#include "TestProgramsCompartors.cpp"
#include "TestStudentsCompartors.cpp"
#include "TestProgramsGenerator.cpp"
#include "TestStudentsGenerator.cpp"

using namespace std;

int STUDENTS_COUNT = 100;

int main()
{

    vector<Student *> students = generateTestStudents(STUDENTS_COUNT);
    vector<Program *> programs = generateTestPrograms();

    auto *system = new StudentMatchingSystem(students, programs);
    system->match();

    for (Program *program : programs)
    {
        vector<Student *> assignedStudents = program->getStudents();
        sort(assignedStudents.begin(), assignedStudents.end(), program->getCompartor());
        printf("The program of %s at %s ranked #%d in %s which has %s have %lu students:\n",
               facultyTypeNames[program->getFacultyType()].c_str(), universityNames[program->getUniversity()].c_str(),
               program->getRank(), cityNames[program->getCity()].c_str(),
               programCompartorNames[program->getCompartor()].c_str(), assignedStudents.size());

        for (Student *student : assignedStudents)
        {
            printf("Arabic: %.2f, English: %.2f, Math: %.2f, Science: %.2f, Cover Letter: %s, Comparator: %s\n",
                   student->getArabicGrade(), student->getEnglishGrade(), student->getMathGrade(),
                   student->getScienceGrade(), student->getCoverLetter().c_str(),
                   studentCompartorNames[student->getComparator()].c_str());
        }
        printf("\n");
    }
}
