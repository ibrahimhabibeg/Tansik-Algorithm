vector<string> names = {
    "Ahmed", "Mohamed", "Ibrahim", "Ali", "Omar", "Khaled", "Mahmoud", "Amr", "Hassan", "Hussein", "Yosef"};

vector<string> coverLetters = {
    "Influential",
    "Innovative",
    "Intelligent",
    "Boring",
    "Creative",
    "Empty"};

double getRandomGrade()
{
    int min = 50;
    int max = 100;
    return min + (rand() % (int)(max - min + 1));
}

vector<Student *> generateTestStudents(int count)
{
    vector<Student *> students;

    for (int i = 0; i < count; i++)
    {
        students.push_back(new Student(i + 1, names[rand() % names.size()],
                                       getRandomGrade(),
                                       getRandomGrade(),
                                       getRandomGrade(),
                                       getRandomGrade(),
                                       coverLetters[rand() % coverLetters.size()],
                                       studentCompartors[rand() % studentCompartors.size()]));
    }
    return students;
}
